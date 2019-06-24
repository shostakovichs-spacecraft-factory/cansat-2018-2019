/*
 * 	Routing functions for ICU
 *
 *  Created on: May 12, 2019
 *      Author: kirs
 */
#include <stdbool.h>

#include "stm32f1xx_hal.h"

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>

#include <sx1268.h>
#include <fatfs.h>

#include <router.h>

#include <zikush_config.h>

extern CAN_HandleTypeDef hcan;
extern sx1268_t radio;
extern int16_t zikush_runsessnum;

static int8_t _SD_extfilenum = -1, _SD_intfilenum = -1;
static FIL	_extfile = {0}, _intfile = {0};

router_status_t router_send_SD(mavlink_message_t * msg)
{
	FIL * currentfile;
	int8_t * currentfilenum;
	char filename_sourcepart[4];

	if(msg->sysid == 0) //internal
		{ currentfile = &_intfile; currentfilenum = &_SD_intfilenum; sprintf(filename_sourcepart, "int"); }

	else //external
		{ currentfile = &_extfile; currentfilenum = &_SD_extfilenum; sprintf(filename_sourcepart, "ext"); }


	if(currentfile->fs == NULL || currentfile->fsize > ICU_SD_MAXFILELEN)
	{
		*currentfilenum += 1;

		if(currentfile->fs != NULL)
		{
			f_sync(currentfile);
			f_close(currentfile);
		}

		char filename[ICU_SD_MAXFILENAMELEN];
		sprintf(filename, ICU_SD_TELFILENAMEFMT, zikush_runsessnum, filename_sourcepart, *currentfilenum);

		f_open(currentfile, filename, FA_CREATE_NEW | FA_WRITE);
	}

	uint8_t buf[MAVLINK_MAX_PACKET_LEN];
	uint16_t len = mavlink_msg_to_send_buffer(buf, msg);
	UINT infactwritten;

	FRESULT result = f_write(currentfile, buf, len, &infactwritten);
	if(result != FR_OK || infactwritten != len)
		return ROUTER_MALFUNCTION;

	result = f_sync(currentfile);
	if(result != FR_OK)
		return ROUTER_MALFUNCTION;

	return ROUTER_OK;
}

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
	uint8_t framebuff[MAVLINK_MAX_PACKET_LEN];
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

static bool _table_SD(mavlink_message_t * msg)
{
	return msg != NULL;

	return false;
}

static bool _table_CAN(mavlink_message_t * msg)
{
	if(msg->sysid == 0)
		return false;

	return false;
}

static bool _table_radio(mavlink_message_t * msg)
{
	if(msg->sysid == 0)
		return true;

	return false;
}

static bool _table_Iridium(mavlink_message_t * msg)
{
	if(msg->sysid != 0)
		return false;

	return false;
}

static bool _table_ICU(mavlink_message_t * msg)
{
	return false;
}

router_status_t router_route(mavlink_message_t * msg)
{
	router_status_t status;

	if(_table_SD(msg))
		status |= router_send_SD(msg);

	if(_table_ICU(msg))
		//TODO some internal func
		return ROUTER_MALFUNCTION;

	if(_table_CAN(msg))
		status |= router_send_CAN(msg);

	if(_table_radio(msg))
		status |= router_send_radio(msg);

	if(_table_Iridium(msg))
		return ROUTER_MALFUNCTION; //FIXME add IRIDIUM sending

	return ROUTER_OK;
}
