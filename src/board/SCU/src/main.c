#include <stm32f4xx_hal.h>

#include "lsm6ds3.h"
#include "i2c.h"
#include "bme280.h"
#include <stdio.h>
#include <diag/Trace.h>

void SysTick_Handler(void)
{
    HAL_IncTick();
    //HAL_SYSTICK_IRQHandler();
}

int main()
{
	HAL_Init();

	//SystemClock_Config();
	SystemClock_Config();
	SysTick_Handler();
/*
	UART_HandleTypeDef uartHandler;
	uartHandler.Instance = USART1;
	uartHandler.Init.BaudRate = 115200;
	uartHandler.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uartHandler.Init.Mode = UART_MODE_TX_RX;
	uartHandler.Init.OverSampling = UART_OVERSAMPLING_16;
	uartHandler.Init.Parity = UART_PARITY_NONE;
	uartHandler.Init.StopBits = UART_STOPBITS_1;
	uartHandler.Init.WordLength = UART_WORDLENGTH_8B;


	HAL_UART_Init(&uartHandler);
	UART_InitTypeDef uartIniter;

	SPI_HandleTypeDef spiHandler;
	spiHandler.Instance = SPI1;

	spiHandler.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
	spiHandler.Init.Direction = SPI_DIRECTION_2LINES;
	spiHandler.Init.CLKPhase = SPI_PHASE_2EDGE;
	spiHandler.Init.CLKPolarity = SPI_POLARITY_HIGH;
	spiHandler.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;
	spiHandler.Init.DataSize = SPI_DATASIZE_8BIT;
	spiHandler.Init.FirstBit = SPI_FIRSTBIT_LSB;
	spiHandler.Init.NSS = SPI_NSS_SOFT;
	spiHandler.Init.TIMode = SPI_TIMODE_DISABLED;
	spiHandler.Init.Mode = SPI_MODE_MASTER;

	HAL_SPI_Init(&spiHandler);


	const char data[] = "hello world\n";
	while(1)
	{
		HAL_UART_Transmit(&uartHandler, data, sizeof(data)-1, HAL_MAX_DELAY);
	}*/

	struct bme280_dev_s descr_bme280;

	I2C_HandleTypeDef i2c_handler = I2C_init_for_bme280(1);
	bme280_register_i2c(&descr_bme280, &i2c_handler, BME280_I2C_ADDR_SDO_LOW);
	bme280_init(&descr_bme280);

	struct bme280_float_data_s data;
	while(1)
	{
		bme280_read(&descr_bme280, (char*)&data, sizeof(data));
		trace_printf("%9f %9f %9f \n", data.pressure, data.temperature, data.humidity);
	}

	bme280_deinit(&descr_bme280);
	I2C_deinit(&i2c_handler);

	return 0;
}

