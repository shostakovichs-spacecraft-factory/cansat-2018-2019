/*
 * 	Routing functions for ICU
 *
 *  Created on: May 12, 2019
 *      Author: kirs
 */
#include <stdbool.h>

#include <FreeRTOS.h>
#include <FreeRTOS/queue.h>

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>

#include <router.h>

#include <main.h>
#include <zikush_config.h>

extern QueueHandle_t	ICU_queue_handle;
extern QueueHandle_t	can_queue_handle;
extern QueueHandle_t	sd_queue_handle;
extern QueueHandle_t	radio_queue_handle;

static bool _table_ICU(mavlink_message_t * msg);
static bool _table_CAN(mavlink_message_t * msg);
static bool _table_SD(mavlink_message_t * msg);
static bool _table_radio(mavlink_message_t * msg);
static bool _table_Iridium(mavlink_message_t * msg);

router_status_t router_route(mavlink_message_t * msg, TickType_t xTicksToWait)
{
	if(_table_SD(msg))
		xQueueSendToBack(sd_queue_handle, msg, xTicksToWait);

	if(_table_ICU(msg))
		xQueueSendToBack(ICU_queue_handle, msg, xTicksToWait);

	if(_table_CAN(msg))
	{
		xQueueSendToBack(can_queue_handle, msg, xTicksToWait);
		xTaskNotifyGive(can_task_handle);
	}

	if(_table_radio(msg))
	{
		xQueueSendToBack(radio_queue_handle, msg, xTicksToWait);
		xTaskNotify(radio_task_handle, RADIO_NOTIFICATION_SEND, eSetBits);
	}

	if(_table_Iridium(msg))
		return ROUTER_MALFUNCTION; //FIXME add IRIDIUM sending

	return ROUTER_OK;
}


/*Routing 'tables'*/
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
