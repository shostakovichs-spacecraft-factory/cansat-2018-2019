/*
 * i2c.h
 *
 *  Created on: 20 апр. 2019 г.
 *      Author: snork
 */

#ifndef I2C_H_
#define I2C_H_

#include <stddef.h>
#include <stdint.h>

#include <stm32f10x.h>

void i2c_init_bus1(void);

void i2c_init_bus2(void);

//! Передача данных ведомому. Адрес ведомого выровнен "направо". Старший бит всегда 0
int i2c_write(I2C_TypeDef * bus, uint8_t slave, void * buffer, size_t buffer_size);

//! Получение данных от ведомого. Адрес ведомого выровнен "направо". Старший бит всегда 0
int i2c_read(I2C_TypeDef * bus, uint8_t slave, void * buffer, size_t buffer_size);


#endif /* I2C_H_ */
