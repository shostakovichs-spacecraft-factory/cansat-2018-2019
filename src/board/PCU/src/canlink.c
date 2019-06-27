/*
 * canlink.c
 *
 *  Created on: Jun 10, 2019
 *      Author: kirs
 */

#include <stdbool.h>
#include <stm32f10x_can.h>

#include <mavlink/zikush/mavlink.h>
#include <canmavlink.h>

#include <zikush_config.h>
#include "canlink.h"

extern volatile uint32_t global_ms;

bool canlink_init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	RCC_ClocksTypeDef chipclocks;
	RCC_GetClocksFreq(&chipclocks);

	GPIO_InitTypeDef gpioinit =
	{
		.GPIO_Pin = GPIO_Pin_11,
		.GPIO_Mode = GPIO_Mode_IN_FLOATING,
		.GPIO_Speed = GPIO_Speed_10MHz
	};
	GPIO_Init(GPIOA, &gpioinit);

	gpioinit.GPIO_Pin = GPIO_Pin_12;
	gpioinit.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &gpioinit);

	CAN_InitTypeDef caninit =
	{
		.CAN_Prescaler = chipclocks.PCLK1_Frequency / PROBEWIDE_CAN_TICKRATE,
		.CAN_Mode = CAN_OperatingMode_Normal,
		.CAN_SJW = CAN_SJW_1tq,
		.CAN_BS1 = CAN_BS1_5tq,
		.CAN_BS2 = CAN_BS2_2tq,
		.CAN_TTCM = DISABLE,
		.CAN_ABOM = DISABLE,
		.CAN_AWUM = DISABLE,
		.CAN_NART = ENABLE,
		.CAN_RFLM = DISABLE,
		.CAN_TXFP = DISABLE
	};
	CAN_Init(CAN1, &caninit);

	CAN_FilterInitTypeDef canfilter =
	{
		.CAN_FilterMaskIdHigh = 0,
		.CAN_FilterMaskIdLow = 0,
		.CAN_FilterMode = CAN_FilterMode_IdMask,
		.CAN_FilterActivation = ENABLE,
		.CAN_FilterFIFOAssignment = CAN_Filter_FIFO0,
		.CAN_FilterScale = CAN_FilterScale_16bit,
		.CAN_FilterNumber = 0,
	};
	CAN_FilterInit(&canfilter);

	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);
	NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn);

	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;

	return true;
}

void canlink_send(mavlink_message_t * msg)
{
	__disable_irq();

	static CanTxMsg frames[34];
	uint8_t framecount = canmavlink_msg_to_frames(frames, msg);

	for(int i = 0; i < framecount; i++)
	{
		uint32_t mailbox;
		mailbox = CAN_Transmit(CAN1, frames + i);

		uint8_t pending;
		do {
			pending = CAN_TransmitStatus(CAN1, mailbox);//TODO consider yielding here, but notice that for proper canmavlink functionality messages should come in an uninterrupted series
		} while(pending == CAN_TxStatus_Pending);
	}

	__enable_irq();
}

void USB_LP_CAN1_RX0_IRQHandler(void)
{
	static CanRxMsg frame;
	static volatile mavlink_message_t msg;
	static volatile mavlink_status_t status;

	mavlink_zikush_cmd_powerbus_t powercmd;

	CAN_Receive(CAN1, CAN_FIFO0, &frame);

	volatile uint8_t result = canmavlink_parse_frame(&frame, &msg, &status);

	if(result == MAVLINK_FRAMING_OK)
	{
		switch(msg.msgid)
		{
		case MAVLINK_MSG_ID_ZIKUSH_CMD_PREFLIGHTRESET:
			//FIXME implement, if we will have enough time
			break;

		case MAVLINK_MSG_ID_ZIKUSH_CMD_POWEROFF:
			powerswitch_shutdown(); //FIXME maybe we should implement safer way?
			break;

		case MAVLINK_MSG_ID_ZIKUSH_CMD_POWERBUS:
			mavlink_msg_zikush_cmd_powerbus_decode(&msg, &powercmd);

			powerswitch_set(powercmd.bus, powercmd.state);
			break;

		default:
			break;
		}
	}

	return;
}
