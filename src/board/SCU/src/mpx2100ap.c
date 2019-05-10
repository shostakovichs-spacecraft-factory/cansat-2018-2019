/*
 * mpx.c
 *
 *  Created on: 2 мая 2019 г.
 *      Author: sereshotes
 */

#include <stm32f4xx_hal.h>
#include <stdlib.h>
#include <diag/Trace.h>
#include "ads1x1x.h"
#define MPX_TIMEOUT 10 //ms?

typedef struct {
	union{
		ADS1x1x_config_t *hads;
	}iface;

}mpx2100ap_handler;


int mpx2100ap_register_adc(mpx2100ap_handler *hmpx, ADS1x1x_config_t *hads)
{
	hmpx->iface.hads = hads;
	return 0;
}

int mpx2100ap_init(mpx2100ap_handler *handler)
{
	return 0;
}


int mpx2100ap_deinit(mpx2100ap_handler *handler)
{
	//HAL_ADC_Stop(&handler->adc_handler);
	return 0;
}

int mpx2100ap_read(mpx2100ap_handler *handler, uint16_t *raw_data)
{
	return 0;

}

float mpx2100ap_compensate_pressure_flt(uint16_t raw_data)
{
	float offset = 1300;
	float koef = 1;

	float result = (int16_t)raw_data / (float)(1 << 15) * 0.256 / 3.3 / 0.004 * 100000 * koef + offset;
	return result;
}

int mpx2100ap_get_data_int(mpx2100ap_handler *handler, int16_t* data)
{

	return 0;
}

int mpx2100ap_get_data_flt(mpx2100ap_handler *handler, float* data)
{
	uint16_t d;
	int rc = mpx2100ap_read(handler, &d);
	*data = mpx2100ap_compensate_pressure_flt(d);
	return rc;
}
