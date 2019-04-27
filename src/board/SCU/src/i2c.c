/*
 * i2c.c
 *
 *  Created on: 20 апр. 2019 г.
 *      Author: sereshotes
 */
#include "i2c.h"
#include <stm32f4xx_hal.h>
#include <diag/Trace.h>
#include <assert.h>


I2C_HandleTypeDef I2C_init_for_bme280(int i2c_number)
{
	int rc;
	I2C_HandleTypeDef i2c_handler;

	switch(i2c_number)
	{
	case 1:
		i2c_handler.Instance = I2C1;
		break;
	case 2:
		i2c_handler.Instance = I2C2;
		break;
	case 3:
		i2c_handler.Instance = I2C3;
		break;
	default:
		assert("We haven't this i2c");
	}
	i2c_handler.Instance = I2C1;
	i2c_handler.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	i2c_handler.Init.ClockSpeed = CLOCK_SPEED;
	i2c_handler.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	i2c_handler.Init.DutyCycle = I2C_DUTYCYCLE_16_9;
	i2c_handler.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	i2c_handler.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	i2c_handler.Init.OwnAddress1 = 0;
	i2c_handler.Init.OwnAddress2 = 0;

	rc = HAL_I2C_Init(&i2c_handler);
	if(rc)
		trace_printf("ERROR: Can't init I2C: %d\n", rc);
	return i2c_handler;
}
void I2C_deinit(I2C_HandleTypeDef *i2c_handler)
{
	HAL_I2C_DeInit(i2c_handler);
}
