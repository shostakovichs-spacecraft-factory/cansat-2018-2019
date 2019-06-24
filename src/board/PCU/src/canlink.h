/*
 * canlink.h
 *
 *  Created on: Jun 10, 2019
 *      Author: kirs
 */

#ifndef CANLINK_H_
#define CANLINK_H_

#include <stdbool.h>
#include <stm32f10x_can.h>

bool canlink_init(void);

void canlink_send(mavlink_message_t * msg);


#endif /* CANLINK_H_ */
