/*
 * ahrs.c
 *
 *  Created on: 30 мар. 2019 г.
 *      Author: sereshotes
 */

#include "madgwick.h"

#include "../matrix.h"
#include "quaternion.h"


static int madgwick_aproachVector(Matrixf* result, vector_t *real, vector_t *measured, quaternion_t *expected);
static int madgwick_jacobianAproachVector(Matrixf*result, vector_t *real, quaternion_t *expected);

/*
int madgwick_getErrorOri(Matrixf *result, Matrixf *ori_expected, _fun_template_ *functions,
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
}*/
/*
//Delete
void madgwick_quatToMatrix4_4(Matrixf *matrix)
{
	float a = *matrix_at(matrix, 0, 0);
	float b = *matrix_at(matrix, 1, 0);
	float c = *matrix_at(matrix, 2, 0);
	float d = *matrix_at(matrix, 3, 0);
	matrix_resize(matrix, 4, 4);

	*matrix_at(matrix, 0, 0) = a;
	*matrix_at(matrix, 0, 1) = -b;
	*matrix_at(matrix, 0, 2) = -c;
	*matrix_at(matrix, 0, 3) = -d;

	*matrix_at(matrix, 1, 0) = b;
	*matrix_at(matrix, 1, 1) = a;
	*matrix_at(matrix, 1, 2) = -d;
	*matrix_at(matrix, 1, 3) = c;

	*matrix_at(matrix, 2, 0) = c;
	*matrix_at(matrix, 2, 1) = d;
	*matrix_at(matrix, 2, 2) = a;
	*matrix_at(matrix, 2, 3) = -b;

	*matrix_at(matrix, 3, 0) = d;
	*matrix_at(matrix, 3, 1) = -c;
	*matrix_at(matrix, 3, 2) = b;
	*matrix_at(matrix, 3, 3) = a;
}*/
int madgwick_getGyroDerOri(quaternion_t *result, vector_t *gyro_data, float dt, quaternion_t *previous)
{
	quaternion_t S = vecToQuat(gyro_data);

	*result = quat_mulByQuat(previous, &S);
	*result = quat_mulByNum(result, 0.5);
	quat_add(result, previous);

	return 0;
}/*

int madgwick_aproachAccel(Matrixf *result, Matrixf *ori_expected)
{
	return 0;
}

int madgwick_jacobianAproachAcclel(Matrixf *result, Matrixf *ori_expected)
{
	return 0;
}


int madgwick_aproachMag(Matrixf *result, Matrixf *ori_expected)
{
	return 0;
}

int madgwick_jacobianAproachMag(Matrixf *result, Matrixf *ori_expected)
{
	return 0;
}


int madgwick_aproachLDR(Matrixf *result, Matrixf *ori_expected)
{
	float q0 = *matrix_at(ori_expected, 0, 0);
	float q1 = *matrix_at(ori_expected, 1, 0);
	float q2 = *matrix_at(ori_expected, 2, 0);
	float q3 = *matrix_at(ori_expected, 3, 0);
	return 0;
}*/
/*
int madgwick_aproachVector(Matrixf *result, Matrixf *ori_expected, Matrixf *vec_real, Matrixf *vec_measured)
{
	float q1 = *matrix_at(ori_expected, 0, 0);
	float q2 = *matrix_at(ori_expected, 1, 0);
	float q3 = *matrix_at(ori_expected, 2, 0);
	float q4 = *matrix_at(ori_expected, 3, 0);

	float dx = *matrix_at(vec_real, 0, 0);
	float dy = *matrix_at(vec_real, 1, 0);
	float dz = *matrix_at(vec_real, 2, 0);

	float sx = *matrix_at(vec_measured, 0, 0);
	float sy = *matrix_at(vec_measured, 1, 0);
	float sz = *matrix_at(vec_measured, 2, 0);

	*matrix_at(result, 0, 0) = 2*dx*(0.5 - q3*q3 - q4*q4) + 2*dy*(q1*q4 + q2*q3) + 2*dz*(q2*q4 - q1*q3) - sx;
	*matrix_at(result, 1, 0) = 2*dx*(q2*q3 - q1*q4) + 2*dy*(0.5 - q2*q2 - q4*q4) + 2*dz*(q1*q2 + q3*q4) - sy;
	*matrix_at(result, 2, 0) = 2*dx*(q1*q3 + q2*q4) + 2*dy*(q3*q4 - q1*q2) + 2*dx*(0.5 - q2*q2 - q3*q3) - sz;
	return 0;
}*/
/*
static int madgwick_calcGrad(Matrixf* result, Matrixf *func, Matrixf *jack)
{
	return matrix_multiplicate(jack, func, result);
}*/

