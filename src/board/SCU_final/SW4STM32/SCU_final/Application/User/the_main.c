/*
 * the_main.c
 *
 *  Created on: 3 июл. 2019 г.
 *      Author: snork
 */

#include "main.h"

#include "bme280.h"
#include "ads1x1x.h"


int the_main(void)
{
    struct bme280_dev_s bme;
    volatile int rc = bme280_register_spi(&bme, &hspi1, BME_CS_GPIO_Port, BME_CS_Pin, 1000);
    (void)rc;


    ADS1x1x_config_t ads;
    rc = ADS1x1x_register_i2c(&ads, &hi2c1, ADS1x1x_I2C_ADDRESS_ADDR_TO_GND << 1);
    ADS1x1x_config_default(&ads);
    ADS1x1x_init(&ads);


    while(1)
    {

        ADS1x1x_start_conversion(&ads);
        volatile int16_t value = ADS1x1x_read(&ads);

        HAL_Delay(500);
    }

    return 0;
}


