/*
 * sensor_simulation.c
 *
 *  Created on: 12 апр. 2019 г.
 *      Author: sereshotes
 */
#include "sensor_simulation.h"
#include "quaternion.h"
#include <math.h>

#define VECTOR_COUNT 3

#define ACCEL 0
#define MAG 1
#define LIGHT 2

float shift = 0.1;
float rand_shift = 0;

vector_t vectors[VECTOR_COUNT];
quaternion_t rotation_per_second;
float angle_per_second;
vector_t rotation_axis;
quaternion_t rotation;

static void _toEulerAngle(quaternion_t *q, float *roll, float *pitch, float *yaw)//!
{
	// roll (x-axis rotation)
	float sinr_cosp = +2.0 * (q->w * q->x + q->y * q->z);
	float cosr_cosp = +1.0 - 2.0 * (q->x * q->x + q->y * q->y);
	*roll = atan2(sinr_cosp, cosr_cosp);

	// *pitch (y-axis rotation)
	float sinp = +2.0 * (q->w * q->y - q->z * q->x);
	if (fabs(sinp) >= 1)
		*pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
	else
		*pitch = asin(sinp);

	// *yaw (z-axis rotation)
	float siny_cosp = +2.0 * (q->w * q->z + q->x * q->y);
	float cosy_cosp = +1.0 - 2.0 * (q->y * q->y + q->z * q->z);
	*yaw = atan2(siny_cosp, cosy_cosp);
}
void simulation_init()
{
	rotation = quat_init(1,0,0,0);//!
}


void simulation_setRotationPerSecond(float angle, vector_t axis)//!
{
	angle_per_second = angle;
	rotation_axis = axis;
	rotation_per_second = quat_makeRotQuat(angle, &axis);
}
void simulation_setVectorLight(vector_t a)
{
	vectors[LIGHT] = a;
}
void simulation_setVectorMag(vector_t a)
{
	vectors[MAG] = a;
}
void simulation_setVectorAccel(vector_t a)
{
	vectors[ACCEL] = a;
}
vector_t simulation_getGyro()
{
	vector_t result;
	_toEulerAngle(&rotation_per_second, &result.x, &result.y, &result.z);
	return result;
}
void simulation_update(float dt)//!
{
	quaternion_t rot = quat_makeRotQuat(angle_per_second * dt, &rotation_axis);
	rotation = quat_mulByQuat(&rot, &rotation);
	quat_getConjugate(&rot);
	for(int i = 0; i < VECTOR_COUNT; i++)
	{
		vectors[i] = vec_rotate(&vectors[i], &rot);
	}
}
quaternion_t simulation_getRotation()
{
	return rotation;
}

vector_t simulation_getAccel()
{
	return vectors[ACCEL];
}
vector_t simulation_getMag()
{
	return vectors[MAG];
}
vector_t simulation_getLight()
{
	return vectors[LIGHT];
}
