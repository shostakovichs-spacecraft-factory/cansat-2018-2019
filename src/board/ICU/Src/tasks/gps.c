/*
 * GPS task. Receives coordinates from GPS and outputs MAVLink packets
 */

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <main.h>

#include <stm32f1xx_hal_uart.h>
#include <stm32f1xx_hal_rcc.h>

#include <minmea.h>
#define NMEA_MAX_LENGTH	(MINMEA_MAX_LENGTH + 3)

static UART_HandleTypeDef huart3;


static void uart_init(void);

static char _rxbuff[NMEA_MAX_LENGTH];
static uint8_t _rxbuff_received = 0;

static char _processingbuff[NMEA_MAX_LENGTH];

void gps_task (void *pvParameters)
{
	volatile int good = 0;
	uint8_t dummy;
	struct minmea_sentence_gga frame;
	mavlink_hil_gps_t hil_gps;
	mavlink_message_t msg;

	uart_init();

	while(1)
	{
		xTaskNotifyWait(0, 0xFFFFFFFF, NULL, 0xFFFFFFFF);

		memcpy(_processingbuff, _rxbuff, _rxbuff_received);
		_rxbuff_received = 0;
		HAL_UART_Init(&huart3); //maybe not the best way, TODO make it simpler

		switch( minmea_sentence_id(_processingbuff, ICU_GPS_FORCECHECKSUMM) )
		{
		case MINMEA_SENTENCE_GGA:
			if( !minmea_parse_gga(&frame, _processingbuff) )
				continue;

			hil_gps.time_usec = HAL_GetTick() * 1000;
			hil_gps.lat = minmea_tocoord(&frame.latitude) * 10000000;
			hil_gps.lon = minmea_tocoord(&frame.longitude) * 10000000;
			hil_gps.alt = minmea_tofloat(&frame.altitude) * 1000;
			hil_gps.fix_type = frame.fix_quality;
			hil_gps.satellites_visible = frame.satellites_tracked;
			hil_gps.eph =(uint16_t)minmea_tofloat(&frame.hdop) * 100;

			mavlink_msg_hil_gps_encode(0, ZIKUSH_ICU, &msg, &hil_gps);
			router_route(&msg, 200);

			break;

		case MINMEA_INVALID:
			break;

		default:
			good++;
			continue;
		}
	}

	vTaskDelete(NULL);
}

/**
  * @brief This function handles USB low priority or CAN RX0 interrupts.
  */
void USART3_IRQHandler(void)
{
	UART_HandleTypeDef * const huart = &huart3;

	uint32_t isrflags   = READ_REG(huart->Instance->SR);
	uint32_t errorflags = 0x00U;

	/* If no error occurs */
	errorflags = (isrflags & (uint32_t)(USART_SR_PE | USART_SR_FE | USART_SR_ORE | USART_SR_NE));
	/* UART in mode Receiver -------------------------------------------------*/
	if((isrflags & USART_SR_RXNE) != RESET)
	{
		_rxbuff[_rxbuff_received++] = (uint8_t)(huart->Instance->DR & 0xFF);

		if(_rxbuff[0] != '$')
		{
			_rxbuff_received = 0;
			return;
		}

		if(_rxbuff[_rxbuff_received - 1] == '\n' || _rxbuff_received == NMEA_MAX_LENGTH) //If we've finished sentence receiveing or the buffer overflow occured
		{
			xTaskNotifyGive(gps_task_handle);
			HAL_UART_DeInit(huart);
		}


		return;
	}

	/* If some errors occur */
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
	} /* End if some error occurs */
}

//Those functions has been fetched from CubeMX generated code
/**
  * @brief CAN Initialization Function
  * @param None
  * @retval None
  */
static void uart_init(void)
{
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_USART3_CLK_ENABLE();

	GPIO_InitTypeDef gpio_init =
	{
		.Mode = GPIO_MODE_AF_INPUT,
		.Speed = GPIO_SPEED_FREQ_MEDIUM,
		.Pull = GPIO_NOPULL,
		.Pin = GPIO_PIN_9,
	};
	HAL_GPIO_Init(GPIOD, &gpio_init);

	__HAL_AFIO_REMAP_USART3_ENABLE();

	huart3.Instance = USART3;
	huart3.Init.Mode = UART_MODE_RX;
	huart3.Init.BaudRate = 9600;
	huart3.Init.WordLength = UART_WORDLENGTH_8B;
	huart3.Init.StopBits = UART_STOPBITS_1;
	huart3.Init.Parity = UART_PARITY_NONE;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	HAL_UART_Init(&huart3);

	__HAL_UART_ENABLE_IT(&huart3, UART_IT_RXNE);
	__HAL_UART_ENABLE_IT(&huart3, UART_IT_ERR);

	HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART3_IRQn);
}
