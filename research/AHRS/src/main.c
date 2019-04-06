#include <stdio.h>

#include "ahrs.h"
#include "quaternion.h"
#include "madgwick/MadgwickAHRS.h"
#include <math.h>


void toEulerAngle(quaternion_t *q, double *roll, double *pitch, double *yaw)
{
	// roll (x-axis rotation)
	double sinr_cosp = +2.0 * (q->w * q->x + q->y * q->z);
	double cosr_cosp = +1.0 - 2.0 * (q->x * q->x + q->y * q->y);
	*roll = atan2(sinr_cosp, cosr_cosp);

	// *pitch (y-axis rotation)
	double sinp = +2.0 * (q->w * q->y - q->z * q->x);
	if (fabs(sinp) >= 1)
		*pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
	else
		*pitch = asin(sinp);

	// *yaw (z-axis rotation)
	double siny_cosp = +2.0 * (q->w * q->z + q->x * q->y);
	double cosy_cosp = +1.0 - 2.0 * (q->y * q->y + q->z * q->z);
	*yaw = atan2(siny_cosp, cosy_cosp);
}
int main()
{
	ahrs_init();
	ahrs_setKoefB(10);

	ahrs_vectorActivate(LIGHT, 0);
	ahrs_vectorActivate(ACCEL, 1);
	ahrs_vectorActivate(MAG, 1);

	ahrs_updateVecPortion(ACCEL, 1);
	ahrs_updateVecPortion(MAG, 1);
	beta = 10;
	ahrs_updateVecReal(ACCEL, vec_init(0,0,1));
	ahrs_updateVecReal(MAG, vec_init(1,0,0));
	float dt = 1/200.0;

	quaternion_t my_ahrs;
	quaternion_t uu_ahrs;
	vector_t accel = {3, -2, 1/7.0};
	vector_t mag =  {1, 2, 7};
	vector_t gyro = {0, 0, 0};
	ahrs_updateVecMeasured(ACCEL, accel);
	ahrs_updateVecMeasured(MAG, mag);
	ahrs_updateGyroData(gyro);

	double roll, yaw, pitch;

	int k = 0;
	while(++k % 40){
		ahrs_calculateOrientation(dt);
		my_ahrs = ahrs_getOrientation();
		MadgwickAHRSupdate(0, 0, 0,accel.x, accel.y, accel.z, mag.x,mag.y,mag.z);
		uu_ahrs = quat_init(q0,q1,q2,q3);

		toEulerAngle(&uu_ahrs, &roll, &pitch, &yaw);
		roll *= 180 / M_PI;
		yaw *= 180 / M_PI;
		pitch *= 180 / M_PI;

		printf("1: ");
		printf("%3.3lf %3.3lf %3.3lf \n", roll, pitch, yaw);


		toEulerAngle(&my_ahrs, &roll, &pitch, &yaw);
		roll *= 180 / M_PI;
		yaw *= 180 / M_PI;
		pitch *= 180 / M_PI;
		printf("2: ");
		printf("%3.3lf %3.3lf %3.3lf \n", roll, pitch, yaw);
		printf("\n");

	}

    return 0;
}
