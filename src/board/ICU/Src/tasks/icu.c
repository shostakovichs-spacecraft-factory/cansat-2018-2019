/*
 * ICU main task. Runs state machine to control all the probe.
 * */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <main.h>


void ICU_task (void *pvParameters)
{
	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;

	while(1)
	{
		static mavlink_message_t msg;
		BaseType_t status = xQueueReceive(ICU_queue_handle, &msg, portMAX_DELAY);

		if (pdTRUE != status)
			continue;

		bool rc = false;

		switch (msg.msgid)
		{
		case MAVLINK_MSG_ID_ZIKUSH_CMD_SET_IR_DIVIDER:
			{
				mavlink_zikush_cmd_set_ir_divider_t command;
				mavlink_msg_zikush_cmd_set_ir_divider_decode(&msg, &command);
				rc = router_set_ir_divider(command.mav_msg_id, command.divider);
			}
			break;
		}; // switch

		if (rc)
			global_stats.cmds_executed++;
		else
			global_stats.cmds_rejected++;
	}

	vTaskDelete(NULL);
}
