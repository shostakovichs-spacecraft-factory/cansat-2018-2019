/*
 * magnetometer.h
 *
 *  Created on: 2 нояб. 2017 г.
 *      Author: developer
 */

#ifndef MAGNETOMETER_H_
#define MAGNETOMETER_H_

#include <stdbool.h>

typedef enum {
	LSM303C_DATARATE_POWERDOWN = 0,
	LSM303C_DATARATE_10Hz,
	LSM303C_DATARATE_50Hz,
	LSM303C_DATARATE_100Hz,
	LSM303C_DATARATE_200Hz,
	LSM303C_DATARATE_400Hz,
	LSM303C_DATARATE_800Hz
} LSM303C_acc_datarate_t;

typedef enum {
	LSM303C_POWERMODE_LOW = 0,
	LSM303C_POWERMODE_MEDIUM,
	LSM303C_POWERMODE_HIGH,
	LSM303C_POWERMODE_ULTRA_HIGH
} LSM303C_mag_operative_mode_t;

typedef enum {
	LSM303C_ODR_0dot625Hz = 0,
	LSM303C_ODR_1dot25Hz,
	LSM303C_ODR_2dot5Hz,
	LSM303C_ODR_5Hz,
	LSM303C_ODR_10Hz,
	LSM303C_ODR_20Hz,
	LSM303C_ODR_40Hz,
	LSM303C_ODR_80Hz
} LSM303C_mag_output_data_rate_t;

typedef struct {
	// CTRL_REG1_M
	bool temp_en;
	LSM303C_mag_operative_mode_t power_mode;
	LSM303C_mag_output_data_rate_t data_rate;
} LSM303C_config_t;

typedef struct {
	SPI_HandleTypeDef * spi;
	GPIO_TypeDef * cs_port;
	uint16_t acc_cs_pin;
	uint16_t mag_cs_pin;
} LSM303C_t;

HAL_StatusTypeDef LSM303C_mag_setup(LSM303C_t * self, LSM303C_config_t * config);

HAL_StatusTypeDef LSM303C_mag_getData(int16_t* mag_data, LSM303C_t * self);

HAL_StatusTypeDef LSM303C_acc_getData(uint16_t* acc_data, LSM303C_t * self);

HAL_StatusTypeDef LSM303C_temp_getData(uint16_t* temp_data, LSM303C_t * self);

#endif /* MAGNETOMETER_H_ */
