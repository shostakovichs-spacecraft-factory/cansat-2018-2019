/*
 * camera.c
 *
 *  Created on: 2 июл. 2019 г.
 *      Author: sereshotes
 */

#include "camera_system.h"
#include "camera_interface.h"
#include "my_uart.h"

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>
#include "can.h"
#include <stdbool.h>

 bool can_zenithcam_request;
 void can_mavlink_transmit(mavlink_message_t *msg)
 {

 }

#define CAM_BUFFER_SIZE 100

void camera_system_init(CAMERA *hcam)
{
	MY_UART huart2;

	GPIO_InitTypeDef pa_init;
	pa_init.Alternate = GPIO_AF7_USART2;
	pa_init.Mode = GPIO_MODE_AF_PP;
	pa_init.Pin = GPIO_PIN_5;
	pa_init.Pull = GPIO_NOPULL;
	pa_init.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOD, &pa_init);

	pa_init.Pin = GPIO_PIN_6;
	HAL_GPIO_Init(GPIOD, &pa_init);

	uart_config_default(&huart2.huart);
	huart2.huart.Instance = USART2;
	uart_init(&huart2.huart);


	camera_init(hcam, &huart2);

	camera_reset(hcam);

	camera_restore_picture(hcam);
	camera_set_image_size(hcam, VC0706_640x480);

	camera_status = CAMST_READY_TO_TAKE_PHOTO;
}

void camera_send_photo(CAMERA *hcam) {

	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1; //We do it there, cause channel status is a static variable, thus not system-wide

	camera_load_image_size(hcam);
	camera_prepare_to_read(hcam);
	hcam->image_size;
	/*  transmit raw 8-bit image */
	/* TODO image is too large for this transmission protocol (too much packets), but it works */

	mavlink_data_transmission_handshake_t handshake = {
		.type = MAVLINK_DATA_STREAM_IMG_RAW8U,
		.size = hcam->image_size,
		.width = 640,
		.height = 480,
		.packets = hcam->image_size / MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN + 1,
		.payload = MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN,
		.jpg_quality = 100
	};

	mavlink_zikush_picture_header_t picture_header = {
		.camid = ZIKUSH_CAM_ZENITH,
		.size = hcam->image_size,
		.packets = hcam->image_size / MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN + 1,
		.y_upleft_crop = 0, //TODO what for?
		.time_boot_ms = HAL_GetTick(),
	};

	mavlink_encapsulated_data_t encdata = {};
	mavlink_message_t msg;

	/*We send both data_transmission_handshake and zikush_picture_header so it can be received by spectrum_viewer,
	 * 	QGriund control and Grain MCC
	 */
	mavlink_msg_data_transmission_handshake_encode(0, ZIKUSH_CCU, &msg, &handshake);
	can_mavlink_transmit(&msg);
#ifdef CCU_TESTMODE
	usart3_mavlink_transmit(&msg);
#endif

	mavlink_msg_zikush_picture_header_encode(0, ZIKUSH_CCU, &msg, &picture_header);
	can_mavlink_transmit(&msg);
#ifdef CCU_TESTMODE
	usart3_mavlink_transmit(&msg);
#endif

	uint16_t frame = 0;
	uint8_t * frame_buffer = encdata.data;

	while(!camera_is_all_image_loaded(hcam))
	{
		uint8_t buffer[MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN + 10];
		camera_read_picture(hcam, buffer, MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN + 10);
		memcpy(frame_buffer, buffer + 5, MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN);

		encdata.seqnr = frame;
		mavlink_msg_encapsulated_data_encode(0, ZIKUSH_CCU, &msg, &encdata);
		can_mavlink_transmit(&msg);
#ifdef CCU_TESTMODE
		usart3_mavlink_transmit(&msg);
#endif

		//HAL_Delay(100);

		frame++;
	}
}


void camera_system_update(CAMERA *hcam)
{
	camera_request = can_zenithcam_request ? CAMRQ_TAKE_PHOTO : CAMRQ_NO;
	switch(camera_request)
	{
	case CAMRQ_TAKE_PHOTO:
	{
		if(camera_status == CAMST_READY_TO_SEND)
		{
			int rc = camera_take_picture(hcam);
			if(rc)
				camera_status = CAMST_ERROR;

			camera_status = CAMST_READY_TO_SEND;
		}
		else
		{
			camera_status = CAMST_ERROR;
		}
		camera_request = CAMRQ_SEND_PHOTO;
	}
	/* no break */
	case CAMRQ_SEND_PHOTO:
	{

		if(camera_status == CAMST_READY_TO_SEND)
		{
			mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1; //We do it there, cause channel status is a static variable, thus not system-wide

			camera_load_image_size(hcam);
			camera_prepare_to_read(hcam);
			hcam->image_size;
			/*  transmit raw 8-bit image */
			/* TODO image is too large for this transmission protocol (too much packets), but it works */

			mavlink_data_transmission_handshake_t handshake = {
				.type = MAVLINK_DATA_STREAM_IMG_RAW8U,
				.size = hcam->image_size,
				.width = 640,
				.height = 480,
				.packets = hcam->image_size / MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN + 1,
				.payload = MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN,
				.jpg_quality = 100
			};

			mavlink_zikush_picture_header_t picture_header = {
				.camid = ZIKUSH_CAM_ZENITH,
				.size = hcam->image_size,
				.packets = hcam->image_size / MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN + 1,
				.y_upleft_crop = 0, //TODO what for?
				.time_boot_ms = HAL_GetTick(),
			};

			mavlink_encapsulated_data_t encdata = {};
			mavlink_message_t msg;

			/*We send both data_transmission_handshake and zikush_picture_header so it can be received by spectrum_viewer,
			 * 	QGriund control and Grain MCC
			 */
			mavlink_msg_data_transmission_handshake_encode(0, ZIKUSH_CCU, &msg, &handshake);
			can_mavlink_transmit(&msg);
#ifdef CCU_TESTMODE
			usart3_mavlink_transmit(&msg);
#endif

			mavlink_msg_zikush_picture_header_encode(0, ZIKUSH_CCU, &msg, &picture_header);
			can_mavlink_transmit(&msg);
#ifdef CCU_TESTMODE
			usart3_mavlink_transmit(&msg);
#endif



		}else if(camera_status == CAMST_SEND_PHOTO)
		{

			mavlink_encapsulated_data_t encdata = {};
			mavlink_message_t msg;

			static uint16_t frame = 0;
			uint8_t * frame_buffer = encdata.data;

			if(camera_is_all_image_loaded(hcam))
			{
				frame = 0;
				camera_restore_picture(hcam);
				camera_request = CAMRQ_NO;
				camera_status = CAMST_READY_TO_TAKE_PHOTO;
				return;
			}


			uint8_t buffer[MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN + 10];
			camera_read_picture(hcam, buffer, MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN + 10);
			memcpy(frame_buffer, buffer + 5, MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN);

			encdata.seqnr = frame;
			mavlink_msg_encapsulated_data_encode(0, ZIKUSH_CCU, &msg, &encdata);
			can_mavlink_transmit(&msg);
	#ifdef CCU_TESTMODE
			usart3_mavlink_transmit(&msg);
	#endif


			//HAL_Delay(100);

			frame++;

		}
		else
			camera_status = CAMST_ERROR;
		}
	}
}


