/*
 * thread.c
 *
 *  Created on: 10 мая 2019 г.
 *      Author: sereshotes
 */

#include "main.h"
#include "task.h"

#include "bme280.h"
#include "ads1x1x.h"
#include "mpx2100ap.h"
#include "ds18b20.h"
#include <can.h>


#define SENSORS_SEND_FREQ 2

//Read data from BME280 sensor and send scaled_pressure MAVLink message
void sensors_bme280_update(void)
{
	task_begin(1000 / SENSORS_SEND_FREQ);

	struct bme280_float_data_s data;
	mavlink_scaled_pressure_t scaled_pressure;
	mavlink_zikush_humidity_t humidity;
	mavlink_message_t msg;

	bme280_read(&hbme, (char*)&data, sizeof(struct bme280_float_data_s));

	scaled_pressure.time_boot_ms = HAL_GetTick();
	scaled_pressure.press_abs = data.pressure;
	scaled_pressure.temperature = data.temperature;
	mavlink_msg_scaled_pressure_encode(0, ZIKUSH_SCU, &msg, &scaled_pressure);
	can_mavlink_send(&msg);

	humidity.time_boot_ms = HAL_GetTick();
	humidity.humidity = data.humidity;
	mavlink_msg_zikush_humidity_encode(0, ZIKUSH_SCU, &msg, &humidity);
	can_mavlink_send(&msg);

	task_end();
}

//Read data from DS18B20 and MPX2100AP sensors and send scaled_pressure2 MAVLink message
void sensors_external_update(void)
{
	task_begin(1000 / SENSORS_SEND_FREQ);

	float temperature;
	static mavlink_scaled_pressure2_t scaled_pressure;
	mavlink_message_t msg;

	if( ds18b20_Read(&hds, &temperature) )
	{
		scaled_pressure.temperature = temperature * 100;

		ds18b20_Start(&hds);
	}

	static previousConversionTime = 0;
	if(HAL_GetTick() - previousConversionTime >= 200)
	{
		uint16_t data = ADS1x1x_read(&hads);

		scaled_pressure.press_abs = mpx2100ap_compensate_pressure_flt(data);

		ADS1x1x_start_conversion(&hads);
		previousConversionTime = HAL_GetTick();
	}

	scaled_pressure.time_boot_ms = HAL_GetTick();

	mavlink_msg_scaled_pressure2_encode(0, ZIKUSH_SCU, &msg, &scaled_pressure);
	can_mavlink_send(&msg);

	task_end();
}


