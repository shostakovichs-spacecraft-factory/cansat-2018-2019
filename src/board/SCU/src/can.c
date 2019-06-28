/*
 * can.c
 *
 *  Created on: Jun 28, 2019
 *      Author: kirs
 */

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_gpio.h>
#include <stm32f4xx_hal_rcc.h>

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>

#include <zikush_config.h>

static CAN_HandleTypeDef hcan;

void can_init(void)
{
	GPIO_InitTypeDef gpio_init =
	{
		.Mode = GPIO_MODE_AF_PP,
		.Alternate = GPIO_AF9_CAN1,
		.Pull = GPIO_NOPULL,
		.Speed = GPIO_SPEED_LOW,
		.Pin = GPIO_PIN_11 | GPIO_PIN_12
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

	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;
}

void can_malvink_send(mavlink_message_t * msg)
{
	CANMAVLINK_TX_FRAME_T frames[CANMAVLINK_MAXFRAMES];
	uint8_t framecount = canmavlink_msg_to_frames(frames, msg);
	for(int i = 0; i < framecount; i++)
	{
		hcan.pTxMsg = frames + i; //DELICIOUS!!
		HAL_CAN_Transmit(&hcan, 100);
	}
}
