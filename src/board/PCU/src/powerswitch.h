/*
 * powerswitch.h
 *
 *  Created on: Jun 10, 2019
 *      Author: kirs
 */

#ifndef POWERSWITCH_H_
#define POWERSWITCH_H_

#include <mavlink/zikush/mavlink.h>

void powerswitch_init(void);

void powerswitch_shutdown(void);

void powerswitch_set(ZIKUSH_CONTROLLER bus, bool enable);

#endif /* POWERSWITCH_H_ */
