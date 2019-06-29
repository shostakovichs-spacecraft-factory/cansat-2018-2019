/*
 * ICU main task. Runs state machine to control all the probe.
 * */
#include "FreeRTOS.h"
#include "task.h"

#include <main.h>


void heartbeat_task(void *pvParameters)
{
	int counter = 0;
	while(1)
	{
		static mavlink_message_t msg;
		static mavlink_heartbeat_t heartbeat =
		{
			.type = MAV_TYPE_FREE_BALLOON,
			.autopilot = MAV_AUTOPILOT_INVALID,
			.base_mode = MAV_MODE_FLAG_TEST_ENABLED,
			.system_status = MAV_STATE_ACTIVE
		};
		mavlink_msg_heartbeat_encode(0, ZIKUSH_ICU, &msg, &heartbeat);

		router_route(&msg, 0);

		counter++;
		if (counter % 10 == 0)
		{
			mavlink_msg_zikush_icu_stats_encode(0, ZIKUSH_ICU, &msg, &global_stats);
			router_route(&msg, 0);
		}


		vTaskDelay(1000 * portTICK_RATE_MS);
	}

	vTaskDelete(NULL);
}
