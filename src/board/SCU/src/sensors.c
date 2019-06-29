/*
 * thread.c
 *
 *  Created on: 10 мая 2019 г.
 *      Author: sereshotes
 */

#include <stm32f4xx_hal.h>

#include "lsm6ds3.h"
#include "i2c.h"
#include "bme280.h"
#include <stdio.h>
#include <diag/Trace.h>
#include "i2c.h"
#include "ads1x1x.h"
#include "mpx2100ap.h"
#include "ds18b20.h"
#include "Time.h"
#include <can.h>

#include "thread.h"

static I2C_HandleTypeDef hi2c;
static struct bme280_dev_s hbme;

static onewire_t how;
static ds18b20_config_t hds;

static ADS1x1x_config_t hads;

//Inits BME280, DS18B20, MPX2100AP (and also I2C1, OneWire and ADS1115 required for them)
void sensors_init(void)
{
	{	//I2C1 (separately, cause it's used both by BME280 and MPX2100)
		i2c_pin_scl_init(GPIOB, GPIO_PIN_6);
		i2c_pin_sda_init(GPIOB, GPIO_PIN_7);
		i2c_config_default(&hi2c);
		hi2c.Instance = I2C1;
		i2c_init(&hi2c);
	}

	{	//BME280
		bme280_register_i2c(&hbme, &hi2c, BME280_I2C_ADDR_SDO_LOW << 1);
		bme280_init(&hbme);
	}

	{	//DS18B20
		delay_us_init();

		onewire_Init(&how, GPIOB, GPIO_PIN_3);

		onewire_ReadRom(&how, &hds->rom);
		hds.resolution = ds18b20_Resolution_12bits;
		hds.how = &how;
		ds18b20_SetResolution(&hds, hds.resolution);
		ds18b20_Start(&hds);
	}

	{	//MPX2100AP
		ADS1x1x_config_default(&hads);
		ADS1x1x_register_i2c(&hads, &hi2c, ADS1x1x_I2C_ADDRESS_ADDR_TO_GND << 1);
		ADS1x1x_init(&hads);

		ADS1x1x_start_conversion(&hads);
	}

	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;
}

//Read data from BME280 sensor and send scaled_pressure MAVLink message
void sensors_bme280_update(void)
{
	struct bme280_float_data_s data;
	mavlink_scaled_pressure_t scaled_pressure;
	mavlink_zikush_humidity_t humidity;
	mavlink_message_t msg;

	bme280_read(&hbme, &data, sizeof(struct bme280_float_data_s));

	scaled_pressure.time_boot_ms = HAL_GetTick();
	scaled_pressure.press_abs = data.pressure;
	scaled_pressure.temperature = data.temperature;
	mavlink_msg_scaled_pressure_encode(0, ZIKUSH_SCU, &msg, &scaled_pressure);
	can_malvink_send(&msg);

	humidity.time_boot_ms = HAL_GetTick();
	humidity.humidity = data.humidity;
	mavlink_msg_zikush_humidity_encode(0, ZIKUSH_SCU, &msg, &humidity);
	can_malvink_send(&msg);
}

//Read data from DS18B20 and MPX2100AP sensors and send scaled_pressure2 MAVLink message
void sensors_external_update(void)
{
	float temperature;
	static mavlink_scaled_pressure2_t scaled_pressure;
	mavlink_message_t msg;

	if( ds18b20_Read(&hds, &temperature) )
	{
		scaled_pressure.temperature = temperature * 100;

		ds18b20_Start(&hds);
	}

	static previousConversionTime = 0;
	if(HAL_GetTick() - previousConversionTime >= 200)
	{
		uint16_t data = ADS1x1x_read(hads);

		scaled_pressure.press_abs = mpx2100ap_compensate_pressure_flt(data);

		ADS1x1x_start_conversion(&hads);
		previousConversionTime = HAL_GetTick();
	}

	scaled_pressure.time_boot_ms = HAL_GetTick();

	mavlink_msg_scaled_pressure2_encode(0, ZIKUSH_SCU, &msg, &scaled_pressure);
	can_mavlink_send(&msg);
}
