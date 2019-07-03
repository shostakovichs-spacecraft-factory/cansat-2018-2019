/*
 * can.h
 *
 *  Created on: 3 июл. 2019 г.
 *      Author: snork
 */

#ifndef APPLICATION_USER_CAN_H_
#define APPLICATION_USER_CAN_H_

#include "mavlink/zikush/mavlink.h"

void can_init(void);
void can_mavlink_send(mavlink_message_t * msg);


#endif /* APPLICATION_USER_CAN_H_ */
