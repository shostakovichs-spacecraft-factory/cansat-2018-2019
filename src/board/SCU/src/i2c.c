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
	I2C_HandleTypeDef hi2c;

	switch(i2c_number)
	{
	case 1:
		hi2c.Instance = I2C1;
		break;
	case 2:
		hi2c.Instance = I2C2;
		break;
	case 3:
		hi2c.Instance = I2C3;
		break;
	default:
		assert("We haven't this i2c");
	}
	hi2c.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c.Init.ClockSpeed = CLOCK_SPEED;
	hi2c.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c.Init.DutyCycle = I2C_DUTYCYCLE_16_9;
	hi2c.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	hi2c.Init.OwnAddress1 = 0;
	hi2c.Init.OwnAddress2 = 0;

	rc = HAL_I2C_Init(&hi2c);
	if(rc)
		trace_printf("ERROR: Can't init I2C: %d\n", rc);
	return hi2c;
}
int i2c_init(I2C_HandleTypeDef * hi2c)
{
	int rc = HAL_I2C_Init(hi2c);;
	if(rc)
		trace_printf("ERROR: Can't init I2C: %d\n", rc);
	return rc;
}

int i2c_config_default(I2C_HandleTypeDef * hi2c)
{
	hi2c->Instance = I2C1;
	hi2c->Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c->Init.ClockSpeed = CLOCK_SPEED;
	hi2c->Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c->Init.DutyCycle = I2C_DUTYCYCLE_16_9;
	hi2c->Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c->Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	hi2c->Init.OwnAddress1 = 0;
	hi2c->Init.OwnAddress2 = 0;

	return 0;

}
int i2c_deinit(I2C_HandleTypeDef *hi2c)
{
	int rc = HAL_I2C_DeInit(hi2c);
	if(rc)
		trace_printf("ERROR: Can't deinit I2C: %d\n", rc);
	return rc;
}

int i2c_pin_scl_init(GPIO_TypeDef* GPIOX, uint32_t pin)
{
	GPIO_InitTypeDef pa_init;
	pa_init.Alternate = GPIO_AF4_I2C1;
	pa_init.Mode = GPIO_MODE_AF_OD;
	pa_init.Pin = pin;
	pa_init.Pull = GPIO_PULLUP;
	pa_init.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOX, &pa_init);

	return 0;
}
int i2c_pin_sda_init(GPIO_TypeDef* GPIOX, uint32_t pin)
{
	GPIO_InitTypeDef pa_init;
	pa_init.Alternate = GPIO_AF4_I2C1;
	pa_init.Mode = GPIO_MODE_AF_OD;
	pa_init.Pin = pin;
	pa_init.Pull = GPIO_PULLUP;
	pa_init.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOX, &pa_init);

	return 0;
}
