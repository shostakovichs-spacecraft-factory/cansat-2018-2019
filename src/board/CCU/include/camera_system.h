
#ifndef CAMERA_SYSTEM_H
#define CAMERA_SYSTEM_H

#include "camera_interface.h"



enum {
	CAMRQ_NO = 0,
	CAMRQ_TAKE_PHOTO,
	CAMRQ_SEND_PHOTO,
} camera_request;
enum{
	CAMST_NOT_READY,
	CAMST_READY_TO_TAKE_PHOTO,
	CAMST_READY_TO_SEND,
	CAMST_SEND_PHOTO,
	CAMST_SLEEP,
	CAMST_ERROR,
} camera_status;

void camera_system_init(CAMERA *hcam);

void camera_system_update(CAMERA *hcam);
#endif
