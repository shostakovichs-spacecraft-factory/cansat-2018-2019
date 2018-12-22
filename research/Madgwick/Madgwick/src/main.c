//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "diag/Trace.h"

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_i2c.h"
#include "stm32f4xx_hal_uart.h"
#include "stm32f4xx_hal_gpio.h"


#include "lsmd6s3/lsm6ds3.h"
#include "magnetometer.h"
#include "madgwick/MadgwickAHRS.h"

// ----------------------------------------------------------------------------
//
// Standalone STM32F4 empty sample (trace via DEBUG).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

I2C_HandleTypeDef i2c;
HAL_StatusTypeDef i2c_init_err;

lsm6ds3_t acc;
HAL_StatusTypeDef acc_init_err;

UART_HandleTypeDef uart;
HAL_StatusTypeDef uart_init_err;

SPI_HandleTypeDef spi;
HAL_StatusTypeDef spi_init_err;

LSM303C_t lsm;
HAL_StatusTypeDef mag_init_err;


TIM_HandleTypeDef tim;

int16_t data[6];

float accel_data[3];
float gyro_data[3];
float mag_data[3];

#define SAMPLE_FREQ_Hz 200

char string[100];
uint32_t endofcaltime;

inline void routine() {
	volatile HAL_StatusTypeDef lsm_read_err = lsm6ds3_acc_gyro_read_raw_all(&acc, data);

	lsm6ds3_acc_recalc(&acc, data + 3, accel_data);
	lsm6ds3_gyro_recalc(&acc, data, gyro_data);

	lsm6ds3_gyro_remove_static_error(&acc, gyro_data);

	volatile HAL_StatusTypeDef lsm_read_mag_err = LSM303C_mag_getData(data, &lsm);

	mag_data[0] = data[1] * -1.0 * 0.58 * 0.001;
	mag_data[1] = data[0] * -1.0 * 0.58 * 0.001;
	mag_data[2] = data[2] * 1.0 * 0.58 * 0.001;

	/*MadgwickAHRSupdateIMU(	gyro_data[0], gyro_data[1], gyro_data[2],
							accel_data[0], accel_data[1], accel_data[2]);*/
	MadgwickAHRSupdate(gyro_data[0], gyro_data[1], gyro_data[2],
			accel_data[0], accel_data[1], accel_data[2],
			mag_data[0], mag_data[1], mag_data[2]);


	//int length = sprintf(string, "%f %f %f %f\n", q0, q1, q2, q3);
	/*int length = sprintf(string, "%f %f %f %f %f %f\n",	accel_data[0], accel_data[1], accel_data[2],
														gyro_data[0], gyro_data[1], gyro_data[2]);*/

	if(HAL_GetTick() % 50 < 5) {
		//HAL_UART_Transmit(&uart, (uint8_t *)string, length + 1, 10);
		HAL_UART_Transmit(&uart, (uint8_t *) &q0, sizeof(float), 10);
		HAL_UART_Transmit(&uart, (uint8_t *) &q1, sizeof(float), 10);
		HAL_UART_Transmit(&uart, (uint8_t *) &q2, sizeof(float), 10);
		HAL_UART_Transmit(&uart, (uint8_t *) &q3, sizeof(float), 10);
		HAL_UART_Transmit(&uart, (uint8_t *) accel_data, sizeof(float), 10);
		HAL_UART_Transmit(&uart, (uint8_t *) (accel_data + 1), sizeof(float), 10);
		HAL_UART_Transmit(&uart, (uint8_t *) (accel_data + 2), sizeof(float), 10);
		HAL_UART_Transmit(&uart, (uint8_t *) mag_data, sizeof(float), 10);
		HAL_UART_Transmit(&uart, (uint8_t *) (mag_data + 1), sizeof(float), 10);
		HAL_UART_Transmit(&uart, (uint8_t *) (mag_data + 2), sizeof(float), 10);

		if(lsm_read_err != HAL_OK) 	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
		else 	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);

		if(lsm_read_mag_err != HAL_OK) 	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
		else 	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);

		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	}

	if(beta != 0.066 && HAL_GetTick() > endofcaltime) {
		beta = 0.066;
	}
}

void init_hardware(void);

