/*
 * mpx.c
 *
 *  Created on: 2 мая 2019 г.
 *      Author: sereshotes
 */

#include <stdlib.h>
#include "ads1x1x.h"

#include "mpx2100ap.h"

float mpx2100ap_compensate_pressure_flt(uint16_t raw_data)
{
	float offset = 1300;
	float koef = 1;

	float result = (int16_t)raw_data / (float)(1 << 15) * 0.256 / 3.3 / 0.004 * 100000 * koef + offset;
	return result;
}
