// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "diag/Trace.h"

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_can.h>

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>
#include <spectrum.h>
#include <usart.h>

#include <can.h>

#include "zikush_config.h"

/* coprocessor control register (fpu) */
#ifndef SCB_CPACR
#define SCB_CPACR (*((uint32_t*) (((0xE000E000UL) + 0x0D00UL) + 0x088)))
#endif


void SysTick_Handler(void)
{
	HAL_IncTick();
}


int main(int argc, char* argv[])
{
	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;
	mavlink_heartbeat_t heartbeat =
	{
		.type = MAV_TYPE_ONBOARD_CONTROLLER,
		.autopilot = MAV_AUTOPILOT_INVALID,
		.base_mode = MAV_MODE_FLAG_TEST_ENABLED,
		.system_status = MAV_STATE_ACTIVE
	};
	mavlink_message_t msg;
	mavlink_msg_heartbeat_encode(0, ZIKUSH_CCU, &msg, &heartbeat);

	SysTick_Config(SystemCoreClock / 1000);

#ifdef CCU_TESTMODE
	usart_init();
#endif

	spectrum_init_capture();
	can_init();


	while(true)
	{
		can_mavlink_transmit(&msg);
		usart2_mavlink_transmit(&msg);

		if(can_spectrum_request)
		{
			spectrum_take(can_spectrum_request == SPRQ_FULL, can_spectrum_processing_y_start, can_spectrum_processing_y_end, \
																can_spectrum_processing_x_start, can_spectrum_processing_x_end);
			can_spectrum_request = SPRQ_NO;
		}


		//TODO add cam requests processing


		HAL_Delay(1000); //TODO Add transition into true sleep mode?

#ifdef CCU_TESTMODE
		can_spectrum_request = SPRQ_FULL;
#endif
	}
}
