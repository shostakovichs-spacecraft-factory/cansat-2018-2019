/*
 * spi.c
 *
 *  Created on: 1 июн. 2019 г.
 *      Author: sereshotes
 */

#include <diag/Trace.h>
#include <stm32f4xx_hal.h>

#define TO_U32(a) *(uint32_t*)(&a)

int spi_init(SPI_HandleTypeDef * hspi)
{
	__SPI1_CLK_ENABLE();
	int rc = HAL_SPI_Init(hspi);
	if(rc)
		trace_printf("ERROR: Can't init SPI: %d\n", rc);
	return rc;
}
int spi_deinit(SPI_HandleTypeDef * hspi)
{
	int rc = HAL_SPI_DeInit(hspi);
	__SPI1_CLK_DISABLE();
	if(rc)
		trace_printf("ERROR: Can't init SPI: %d\n", rc);
	return rc;
}

int spi_config_default(SPI_HandleTypeDef * hspi)
{
	hspi->Instance = SPI1;

	hspi->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
	hspi->Init.Direction         = SPI_DIRECTION_2LINES;
	hspi->Init.CLKPhase          = SPI_PHASE_1EDGE;
	hspi->Init.CLKPolarity       = SPI_POLARITY_LOW;
	hspi->Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
	hspi->Init.CRCPolynomial     = 7;
	hspi->Init.DataSize          = SPI_DATASIZE_8BIT;
	hspi->Init.FirstBit          = SPI_FIRSTBIT_MSB;
	hspi->Init.NSS               = SPI_NSS_SOFT;
	hspi->Init.TIMode            = SPI_TIMODE_DISABLE;
	hspi->Init.Mode 			 = SPI_MODE_MASTER;

	return 0;
}
int spi_pin_sck_init(SPI_HandleTypeDef *hspi, GPIO_TypeDef* GPIOX, uint32_t pin)
{
	GPIO_InitTypeDef gp = {
		.Pin = pin,
		.Mode = GPIO_MODE_AF_PP,
		.Pull = GPIO_PULLUP,
		.Speed = GPIO_SPEED_FAST
	};
	if(hspi->Instance == SPI1)
		gp.Alternate = GPIO_AF5_SPI1;
	else if(hspi->Instance == SPI2)
		gp.Alternate = GPIO_AF5_SPI2;
	else if(hspi->Instance == SPI2)
		gp.Alternate = GPIO_AF6_SPI3;

	HAL_GPIO_Init(GPIOX, &gp);
	return 0;
}
int spi_pin_miso_init(SPI_HandleTypeDef *hspi, GPIO_TypeDef* GPIOX, uint32_t pin)
{
	GPIO_InitTypeDef gp = {
		.Pin = pin,
		.Mode = GPIO_MODE_AF_PP,
		.Pull = GPIO_PULLUP,
		.Speed = GPIO_SPEED_FAST
	};
	if(hspi->Instance == SPI1)
		gp.Alternate = GPIO_AF5_SPI1;
	else if(hspi->Instance == SPI2)
		gp.Alternate = GPIO_AF5_SPI2;
	else if(hspi->Instance == SPI2)
		gp.Alternate = GPIO_AF6_SPI3;


	HAL_GPIO_Init(GPIOX, &gp);
	return 0;
}
int spi_pin_mosi_init(SPI_HandleTypeDef *hspi, GPIO_TypeDef* GPIOX, uint32_t pin)
{
	GPIO_InitTypeDef gp = {
		.Pin = pin,
		.Mode = GPIO_MODE_AF_PP,
		.Pull = GPIO_PULLUP,
		.Speed = GPIO_SPEED_FAST
	};
	if(hspi->Instance == SPI1)
		gp.Alternate = GPIO_AF5_SPI1;
	else if(hspi->Instance == SPI2)
		gp.Alternate = GPIO_AF5_SPI2;
	else if(hspi->Instance == SPI2)
		gp.Alternate = GPIO_AF6_SPI3;


	HAL_GPIO_Init(GPIOX, &gp);
	return 0;
}

int spi_pin_nss_init(SPI_HandleTypeDef *hspi, GPIO_TypeDef* GPIOX, uint32_t pin)
{
	GPIO_InitTypeDef gp = {
		.Pin = pin,
		.Mode = GPIO_MODE_OUTPUT_PP,
		.Pull = GPIO_PULLUP,
		.Speed = GPIO_SPEED_FAST
	};


	HAL_GPIO_Init(GPIOX, &gp);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	return 0;
}



