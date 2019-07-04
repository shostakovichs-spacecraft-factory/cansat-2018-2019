#ifndef SENSORS_H_
#define SENSORS_H_

#include <stm32f4xx_hal.h>

#include "lsm6ds3.h"
#include "i2c.h"
#include "bme280.h"
#include "i2c.h"
#include "ads1x1x.h"
#include "mpx2100ap.h"
#include "ds18b20.h"
#include <can.h>

extern I2C_HandleTypeDef hi2c;
extern SPI_HandleTypeDef hspi2;
extern SPI_HandleTypeDef hspi3;
extern onewire_t how;

extern struct bme280_dev_s hbme;
extern ds18b20_config_t hds;
extern ADS1x1x_config_t hads;

extern struct lsm303c_handler_s hlsm3;
extern struct lsm6ds3_dev_s hlsm6;

//Inits BME280, DS18B20, MPX2100AP (and also I2C1, OneWire and ADS1115 required for them)
void sensors_init(void);

//Read data from BME280 sensor and send scaled_pressure MAVLink message
void sensors_bme280_update(void);

//Read data from DS18B20 and MPX2100AP sensors and send scaled_pressure2 MAVLink message
void sensors_external_update(void);

#endif //#ifndef SENSORS_H_
