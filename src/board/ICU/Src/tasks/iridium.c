#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <errno.h>

#include <main.h>

#include <ir9602.h>

static ir9602_t _ir;


typedef struct
{
	// Статусные поля таска
	uint8_t signal_power;

	UART_HandleTypeDef uart;

	mavlink_message_t mavmsgbuf;

	QueueHandle_t rx_queue;
	StaticQueue_t rx_queue_object;
	uint8_t rx_buffer[ICU_IR_UART_RX_BUFFER_SIZE];

	size_t tx_carret;
	uint8_t tx_accum[ICU_IR_TX_ACCUMULATOR_SIZE];
} ir9602_user_struct_t;

static ir9602_user_struct_t _ir_user_struct;


static int _ir_uart_getch(void * user_arg)
{
	ir9602_user_struct_t * const user_struct = (ir9602_user_struct_t *)user_arg;

	uint8_t byte;
	const BaseType_t status = xQueueReceive(user_struct->rx_queue, &byte, ICU_IR_UART_RX_QUEUE_WAIT);
	if (pdTRUE != status)
		return -ETIMEDOUT;

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
	ir9602_user_struct_t * const user_struct = (ir9602_user_struct_t *)user_arg;

	// Смотрим уровень сигнала и запоминаем
	if (IR9602_EVT_CIEV == event->code && IR9602_EVT_CIEV_KIND_SIGIND == event->arg.ciev.type)
		user_struct->signal_power = event->arg.ciev.value;
}


static void _hw_init(void)
{
	__HAL_RCC_USART1_CLK_ENABLE();

	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	__HAL_RCC_AFIO_CLK_ENABLE();
	__HAL_AFIO_REMAP_USART1_ENABLE();


	GPIO_InitTypeDef pinit;
	pinit.Mode = GPIO_MODE_AF_PP;
	pinit.Pin = GPIO_PIN_7; // PB7 - RX
	pinit.Pull = GPIO_NOPULL;
	pinit.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB, &pinit);

	pinit.Pin = GPIO_PIN_6; // PB6 - TX
	HAL_GPIO_Init(GPIOB, &pinit);

	pinit.Mode = GPIO_MODE_INPUT;
	pinit.Pin = GPIO_PIN_9; // PC7 - RING INDICATOR
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
}


void iridium_task(void *pvParameters)
{
	(void)pvParameters;

	_ir_user_struct.signal_power = 0;
	_ir_user_struct.tx_carret = 0;
	_ir_user_struct.rx_queue = xQueueCreateStatic(ICU_IR_UART_RX_BUFFER_SIZE, 1,
			_ir_user_struct.rx_buffer, &_ir_user_struct.rx_queue_object
	);

	ir9602_init(&_ir, &_ir_user_struct, _ir_uart_getch, _ir_uart_putch_t, _ir_event_hook);

	// Неможко не логично включать железо в последнюю очередь, но мы должны
	// быть готовы взаранее
	_hw_init();


	for(;;)
	{
		const BaseType_t status = xQueueReceive(iridium_queue_handle, &_ir_user_struct.mavmsgbuf, ICU_IR_TASK_PERIOD);
		if (pdTRUE == status)
		{
			// Если нам есть чего отправлять!
			// mavlink_expected_message_length(&struct.mavmsgbuf);
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

	/* If no error occurs */
	errorflags = (isrflags & (uint32_t)(USART_SR_PE | USART_SR_FE | USART_SR_ORE | USART_SR_NE));
	if(errorflags == RESET)
	{
		/* UART in mode Receiver -------------------------------------------------*/
		if(((isrflags & USART_SR_RXNE) != RESET) && ((cr1its & USART_CR1_RXNEIE) != RESET))
		{
			const uint8_t rx_byte = (uint8_t)(huart->Instance->DR & (uint8_t)0x00FF);
			BaseType_t callcontextswitch = false;
			xQueueSendToBackFromISR(user_struct->rx_queue, &rx_byte, &callcontextswitch);
			portEND_SWITCHING_ISR(callcontextswitch);
			return;
		}
	}

	/* If some errors occur */
	if((errorflags != RESET) && (((cr3its & USART_CR3_EIE) != RESET) || ((cr1its & (USART_CR1_RXNEIE | USART_CR1_PEIE)) != RESET)))
	{
		if(errorflags != HAL_UART_ERROR_NONE)
		{
			/* UART in mode Receiver -----------------------------------------------*/
			if(((isrflags & USART_SR_RXNE) != RESET) && ((cr1its & USART_CR1_RXNEIE) != RESET))
			{
				const uint8_t rx_byte = (uint8_t)(huart->Instance->DR & (uint8_t)0x00FF);
				BaseType_t callcontextswitch = false;
				xQueueSendToBackFromISR(user_struct->rx_queue, &rx_byte, &callcontextswitch);
				portEND_SWITCHING_ISR(callcontextswitch);
				return;
			}
		}

		if(errorflags != 0)
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
	} /* End if some error occurs */
}


