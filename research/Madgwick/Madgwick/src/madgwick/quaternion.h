/*
 * quaternion.h
 *
 *  Created on: 01 нояб. 2017 г.
 *      Author: developer
 */

#ifndef MADGWICK_QUATERNION_H_
#define MADGWICK_QUATERNION_H_

typedef struct {
	double x, y, z;
} vector_t;

typedef struct {
	double w, x, y, z;
} quaternion_t;


quaternion_t quat_mult(quaternion_t * a, double k);
double quat_abs(quaternion_t * a);
quaternion_t quat_normalize(quaternion_t * a);
quaternion_t quat_invert(quaternion_t * a);
quaternion_t quat_mult_by_quat(quaternion_t * a, quaternion_t * b);
quaternion_t quat_mult_by_vect(quaternion_t * a, vector_t * b);
vector_t vect_rotate(vector_t * vect, quaternion_t * rotation);




#endif /* MADGWICK_QUATERNION_H_ */
