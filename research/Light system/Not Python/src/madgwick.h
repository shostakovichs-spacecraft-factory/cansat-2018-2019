/*
 * ahrs.h
 *
 *  Created on: 31 мар. 2019 г.
 *      Author: sereshotes
 */

#ifndef MADGWICK_H_
#define MADGWICK_H_

#include "matrix.h"
#include "quaternion.h"

int madgwick_getErrorOri(quaternion_t *result, vector_t real[], vector_t measured[], float portions[], int count, quaternion_t *previous);

int madgwick_getEstimatedOri(quaternion_t *result, quaternion_t *gyroDerOri, quaternion_t *error, quaternion_t *previous, float dt, float koef_B);

int madgwick_getGyroDerOri(quaternion_t *result, quaternion_t *previous, vector_t *gyro_data, float dt);
#endif /* MADGWICK_H_ */
