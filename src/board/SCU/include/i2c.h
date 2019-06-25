/*
 * i2c.h
 *
 *  Created on: 20 апр. 2019 г.
 *      Author: sereshotes
 */

#ifndef I2C_H_
#define I2C_H_

#include <stm32f4xx_hal.h>
#define I2C_BME280_ADDRESS 0b1110110 << 1;
#define CLOCK_SPEED 50000 //hz

I2C_HandleTypeDef I2C_init_for_bme280(int i2c_number);

int i2c_init(I2C_HandleTypeDef * hi2c);

int i2c_config_default(I2C_HandleTypeDef * hi2c);
int i2c_deinit(I2C_HandleTypeDef *hi2c);

int i2c_pin_scl_init(GPIO_TypeDef* GPIOX, uint32_t pin);
int i2c_pin_sda_init(GPIO_TypeDef* GPIOX, uint32_t pin);

#endif /* I2C_H_ */
