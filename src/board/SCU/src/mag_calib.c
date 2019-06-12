/*
 * mag_calib.c
 *
 *  Created on: 11 июн. 2019 г.
 *      Author: sereshotes
 */

#include "mag_calib.h"
#include "matrix.h"
#include "lsm303c.h"
#include "stm32f4xx_hal.h"

static Matrixf mag_calib_soft;
static Matrixf mag_calib_hard;

void mag_calib_init()
{
	mag_calib_soft = matrix_create(3,3);
	mag_calib_hard = matrix_create(3,1);
}

void mag_calib_deinit()
{
	matrix_delete(&mag_calib_soft);
	matrix_delete(&mag_calib_hard);
}

void mag_calib_scale(float *x, float *y, float *z)
{
	float a[3];
	Matrixf t1 =
	{
		.height = 3,
		.width = 1,
		.arr = a,
	};
	float b[] = {*x, *y ,*z};
	Matrixf t2 =
	{
		.height = 3,
		.width = 1,
		.arr = b,
	};

	matrix_multiplicate(&mag_calib_soft, &t2, &t1);
	matrix_add(&t1, &mag_calib_hard);
	*x = t1.arr[0];
	*y = t1.arr[1];
	*z = t1.arr[2];
}

void mag_calib_calibrate_lsm303c(struct lsm303c_handler_s *handler, int n, uint32_t wait_ms)
{
	matrix_make_identity(&mag_calib_soft);
	matrix_make_zero(&mag_calib_hard);

	for(int i = 0; i < n; i++)
	{
		struct lsm303c_raw_data_m_s rd;
		lsm303c_m_pull(handler, &rd);
		mag_calib_hard.arr[0] += rd.m[0];
		mag_calib_hard.arr[1] += rd.m[1];
		mag_calib_hard.arr[2] += rd.m[2];
		HAL_Delay(wait_ms);
	}
	mag_calib_hard.arr[0] /= -(float)n;
	mag_calib_hard.arr[1] /= -(float)n;
	mag_calib_hard.arr[2] /= -(float)n;
}
