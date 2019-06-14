
#include <inttypes.h>

#include <stm32f10x.h>
#include <diag/Trace.h>

#include "i2c.h"
#include "ina219.h"

#include <mavlink/zikush/mavlink.h>

#include "pcu_inahelpers.h"
#include "delay.h"

#include "zikush_config.h"

ina219_t ina_icu, ina_scu, ina_ccu;

volatile uint32_t global_ms = 0;

void SysTick_Handler(void)
{
	global_ms++;
}

#pragma GCC push_options
#pragma GCC optimize ("O0")
void delay_until(uint32_t ms)
{
	while(ms < global_ms);
}
#pragma GCC pop_options



mavlink_heartbeat_t heartbeat =
{
	.type = MAV_TYPE_ONBOARD_CONTROLLER,
	.autopilot = MAV_AUTOPILOT_INVALID,
	.base_mode = MAV_MODE_FLAG_TEST_ENABLED,
	.system_status = MAV_STATE_ACTIVE
};

mavlink_zikush_power_state_t powerstate;
mavlink_zikush_power_consumed_t powerconsumed =
{
	.icu_consumed = 0, .scu_consumed = 0, .ccu_consumed = 0
};

int main()
 {
	SysTick_Config(SystemCoreClock / 1000);

	i2c_init_bus1();

	_ina_init(&ina_icu, PCU_INA_ICU_ADDR);
	_ina_init(&ina_scu, PCU_INA_SCU_ADDR);
	_ina_init(&ina_ccu, PCU_INA_CCU_ADDR);

	uint16_t cyclenum = 0;
	mavlink_message_t msg;
	while(1)
	{
		uint32_t cycle_start_time = global_ms;
		cyclenum++;
		if(cyclenum == PCU_HEARTBEATSENDPERIOD_CYCL * PCU_CURRSENDPERIOD_CYCL * PCU_POWERSENDPERIOD_CYCL)
			cyclenum = 0;

		float icu_power_prev = powerstate.icu_power;
		float scu_power_prev = powerstate.scu_power;
		float ccu_power_prev = powerstate.ccu_power;

		_ina_read(&ina_icu, &powerstate.icu_current, &powerstate.icu_power);
		_ina_read(&ina_scu, &powerstate.scu_current, &powerstate.scu_power);
		_ina_read(&ina_ccu, &powerstate.ccu_current, &powerstate.ccu_power);

		powerconsumed.icu_consumed += (icu_power_prev + powerstate.icu_power) / 2.0f * (1.0f / PCU_MEASFREQ_Hz);
		powerconsumed.scu_consumed += (scu_power_prev + powerstate.scu_power) / 2.0f * (1.0f / PCU_MEASFREQ_Hz);
		powerconsumed.ccu_consumed += (ccu_power_prev + powerstate.ccu_power) / 2.0f * (1.0f / PCU_MEASFREQ_Hz);



		if(cyclenum % PCU_HEARTBEATSENDPERIOD_CYCL == 0)
		{
			mavlink_msg_heartbeat_encode(0, ZIKUSH_PCU, &msg, &heartbeat);
			canlink_send(&msg);
		}

		if(cyclenum % PCU_CURRSENDPERIOD_CYCL == 0)
		{
			powerstate.time_boot_ms = global_ms;

			mavlink_msg_zikush_power_state_encode(0, ZIKUSH_PCU, &msg, &powerstate);
			canlink_send(&msg);
		}

		if(cyclenum % PCU_POWERSENDPERIOD_CYCL == 0)
		{
			powerconsumed.time_boot_ms = global_ms;

			mavlink_msg_zikush_power_consumed_encode(0, ZIKUSH_PCU, &msg, &powerconsumed);
			canlink_send(&msg);
		}



		delay_until(cycle_start_time + (1000 / PCU_MEASFREQ_Hz) );
	}

	return 0;
}
