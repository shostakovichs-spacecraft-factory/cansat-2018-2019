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

typedef struct {
	int16_t msg_id;
	uint32_t divider;
	uint32_t counter;
} _ir_divider_t;

static _ir_divider_t _ir_divider_table[] = {
		{ MAVLINK_MSG_ID_ZIKUSH_ICU_STATS, 1 },
		{ MAVLINK_MSG_ID_HIL_GPS, 10 },
		{ MAVLINK_MSG_ID_ZIKUSH_POWER_STATE, 10 },

		{ MAVLINK_MSG_ID_ZIKUSH_PICTURE_HEADER, 1 },
		{ MAVLINK_MSG_ID_ZIKUSH_SPECTRUM_INTENSITY_HEADER, 1},
		{-1, 0 }
};

static _ir_divider_t * _ir_divider_find_entry(uint8_t msg_id)
{
	const _ir_divider_t * retval = _ir_divider_table;

	for ( ; retval->msg_id >= 0; retval++)
	{
		if (retval->msg_id == msg_id)
			return (_ir_divider_t *)retval;
	}

	return NULL;
}


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
	{
		if (xQueueSendToBack(sd_queue_handle, msg, xTicksToWait) != pdTRUE)
			global_stats.rt_drops_sd++;
	}

	if(_table_ICU(msg))
	{
		if (xQueueSendToBack(ICU_queue_handle, msg, xTicksToWait) != pdTRUE)
			global_stats.rt_drops_icu++;
	}

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


bool router_set_ir_divider(uint8_t mav_msg_id, uint16_t divider)
{
	_ir_divider_t * const entry = _ir_divider_find_entry(mav_msg_id);
	if (NULL == entry)
		return false;

	entry->divider = divider;
	return true;
}


/*Routing 'tables'*/
static bool _table_SD(mavlink_message_t * msg)
{
	return msg != NULL;
}

static bool _table_CAN(mavlink_message_t * msg)
{
	// На данный момент в CAN не форвардится ничего
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
	if(msg->sysid == 0)
		return false;

	_ir_divider_t * const entry = _ir_divider_find_entry(msg->msgid);

	if (NULL == entry)
		return false;

	if (0 == entry->divider)
		return false;

	if (entry->counter + 1 >= entry->divider)
	{
		entry->counter = 0;
		return true;
	}
	else
	{
		entry->counter++;
		return false;
	}

	/*
	 * 0+1 = 1 >= 1 => true
	 * 0+1 = 1 >= 1 => true
	 *
	 * 0+1 = 1 >= 2 => false
	 * 1+1 = 2 >= 2 => true
	 * 0+1 = 1 >= 2 => false
	 *
	 * 0+1 = 1 >= 3 => false
	 * 1+1 = 2 >= 3 => false
	 * 2+1 = 3 >= 3 => true
	 * 0+1 = 1 >= 3 => false
	 */
}

static bool _table_ICU(mavlink_message_t * msg)
{
	if (msg->sysid == 0)
		return false; // Сообщения с борта не обрабатываем

	switch (msg->msgid)
	{
	case MAVLINK_MSG_ID_ZIKUSH_CMD_SET_IR_DIVIDER:
		return true;
	}

	return false;
}


