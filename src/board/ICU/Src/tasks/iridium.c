#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <errno.h>

#include <main.h>

#include <ir9602.h>

static ir9602_t _ir;


typedef struct
{
	UART_HandleTypeDef uart;

	mavlink_message_t mavmsgbuf;

	QueueHandle_t rx_queue;
	StaticQueue_t rx_queue_object;
	uint8_t rx_buffer[ICU_IR_UART_RX_BUFFER_SIZE];

	uint8_t accum[ICU_IR_TX_ACCUMULATOR_SIZE];
	uint16_t accum_carret;
} ir9602_user_struct_t;

static ir9602_user_struct_t _ir_user_struct;


static int _ir_uart_getch(void * user_arg, bool should_block)
{
	ir9602_user_struct_t * const user_struct = (ir9602_user_struct_t *)user_arg;

	const TickType_t to_wait = should_block ? ICU_IR_UART_RX_QUEUE_WAIT : 0;

	uint8_t byte;
	const BaseType_t status = xQueueReceive(user_struct->rx_queue, &byte, to_wait);
	if (pdTRUE != status)
		return should_block ? -ETIMEDOUT: -EWOULDBLOCK;

	return byte;
}


// Отправка байта в уарт.
static int _ir_uart_putch_t(void * user_arg, uint8_t byte)
{
	ir9602_user_struct_t * const user_struct = (ir9602_user_struct_t *)user_arg;

	const HAL_StatusTypeDef status = HAL_UART_Transmit(
			&user_struct->uart,
			&byte, 1,
			ICU_IR_UART_TX_HAL_WAIT
	);

	switch (status)
	{
	case HAL_OK:
		return 0;

	case HAL_BUSY:
		return -EBUSY;

	case HAL_TIMEOUT:
		return -ETIMEDOUT;

	case HAL_ERROR:	default:
		return -ENOTCONN;
	};
}


static void _ir_event_hook(void * user_arg, const ir9602_evt_t * event)
{
	// Смотрим уровень сигнала и запоминаем
	if (IR9602_EVT_CIEV == event->code && IR9602_EVT_CIEV_KIND_SIGIND == event->arg.ciev.type)
	{
		global_stats.iridium_sigind = event->arg.ciev.value;
	}
}


static void _hw_init(void)
{
	__HAL_RCC_USART1_CLK_ENABLE();

	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	__HAL_RCC_AFIO_CLK_ENABLE();
	__HAL_AFIO_REMAP_USART1_ENABLE();


	GPIO_InitTypeDef pinit;
	pinit.Mode = GPIO_MODE_AF_INPUT;
	pinit.Pin = GPIO_PIN_7; // PB7 - RX
	pinit.Pull = GPIO_NOPULL;
	pinit.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB, &pinit);

	pinit.Pin = GPIO_PIN_6; // PB6 - TX
	pinit.Mode = GPIO_MODE_AF_PP;
	HAL_GPIO_Init(GPIOB, &pinit);

	pinit.Pin = GPIO_PIN_9; // PC7 - RING INDICATOR
	pinit.Mode = GPIO_MODE_INPUT;
	HAL_GPIO_Init(GPIOC, &pinit);

	_ir_user_struct.uart.Instance = USART1;
	_ir_user_struct.uart.Init.BaudRate = 19200;
	_ir_user_struct.uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	_ir_user_struct.uart.Init.Mode = UART_MODE_TX_RX;
	_ir_user_struct.uart.Init.OverSampling = UART_OVERSAMPLING_16;
	_ir_user_struct.uart.Init.Parity = UART_PARITY_NONE;
	_ir_user_struct.uart.Init.StopBits = UART_STOPBITS_1;
	_ir_user_struct.uart.Init.WordLength = UART_WORDLENGTH_8B;

	if (HAL_UART_Init(&_ir_user_struct.uart) != HAL_OK)
		Error_Handler();

	__HAL_UART_ENABLE_IT(&_ir_user_struct.uart, UART_IT_ERR);
	__HAL_UART_ENABLE_IT(&_ir_user_struct.uart, UART_IT_RXNE);

	HAL_NVIC_SetPriority(USART1_IRQn, ICU_IR_UART_RX_IT_PRIO, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
}


static int mavmsg_len(const mavlink_message_t * msg)
{
	uint8_t signature_len, header_len;
	uint8_t length = msg->len;

	if (msg->magic == MAVLINK_STX_MAVLINK1) {
		signature_len = 0;
		header_len = MAVLINK_CORE_HEADER_MAVLINK1_LEN;
	} else {
		length = _mav_trim_payload(_MAV_PAYLOAD(msg), length);
		header_len = MAVLINK_CORE_HEADER_LEN;
		signature_len = (msg->incompat_flags & MAVLINK_IFLAG_SIGNED)?MAVLINK_SIGNATURE_BLOCK_LEN:0;
	}
	return header_len + 1 + 2 + (uint16_t)length + (uint16_t)signature_len;
}


