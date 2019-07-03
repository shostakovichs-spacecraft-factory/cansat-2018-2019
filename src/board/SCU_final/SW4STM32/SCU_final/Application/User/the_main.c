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
    volatile int rc = bme280_register_spi(&bme, &hspi1, BME_CS_GPIO_Port, BME_CS_Pin, 1000);/*
    rc = bme280_load_preset_conf(&bme.settings, BME280_CONF_PRESET_WEATHER_MONITORING);
    rc = bme280_push_sensor_conf(&bme, BME280_APPLY_SEL_ALL);
    rc = bme280_push_sensor_mode(&bme, BME280_MODE_NORMAL);
    (void)rc;*/
    bme280_init(&bme);

    ADS1x1x_config_t ads;
    rc = ADS1x1x_register_i2c(&ads, &hi2c1, ADS1x1x_I2C_ADDRESS_ADDR_TO_GND << 1);
    ADS1x1x_config_default(&ads);
    ADS1x1x_init(&ads);
    ADS1x1x_start_conversion(&ads);

    struct lsm6ds3_dev_s lsm6d;
    lsm6ds3_register_spi(&lsm6d, &hspi2, LSM_CS_GPIO_Port, LSM_CS_Pin);
    lsm6ds3_conf_default(&lsm6d);
    lsm6ds3_push_conf(&lsm6d);

    onewire_t wire;
    onewire_Init(&wire, GPIOB, GPIO_PIN_0);
    ds18b20_config_t ds18;
    ds18.how = &wire;
    ds18.resolution = ds18b20_Resolution_12bits;
    ds18.rom = 0x00;
    onewire_ReadRom(&wire, &ds18.rom);

    const uint32_t ds18_pause = 5000;
    ds18b20_StartAll(&ds18);
    uint32_t ds18_cmd_sent = HAL_GetTick();


    while(1)
    {
        struct bme280_float_data_s data;
        bme280_read(&bme, (char*)&data, sizeof(struct bme280_float_data_s));
        struct lsm6ds3_raw_data_s inertial;
        lsm6ds3_gxl_pull(&lsm6d, &inertial);
        lsm6ds3_float_t xl[3];
        lsm6ds3_float_t gyro[3];
        lsm6ds3_scale_g(&lsm6d.conf.g, inertial.g, gyro, 3);
        lsm6ds3_scale_xl(&lsm6d.conf.xl, inertial.xl, xl, 3);

        float ext_temper;
        if (ds18b20_AllDone(&ds18))
        {
            rc = ds18b20_Read(&ds18, &ext_temper);
            ds18b20_StartAll(&ds18);
            (void)ext_temper;
        }

        volatile int16_t mpx_raw = ADS1x1x_read(&ads);
        volatile float mpx_press = mpx2100ap_compensate_pressure_flt(mpx_raw);
        (void)mpx_press;

        /*
        mavlink_message_t msgbuf;
        mavlink_heartbeat_t msg = {0};
        mavlink_msg_heartbeat_encode_chan(0, ZIKUSH_SCU, ZIKUSH_SCU, &msgbuf, &msg);
//        mavlink_zikush_icu_stats_t msg = {0};
//        mavlink_msg_zikush_icu_stats_encode_chan(0, ZIKUSH_SCU, ZIKUSH_SCU, &msgbuf, &msg);
        can_mavlink_send(&msgbuf);*/
        volatile float temp = 0;
        //ds18b20_Read(&ds18, &temp);
        HAL_Delay(500);

        //ahrs_system_update();
        sensors_bme280_update();
        //sensors_external_update();
        //heartbeat_send();


        //camera_system_update(&hcam);
    }

    return 0;
}


