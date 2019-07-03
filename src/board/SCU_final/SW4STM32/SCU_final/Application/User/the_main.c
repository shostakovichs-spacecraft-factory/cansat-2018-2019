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
    if((t_now = HAL_GetTick()) - t_prev < 1000 / freq)
    {
        t_prev = t_now;
        return;
    }
    can_mavlink_send(&msg_heartbeat);

}


int the_main(void)
{
    mavlink_get_channel_status(ZIKUSH_SCU)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;

    can_init();

    struct bme280_dev_s bme;
    volatile int rc = bme280_register_spi(&bme, &hspi1, BME_CS_GPIO_Port, BME_CS_Pin, 1000);
    (void)rc;


    ADS1x1x_config_t ads;
    rc = ADS1x1x_register_i2c(&ads, &hi2c1, ADS1x1x_I2C_ADDRESS_ADDR_TO_GND << 1);
    ADS1x1x_config_default(&ads);
    ADS1x1x_init(&ads);


    struct lsm6ds3_dev_s lsm6d;
    lsm6ds3_register_spi(&lsm6d, &hspi2, LSM_CS_GPIO_Port, LSM_CS_Pin);
    lsm6ds3_conf_default(&lsm6d);

    lsm6ds3_push_conf(&lsm6d);



    while(1)
    {
        ADS1x1x_start_conversion(&ads);
        volatile int16_t value = ADS1x1x_read(&ads);
        (void)value;

        struct lsm6ds3_raw_data_s inertial;
        lsm6ds3_gxl_pull(&lsm6d, &inertial);
        lsm6ds3_float_t xl[3];
        lsm6ds3_float_t gyro[3];
        lsm6ds3_scale_g(&lsm6d.conf.g, inertial.g, gyro, 3);
        lsm6ds3_scale_xl(&lsm6d.conf.xl, inertial.xl, xl, 3);

        mavlink_message_t msgbuf;
        mavlink_heartbeat_t msg = {0};
        mavlink_msg_heartbeat_encode_chan(0, ZIKUSH_SCU, ZIKUSH_SCU, &msgbuf, &msg);
//        mavlink_zikush_icu_stats_t msg = {0};
//        mavlink_msg_zikush_icu_stats_encode_chan(0, ZIKUSH_SCU, ZIKUSH_SCU, &msgbuf, &msg);
        can_mavlink_send(&msgbuf);
        HAL_Delay(500);

        //ahrs_system_update();
        sensors_bme280_update();
        //sensors_external_update();
        //heartbeat_send();


        //camera_system_update(&hcam);
    }

    return 0;
}


