#include "main.h"

/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
	__HAL_RCC_AFIO_CLK_ENABLE();
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_AFIO_REMAP_SWJ_NOJTAG();
}

/**
* @brief CAN MSP Initialization
* This function configures the hardware resources used in this example
* @param hcan: CAN handle pointer
* @retval None
*/
void HAL_CAN_MspInit(CAN_HandleTypeDef* hcan)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if(hcan->Instance==CAN1)
	{
		__HAL_RCC_CAN1_CLK_ENABLE();
		__HAL_RCC_GPIOD_CLK_ENABLE();

		/**CAN GPIO Configuration
		PD0     ------> CAN_RX
		PD1     ------> CAN_TX
		*/
		GPIO_InitStruct.Pin = GPIO_PIN_0;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_1;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

		__HAL_AFIO_REMAP_CAN1_3();

		/* CAN1 interrupt Init */
		HAL_NVIC_SetPriority(USB_LP_CAN1_RX0_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn);
	}
}

/**
* @brief CAN MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hcan: CAN handle pointer
* @retval None
*/
void HAL_CAN_MspDeInit(CAN_HandleTypeDef* hcan)
{
	if(hcan->Instance==CAN1)
	{
		/* Peripheral clock disable */
		__HAL_RCC_CAN1_CLK_DISABLE();
  
		/**CAN GPIO Configuration
		PD0     ------> CAN_RX
		PD1     ------> CAN_TX
		*/
		HAL_GPIO_DeInit(GPIOD, GPIO_PIN_0|GPIO_PIN_1);

		/* CAN1 interrupt DeInit */
		HAL_NVIC_DisableIRQ(USB_LP_CAN1_RX0_IRQn);
	}
}

/**
* @brief SD MSP Initialization
* This function configures the hardware resources used in this example
* @param hsd: SD handle pointer
* @retval None
*/
void HAL_SD_MspInit(SD_HandleTypeDef* hsd)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if(hsd->Instance==SDIO)
	{
		/* Peripheral clock enable */
		__HAL_RCC_SDIO_CLK_ENABLE();

		__HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_GPIOD_CLK_ENABLE();
		/**SDIO GPIO Configuration
		PC8     ------> SDIO_D0
		PC9     ------> SDIO_D1
		PC10     ------> SDIO_D2
		PC11     ------> SDIO_D3
		PC12     ------> SDIO_CK
		PD2     ------> SDIO_CMD
		*/
		GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
							  |GPIO_PIN_12;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_2;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	}
}

/**
* @brief SD MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hsd: SD handle pointer
* @retval None
*/
void HAL_SD_MspDeInit(SD_HandleTypeDef* hsd)
{
	if(hsd->Instance==SDIO)
	{
		/* Peripheral clock disable */
		__HAL_RCC_SDIO_CLK_DISABLE();

		/**SDIO GPIO Configuration
		PC8     ------> SDIO_D0
		PC9     ------> SDIO_D1
		PC10     ------> SDIO_D2
		PC11     ------> SDIO_D3
		PC12     ------> SDIO_CK
		PD2     ------> SDIO_CMD
		*/
		HAL_GPIO_DeInit(GPIOC, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
							  |GPIO_PIN_12);

		HAL_GPIO_DeInit(GPIOD, GPIO_PIN_2);
	}
}

/**
* @brief SPI MSP Initialization
* This function configures the hardware resources used in this example
* @param hspi: SPI handle pointer
* @retval None
*/
void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if(hspi->Instance==SPI2)
	{
		/* Peripheral clock enable */
		__HAL_RCC_SPI2_CLK_ENABLE();

		__HAL_RCC_GPIOB_CLK_ENABLE();
		/**SPI2 GPIO Configuration
		PB13     ------> SPI2_SCK
		PB14     ------> SPI2_MISO
		PB15     ------> SPI2_MOSI
		*/
		GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_15;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_14;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	}
}

/**
* @brief SPI MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hspi: SPI handle pointer
* @retval None
*/
void HAL_SPI_MspDeInit(SPI_HandleTypeDef* hspi)
{
	if(hspi->Instance==SPI2)
	{
		__HAL_RCC_SPI2_CLK_DISABLE();

		/**SPI2 GPIO Configuration
		PB13     ------> SPI2_SCK
		PB14     ------> SPI2_MISO
		PB15     ------> SPI2_MOSI
		*/
		HAL_GPIO_DeInit(GPIOB, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15);
	}
}
