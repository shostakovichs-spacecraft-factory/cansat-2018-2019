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
	double x, y, z;
} vector_t;

typedef struct {
	double w, x, y, z;
} quaternion_t;


quaternion_t quat_getConj(quaternion_t *a);
quaternion_t quat_mulByNum(quaternion_t * a, double k);
double quat_getNorm(quaternion_t * a);
quaternion_t quat_normalize(quaternion_t * a);
quaternion_t quat_getInverted(quaternion_t * a);
quaternion_t quat_mulByQuat(quaternion_t * a, quaternion_t * b);
quaternion_t quat_mulByVec(quaternion_t * a, vector_t * b);
vector_t vect_rotate(vector_t * vect, quaternion_t * rotation);

void quat_add(quaternion_t *left, quaternion_t *right);
void quat_sub(quaternion_t *left, quaternion_t *right);


int vecToMatrix(Matrixf *result, vector_t *vec);
int quatToMatrix(Matrixf *result, quaternion_t *quat);
quaternion_t vecToQuat(vector_t *vec);
int matrixToQuat(quaternion_t *result, Matrixf *m);


#endif /* MADGWICK_QUATERNION_H_ */
