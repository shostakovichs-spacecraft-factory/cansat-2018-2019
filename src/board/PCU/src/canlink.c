/*
 * canlink.c
 *
 *  Created on: Jun 10, 2019
 *      Author: kirs
 */

#include <stdbool.h>
#include <stm32f10x_can.h>
#include <cmsis/cmsis_armcc.h>

#include <mavlink/zikush/mavlink.h>
#include <canmavlink.h>

#include <zikush_config.h>
#include "canlink.h"

bool canlink_init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef gpioinit =
	{
		.GPIO_Pin = 11,
		.GPIO_Mode = GPIO_Mode_IN_FLOATING,
		.GPIO_Speed = GPIO_Speed_10MHz
	};
	GPIO_Init(GPIOA, &gpioinit);

	gpioinit.GPIO_Pin = 12;
	gpioinit.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &gpioinit);

	CAN_InitTypeDef caninit =
	{
		.CAN_Prescaler = 400, //FIXME redefine
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

	};
	CAN_FilterInit(&canfilter);

	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);
	NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn);

	return true;
}

void canlink_send(mavlink_message_t * msg)
{
	__disable_irq();

	static CanTxMsg frames[34];
	uint8_t framecount = canmavlink_msg_to_frames(frames, &msg);

	for(int i = 0; i < framecount; i++) //FIXME rewrite with IRQs
	{
		uint32_t starttime = global_ms;
		uint8_t mailbox;

		do {
			mailbox = CAN_Transmit(CAN1, frames + i);
		} while(mailbox == CAN_TxStatus_NoMailBox && (global_ms - starttime) < PCU_CAN_TIMEOUT_MS);
	}

	__enable_irq();
}

void USB_LP_CAN1_RX0_IRQHandler(void)
{
	static CanRxMsg frame;
	static volatile mavlink_message_t msg;
	static volatile mavlink_status_t status;

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
			mavlink_zikush_cmd_powerbus_t powercmd;
			mavlink_msg_zikush_cmd_powerbus_decode(&msg, &powercmd);

			powerswitch_set(powercmd.bus, powercmd.state);
			break;

		default:
			break;
		}
	}

	return;
}
