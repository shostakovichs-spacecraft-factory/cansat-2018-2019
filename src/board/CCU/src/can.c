/*
 * can.c
 *
 *  Created on: Jun 27, 2019
 *      Author: kirs
 */

#include <stdbool.h>

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_can.h>

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>

#include "zikush_config.h"

#include <can.h>


can_spectrum_request_t can_spectrum_request = SPRQ_NO;
uint16_t can_spectrum_processing_y_start = CCU_SPECTRUM_Y_START,\
		can_spectrum_processing_y_end	= CCU_SPECTRUM_Y_END,\
		can_spectrum_processing_x_start = CCU_SPECTRUM_X_START,\
		can_spectrum_processing_x_end	= CCU_SPECTRUM_X_END;


bool can_nadircam_request = false;
bool can_zenithcam_request = false;


static CAN_HandleTypeDef hcan;


void can_init(void)
{
	__GPIOA_CLK_ENABLE();
	__CAN1_CLK_ENABLE();

	GPIO_InitTypeDef gpio_init =
	{
		.Mode = GPIO_MODE_AF_PP,
		.Alternate = GPIO_AF9_CAN1,
		.Pull = GPIO_NOPULL,
		.Speed = GPIO_SPEED_LOW,
		.Pin = GPIO_PIN_12 | GPIO_PIN_11
	};
	HAL_GPIO_Init(GPIOA, &gpio_init);

	hcan.Instance = CAN1;
	hcan.Init.Prescaler = HAL_RCC_GetPCLK1Freq() / PROBEWIDE_CAN_TICKRATE;
	hcan.Init.Mode = CAN_MODE_NORMAL;
	hcan.Init.SJW = CAN_SJW_1TQ;
	hcan.Init.BS1 = CAN_BS1_5TQ;
	hcan.Init.BS2 = CAN_BS2_2TQ;
	hcan.Init.TTCM = DISABLE;
	hcan.Init.ABOM = DISABLE;
	hcan.Init.AWUM = DISABLE;
	hcan.Init.NART = ENABLE;
	hcan.Init.RFLM = DISABLE;
	hcan.Init.TXFP = DISABLE;
	HAL_CAN_Init(&hcan);

	CAN_FilterConfTypeDef filter = {
		.FilterMaskIdHigh = 0,
		.FilterMaskIdLow = 0,
		.FilterMode = CAN_FILTERMODE_IDMASK,
		.FilterActivation = ENABLE,
		.FilterFIFOAssignment = CAN_FILTER_FIFO0,
		.FilterScale = CAN_FILTERSCALE_16BIT,
		.BankNumber = 0
	};

	HAL_CAN_ConfigFilter(&hcan, &filter);

	NVIC_EnableIRQ(CAN1_RX0_IRQn);
	hcan.Instance->IER |= CAN_IER_FMPIE0;
}

void can_mavlink_transmit(mavlink_message_t * msg)
{
	CANMAVLINK_TX_FRAME_T canframes[34];
	uint8_t canframecount = canmavlink_msg_to_frames(canframes, msg);
	for(int i = 0; i < canframecount; i++) //FIXME rewrite with IRQs
	{
		hcan.pTxMsg = canframes + i; //DELICIOUS!!
		HAL_CAN_Transmit(&hcan, 100);
	}
}

void USB_LP_CAN1_RX0_IRQHandler(void)
{
	CANMAVLINK_RX_FRAME_T frame;
	static mavlink_message_t msg;
	static mavlink_status_t status;
	static mavlink_zikush_cmd_take_photo_t cmd_photo;
	static mavlink_zikush_cmd_take_spectrum_t cmd_spectrum;

	hcan.pRxMsg = &frame;
	HAL_CAN_Receive(&hcan, 0, 0);

	volatile uint8_t result = canmavlink_parse_frame(&frame, &msg, &status);

	if(result == MAVLINK_FRAMING_OK)
	{
		switch(msg.msgid)
		{
		case MAVLINK_MSG_ID_ZIKUSH_CMD_TAKE_SPECTRUM:
			if(!can_spectrum_request)
			{
				mavlink_msg_zikush_cmd_take_spectrum_decode(&msg, &cmd_spectrum);

				if(cmd_spectrum.send_picture)
					can_spectrum_request = SPRQ_FULL;
				else
					can_spectrum_request = SPQR_DATAONLY;

				can_spectrum_processing_x_start = cmd_spectrum.x_start;
				can_spectrum_processing_x_end = cmd_spectrum.x_end;
				can_spectrum_processing_y_start = cmd_spectrum.y_start;
				can_spectrum_processing_y_end = cmd_spectrum.y_end;

			} //else TODO maybe we should send some info msg?

			break;

		case MAVLINK_MSG_ID_ZIKUSH_CMD_TAKE_PHOTO:
			mavlink_msg_zikush_cmd_take_photo_decode(&msg, &cmd_photo);

			if(cmd_photo.camid == ZIKUSH_CAM_NADIR)
				can_nadircam_request = true;

			else if(cmd_photo.camid == ZIKUSH_CAM_ZENITH)
				can_zenithcam_request = true;

			break;

		default:
			break;
		}
	}

	return;
}
