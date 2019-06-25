/**
  Main for ICU
  */

#include "main.h"
#include "fatfs.h"

#include <string.h>

#include <sx1268.h>

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>

#include <zikush_config.h>

CAN_HandleTypeDef hcan;
SD_HandleTypeDef hsd;
SPI_HandleTypeDef hspi2;

sx1268_t radio;
sx1268_stm32_t radio_specific;
uint8_t radio_rxbuf[ICU_RADIO_RXBUFFLEN], radio_txbuf[ICU_RADIO_TXBUFFLEN];
uint8_t can_rxbuf[ICU_CAN_RXBUFFLEN];
sx1268_fifo_t can_rxfifo = {.empty = true, .head = 0, .tail = 0, .length = ICU_CAN_RXBUFFLEN, .mem = can_rxbuf, .locked = false}; //грустно но вкусно

int16_t zikush_runsessnum = -1;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI2_Init(void);
static void MX_CAN_Init(void);
static void MX_SDIO_SD_Init(void);


void radio_init()
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


void sd_init()
{
	FRESULT fileworkresult;
	char filename[ICU_SD_MAXFILENAMELEN];

	fileworkresult = f_mkdir("0:/zikush");
	if( !( fileworkresult == FR_OK || fileworkresult == FR_EXIST ) )
		printf("Problem %d with zikush folder creation\n", fileworkresult); //FIXME error handlers

	for(zikush_runsessnum = 0; zikush_runsessnum < ICU_SD_SESSNUMBOUNDARY; zikush_runsessnum++)
	{
		sprintf(filename, ICU_SD_SESSFOLDERNAMEFMT, zikush_runsessnum);
		fileworkresult = f_stat(filename, NULL);

		if(fileworkresult != FR_OK)
			break;

		if(zikush_runsessnum == ICU_SD_SESSNUMBOUNDARY)
			zikush_runsessnum = -2; //FIXME proper error handling
	}

	f_mkdir(filename);
}


void can_init()
{
	HAL_CAN_Start(&hcan);

	CAN_FilterTypeDef filter = {
		.FilterMaskIdHigh = 0,
		.FilterMaskIdLow = 0,
		.FilterMode = CAN_FILTERMODE_IDMASK,
		.FilterActivation = CAN_FILTER_ENABLE,
		.FilterFIFOAssignment = CAN_FILTER_FIFO0,
		.FilterScale = CAN_FILTERSCALE_16BIT,
		.FilterBank = 0,
		.SlaveStartFilterBank = 14,
	};

	HAL_CAN_ConfigFilter(&hcan, &filter);

	hcan.Instance->IER |= CAN_IER_FMPIE0;


}


int main(void)
{
	HAL_Init();
	SystemClock_Config();

	MX_GPIO_Init();
	MX_SPI2_Init();
	MX_CAN_Init();
	MX_SDIO_SD_Init();
	MX_FATFS_Init();

	radio_init();
	sd_init();
	can_init();

	while(1)
	{
	mavlink_message_t msg;
	mavlink_heartbeat_t heartbeat =
	{
		.type = MAV_TYPE_FREE_BALLOON,
		.autopilot = MAV_AUTOPILOT_INVALID,
		.base_mode = MAV_MODE_FLAG_TEST_ENABLED,
		.system_status = MAV_STATE_ACTIVE
	};
	mavlink_msg_heartbeat_encode(0, ZIKUSH_ICU, &msg, &heartbeat);

	//router_route(&msg);

	HAL_Delay(80);

	mavlink_scaled_pressure_t pressure =
	{
		.press_abs = 100.0f,
		.press_diff = 0,
		.temperature = 2213,
		.time_boot_ms = HAL_GetTick(),
	};
	mavlink_msg_scaled_pressure_encode(0, ZIKUSH_ICU, &msg, &pressure);

	//router_route(&msg);

	HAL_Delay(1000);
	}
}

/**
  * @brief System Clock Configuration
  */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Initializes the CPU, AHB and APB busses clocks
	*/
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB busses clocks
	*/
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
							  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
  * @brief CAN Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN_Init(void)
{
	hcan.Instance = CAN1;
	hcan.Init.Prescaler = 100;
	hcan.Init.Mode = CAN_MODE_NORMAL;
	hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
	hcan.Init.TimeSeg1 = CAN_BS1_5TQ;
	hcan.Init.TimeSeg2 = CAN_BS2_2TQ;
	hcan.Init.TimeTriggeredMode = DISABLE;
	hcan.Init.AutoBusOff = DISABLE;
	hcan.Init.AutoWakeUp = DISABLE;
	hcan.Init.AutoRetransmission = DISABLE;
	hcan.Init.ReceiveFifoLocked = DISABLE;
	hcan.Init.TransmitFifoPriority = DISABLE;
	if (HAL_CAN_Init(&hcan) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
  * @brief SDIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_SDIO_SD_Init(void)
{
	hsd.Instance = SDIO;
	hsd.Init.ClockEdge = SDIO_CLOCK_EDGE_RISING;
	hsd.Init.ClockBypass = SDIO_CLOCK_BYPASS_DISABLE;
	hsd.Init.ClockPowerSave = SDIO_CLOCK_POWER_SAVE_DISABLE;
	hsd.Init.BusWide = SDIO_BUS_WIDE_1B;
	hsd.Init.HardwareFlowControl = SDIO_HARDWARE_FLOW_CONTROL_DISABLE;
	hsd.Init.ClockDiv = 100;
}

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

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(LEDPIN_GPIO_Port, LEDPIN_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin : RADIO_BUSY_Pin */
	GPIO_InitStruct.Pin = RADIO_BUSY_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(RADIO_BUSY_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : RADIO_DIO2_Pin */ //FIXME redefine with STM32Cube, or throw him away
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
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{}
