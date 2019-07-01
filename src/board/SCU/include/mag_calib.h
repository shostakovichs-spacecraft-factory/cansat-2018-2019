/*
 * mag_calib.h
 *
 *  Created on: 12 июн. 2019 г.
 *      Author: sereshotes
 */

#ifndef MAG_CALIB_H_
#define MAG_CALIB_H_

#include "lsm303c.h"

void mag_calib_init();

void mag_calib_deinit();

void mag_calib_scale(float *in, float *out);

void mag_calib_calibrate_lsm303c(struct lsm303c_handler_s *handler, int n, uint32_t wait_ms);

#endif /* MAG_CALIB_H_ */