static int _perform_sbd(ir9602_t * ir, const uint8_t * data, int datasize)
{
	ir9602_user_struct_t * const user = (ir9602_user_struct_t*)ir->user_arg;

	int rc;
	if (user->accum_carret > 0) // Если есть что отправлять, то попытаемся
	{
		ir9602_evt_errcode_t err_evt;
		rc = ir9602_sbdwb(ir, data, datasize, &err_evt);
		if (rc < 0)
			global_stats.iridium_errors++;
	}

	// Даже если у нас не получилось заложить сообщение в модем
	// сеанс всеравно будем проводить. Вдруг что-то придет сверху
	// Так и так, считаем что отправлять нам теперь уж точно нечего
	user->accum_carret = 0;

	ir9602_evt_sbdi_t evt_sbdi;
	rc = ir9602_sbdi(ir, &evt_sbdi);
	if (rc < 0)
	{
		global_stats.iridium_errors++;
		return rc;
	}

	// чего-нибудь нам пришло?
//	if (IR9602_EVT_SBDMSTATUS_YES == evt_sbdi.mo_status)
//		global_stats.iridium_tx++;
	global_stats.iridium_tx = evt_sbdi.momsn;

#if ICU_IR_PROCESS_UPLINK

	if (IR9602_EVT_SBDMSTATUS_YES != evt_sbdi.mt_status)
		return 0; // Если ничего не пришло - больше ничего и не делаем

	// Теперь, если что-то нам пришло..
	global_stats.iridium_rx++;


	// Вытяигваем сообщение
	rc = ir9602_sbdrb(ir, user->accum, sizeof(user->accum));
	if (rc < 0)
	{
		global_stats.iridium_errors++;
		return rc;
	}


	// Ничего себе! оно вытянулось!
	for (int i = 0; i < rc; i++)
	{
		mavlink_status_t status;
		uint8_t parsed = mavlink_parse_char(MAVLINK_COMM_0, user->accum[i], &user->mavmsgbuf, &status);
		if (parsed)
		{
			// оно еще и распарсилось!
			global_stats.iridium_rx_mav++;
			router_route(&user->mavmsgbuf, ICU_IR_ROUTE_WAIT);
		}
	}
#endif //ICU_IR_PROCESS_UPLINK

	return 0;
}


void iridium_task(void *pvParameters)
{
	(void)pvParameters;
	ir9602_user_struct_t * const user = &_ir_user_struct;

	user->accum_carret = 0;
	user->rx_queue = xQueueCreateStatic(ICU_IR_UART_RX_BUFFER_SIZE, 1,
			user->rx_buffer, &user->rx_queue_object
	);

	ir9602_init(&_ir, user, _ir_uart_getch, _ir_uart_putch_t, _ir_event_hook);

	// Неможко не логично включать железо в последнюю очередь, но мы должны
	// быть готовы взаранее
	_hw_init();

	// запомним когда мы начали
	// portTickType timemark = xTaskGetTickCount();
	for(;;)
	{
		const BaseType_t status = xQueueReceive(iridium_queue_handle, &_ir_user_struct.mavmsgbuf, ICU_IR_TASK_PERIOD);
		if (pdTRUE != status)
		{
			// Мы таймаутнулись - нужно сливать буфер даже если он не полный
			_perform_sbd(&_ir, user->accum, user->accum_carret);
		}
		else
		{
			// оп, что-то пришло - пробуем сложить в буфер
			const uint8_t msglen = mavmsg_len(&user->mavmsgbuf);
			if (msglen > sizeof(user->accum) - user->accum_carret)
			{
				// Сообщение не влезает в буфер - сливаем его
				_perform_sbd(&_ir, user->accum, user->accum_carret);
			}

			// ну теперь то влезает? Всеравно проверим на всякий
			// если нет - ну нет
			if (msglen > sizeof(user->accum) - user->accum_carret)
				continue;

			// Влезает - пушим сообщение дальше
			mavlink_msg_to_send_buffer(user->accum, &user->mavmsgbuf);
		}
	}
}


void USART1_IRQHandler(void)
{
	ir9602_user_struct_t * const user_struct = (ir9602_user_struct_t *)_ir.user_arg;
	UART_HandleTypeDef * const huart = &user_struct->uart;

	uint32_t isrflags   = READ_REG(huart->Instance->SR);
	uint32_t cr1its     = READ_REG(huart->Instance->CR1);
	uint32_t cr3its     = READ_REG(huart->Instance->CR3);
	uint32_t errorflags = 0x00U;
	(void)cr1its;
	(void)cr3its;

	/* If no error occurs */
	errorflags = (isrflags & (uint32_t)(USART_SR_PE | USART_SR_FE | USART_SR_ORE | USART_SR_NE));
	/* UART in mode Receiver -------------------------------------------------*/
	if((isrflags & USART_SR_RXNE) != RESET)
	{
		const uint8_t rx_byte = (uint8_t)(huart->Instance->DR & (uint8_t)0x00FF);
		BaseType_t callcontextswitch = false;
		xQueueSendToBackFromISR(user_struct->rx_queue, &rx_byte, &callcontextswitch);
		portEND_SWITCHING_ISR(callcontextswitch);
		return;
	}

	if(errorflags != RESET)
	{
		// Если у нас случилась ошибка и зажегся какой-то бит ошибки
		// никто за нас его не снимет
		// Сдалем вид что не было никакой ошибки и продолжим работать
		// Ошибки пускай ловит драйвер выше. Тут слишком геморно передавать наверх что случилось

		// Сбрасываем все биты ошибок
		// Согласно даташиту такая последовательность должна помочь
		__disable_irq();
		READ_REG(huart->Instance->SR);
		READ_REG(huart->Instance->DR); // надеемся, что там ничего не повяилось с тех пор как мы проверяли последний раз
		__enable_irq();
	}
}


