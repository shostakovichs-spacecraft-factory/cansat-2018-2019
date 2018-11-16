/*
 * quaternion.c
 *
 *  Created on: 01 нояб. 2017 г.
 *      Author: developer
 */

#include "quaternion.h"

#include <math.h>

quaternion_t quat_mult(quaternion_t * a, double k) {

	quaternion_t result;

	result.w = a->w * k;
	result.x = a->x * k;
	result.y = a->y * k;
	result.z = a->z * k;

	return result;
}

double quat_abs(quaternion_t * a) {
	return sqrt( a->w * a->w + a->x * a->x + a->y * a->y + a->z * a->z);
}

quaternion_t quat_normalize(quaternion_t * a) {

	return quat_mult(a, 1 / quat_abs(a) );
}

quaternion_t quat_invert(quaternion_t * a) {

	quaternion_t result;

	result.w = a->w;
	result.x = -1 * a->x;
	result.y = -1 * a->y;
	result.z = -1 * a->z;

	result = quat_normalize(&result); //FIXME А точно надо? В статье было так

	return result;
}

quaternion_t quat_mult_by_quat(quaternion_t * a, quaternion_t * b) {

	quaternion_t result;

	result.w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;
	result.x = a->w * b->x + a->x * b->w + a->y * b->z - a->z * b->y;
	result.y = a->w * b->y - a->x * b->z + a->y * b->w + a->z * b->x;
	result.z = a->w * b->z + a->x * b->y - a->y * b->x + a->z * b->w;

	return result;
}

quaternion_t quat_mult_by_vect(quaternion_t * a, vector_t * b) {

	quaternion_t vectQuat = {0, b->x, b->y, b->z};

	return quat_mult_by_quat(a, &vectQuat);
}

vector_t vect_rotate(vector_t * vect, quaternion_t * rotation) {
	quaternion_t rot_normal = quat_normalize(rotation);

	quaternion_t tmp = quat_mult_by_vect(&rot_normal, vect);
	quaternion_t inverted = quat_invert(&rot_normal);
	tmp = quat_mult_by_quat(&tmp, &inverted);

	vector_t result;
	result.x = tmp.x;
	result.y = tmp.y;
	result.z = tmp.z;

	return result;
}
