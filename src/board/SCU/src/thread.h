/*
 * thread.h
 *
 *  Created on: 10 мая 2019 г.
 *      Author: sereshotes
 */

#ifndef THREAD_H_
#define THREAD_H_

/*
 * thread.c
 *
 *  Created on: 10 мая 2019 г.
 *      Author: sereshotes
 */

#include <stm32f4xx_hal.h>

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
//////////////////////////////
void thread_init_bme280(bme280_dev_s *hbme, I2C_HandleTypeDef* i2c_handler);
void thread_update_bme280(bme280_dev_s *hbme, uint8_t *arg);
///////////////////
void thread_init_ds18b20(ds18b20_config_t *hds, onewire_t * how);
void thread_update_ds18b20(ds18b20_config_t *hds, uint8_t *arg);
////////////////////////
void thread_init_mpx2100ap(ADS1x1x_config_t *hads);

void thread_update_mpx2100ap(ADS1x1x_config_t *hads, uint8_t *arg);







#endif /* THREAD_H_ */
