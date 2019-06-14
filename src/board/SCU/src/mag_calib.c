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
#include "limits.h"
#include <math.h>
#include <assert.h>

#define MAG_CALIB_ACCURACY 0.01

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

void _mag_mat_rot_left(Matrixf *A, int i, int j, float c, float s)
{

	for(int k = 0; k < A->width; k++)
	{
		float bi = *matrix_at(A, i, k);
		float bj = *matrix_at(A, j, k);
		*matrix_at(A, i, k) = bi *c + bj * s;
		*matrix_at(A, j, k) = -bi *s + bj * c;
	}
}
void _mag_mat_rot_right(Matrixf *A, int i, int j, float c, float s)
{

	for(int k = 0; k < A->height; k++)
	{
		float bi = *matrix_at(A, k, i);
		float bj = *matrix_at(A, k, j);
		*matrix_at(A, k, i) = bi *c + bj * s;
		*matrix_at(A, k, j) = -bi *s + bj * c;
	}
}

void _mag_mat_rot(Matrixf *A, int i, int j, float c, float s)
{
	_mag_mat_rot_left(A, i, j, c, s);
	_mag_mat_rot_right(A, i, j, c, s);
}

void _mag_mat_make_ij_zero(Matrixf *A, int i, int j, float *s, float *c)
{
	float t = 2 * *matrix_at(A, i, j) / (*matrix_at(A, i, i) - *matrix_at(A, j, j));
	float ss = t / fabsf(t);
	float k = 1 / sqrt(1 + t * t);
	*s = ss * sqrt((1 - k) / 2);
	*c = sqrt((1 + k) / 2);

	_mag_mat_rot_left(A, i, j, *c, *s);
	_mag_mat_rot_right(A, i, j, *c, *s);
}

void mag_calib_calibrate_lsm303c(struct lsm303c_handler_s *handler, int n, uint32_t wait_ms)
{

	////////////////////////////////////
	//Find koefs of equation of second order surface (ellipse)
	////////////////////////////////
	matrix_make_identity(&mag_calib_soft);
	matrix_make_zero(&mag_calib_hard);
	Matrixf A = matrix_create(n, 9);
	Matrixf b = matrix_create(n, 1);
	Matrixf At_A = matrix_create(9, 9);
	Matrixf At = matrix_create(n, 9);
	Matrixf At_b = matrix_create(9, 1);
	Matrixf x = matrix_create(9, 1);

	for(int i = 0; i < n; i++)
	{
		*matrix_at(&b, i, 0) = 1;
	}

	for(int k = 0; k < n; k++)
	{
		uint32_t st = HAL_GetTick();
		struct lsm303c_raw_data_m_s rd;
		lsm303c_m_pull(handler, &rd);

		float dd[3];
		lsm303c_scale_m(handler, rd.m, dd, 3);


		for(int i = 0; i < 3; i++)
		{
			*matrix_at(&A, k, i) = dd[i] * dd[i];
			*matrix_at(&A, k, 3 + i) = dd[i] * dd[(i + 1) % 3];
			*matrix_at(&A, k, 6 + i) = dd[i];

		}


		while(HAL_GetTick() - st < wait_ms);
	}

	matrix_copy(&A, &At, 0);
	matrix_transpose(&At);

	matrix_multiplicate(&At, &A, &At_A);
	//matrix_print(&At_A);
	matrix_inverse(&At_A);
	//matrix_print(&At_A);

	matrix_multiplicate(&At, &b, &At_b);
	matrix_multiplicate(&At_A, &At_b, &x);

	matrix_print(&x);

	matrix_delete(&A);
	matrix_delete(&At_A);
	matrix_delete(&At_b);
	matrix_delete(&At);
	matrix_delete(&b);

	/////////////////////////////////////////////////
	// Find diag form of bilinear form in orthonormal basis
	// and it's transfer matrix
	/////////////////////////////////////////////////
	for(int i = 3; i < 6; i++)
	{
		x.arr[i] /= 2.0;
	}
	A = matrix_create(3,3);
	*matrix_at(&A, 0, 1) = x.arr[3];
	*matrix_at(&A, 1, 2) = x.arr[4];
	*matrix_at(&A, 0, 2) = x.arr[5];
	*matrix_at(&A, 1, 0) = x.arr[3];
	*matrix_at(&A, 2, 1) = x.arr[4];
	*matrix_at(&A, 2, 0) = x.arr[5];
	for(int i = 0; i < 3; i++)
	{
		*matrix_at(&A, i, i) = x.arr[i];
	}

	float norm1 = 0;
	for(int i = 0; i < 3; i++)
	{
		norm1 += *matrix_at(&A, i, i) * *matrix_at(&A, i, i);
	}
	float norm2 = 0.5 * (matrix_norm(&A) - norm1);
	float K = norm2 / norm1 / MAG_CALIB_ACCURACY;
	float N = logf(K) / logf(3/2.0);
	assert(N < INT_MAX);

	Matrixf A_trans = matrix_create(3, 3);
	matrix_make_identity(&A_trans);
	for(int k = 0; k < (int)(N); k++)
	{
		int imax = 0, jmax = 1;
		float m = -1;
		for(int i = 0; i < 3; i++)
		{
			for(int j = i + 1; j < 3; j++)
			{
				float m1 = fabsf(*matrix_at(&A, i, j));
				if(m < m1)
				{
					imax = i;
					jmax = j;
					m = m1;
				}
			}
		}

		float c, s;
		_mag_mat_make_ij_zero(&A, imax, jmax, &c, &s);
		_mag_mat_rot_right(&A_trans, imax, jmax, c, s);
		//matrix_print(&A);

	}

	//////////////////////////////////////////////
	// Make it more circle
	//////////////////////////////////////////////
	for(int i = 0; i < 3; i++)
	{
		float tt = sqrtf(*matrix_at(&A, i, i));
		for(int j = 0; j < 3; j++)
		{
			*matrix_at(&A_trans, j, i) /= tt;
		}
	}
	matrix_make_identity(&A);
	///////////////////////////////////////
	// Transfer all equation to new basis
	///////////////////////////////////////
	Matrixf bt = matrix_create(1, 3);
	for(int i = 0; i < 3; i++)
	{
		bt.arr[i] = x.arr[i + 6];
	}
	Matrixf btn = matrix_create(1, 3);
	matrix_multiplicate(&bt, &A_trans, &btn);

	////////////////////////////////////////////////////////
	// Translate coordinate system to make linear form zero
	////////////////////////////////////////////////////////
	float s = 1;
	for(int i = 0; i < 3; i++)
	{
		s += btn.arr[i] * btn.arr[i];
	}
	matrix_copy(&A_trans, &mag_calib_soft, 0);
	for(int i = 0; i < 3; i++)
	{
		mag_calib_hard.arr[i] = -btn.arr[i] / s;

		for(int j = 0; j < 3; j++)
		{
			*matrix_at(&mag_calib_soft, i, j) /= s;
		}
	}

	matrix_print(&mag_calib_soft);
	matrix_print(&mag_calib_hard);


	matrix_delete(&A);
	matrix_delete(&A_trans);
	matrix_delete(&btn);
	matrix_delete(&bt);




}
