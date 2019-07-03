#include <stm32f4xx_hal.h>

#include "my_debug.h"
#include "lsm6ds3.h"
#include "i2c.h"
#include "bme280.h"
#include <stdio.h>
#include <diag/Trace.h>
#include "i2c.h"
#include "ads1x1x.h"
#include "mpx2100ap.h"
#include "ds18b20.h"
#include "Time.h"
#include "spi.h"
#include "lsm6ds3.h"
#include "lsm303c.h"
#include "mag_calib.h"
#include <math.h>
#include "MadgwickAHRS.h"
#include "ahrs.h"
#include <sensors.h>
#include <can.h>
#include <mavlink/zikush/mavlink.h>
#include "ahrs_system.h"
#include "camera_system.h"


#include "thread.h"

static mavlink_message_t msg_heartbeat;
void heartbeat_init(void)
{
	mavlink_heartbeat_t heartbeat =
	{
		.type = MAV_TYPE_ONBOARD_CONTROLLER,
		.autopilot = MAV_AUTOPILOT_INVALID,
		.base_mode = MAV_MODE_FLAG_TEST_ENABLED,
		.system_status = MAV_STATE_ACTIVE
	};
	mavlink_msg_heartbeat_encode(0, ZIKUSH_SCU, &msg_heartbeat, &heartbeat);
}

void heartbeat_send(void)
{
	const uint32_t freq = 1;
	static uint32_t t_prev = 0, t_now = 0;
	if((t_now = HAL_GetTick()) - t_prev < 1000 / freq)
	{
		return;
	}
	can_mavlink_send(&msg_heartbeat);
	t_prev = t_now;
}

int main()
{

	my_debug_init();
	heartbeat_init();
	can_init();
	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;
	sensors_init();
	ahrs_system_init();

	CAMERA hcam;
	//camera_system_init(&hcam);
	while(1)
	{
		ahrs_system_update();
		//sensors_bme280_update();
		sensors_external_update();
		heartbeat_send();


		//camera_system_update(&hcam);
		/*



		HAL_Delay(1000);*/
	}

	return 0;
}
