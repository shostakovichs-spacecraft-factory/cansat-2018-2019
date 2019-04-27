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
#define CLOCK_SPEED 100000U //hz

I2C_HandleTypeDef I2C_init_for_bme280(int i2c_number);

void I2C_deinit(I2C_HandleTypeDef *i2c_handler);



#endif /* I2C_H_ */
