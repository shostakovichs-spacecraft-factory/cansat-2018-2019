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
		if (xQueueSendToBack(sd_queue_handle, msg, xTicksToWait) != pdTRUE)
			global_stats.rt_drops_sd++;

	if(_table_ICU(msg))
		if (xQueueSendToBack(ICU_queue_handle, msg, xTicksToWait) != pdTRUE)
			global_stats.rt_drops_icu++;

	if(_table_CAN(msg))
	{
		if (xQueueSendToBack(can_queue_handle, msg, xTicksToWait) != pdTRUE)
			global_stats.rt_drops_can++;

		xTaskNotifyGive(can_task_handle);
	}

	if(_table_radio(msg))
	{
		if (xQueueSendToBack(radio_queue_handle, msg, xTicksToWait) != pdTRUE)
			global_stats.rt_drops_radio++;

		xTaskNotify(radio_task_handle, RADIO_NOTIFICATION_SEND, eSetBits);
	}

	if(_table_Iridium(msg))
	{
		if (xQueueSendToBack(iridium_queue_handle, msg, xTicksToWait) != pdTRUE)
			global_stats.rt_drops_iridium++;
	}

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

	if (msg->msgid == MAVLINK_MSG_ID_HIL_GPS)
	{
		return true;
	}

	if (msg->msgid == MAVLINK_MSG_ID_ZIKUSH_ICU_STATS)
	{
		return true;
	}

	return false;
}

static bool _table_ICU(mavlink_message_t * msg)
{
	return false;
}
