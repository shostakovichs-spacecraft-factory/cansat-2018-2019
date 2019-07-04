#ifndef AHRS_SYSTEM_H
#define AHRS_SYSTEM_H

typedef enum {
	AHRSEST_NO,
	AHRSEST_ORI_ONLY,
	AHRSEST_ORI_TRAJ,
} ahrs_exec_status_t ;

typedef enum {
	AHRSSST_NO,
	AHRSSST_ORI_ONLY,
	AHRSSST_ORI_TRAJ,
} ahrs_send_status_t;


typedef enum{
	AHRSRQ_STOP,
	AHRSRQ_GO_ORI_ONLY,
	AHRSRQ_GO_FULL,
	//AHRSRQ_GET_
} ahrs_request_t;

extern ahrs_exec_status_t ahrs_exec_status;
extern ahrs_send_status_t ahrs_send_status;


void ahrs_system_update();
void ahrs_system_init();

#endif
