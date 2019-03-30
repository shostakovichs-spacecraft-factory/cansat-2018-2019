/*
 * ahrs.c
 *
 *  Created on: 30 мар. 2019 г.
 *      Author: sereshotes
 */

#include "matrix.h"

static Matrixf ori_previous;
static Matrixf ori_present;

#define AHRS_VECTORS_COUNT 3

struct AHRS_parametres_struct{
	float koef_M;
	float koef_B;

	int is_LDR_used;
	int is_MAG_used;
	int is_ACCEL_used;

	float gyro_data[3];
	float accel_data[3];
	float mag_data[3];
	float ldr_data[3];
} AHRS_parametres;

void AHRS_init()
{
	ori_previous = matrix_create(4, 1);
	ori_present = matrix_create(4, 1);
}

void AHRS_deinit()
{
	matrix_delete(&ori_previous);
	matrix_delete(&ori_present);
}

typedef int (*_fun_template_)(Matrixf*, Matrixf*);

int AHRS_combineVectorOris(Matrixf *result, Matrixf *ori_expected, _fun_template_ *functions,
		_fun_template_ *jacobians, float *portions, int size)
{
	matrix_make_zero(result);
	Matrixf temp = matrix_create(4, 1);
	Matrixf F = matrix_create(3, 1);
	Matrixf J = matrix_create(4, 3);


	for(int i = 0; i < size; i++)
	{
		functions[i](&F, ori_expected);
		jacobians[i](&J, ori_expected);

		matrix_multiplicate(&J, &F, &temp);
		matrix_mulNumber(&temp, portions[i]);

		matrix_add(result, &temp);
	}
	matrix_normalize(result);

	for(int i = 0; i < result->height; i++)
	{
		*matrix_at(result, i, 0) = -*matrix_at(result, i, 0);
	}
	matrix_add(result, ori_expected);

	matrix_delete(&temp);
	matrix_delete(&F);
	matrix_delete(&J);
	return 0;
}

int AHRS_getGyroOri(Matrixf *result, float gyro_data[3]);

int AHRS_aproachAccel(Matrixf *result, Matrixf *ori_expected);
int AHRS_jacobianAproachAcclel(Matrixf *result, Matrixf *ori_expected);

int AHRS_aproachMag(Matrixf *result, Matrixf *ori_expected);
int AHRS_jacobianAproachMag(Matrixf *result, Matrixf *ori_expected);

int AHRS_aproachLDR(Matrixf *result, Matrixf *ori_expected);
int AHRS_jacobianAproachLDR(Matrixf *result, Matrixf *ori_expected);

void AHRS_update()
{
	_fun_template_ funcs[3];
	_fun_template_ jacobs[3];
	float portions[3];
	int size = 0;
	if(AHRS_parametres.is_ACCEL_used)
	{
		funcs[size] = AHRS_aproachAccel;
		jacobs[size] = AHRS_jacobianAproachAcclel;
		portions[size] = 1;
		size++;
	}
	if(AHRS_parametres.is_MAG_used)
	{
		funcs[size] = AHRS_aproachMag;
		jacobs[size] = AHRS_jacobianAproachMag;
		portions[size] = 1;
		size++;
	}
	if(AHRS_parametres.is_LDR_used)
	{
		funcs[size] = AHRS_aproachLDR;
		jacobs[size] = AHRS_jacobianAproachLDR;
		portions[size] = 1;
		size++;
	}

	Matrixf ori_vectors = matrix_create(4, 1);
	Matrixf ori_gyro = matrix_create(4, 1);


	AHRS_getGyroOri(&ori_gyro, AHRS_parametres.gyro_data);
	AHRS_combineVectorOris(&ori_vectors, &ori_previous, funcs, jacobs, portions, 3);
}

void AHRS_complement(Matrixf *result, Matrixf* ori_gyro, Matrixf* ori_vectors)
{
	matrix_copy(ori_gyro, result, 0);
	float k = 1 / AHRS_parametres.koef_M - 1;

	matrix_mulNumber(result, k);
	matrix_add(result, ori_vectors);
	matrix_mulNumber(result, AHRS_parametres.koef_M);
}

void AHRS_templateFunMinimization(Matrixf *result, Matrixf *ori_expected)
{

}
void AHRS_templateFunDerivative(Matrixf *result, Matrixf *ori_expected)
{

}
