/*
 * thread.c
 *
 *  Created on: 10 мая 2019 г.
 *      Author: sereshotes
 */

#include <stm32f4xx_hal.h>

#include "lsm6ds3.h"
#include "lsm303c.h"
#include "i2c.h"
#include "bme280.h"
#include "i2c.h"
#include "ads1x1x.h"
#include "mpx2100ap.h"
#include "ds18b20.h"
#include <can.h>

#include "thread.h"

I2C_HandleTypeDef hi2c;
SPI_HandleTypeDef hspi;
onewire_t how;

struct bme280_dev_s hbme;
ds18b20_config_t hds;
ADS1x1x_config_t hads;

struct lsm303c_handler_s hlsm3;
struct lsm6ds3_dev_s hlsm6;

#define SENSORS_SEND_FREQ 2

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

	{
		spi_config_default(&hspi);
		hspi.Instance = SPI1;
		spi_pin_miso_init(&hspi, GPIOA, GPIO_PIN_6);
		spi_pin_mosi_init(&hspi, GPIOA, GPIO_PIN_7);
		spi_pin_sck_init(&hspi, GPIOA, GPIO_PIN_5);
		spi_pin_nss_init(&hspi, GPIOA, GPIO_PIN_4);

		spi_init(&hspi);
	}

	{	//BME280
		bme280_register_i2c(&hbme, &hi2c, BME280_I2C_ADDR_SDO_LOW << 1);
		bme280_init(&hbme);
	}

	{	//DS18B20
		delay_us_init();

		onewire_Init(&how, GPIOB, GPIO_PIN_3);

		onewire_ReadRom(&how, &hds.rom);
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

	{	//lsm303c
		lsm303c_m_conf_default(&hlsm3);
		lsm303c_register_i2c(&hlsm3, &hi2c);
		lsm303c_m_push_conf(&hlsm3, &hlsm3.conf.m);
	}

	{	//lsm6ds3
		lsm6ds3_conf_default(&hlsm6);
		lsm6ds3_register_spi(&hlsm6, &hspi);
		HAL_Delay(50); //FIXME do we need it?
		lsm6ds3_push_conf(&hlsm6);
	}

	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;
}

//Read data from BME280 sensor and send scaled_pressure MAVLink message
void sensors_bme280_update(void)
{
	static uint32_t t_prev = 0, t_now;
	if((t_now = HAL_GetTick()) - t_prev < 1000 / SENSORS_SEND_FREQ)
	{
		return;
	}

	struct bme280_float_data_s data;
	mavlink_scaled_pressure_t scaled_pressure;
	mavlink_zikush_humidity_t humidity;
	mavlink_message_t msg;

	bme280_read(&hbme, &data, sizeof(struct bme280_float_data_s));

	scaled_pressure.time_boot_ms = HAL_GetTick();
	scaled_pressure.press_abs = data.pressure;
	scaled_pressure.temperature = data.temperature;
	mavlink_msg_scaled_pressure_encode(0, ZIKUSH_SCU, &msg, &scaled_pressure);
	can_mavlink_send(&msg);

	humidity.time_boot_ms = HAL_GetTick();
	humidity.humidity = data.humidity;
	mavlink_msg_zikush_humidity_encode(0, ZIKUSH_SCU, &msg, &humidity);
	can_mavlink_send(&msg);
}

//Read data from DS18B20 and MPX2100AP sensors and send scaled_pressure2 MAVLink message
void sensors_external_update(void)
{
	static uint32_t t_prev = 0, t_now;
	if((t_now = HAL_GetTick()) - t_prev < 1000 / SENSORS_SEND_FREQ)
	{
		return;
	}

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
		uint16_t data = ADS1x1x_read(&hads);

		scaled_pressure.press_abs = mpx2100ap_compensate_pressure_flt(data);

		ADS1x1x_start_conversion(&hads);
		previousConversionTime = HAL_GetTick();
	}

	scaled_pressure.time_boot_ms = HAL_GetTick();

	mavlink_msg_scaled_pressure2_encode(0, ZIKUSH_SCU, &msg, &scaled_pressure);
	can_mavlink_send(&msg);
}