int madgwick_getErrorOri(quaternion_t *result, vector_t *real[], vector_t *measured[], float portions[], int count, quaternion_t *previous)
{
	Matrixf _result = matrix_create(4, 1);
	matrix_make_zero(&_result);
	Matrixf temp = matrix_create(4, 1);
	Matrixf F = matrix_create(3, 1);
	Matrixf J = matrix_create(4, 3);


	for(int i = 0; i < count; i++)
	{
		madgwick_aproachVector(&F, real[i],measured[i],previous);
		madgwick_jacobianAproachVector(&J, real[i], previous);

		matrix_multiplicate(&J, &F, &temp);
		matrix_mulNumber(&temp, portions[i]);

		matrix_add(&_result, &temp);
		//matrix_print(&F);
		//matrix_print(&J);
	}
	float n = matrix_norm(&_result);
	if(n != 0)
		matrix_mulNumber(&_result, 1 / n);

	matrixToQuat(result, &_result);

	matrix_delete(&temp);
	matrix_delete(&F);
	matrix_delete(&J);
	return 0;
}
static int madgwick_aproachVector(Matrixf* result, vector_t *real, vector_t *measured, quaternion_t *expected)
{
	float q1 = expected->w;
	float q2 = expected->x;
	float q3 = expected->y;
	float q4 = expected->z;

	float dx = real->x;
	float dy = real->y;
	float dz = real->z;

	float sx = measured->x;
	float sy = measured->y;
	float sz = measured->z;

	*matrix_at(result, 0, 0) = 2*dx*(0.5 - q3*q3 - q4*q4) + 2*dy*(q1*q4 + q2*q3) + 2*dz*(q2*q4 - q1*q3) - sx;
	*matrix_at(result, 1, 0) = 2*dx*(q2*q3 - q1*q4) + 2*dy*(0.5 - q2*q2 - q4*q4) + 2*dz*(q1*q2 + q3*q4) - sy;
	*matrix_at(result, 2, 0) = 2*dx*(q1*q3 + q2*q4) + 2*dy*(q3*q4 - q1*q2) + 2*dz*(0.5 - q2*q2 - q3*q3) - sz;
	return 0;
}
static int madgwick_jacobianAproachVector(Matrixf*result, vector_t *real, quaternion_t *expected)
{
	float q1 = expected->w;
	float q2 = expected->x;
	float q3 = expected->y;
	float q4 = expected->z;

	float dx = real->x;
	float dy = real->y;
	float dz = real->z;


	*matrix_at(result, 0, 0) = 2 * (dy * q4 - dz * q3);
	*matrix_at(result, 0, 1) = 2 * (dz * q2 - dx * q4);
	*matrix_at(result, 0, 2) = 2 * (dx * q3 - dy * q2);

	*matrix_at(result, 1, 0) = 2 * (dy * q3 + dz * q4);
	*matrix_at(result, 1, 1) = 2 * (dx * q3 - 2 * dy * q2 + dz * q1);
	*matrix_at(result, 1, 2) = 2 * (dx * q4 - 2 * dz * q2 - dy * q1);

	*matrix_at(result, 2, 0) = 2 * (dy * q2 - 2 * dx * q3 - dz * q1);
	*matrix_at(result, 2, 1) = 2 * (dx * q2 + dz * q4);
	*matrix_at(result, 2, 2) = 2 * (dx * q1 - 2 * dz * q3 - dy * q4);

	*matrix_at(result, 3, 0) = 2 * (dy * q1 - 2 * dx * q4 + dz * q2);
	*matrix_at(result, 3, 1) = 2 * (dz * q3 - 2 * dy * q4 - dx * q1);
	*matrix_at(result, 3, 2) = 2 * (dx * q2 + dy * q3);
	return 0;
}

