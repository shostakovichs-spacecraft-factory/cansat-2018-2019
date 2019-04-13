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

#define MAX_COUNT 3
typedef struct{
	float koef_B;
	quaternion_t orientation;

	vector_t real_vectros[MAX_COUNT];
	vector_t mesuared_vectros[MAX_COUNT];

	vector_t gyro_data;
	float portions[MAX_COUNT];

	int is_vector_used[MAX_COUNT];


}ahrs_struct_t;
ahrs_struct_t ahrs_init();
void ahrs_deinit(ahrs_struct_t *ahrs_struct);

void ahrs_setKoefB(ahrs_struct_t *ahrs_struct, float koef_B);
void ahrs_vectorActivate(ahrs_struct_t *ahrs_struct, enum Vector_type vec, int isUsed);
void ahrs_updateVecMeasured(ahrs_struct_t *ahrs_struct, enum Vector_type vec, vector_t vector);
void ahrs_updateVecReal(ahrs_struct_t *ahrs_struct, enum Vector_type vec, vector_t vector);
void ahrs_updateVecPortion(ahrs_struct_t *ahrs_struct, enum Vector_type vec, float portion);
void ahrs_updateGyroData(ahrs_struct_t *ahrs_struct, vector_t gyro_data);

quaternion_t ahrs_getOrientation(ahrs_struct_t *ahrs_struct);

int ahrs_calculateOrientation(ahrs_struct_t *ahrs_struct, float dt);

int ahrs_updateError(ahrs_struct_t *ahrs_struct);



#endif /* SRC_AHRS_H_ */
