/*
 * magnetometer.c
 *
 *  Created on: 2 нояб. 2017 г.
 *      Author: developer
 */
/*
 * magnetometer.c
 *
 *  Created on: 26 окт. 2017 г.
 *      Author: developer
 */
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_spi.h"
#include "magnetometer.h"

#include "diag/Trace.h"

#define BIT_READ 1
#define BIT_WRITE 0
#define MS_withInc 1
#define MS_withoutInc 0

#define SENS_MAG 1
#define SENS_ACC 0

#define MAG_REG_ADDR 0x28
#define TEMP_REG_ADDR 0x2E
#define ACC_REG_ADDR 0x28
#define MAG_CTRL1_ADDR 0x20
#define MAG_CTRL2_ADDR 0x21
#define MAG_CTRL3_ADDR 0x22
#define MAG_CTRL4_ADDR 0x23
#define MAG_CTRL5_ADDR 0x24

#define acc

#define RETURN_IF_ERROR(x) \
	error = x; \
	if (error != HAL_OK) {\
		trace_printf("eafowe\n"); \
		HAL_GPIO_WritePin(self->cs_port, cs_pin, GPIO_PIN_SET); \
		return error;\
	}

static inline void set_bit(uint8_t* reg, int pos, int bit) {
	if (bit)
		*reg |= (1 << pos);
	else
		*reg &= ~(1 << pos);
}

static HAL_StatusTypeDef _readmanyreg(LSM303C_t * self, uint8_t regaddr, void * data, uint8_t sens, uint8_t count) {
	HAL_StatusTypeDef error;
	uint16_t cs_pin;

	if (sens)
		cs_pin = self->mag_cs_pin;
	else
		cs_pin = self->acc_cs_pin;

	HAL_GPIO_WritePin(self->cs_port, cs_pin, GPIO_PIN_RESET);

	set_bit(&regaddr, 7, BIT_READ);
	set_bit(&regaddr, 6, MS_withInc);

	RETURN_IF_ERROR(HAL_SPI_Transmit(self->spi, &regaddr, 1, 1000))
	RETURN_IF_ERROR(HAL_SPI_Receive(self->spi, (uint8_t *)data, count, 1000))

	HAL_GPIO_WritePin(self->cs_port, cs_pin, GPIO_PIN_SET);
	return error;
}

static inline HAL_StatusTypeDef _readreg(LSM303C_t * self, uint8_t regaddr, void * data, uint8_t sens) {
	return _readmanyreg(self, regaddr, data, sens, 1);
}

static HAL_StatusTypeDef _writemanyreg(LSM303C_t * self, uint8_t regaddr, uint8_t * data, uint8_t sens, uint8_t count) {
	HAL_StatusTypeDef error;
	uint16_t cs_pin;

	if (sens == SENS_MAG)
		cs_pin = self->mag_cs_pin;
	else
		cs_pin = self->acc_cs_pin;

	HAL_GPIO_WritePin(self->cs_port, cs_pin, GPIO_PIN_RESET);

	set_bit(&regaddr, 7, BIT_WRITE);
	set_bit(&regaddr, 6, MS_withInc);

	RETURN_IF_ERROR(HAL_SPI_Transmit(self->spi, &regaddr, 1, 1000))
	RETURN_IF_ERROR(HAL_SPI_Transmit(self->spi, data, count, 1000))

	HAL_GPIO_WritePin(self->cs_port, cs_pin, GPIO_PIN_SET);

	return error;
}

static inline HAL_StatusTypeDef _writereg(LSM303C_t * self, uint8_t regaddr, uint8_t data, uint8_t sens) {
	return _writemanyreg(self, regaddr, &data, sens, 1);
}

HAL_StatusTypeDef LSM303C_mag_setup(LSM303C_t * self, LSM303C_config_t * config) {
	uint8_t transmit_byte[5] = {0};
	transmit_byte[0] = (config->temp_en << 7) | (config->power_mode << 5) | (config->data_rate << 2);
	transmit_byte[1] = (3 << 5); // 11 - включение разрешения в +-16 gauss
	transmit_byte[2] = (1 << 2) | (0 << 0); // включением чтение в SPI и периодические измерения
	transmit_byte[3] = (config->power_mode << 2);

	return _writemanyreg(self, MAG_CTRL1_ADDR, transmit_byte, SENS_MAG, 4);
}

HAL_StatusTypeDef LSM303C_mag_getData(int16_t* mag_data, LSM303C_t* self){
	return _readmanyreg(self, MAG_REG_ADDR, mag_data, SENS_MAG, 6);
}

HAL_StatusTypeDef LSM303C_acc_getData(uint16_t* acc_data, LSM303C_t* self){
	return _readmanyreg(self, ACC_REG_ADDR, acc_data, SENS_ACC, 6);
}

HAL_StatusTypeDef LSM303C_temp_getData(uint16_t* temp_data, LSM303C_t* self){
	return _readmanyreg(self, TEMP_REG_ADDR, temp_data, SENS_MAG, 2);
}