int madgwick_getEstimatedOri(quaternion_t *result, quaternion_t *gyroDerOri, quaternion_t *error, float dt, float koef_B, quaternion_t *previous)
{
	*result = quat_mulByNum(error, -koef_B);
	quat_add(result, gyroDerOri);
	*result = quat_mulByNum(result, dt);
	quat_add(result, previous);
	return 0;
}

/*
int madgwick_jacobianAproachLDR(Matrixf *result, Matrixf *ori_expected)
{
	return 0;
}

int madgwick_jacobianAproachVector(Matrixf *result, Matrixf *ori_expected, Matrixf *vec_real, Matrixf *vec_measured)
{
	float q1 = *matrix_at(ori_expected, 0, 0);
	float q2 = *matrix_at(ori_expected, 1, 0);
	float q3 = *matrix_at(ori_expected, 2, 0);
	float q4 = *matrix_at(ori_expected, 3, 0);

	float dx = *matrix_at(vec_real, 0, 0);
	float dy = *matrix_at(vec_real, 1, 0);
	float dz = *matrix_at(vec_real, 2, 0);

	float sx = *matrix_at(&vec_measured, 0, 0);
	float sy = *matrix_at(&vec_measured, 1, 0);
	float sz = *matrix_at(&vec_measured, 2, 0);

	*matrix_at(result, 0, 0) = 2 * (dy * q4 - dz * q3);
	*matrix_at(result, 0, 1) = 2 * (dz * q2 - dx * q4);
	*matrix_at(result, 0, 2) = 2 * (dx * q3 - dy * q2);

	*matrix_at(result, 1, 0) = 2 * (dy * q3 + dz * q4);
	*matrix_at(result, 1, 1) = 2 * (dx * q3 - 2 * dy * q2 + dz * q1);
	*matrix_at(result, 1, 2) = 2 * (dx * q4 - 2 * dz * q2 - dy * q1);

	*matrix_at(result, 2, 0) = 2 * (dy * q2 - 2 * dx * q3 + dz * q1);
	*matrix_at(result, 2, 1) = 2 * (dy * q3 + dz * q4);
	*matrix_at(result, 2, 2) = 2 * (dx * q4 - 2 * dz * q2 - dy * q1);

	*matrix_at(result, 3, 0) = 2 * (dx * q3 - 2 * dy * q2 + dz * q1);
	*matrix_at(result, 3, 1) = 2 * (dx * q4 - 2 * dz * q2 - dy * q1);
	*matrix_at(result, 3, 2) = 2 * (dy * q3 + dz * q4);
	return 0;
}*/
/*

void madgwick_update()
{
	_fun_template_ funcs[3];
	_fun_template_ jacobs[3];
	float portions[3];
	int size = 0;
	if(madgwick_parametres.is_ACCEL_used)
	{
		funcs[size] = madgwick_aproachAccel;
		jacobs[size] = madgwick_jacobianAproachAcclel;
		portions[size] = 1;
		size++;
	}
	if(madgwick_parametres.is_MAG_used)
	{
		funcs[size] = madgwick_aproachMag;
		jacobs[size] = madgwick_jacobianAproachMag;
		portions[size] = 1;
		size++;
	}
	if(madgwick_parametres.is_LDR_used)
	{
		funcs[size] = madgwick_aproachLDR;
		jacobs[size] = madgwick_jacobianAproachLDR;
		portions[size] = 1;
		size++;
	}

	Matrixf ori_vectors = matrix_create(4, 1);
	Matrixf ori_gyro = matrix_create(4, 1);


	madgwick_getGyroDerOri(&ori_gyro, madgwick_parametres.gyro_data);
	madgwick_combineVectorOris(&ori_vectors, &ori_previous, funcs, jacobs, portions, 3);

	madgwick_complement(&ori_present, &ori_previous, &ori_gyro, &ori_vectors, madgwick_parametres.koef_B);
}

void madgwick_complement(Matrixf *result, Matrixf *ori_previous, Matrixf* ori_gyro, Matrixf* ori_error, float koef_b)
{
	matrix_copy(ori_error, result, 0);
	matrix_mulNumber(result, -koef_b);
	matrix_add(result, ori_gyro);
	matrix_add(result, ori_previous);
}

void madgwick_templateFunMinimization(Matrixf *result, Matrixf *ori_expected)
{

}
void madgwick_templateFunDerivative(Matrixf *result, Matrixf *ori_expected)
{

}*/
