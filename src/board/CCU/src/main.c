// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "diag/Trace.h"

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_can.h>

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>
#include <spectrum.h>
#include <usart.h>

#include <can.h>

#include "camera/camera_interface.h"


#include "zikush_config.h"

/* coprocessor control register (fpu) */
#ifndef SCB_CPACR
#define SCB_CPACR (*((uint32_t*) (((0xE000E000UL) + 0x0D00UL) + 0x088)))
#endif


void SysTick_Handler(void)
{
	HAL_IncTick();
}

void cam_init(CAMERA *hcam)
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
	uart_init(&huart2);


	camera_init(hcam, &huart2);

	camera_reset(hcam);

	camera_restore_picture(hcam);
	camera_set_image_size(hcam, VC0706_640x480);
}

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

#define CAM_BUFFER_SIZE 100

int main(int argc, char* argv[])
{
	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;
	mavlink_heartbeat_t heartbeat =
	{
		.type = MAV_TYPE_ONBOARD_CONTROLLER,
		.autopilot = MAV_AUTOPILOT_INVALID,
		.base_mode = MAV_MODE_FLAG_TEST_ENABLED,
		.system_status = MAV_STATE_ACTIVE
	};
	mavlink_message_t msg;
	mavlink_msg_heartbeat_encode(0, ZIKUSH_CCU, &msg, &heartbeat);

	SysTick_Config(SystemCoreClock / 1000);

#ifdef CCU_TESTMODE
	usart_init();
#endif

	spectrum_init_capture();
	CAMERA hcam;

	enable_image_capture();
	can_init();
	cam_init(&hcam);
	camera_status = CAMST_READY_TO_TAKE_PHOTO;

	while(true)
	{
		can_mavlink_transmit(&msg);

		if(can_spectrum_request)
		{
			spectrum_take(can_spectrum_request == SPRQ_FULL, can_spectrum_processing_y_start, can_spectrum_processing_y_end, \
																can_spectrum_processing_x_start, can_spectrum_processing_x_end);
			can_spectrum_request = SPRQ_NO;
		}
		if(camera_request)
		{
			if(camera_request == CAMRQ_TAKE_PHOTO)
			{
				if(camera_status == CAMST_READY_TO_SEND)
				{
					int rc = camera_take_picture(&hcam);
					if(rc)
						camera_status = CAMST_ERROR;

					camera_status = CAMST_READY_TO_SEND;
				}
				else
				{
					camera_status = CAMST_ERROR;
				}
			}
			else if(camera_request == CAMRQ_SEND_PHOTO)
			{
				if(camera_status == CAMST_READY_TO_SEND)
				{
					uint8_t cam_buffer[CAM_BUFFER_SIZE];
					int rc = camera_read_picture(&hcam, cam_buffer, CAM_BUFFER_SIZE);

					if(rc)
						camera_status = CAMST_ERROR;
					{

						if(camera_is_all_image_loaded(&hcam))
						{
							camera_restore_picture(&hcam);
							camera_status = CAMST_READY_TO_TAKE_PHOTO;
						}
					}
					/*
					 * mavlink_send_as_zenith_or_nadir_camera(cam_buffer, CAM_BUFFER_SIZE);
					 */

				}
				else
				{
					camera_status = CAMST_ERROR;
				}
			}
		}

		//TODO add cam requests processing


		HAL_Delay(1000); //TODO Add transition into true sleep mode?

#ifdef CCU_TESTMODE
		can_spectrum_request = SPRQ_FULL;
#endif
	}
}
