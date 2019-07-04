/*
 * the_main.c
 *
 *  Created on: 3 июл. 2019 г.
 *      Author: snork
 */


#include "main.h"

#include <zikush_config.h>

#include "bme280.h"
#include "ads1x1x.h"
#include "lsm6ds3.h"
#include "can.h"
#include "ds18b20.h"
#include "mpx2100ap.h"
#include "sensors.h"
#include "ahrs.h"
#include "ahrs_system.h"
#include "lsm303c.h"

#include "mavlink/zikush/mavlink.h"

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
    if((t_now = HAL_GetTick()) - t_prev > 1000 / freq)
    {
        t_prev = t_now;
        return;
    }
    can_mavlink_send(&msg_heartbeat);

}


int the_main(void)
{
    mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;

    mavlink_get_channel_status(ZIKUSH_SCU)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;
    can_init();

    lsm6ds3_register_spi(&hlsm6, &hspi2, LSM_CS_GPIO_Port, LSM_CS_Pin);
    lsm6ds3_conf_default(&hlsm6);
    lsm6ds3_push_conf(&hlsm6);

    lsm303c_register_i2c(&hlsm3, &hi2c2);
    lsm303c_m_conf_default(&hlsm3);
    lsm303c_m_push_conf(&hlsm3, &hlsm3.conf.m);


    bme280_register_spi(&hbme, &hspi1, BME_CS_GPIO_Port, BME_CS_Pin, 1000);
    bme280_init(&hbme);

    ADS1x1x_register_i2c(&hads, &hi2c1, ADS1x1x_I2C_ADDRESS_ADDR_TO_GND << 1);
    ADS1x1x_config_default(&hads);
    ADS1x1x_init(&hads);
    ADS1x1x_start_conversion(&hads);


    onewire_t wire;
    onewire_Init(&wire, GPIOB, GPIO_PIN_0);
    hds.how = &wire;
    hds.resolution = ds18b20_Resolution_12bits;
    hds.rom = 0x00;
    onewire_ReadRom(&wire, &hds.rom);

    ds18b20_StartAll(&hds);

    ahrs_system_init();

    while(1)
    {
        ahrs_system_update();
        sensors_bme280_update();
        sensors_external_update();
        heartbeat_send();


        //camera_system_update(&hcam);
    }

    return 0;
}


