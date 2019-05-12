/*
 * adc_comtroller.c
 *
 *  Created on: 4 мая 2019 г.
 *      Author: sereshotes
 */

#include <stm32f4xx_hal.h>
#include <stdlib.h>
#include <diag/Trace.h>

int adc_pin_chk_init(GPIO_TypeDef* GPIOX, uint32_t pin)
{
	GPIO_InitTypeDef pa_init;

	pa_init.Pin = pin;
	pa_init.Mode = GPIO_MODE_ANALOG;
	pa_init.Speed = GPIO_SPEED_FREQ_LOW;
	pa_init.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(GPIOX, &pa_init);

	return 0;
}

int adc_config_default(ADC_HandleTypeDef *hadc)
{
	hadc->Instance = ADC1;
	hadc->Init.ClockPrescaler        = ADC_CLOCKPRESCALER_PCLK_DIV2;
	hadc->Init.Resolution            = ADC_RESOLUTION_12B;
	hadc->Init.ScanConvMode          = ENABLE;
	hadc->Init.ContinuousConvMode    = DISABLE;
	hadc->Init.DiscontinuousConvMode = DISABLE;
	hadc->Init.NbrOfDiscConversion   = 0;
	hadc->Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc->Init.ExternalTrigConv      = ADC_EXTERNALTRIGCONV_T2_CC2;
	hadc->Init.DataAlign             = ADC_DATAALIGN_RIGHT;
	hadc->Init.NbrOfConversion       = 2;
	hadc->Init.DMAContinuousRequests = DISABLE;
	hadc->Init.EOCSelection          = ADC_EOC_SEQ_CONV;

	return 0;
}

int adc_init(ADC_HandleTypeDef *hadc)
{
	int rc = HAL_ADC_Init(hadc);
	//__HAL_ADC_ENABLE(hadc);
	if(rc)
	{
		trace_printf("ERROR: can't init adc: %d\n", rc);
	}
	return rc;
}
int adc_deinit(ADC_HandleTypeDef *hadc)
{
	int rc = HAL_ADC_DeInit(hadc);
	if(rc)
	{
		trace_printf("ERROR: can't deinit adc: %d\n", rc);
	}
	return rc;
}



