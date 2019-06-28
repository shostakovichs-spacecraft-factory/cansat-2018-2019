/*
 * Radio task. Handles transmitting telemetry over sx1268 radio
 * */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <main.h>

#include <sx1268.h>


static SPI_HandleTypeDef hspi2;


static sx1268_t radio;
static sx1268_stm32_t radio_specific;
static uint8_t radio_rxbuf[ICU_RADIO_RXBUFFLEN], radio_txbuf[ICU_RADIO_TXBUFFLEN];


static void MX_SPI2_Init(void);
static void MX_GPIO_Init(void);
static void radio_init(void);


void radio_task (void *pvParameters)
{
	static uint8_t framebuff[MAVLINK_MAX_PACKET_LEN];
	static mavlink_message_t msg;
	static uint32_t notifications = 0;

	MX_SPI2_Init();
	MX_GPIO_Init();

	radio_init();

	while(1)
	{
		xTaskNotifyWait(0, RADIO_NOTIFICATION_SEND|RADIO_NOTIFICATION_EVT, &notifications, 0xFFFFFFFF);

		if(notifications & RADIO_NOTIFICATION_EVT)
			sx1268_event(&radio);

		if(notifications & RADIO_NOTIFICATION_SEND)
		{
			while( xQueueReceive(radio_queue_handle, &msg, 0) != errQUEUE_EMPTY )
			{
				uint16_t len = mavlink_msg_to_send_buffer(framebuff, &msg);
				sx1268_send(&radio, framebuff, len);

				sx1268_event(&radio);
			}
		}
	}

	vTaskDelete(NULL);
}

static void radio_init(void)
{
	sx1268_struct_init(&radio, &radio_specific, radio_rxbuf, ICU_RADIO_RXBUFFLEN, radio_txbuf, ICU_RADIO_TXBUFFLEN);
	radio_specific.bus = &hspi2;
	radio_specific.busy_port = RADIO_BUSY_GPIO_Port;
	radio_specific.busy_pin = RADIO_BUSY_Pin;
	radio_specific.dio2_port = RADIO_DIO2_GPIO_Port;
	radio_specific.dio2_pin = RADIO_DIO2_Pin;
	radio_specific.cs_port = RADIO_NSS_GPIO_Port;
	radio_specific.cs_pin = RADIO_NSS_Pin;
	radio_specific.nrst_port = RADIO_NRST_GPIO_Port;
	radio_specific.nrst_pin = RADIO_NRST_Pin;
	radio_specific.rxen_port = RADIO_RXEN_GPIO_Port;
	radio_specific.rxen_pin = RADIO_RXEN_Pin;
	radio_specific.txen_port = RADIO_TXEN_GPIO_Port;
	radio_specific.txen_pin = RADIO_TXEN_Pin;

	sx1268_init(&radio);
}

/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler(void)
{
	if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_15) != RESET)
	{
		__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_15);
		xTaskNotify(radio_task_handle, RADIO_NOTIFICATION_EVT, eSetBits);
	}

	return;
}

//Those functions has been fetched from CubeMX generated code
/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{
	hspi2.Instance = SPI2;
	hspi2.Init.Mode = SPI_MODE_MASTER;
	hspi2.Init.Direction = SPI_DIRECTION_2LINES;
	hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi2.Init.NSS = SPI_NSS_SOFT;
	hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
	hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi2.Init.CRCPolynomial = 10;
	if (HAL_SPI_Init(&hspi2) != HAL_OK)
	{
		Error_Handler();
	}
}


/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOE, RADIO_TXEN_Pin|RADIO_RXEN_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(RADIO_NRST_GPIO_Port, RADIO_NRST_Pin, GPIO_PIN_SET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(RADIO_NSS_GPIO_Port, RADIO_NSS_Pin, GPIO_PIN_SET);

	/*Configure GPIO pin : RADIO_BUSY_Pin */
	GPIO_InitStruct.Pin = RADIO_BUSY_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(RADIO_BUSY_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : RADIO_DIO2_Pin */
	GPIO_InitStruct.Pin = RADIO_DIO2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(RADIO_DIO2_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : RADIO_TXEN_Pin RADIO_RXEN_Pin */
	GPIO_InitStruct.Pin = RADIO_TXEN_Pin|RADIO_RXEN_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	/*Configure GPIO pin : RADIO_NRST_Pin */
	GPIO_InitStruct.Pin = RADIO_NRST_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(RADIO_NRST_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : RADIO_NSS_Pin LEDPIN_Pin */
	GPIO_InitStruct.Pin = RADIO_NSS_Pin|LEDPIN_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pin : RADIO_IRQ_Pin */
	GPIO_InitStruct.Pin = RADIO_IRQ_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(RADIO_IRQ_GPIO_Port, &GPIO_InitStruct);

	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, configMAX_SYSCALL_INTERRUPT_PRIORITY + 1, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}
