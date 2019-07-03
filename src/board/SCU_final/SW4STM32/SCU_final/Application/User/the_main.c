/*
 * the_main.c
 *
 *  Created on: 3 июл. 2019 г.
 *      Author: snork
 */

#include "main.h"

#include "bme280.h"


int the_main(void)
{
    struct bme280_dev_s bme;
    volatile int rc = bme280_register_spi(&bme, &hspi1, BME_CS_GPIO_Port, BME_CS_Pin, 1000);
    (void)rc;

    while(1)
    {}

    return 0;
}


