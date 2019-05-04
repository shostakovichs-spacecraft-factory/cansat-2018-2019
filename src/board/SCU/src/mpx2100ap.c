/*
 * mpx.c
 *
 *  Created on: 2 мая 2019 г.
 *      Author: sereshotes
 */

#include <stm32f4xx_hal.h>
#include <stdlib.h>
#include <diag/Trace.h>

#define MPX_TIMEOUT 10 //ms?

typedef struct {
	ADC_HandleTypeDef adc_handler;
}mpx2105ap_handler;

int adc_init_for_mpx2105ap(mpx2105ap_handler *handler)
{
	ADC_HandleTypeDef h = handler->adc_handler;
	h.Init.ClockPrescaler        = ADC_CLOCKPRESCALER_PCLK_DIV4;
	h.Init.Resolution            = ADC_RESOLUTION_12B;
	h.Init.ScanConvMode          = DISABLE;
	h.Init.ContinuousConvMode    = DISABLE;
	h.Init.DiscontinuousConvMode = DISABLE;
	h.Init.NbrOfDiscConversion   = 0;
	h.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE;
	h.Init.ExternalTrigConv      = ADC_EXTERNALTRIGCONV_T1_CC1;
	h.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
	h.Init.NbrOfConversion       = 1;
	h.Init.DMAContinuousRequests = ENABLE;
	h.Init.EOCSelection          = DISABLE;
	HAL_ADC_Init(&h);
}

int mpx2105ap_LL_init()
{
	return 0;
}

int mpx2105ap_init(mpx2105ap_handler *handler)
{
	return 0;
}


int mpx2105ap_deinit(mpx2105ap_handler *handler)
{
	HAL_ADC_Stop(&handler->adc_handler);
	return 0;
}

int mpx2105ap_read(mpx2105ap_handler *handler, uint16_t *raw_data)
{
	int rc = HAL_ADC_PollForConversion(&handler->adc_handler, MPX_TIMEOUT);
	if(rc)
	{
		trace_printf("ERROR: mpx2105ap bad read: %d", rc);
		return rc;
	}
	*raw_data = HAL_ADC_GetValue(&handler->adc_handler);
	return 0;

}

float mpx2105ap_compensate_pressure_flt(uint16_t raw_data)
{
	float sensitivity = 0.4f;//mv/kPa
	return raw_data/sensitivity;
}

int mpx2105ap_get_data_int(mpx2105ap_handler *handler, int16_t* data)
{

	return 0;
}

int mpx2105ap_get_data_flt(mpx2105ap_handler *handler, float* data)
{
	uint16_t d;
	int rc = mpx2105ap_read(handler, &d);
	*data = mpx2105ap_compensate_pressure_flt(d);
	return rc;
}
