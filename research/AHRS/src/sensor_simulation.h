/*
 * sensor_simulation.h
 *
 *  Created on: 12 апр. 2019 г.
 *      Author: sereshotes
 */

#ifndef SRC_SENSOR_SIMULATION_H_
#define SRC_SENSOR_SIMULATION_H_


/*
 * sensor_simulation.c
 *
 *  Created on: 12 апр. 2019 г.
 *      Author: sereshotes
 */

#include "quaternion.h"

void simulation_init();
void simulation_setVectorLight(vector_t a);
void simulation_setVectorMag(vector_t a);
void simulation_setVectorAccel(vector_t a);
vector_t simulation_getGyro();
void simulation_update(float dt);
vector_t simulation_getVector(int type);
void simulation_setRotationPerSecond(float angle, vector_t axis);
quaternion_t simulation_getRotation();

vector_t simulation_getAccel();
vector_t simulation_getMag();
vector_t simulation_getLight();



#endif /* SRC_SENSOR_SIMULATION_H_ */
