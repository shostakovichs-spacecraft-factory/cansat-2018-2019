/*
 * ahrs.h
 *
 *  Created on: 6 апр. 2019 г.
 *      Author: sereshotes
 */

#ifndef SRC_AHRS_H_
#define SRC_AHRS_H_

#include "quaternion.h"

enum Vector_type{
	ACCEL = 0,
	MAG,
	LIGHT
};

void ahrs_init();
void ahrs_deinit();

void ahrs_setKoefB(float koef_B);
void ahrs_vectorActivate(enum Vector_type vec, int isUsed);
void ahrs_updateVecMeasured(enum Vector_type vec, vector_t vector);
void ahrs_updateVecReal(enum Vector_type vec, vector_t vector);
void ahrs_updateVecPortion(enum Vector_type vec, float portion);
void ahrs_updateGyroData(vector_t gyro_data);

quaternion_t ahrs_getOrientation();

int ahrs_calculateOrientation(float dt);

int ahrs_updateError();



#endif /* SRC_AHRS_H_ */
