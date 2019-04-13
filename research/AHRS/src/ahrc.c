/*
 * ahrc.c
 *
 *  Created on: 6 апр. 2019 г.
 *      Author: sereshotes
 */

#include "ahrs.h"


#include "madgwick.h"


ahrs_struct_t ahrs_init()
{
	ahrs_struct_t ahrs_struct;
	ahrs_struct.gyro_data = vec_zero();
	ahrs_struct.koef_B = 0.3;
	ahrs_struct.orientation = quat_init(1,0,0,0);

	for(int i = 0; i < MAX_COUNT; i++)
	{
		ahrs_struct.portions[i] = 1;
		ahrs_struct.is_vector_used[i] = 0;
	}
	return ahrs_struct;
};
void ahrs_deinit(ahrs_struct_t *ahrs_struct)
{

}

void ahrs_setKoefB(ahrs_struct_t *ahrs_struct, float koef_B)
{
	ahrs_struct->koef_B = koef_B;
}
void ahrs_vectorActivate(ahrs_struct_t *ahrs_struct, enum Vector_type vec, int isUsed)
{
	ahrs_struct->is_vector_used[vec] = isUsed;
}
void ahrs_updateVecMeasured(ahrs_struct_t *ahrs_struct, enum Vector_type vec, vector_t vector)
{
	ahrs_struct->mesuared_vectros[vec] = vector;
}
void ahrs_updateVecReal(ahrs_struct_t *ahrs_struct, enum Vector_type vec, vector_t vector)
{
	ahrs_struct->real_vectros[vec] = vector;
}
void ahrs_updateVecPortion(ahrs_struct_t *ahrs_struct, enum Vector_type vec, float portion)
{
	ahrs_struct->portions[vec] = portion;
}

quaternion_t ahrs_getOrientation(ahrs_struct_t *ahrs_struct)
{
	return ahrs_struct->orientation;
}
int ahrs_calculateOrientation(ahrs_struct_t *ahrs_struct, float dt)
{
	vector_t *measured[MAX_COUNT];
	vector_t *real[MAX_COUNT];
	float portions[MAX_COUNT];
	int size = 0;
	for(int i = 0; i < MAX_COUNT; i++)
	{
		if(ahrs_struct->is_vector_used[i])
		{
			measured[size] = &ahrs_struct->mesuared_vectros[i];
			real[size] = &ahrs_struct->real_vectros[i];
			portions[size] = ahrs_struct->portions[i];
			size++;
		}
	}
	quaternion_t error;
	quaternion_t gyroDer;
	quaternion_t result;

	int err = 0;
	err |= madgwick_getErrorOri(&error, real, measured, portions, size, &ahrs_struct->orientation);
	err |= madgwick_getGyroDerOri(&gyroDer, &ahrs_struct->gyro_data, dt, &ahrs_struct->orientation);
	err |= madgwick_getEstimatedOri(&result, &gyroDer, &error, dt, ahrs_struct->koef_B, &ahrs_struct->orientation);
	quat_normalize(&result);

	ahrs_struct->orientation = result;

	return err;
}

int ahrs_updateError(ahrs_struct_t *ahrs_struct)
{
	return 0;
}

void ahrs_updateGyroData(ahrs_struct_t *ahrs_struct, vector_t gyro_data)
{
	ahrs_struct->gyro_data = gyro_data;
}

