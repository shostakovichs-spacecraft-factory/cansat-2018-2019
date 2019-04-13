/*
 * quaternion.h
 *
 *  Created on: 01 нояб. 2017 г.
 *      Author: developer
 */

#ifndef MADGWICK_QUATERNION_H_
#define MADGWICK_QUATERNION_H_

#include "matrix.h"

typedef struct {
	float x, y, z;
} vector_t;

typedef struct {
	float w, x, y, z;
} quaternion_t;


void quat_getConjugate(quaternion_t *a);
quaternion_t quat_getInverted(quaternion_t * a);
float quat_getNorm(quaternion_t * a);

void quat_normalize(quaternion_t * a);

quaternion_t quat_zero();
quaternion_t quat_init(float w, float x, float y, float z);
quaternion_t quat_makeRotQuat(float angle, vector_t *axis);

quaternion_t quat_mulByNum(quaternion_t * a, float k);
quaternion_t quat_mulByQuat(quaternion_t * a, quaternion_t * b);
quaternion_t quat_mulByVec(quaternion_t * a, vector_t * b);
void quat_add(quaternion_t *left, quaternion_t *right);
void quat_sub(quaternion_t *left, quaternion_t *right);



vector_t vec_rotate(vector_t * vect, quaternion_t * rotation);
float vec_getNorm(vector_t *vec);
void vec_normalize(vector_t *vec);

vector_t vec_init(float x, float y, float z);
vector_t vec_zero();


int vecToMatrix(Matrixf *result, vector_t *vec);
int quatToMatrix(Matrixf *result, quaternion_t *quat);
quaternion_t vecToQuat(vector_t *vec);
int matrixToQuat(quaternion_t *result, Matrixf *m);



void quat_print(quaternion_t *a);

#endif /* MADGWICK_QUATERNION_H_ */