int main(int argc, char* argv[])
{
	init_hardware();


	endofcaltime = HAL_GetTick() + 10000;

	while(1) {
		uint32_t loop_end_time = HAL_GetTick() + (int) 1000 / SAMPLE_FREQ_Hz ;

		routine();


		int32_t delta = loop_end_time - HAL_GetTick();

		if(delta > 0) {
			HAL_Delay(delta);
		}
		//trace_printf("%ld\n", HAL_GetTick());
	}
}

void init_hardware(void) {

	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitTypeDef gpio_init;
	gpio_init.Pin = GPIO_PIN_5 | GPIO_PIN_6;
	gpio_init.Pull = GPIO_NOPULL;
	gpio_init.Mode = GPIO_MODE_OUTPUT_OD;
	gpio_init.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOE, &gpio_init);

	gpio_init.Pin = GPIO_PIN_13;
	HAL_GPIO_Init(GPIOC, &gpio_init);

	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

	i2c.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	i2c.Init.ClockSpeed = 100000;
	i2c.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	i2c.Init.DutyCycle = I2C_DUTYCYCLE_2;
	i2c.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	i2c.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	i2c.Init.OwnAddress1 = 0xFF;
	i2c.Init.OwnAddress2 = 0xF8;

	i2c.Instance = I2C1;
	i2c.Mode = HAL_I2C_MODE_MASTER;

	i2c_init_err = HAL_I2C_Init(&i2c);


	acc.address = LSM6DS3_ADDRESS_HIGH;
	acc.bus = &i2c;

	lsm6ds3_settings_t lsm_settings;
	lsm_settings.accelEnabled = true;
	lsm_settings.accelFilterBandWidth = LSM6DS3_ACCEL_FILTER_BW_AUTO;
	lsm_settings.accelRange = LSM6DS3_ACCEL_RANGE_16;
	lsm_settings.accelSampleRate = LSM6DS3_ACCEL_SRATE_104;
	lsm_settings.commMode = 0;
	lsm_settings.gyroEnabled = true;
	lsm_settings.gyroRange = LSM6DS3_GYRO_RANGE_2000;
	lsm_settings.gyroSampleRate = LSM6DS3_GYRO_SRATE_104;
	lsm_settings.tempEnabled = true;

	acc_init_err = lsm6ds3_setup(&acc, &lsm_settings);
	acc.acc_k *= 0.001;
	acc.gyro_k *= 0.001 * M_PI / 180;


	uart.Init.BaudRate = 115200;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.Mode = UART_MODE_TX;
	uart.Init.OverSampling = UART_OVERSAMPLING_8;
	uart.Init.Parity = UART_PARITY_NONE;
	uart.Init.StopBits = UART_STOPBITS_1;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Instance = USART1;

	uart_init_err = HAL_UART_Init(&uart);


	LSM303C_config_t config;
	config.temp_en = true;
	config.data_rate = LSM303C_DATARATE_800Hz;
	config.power_mode = LSM303C_POWERMODE_MEDIUM;

	lsm.i2c = &i2c;

	mag_init_err = LSM303C_mag_setup(&lsm, &config);
}

void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c) {
	if(hi2c->Instance == I2C1) {
		__I2C1_CLK_ENABLE();
		__GPIOB_CLK_ENABLE();

		GPIO_InitTypeDef gpiob;
		gpiob.Alternate = GPIO_AF4_I2C1;
		gpiob.Mode = GPIO_MODE_AF_PP;
		gpiob.Pin = GPIO_PIN_6 | GPIO_PIN_7;
		gpiob.Pull = GPIO_NOPULL;
		gpiob.Speed = GPIO_SPEED_FREQ_HIGH;

		HAL_GPIO_Init(GPIOB, &gpiob);
	}
	else abort();
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart) {
	if(huart->Instance == USART1) {
		__USART1_CLK_ENABLE();
		__GPIOA_CLK_ENABLE();

		GPIO_InitTypeDef gpioa;
		gpioa.Alternate = GPIO_AF7_USART1;
		gpioa.Mode = GPIO_MODE_AF_OD;
		gpioa.Pin = GPIO_PIN_9;
		gpioa.Pull = GPIO_NOPULL;
		gpioa.Speed = GPIO_SPEED_FREQ_HIGH;

		HAL_GPIO_Init(GPIOA, &gpioa);
	}

	else abort();
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
