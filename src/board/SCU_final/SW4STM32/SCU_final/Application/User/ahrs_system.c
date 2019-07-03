/*
 * ahrs_system.c
 *
 *  Created on: 1 июл. 2019 г.
 *      Author: sereshotes
 */
#include "../task.h"
#include "../sensors.h"
#include <math.h>
#include <../mavlink/zikush/mavlink.h>
#include "ahrs_system.h"
#include "ahrs.h"
#include "mag_calib.h"
#include "lsm6ds3.h"
#include "lsm303c.h"
#include "main.h"



#define AHRS_CALC_FREQ 100
#define AHRS_SEND_FREQ 10


ahrs_exec_status_t ahrs_exec_status;
ahrs_send_status_t ahrs_send_status;

void ahrs_system_init()
{
	mag_calib_init();

	float ddx[3], ddg[3], ddm[3];
	vector_t vx, vg, vm;
	struct lsm303c_raw_data_m_s rdm;
	struct lsm6ds3_raw_data_s rd = {{0,0,0},{0,0,0}};

	ahrs_init();
	ahrs_setKoefB(0.05);
	ahrs_vectorActivate(AHRS_LIGHT, 0);
	ahrs_vectorActivate(AHRS_MAG, 1);
	ahrs_vectorActivate(AHRS_ACCEL, 1);

	lsm6ds3_gxl_pull(&hlsm6, &rd);
	lsm6ds3_scale_xl(&hlsm6.conf.xl, rd.xl, ddx, 3);

	lsm303c_m_pull(&hlsm3, &rdm);
	lsm303c_scale_m(&hlsm3, rdm.m, ddm, 3);
	mag_calib_scale(ddm, ddm);


	vx.x = ddx[0];
	vx.y = ddx[1];
	vx.z = ddx[2];
	vec_normalize(&vx);

	vm.x = -ddm[2];
	vm.y = -ddm[1];
	vm.z = ddm[0];
	vec_normalize(&vm);
	ahrs_updateVecReal(AHRS_ACCEL, vx);
	ahrs_updateVecReal(AHRS_MAG, vm);

	ahrs_exec_status = AHRSEST_ORI_TRAJ;
	ahrs_send_status = AHRSSST_ORI_ONLY;
}
static double _pos[3];
static double _speed[3];

void _ahrs_system_exec(float dt)
{
	//Считаем
	switch(ahrs_exec_status)
	{
	case AHRSEST_ORI_TRAJ:
	{
		//FIXME надо что-то написать.
	}
	/* no break */

	case AHRSEST_ORI_ONLY:
	{

		float ddx[3], ddg[3], ddm[3];
		vector_t vx, vg, vm;
		struct lsm303c_raw_data_m_s rdm;
		struct lsm6ds3_raw_data_s rd = {{0,0,0},{0,0,0}};

		lsm6ds3_gxl_pull(&hlsm6, &rd);
		lsm6ds3_scale_xl(&hlsm6.conf.xl, rd.xl, ddx, 3);
		lsm6ds3_scale_g(&hlsm6.conf.g, rd.g, ddg, 3);
		for(int i = 0; i < 3; i++)
		{
			ddg[i] *= 2 * M_PI / 360.0;
		}

		lsm303c_m_pull(&hlsm3, &rdm);
		lsm303c_scale_m(&hlsm3, rdm.m, ddm, 3);
		mag_calib_scale(ddm, ddm);


		vx.x = ddx[0];
		vx.y = ddx[1];
		vx.z = ddx[2];
		vec_normalize(&vx);

		vm.x = -ddm[2];
		vm.y = -ddm[1];
		vm.z = ddm[0];
		vec_normalize(&vm);

		vg.x = ddg[0];
		vg.y = ddg[1];
		vg.z = ddg[2];

		ahrs_updateVecMeasured(AHRS_ACCEL, vx);
		ahrs_updateVecMeasured(AHRS_MAG, vm);
		ahrs_updateGyroData(vg);
		ahrs_calculateOrientation(dt);

	}
	/* no break */
	}
}


void _ahrs_system_zero_acc_trigger()
{
	const float COEF = 0.5;
	const uint32_t zero_acc_duration_ms = 500;
	const uint32_t cooldown_ms = 10000;

	struct lsm6ds3_raw_data_s rd = {{0,0,0},{0,0,0}};
	float ddx[3];
	lsm6ds3_gxl_pull(&hlsm6, &rd);
	lsm6ds3_scale_xl(&hlsm6.conf.xl, rd.xl, ddx, 3);
	float norm = sqrtf(ddx[0] * ddx[0] + ddx[1] * ddx[1] + ddx[2] * ddx[2]);

	static int status = 0;
	static uint32_t t_prev = 0;

	if(status == 2 && HAL_GetTick() - t_prev < cooldown_ms)
	{
		return;
	}
	if(HAL_GetTick() - t_prev < zero_acc_duration_ms && status == 1)
	{
		status = 2;
		t_prev = HAL_GetTick();

		mavlink_zikush_cmd_take_photo_t qq;
		mavlink_message_t msg;
		qq.camid = ZIKUSH_CAM_ZENITH;
		qq.heigth = 480;
		qq.width = 640;

		mavlink_msg_zikush_cmd_take_photo_encode(0, ZIKUSH_SCU, &msg, &qq);
		can_mavlink_send(&msg);
		return;
	}
	if(norm < LSM6DS3_STANDARD_G_VALUE * COEF)
	{
		status = 1;
		if(!status)
			t_prev = HAL_GetTick();
	}
	else
	{
		status = 0;
		t_prev = 0;
	}

}

void _ahrs_system_send()
{
	switch(ahrs_send_status)
	{

	case AHRSSST_ORI_TRAJ:
	{
		mavlink_message_t msg;
		mavlink_local_position_ned_t xx;
		xx.x = (float)_pos[0];
		xx.y = (float)_pos[1];
		xx.z = (float)_pos[2];
		xx.vx = (float)_speed[0];
		xx.vy = (float)_speed[1];
		xx.vz = (float)_speed[2];
		xx.time_boot_ms = HAL_GetTick();
		mavlink_msg_local_position_ned_encode(0, ZIKUSH_SCU, &msg, &xx);
		can_mavlink_send(&msg);
	}
	/* no break */
	case AHRSSST_ORI_ONLY:
	{
		quaternion_t result = ahrs_getOrientation();
		mavlink_attitude_quaternion_t qq;
		mavlink_message_t msg;
		qq.q1 = result.w;
		qq.q2 = result.x;
		qq.q3 = result.y;
		qq.q4 = result.z;
		qq.time_boot_ms = HAL_GetTick();

		mavlink_msg_attitude_quaternion_encode(0, ZIKUSH_SCU, &msg, &qq);
		can_mavlink_send(&msg);
	}
	/* no break */
	}


}

void ahrs_system_update()
{
	_ahrs_system_zero_acc_trigger();

	task_begin(1000 / AHRS_CALC_FREQ);
	_ahrs_system_exec(task_dt);
	task_end();

	task_begin(1000 / AHRS_SEND_FREQ);
	_ahrs_system_send();
	task_end();


}



