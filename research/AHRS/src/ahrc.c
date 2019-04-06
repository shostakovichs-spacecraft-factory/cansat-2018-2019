/*
 * ahrc.c
 *
 *  Created on: 6 апр. 2019 г.
 *      Author: sereshotes
 */

#include "ahrs.h"


#include "madgwick.h"

#define MAX_COUNT 3
struct{
	float koef_B;
	quaternion_t orientation;

	vector_t real_vectros[MAX_COUNT];
	vector_t mesuared_vectros[MAX_COUNT];

	vector_t gyro_data;
	float portions[MAX_COUNT];

	int is_vector_used[MAX_COUNT];


}ahrs_parametres;

void ahrs_init()
{
	ahrs_parametres.gyro_data = vec_zero();
	ahrs_parametres.koef_B = 0.3;
	ahrs_parametres.orientation = quat_init(1,0,0,0);

	for(int i = 0; i < MAX_COUNT; i++)
	{
		ahrs_parametres.portions[i] = 1;
		ahrs_parametres.is_vector_used[i] = 0;
	}
};
void ahrs_deinit()
{

}

void ahrs_setKoefB(float koef_B)
{
	ahrs_parametres.koef_B = koef_B;
}
void ahrs_vectorActivate(enum Vector_type vec, int isUsed)
{
	ahrs_parametres.is_vector_used[vec] = isUsed;
}
void ahrs_updateVecMeasured(enum Vector_type vec, vector_t vector)
{
	ahrs_parametres.mesuared_vectros[vec] = vector;
}
void ahrs_updateVecReal(enum Vector_type vec, vector_t vector)
{
	ahrs_parametres.real_vectros[vec] = vector;
}
void ahrs_updateVecPortion(enum Vector_type vec, float portion)
{
	ahrs_parametres.portions[vec] = portion;
}

quaternion_t ahrs_getOrientation()
{
	return ahrs_parametres.orientation;
}
int ahrs_calculateOrientation(float dt)
{
	vector_t *measured[MAX_COUNT];
	vector_t *real[MAX_COUNT];
	float portions[MAX_COUNT];
	int size = 0;
	for(int i = 0; i < MAX_COUNT; i++)
	{
		if(ahrs_parametres.is_vector_used[i])
		{
			measured[size] = &ahrs_parametres.mesuared_vectros[i];
			real[size] = &ahrs_parametres.real_vectros[i];
			portions[size] = ahrs_parametres.portions[i];
			size++;
		}
	}
	quaternion_t error;
	quaternion_t gyroDer;
	quaternion_t result;

	int err = 0;
	err |= madgwick_getErrorOri(&error, real, measured, portions, size, &ahrs_parametres.orientation);
	err |= madgwick_getGyroDerOri(&gyroDer, &ahrs_parametres.gyro_data, dt, &ahrs_parametres.orientation);
	err |= madgwick_getEstimatedOri(&result, &gyroDer, &error, dt, ahrs_parametres.koef_B, &ahrs_parametres.orientation);
	quat_normalize(&result);

	ahrs_parametres.orientation = result;

	return err;
}

int ahrs_updateError()
{
	return 0;
}

void ahrs_updateGyroData(vector_t gyro_data)
{
	ahrs_parametres.gyro_data = gyro_data;
}

