#include <stdio.h>

#include "ahrs.h"
#include "quaternion.h"
#include "madgwick/MadgwickAHRS.h"
#include "sensor_simulation.h"
#include <math.h>


void toEulerAngle(quaternion_t *q, float *roll, float *pitch, float *yaw)
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
int main()
{
	ahrs_init();
	ahrs_setKoefB(0.05);

	ahrs_vectorActivate(LIGHT, 0);
	ahrs_vectorActivate(ACCEL, 1);
	ahrs_vectorActivate(MAG, 1);

	ahrs_updateVecPortion(ACCEL, 1);
	ahrs_updateVecPortion(MAG, 1);
	ahrs_updateVecPortion(LIGHT, 1);
	float dt = 1.0/200.0;


	vector_t accel = vec_init(0,0,1);
	vector_t mag =  vec_init(1,0,0);
	vector_t light = vec_init(1,1,-0.5);
	vector_t gyro;

	ahrs_updateVecReal(ACCEL, accel);
	ahrs_updateVecReal(MAG, mag);
	ahrs_updateVecReal(LIGHT, light);

	float angle_per_second = 0.1;
	vector_t axis = {0,1,1};
	simulation_init();

	simulation_setVectorAccel(vec_init(0,0,1));
	simulation_setVectorMag(vec_init(1,0,0));
	simulation_setVectorLight(vec_init(1,1,-0.5));
	simulation_setRotationPerSecond(angle_per_second, axis);
	quaternion_t my_ahrs;
	quaternion_t ma_ahrs;
	beta = 0.05;
	float roll, yaw, pitch;

	int k = 0;
	while(++k % 100000){
		simulation_update(dt);
		accel = simulation_getAccel();
		mag = simulation_getMag();
		light = simulation_getLight();
		gyro = simulation_getGyro();

		ahrs_updateVecMeasured(ACCEL, accel);
		ahrs_updateVecMeasured(MAG, mag);
		ahrs_updateVecMeasured(LIGHT, light);
		ahrs_updateGyroData(gyro);
		ahrs_calculateOrientation(dt);
		my_ahrs = ahrs_getOrientation();


		MadgwickAHRSupdate(gyro.x, gyro.y, gyro.z,accel.x, accel.y, accel.z, mag.x,mag.y,mag.z);
		ma_ahrs = quat_init(q0,q1,q2,q3);

		if(!(k%100)){
			toEulerAngle(&ma_ahrs, &roll, &pitch, &yaw);
			roll *= 180 / M_PI;
			yaw *= 180 / M_PI;
			pitch *= 180 / M_PI;

			printf("%d \t1: ", k);
			printf("%3.3lf %3.3lf %3.3lf \n", roll, pitch, yaw);

			toEulerAngle(&my_ahrs, &roll, &pitch, &yaw);
			roll *= 180 / M_PI;
			yaw *= 180 / M_PI;
			pitch *= 180 / M_PI;
			printf("\t2: ");
			printf("%3.3lf %3.3lf %3.3lf \n", roll, pitch, yaw);

			quaternion_t tt = simulation_getRotation();

			toEulerAngle(&tt, &roll, &pitch, &yaw);
			roll *= 180 / M_PI;
			yaw *= 180 / M_PI;
			pitch *= 180 / M_PI;
			printf("\t3: ");
			printf("%3.3lf %3.3lf %3.3lf \n", roll, pitch, yaw);
			printf("\n");
		}

	}

    return 0;
}
