/*
 * the_main.c
 *
 *  Created on: 3 июл. 2019 г.
 *      Author: snork
 */

#include "main.h"

#include "bme280.h"
#include "ads1x1x.h"
#include "lsm6ds3.h"

int the_main(void)
{
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
        HAL_Delay(500);
    }

    return 0;
}


