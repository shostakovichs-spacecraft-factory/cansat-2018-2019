/*
 * quaternion.c
 *
 *  Created on: 01 нояб. 2017 г.
 *      Author: developer
 */

#include "quaternion.h"

#include <math.h>
#include <stdio.h>

quaternion_t quat_mulByNum(quaternion_t * a, double k) {

	quaternion_t result;

	result.w = a->w * k;
	result.x = a->x * k;
	result.y = a->y * k;
	result.z = a->z * k;

	return result;
}

quaternion_t quat_sum(quaternion_t *a, quaternion_t *b)
{
	quaternion_t result;
	result.w = a->w + b->w;
	result.x = a->x + b->x;
	result.y = a->y + b->y;
	result.z = a->z + b->z;
	return result;
}
void quat_add(quaternion_t *left, quaternion_t *right)
{
	left->w += right->w;
	left->x += right->x;
	left->y += right->y;
	left->z += right->z;
}
void quat_sub(quaternion_t *left, quaternion_t *right)
{
	left->w -= right->w;
	left->x -= right->x;
	left->y -= right->y;
	left->z -= right->z;
}

double quat_getNorm(quaternion_t * a) {
	double t = a->w * a->w + a->x * a->x + a->y * a->y + a->z * a->z;
	t = sqrt(t);
	return t;
}

void quat_normalize(quaternion_t * a) {

	*a = quat_mulByNum(a, 1 / quat_getNorm(a) );
}

quaternion_t quat_getConj(quaternion_t *a)
{

	quaternion_t result;

	result.w = a->w;
	result.x = -a->x;
	result.y = -a->y;
	result.z = -a->z;


	return result;
}

quaternion_t quat_getInverted(quaternion_t * a) {

	quaternion_t result = quat_getConj(a);

	float k = quat_getNorm(a);

	return quat_mulByNum(&result, 1 / (k * k));
}

quaternion_t quat_mulByQuat(quaternion_t * a, quaternion_t * b) {

	quaternion_t result;

	result.w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;
	result.x = a->w * b->x + a->x * b->w + a->y * b->z - a->z * b->y;
	result.y = a->w * b->y - a->x * b->z + a->y * b->w + a->z * b->x;
	result.z = a->w * b->z + a->x * b->y - a->y * b->x + a->z * b->w;

	return result;
}

quaternion_t quat_mulByVec(quaternion_t * a, vector_t * b) {

	quaternion_t vectQuat = {0, b->x, b->y, b->z};

	return quat_mulByQuat(a, &vectQuat);
}

vector_t vec_rotate(vector_t * vect, quaternion_t * rotation) {
	quaternion_t rot_normal = *rotation;//quat_normalize(rotation);

	quaternion_t tmp = quat_mulByVec(&rot_normal, vect);
	quaternion_t inverted = quat_getInverted(&rot_normal);
	tmp = quat_mulByQuat(&tmp, &inverted);

	vector_t result;
	result.x = tmp.x;
	result.y = tmp.y;
	result.z = tmp.z;

	return result;
}


int vecToMatrix(Matrixf *result, vector_t *vec)
{
	if(!matrix_isThatSize(result, 3, 1))
	{
		fprintf(stderr, "Bad sizes: vec -> matrix\n");
		return -1;
	}
	*matrix_at(result, 0, 0) = vec->x;
	*matrix_at(result, 1, 0) = vec->y;
	*matrix_at(result, 2, 0) = vec->z;


	return 0;
}
int quatToMatrix(Matrixf *result, quaternion_t *quat)
{
	if(!matrix_isThatSize(result, 4, 1))
	{
		fprintf(stderr, "Bad sizes: quat -> matrix\n");
		return -1;
	}
	*matrix_at(result, 0, 0) = quat->w;
	*matrix_at(result, 1, 0) = quat->x;
	*matrix_at(result, 2, 0) = quat->y;
	*matrix_at(result, 3, 0) = quat->z;


	return 0;
}

quaternion_t vecToQuat(vector_t *vec)
{
	quaternion_t result;
	result.w = 0;
	result.x = vec->x;
	result.y = vec->y;
	result.z = vec->z;
	return result;
}

int matrixToQuat(quaternion_t *result, Matrixf *m)
{
	if(!matrix_isThatSize(m, 4, 1))
	{
		fprintf(stderr, "Bad sizes: matrix -> quat\n");
		return -1;
	}
	result->w = *matrix_at(m, 0, 0);
	result->x = *matrix_at(m, 1, 0);
	result->y = *matrix_at(m, 2, 0);
	result->z = *matrix_at(m, 3, 0);
	return 0;
}

quaternion_t quat_init(double w, double x, double y, double z)
{
	quaternion_t res = {w,x,y,z};
	return res;
}

quaternion_t quat_zero()
{
	return quat_init(0,0,0,0);
}

vector_t vec_init(double x, double y, double z)
{
	vector_t res = {x,y,z};
	return res;
}

vector_t vec_zero()
{
	return vec_init(0,0,0);
}

void vec_normalize(vector_t *vec)
{
	float v = vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;
	vec->x /= v;
	vec->y /= v;
	vec->z /= v;
}

void quat_print(quaternion_t *a)
{
	printf("%2.3lf %2.3lf %2.3lf %2.3lf\n", a->w, a->x, a->y, a->z);
}

