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

#define MAG_ADDR 0x3C
#define ACC_ADDR 0x3A

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
		trace_printf("Error in lsm303c driver!\n"); \
		return error;\
	}

static inline void set_bit(uint8_t* reg, int pos, int bit) {
	if (bit)
		*reg |= (1 << pos);
	else
		*reg &= ~(1 << pos);
}

static inline HAL_StatusTypeDef _readmanyreg(LSM303C_t * self, uint8_t regaddr, void * data, uint16_t sensor_addr, uint8_t count) {
	return HAL_I2C_Mem_Read(self->i2c, sensor_addr, regaddr, I2C_MEMADD_SIZE_8BIT, data, count, 10000);
}

static inline HAL_StatusTypeDef _readreg(LSM303C_t * self, uint8_t regaddr, void * data, uint16_t sensor_addr) {
	return _readmanyreg(self, regaddr, data, sensor_addr, 1);
}

static inline HAL_StatusTypeDef _writemanyreg(LSM303C_t * self, uint8_t regaddr, uint8_t * data, uint16_t sensor_addr, uint8_t count) {
	return HAL_I2C_Mem_Write(self->i2c, sensor_addr, regaddr, I2C_MEMADD_SIZE_8BIT, data, count, 10000);
}

static inline HAL_StatusTypeDef _writereg(LSM303C_t * self, uint8_t regaddr, uint8_t data, uint8_t sens) {
	return _writemanyreg(self, regaddr, &data, sens, 1);
}

HAL_StatusTypeDef LSM303C_mag_setup(LSM303C_t * self, LSM303C_config_t * config) {
	uint8_t transmit_byte[5] = {0};
	transmit_byte[0] = (config->temp_en << 7) | (config->power_mode << 5) | (config->data_rate << 2);
	transmit_byte[1] = (3 << 5); // 11 - включение разрешения в +-16 gauss
	transmit_byte[2] = (0 << 0) | (0 << 0); // включением периодические измерения
	transmit_byte[3] = (config->power_mode << 2);

	return _writemanyreg(self, MAG_CTRL1_ADDR, transmit_byte, MAG_ADDR, 4);
}

HAL_StatusTypeDef LSM303C_mag_getData(int16_t* mag_data, LSM303C_t* self){
	return _readmanyreg(self, MAG_REG_ADDR, mag_data, MAG_ADDR, 6);
}

HAL_StatusTypeDef LSM303C_acc_getData(uint16_t* acc_data, LSM303C_t* self){
	return _readmanyreg(self, ACC_REG_ADDR, acc_data, ACC_ADDR, 6);
}

HAL_StatusTypeDef LSM303C_temp_getData(uint16_t* temp_data, LSM303C_t* self){
	return _readmanyreg(self, TEMP_REG_ADDR, temp_data, MAG_ADDR, 2);
}




