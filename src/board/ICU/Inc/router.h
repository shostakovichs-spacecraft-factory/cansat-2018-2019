/*
 * 	Routing functions for ICU
 *
 *  Created on: May 12, 2019
 *      Author: kirs
 */

#ifndef ROUTER_H_
#define ROUTER_H_

#include <FreeRTOS.h>

#include <mavlink/zikush/mavlink.h>

typedef enum
{
	ROUTER_OK = 0,
	ROUTER_NOBUFF = 1,
	ROUTER_TIMEOUT = 2,
	ROUTER_MALFUNCTION = 4,
} router_status_t;



router_status_t router_route(mavlink_message_t * msg, TickType_t xTicksToWait);
bool router_set_ir_divider(uint8_t mav_msg_id, uint16_t divider);

#endif /* ROUTER_H_ */
