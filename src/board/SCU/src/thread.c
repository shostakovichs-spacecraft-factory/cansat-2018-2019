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

#include "thread.h"
//////////////////////////////
void thread_init_bme280(bme280_dev_s *hbme, I2C_HandleTypeDef* i2c_handler)
{
	bme280_register_i2c(hbme, i2c_handler, BME280_I2C_ADDR_SDO_LOW << 1);
	bme280_init(hbme);
}

void thread_update_bme280(bme280_dev_s *hbme, uint8_t *arg)
{
	arg[0] = 1;
	bme280_read(hbme, (char*)(arg + 4), sizeof(struct bme280_float_data_s));
}
///////////////////
void thread_init_ds18b20(ds18b20_config_t *hds, onewire_t * how)
{
	onewire_ReadRom(how, &hds->rom);
	hds->resolution = ds18b20_Resolution_12bits;
	hds->how = how;
	ds18b20_SetResolution(hds, hds->resolution);
	ds18b20_Start(hds);

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



