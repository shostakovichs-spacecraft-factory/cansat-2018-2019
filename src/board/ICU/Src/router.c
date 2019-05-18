/*
 * 	Routing functions for ICU
 *
 *  Created on: May 12, 2019
 *      Author: kirs
 */

#include "stm32f1xx_hal.h"

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>

#include <sx1268.h>
#include <router.h>

extern CAN_HandleTypeDef hcan;
extern sx1268_t radio;

router_status_t router_send_CAN(mavlink_message_t * msg)
{
	canmavlink_TX_frame_t framebuff[34];
	uint8_t framecount = canmavlink_msg_to_frames(framebuff, msg);

	for(int i = 0; i < framecount; i++) //FIXME rewrite with IRQs
	{
		uint32_t mb;
		HAL_CAN_AddTxMessage(&hcan, &( framebuff[i].Header ), framebuff[i].Data, &mb);

		bool pending;
		do {
			pending = HAL_CAN_IsTxMessagePending(&hcan, mb);
		} while(pending);
	}

	return ROUTER_OK;
}

router_status_t router_send_radio(mavlink_message_t * msg)
{
	uint8_t framebuff[256];
	uint16_t len = mavlink_msg_to_send_buffer(framebuff, msg);
	sx1268_status_t status = sx1268_send(&radio, framebuff, len);

	if(status == SX1268_OK)
		return ROUTER_OK;
	if(status == SX1268_ERR_BUFSIZE)
		return ROUTER_NOBUFF;
	if(status == SX1268_TIMEOUT)
		return ROUTER_TIMEOUT;
	if(status == SX1268_BUSY || status == SX1268_ERROR)
		return ROUTER_MALFUNCTION;

	return ROUTER_MALFUNCTION;
}

router_status_t router_send_IRIDIUM(mavlink_message_t * msg)
{
	return ROUTER_MALFUNCTION; //FIXME add true IRIDIUM code
}

static bool _table_CAN(mavlink_message_t * msg)
{
	if(msg->sysid == 0)
		return false;

	return false;
}

static bool _table_ground(mavlink_message_t * msg)
{
	if(msg->sysid == 0)
		return true;

	return false;
}

static bool _table_ICU(mavlink_message_t * msg)
{
	return false;
}

router_status_t router_route(mavlink_message_t * msg)
{
	/*if(_table_ICU(msg))
		//TODO some internal func
		return ROUTER_MALFUNCTION;

	if(_table_CAN(msg))
		router_send_CAN(msg);

	if(_table_ground(msg))*/
		router_send_radio(msg); //FIXME add IRIDIUM changeover

	return ROUTER_OK;
}
