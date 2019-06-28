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

struct bme280_dev_s hbme;

void sensors_init(I2C_HandleTypeDef* i2c_handler, onewire_t * how)
{
	{
		bme280_register_i2c(&hbme, i2c_handler, BME280_I2C_ADDR_SDO_LOW << 1);
		bme280_init(&hbme);
	}

	{
		onewire_ReadRom(how, &hds->rom);
		hds->resolution = ds18b20_Resolution_12bits;
		hds->how = how;
		ds18b20_SetResolution(hds, hds->resolution);
		ds18b20_Start(hds);
	}
}

void sensors_internal_read(bme280_dev_s *hbme)
{
	struct bme280_float_data_s data;
	mavlink_scaled_pressure_t scaled_pressure;
	mavlink_zikush_humidity_t humidity;'
	mavlink_message_t msg;

	bme280_read(hbme, &data, sizeof(struct bme280_float_data_s));

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


void thread_update_ds18b20(ds18b20_config_t *hds, uint8_t *arg)
{
	static int isReady = 1;
	static float temp;
	isReady = ds18b20_Read(hds, &temp);
	if(isReady)
	{
		arg[0] = 1;
		*(float*)(arg + 1) = temp;
		ds18b20_Start(hds);
	}
}
////////////////////////
void thread_init_mpx2100ap(ADS1x1x_config_t *hads)
{
	ADS1x1x_start_conversion(hads);
}

void thread_update_mpx2100ap(ADS1x1x_config_t *hads, uint8_t *arg)
{
	static uint32_t start = 0;

	if(HAL_GetTick() - start >= 200)
	{
		arg[0] = 1;

		uint16_t data = ADS1x1x_read(hads);

		float result = mpx2100ap_compensate_pressure_flt(data);
		*(float*)(arg + 1) = result;
		ADS1x1x_start_conversion(hads);
		start = HAL_GetTick();
	}
}



