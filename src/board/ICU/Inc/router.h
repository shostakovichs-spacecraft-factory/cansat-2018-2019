/*
 * 	Routing functions for ICU
 *
 *  Created on: May 12, 2019
 *      Author: kirs
 */

#ifndef ROUTER_H_
#define ROUTER_H_

#include <mavlink/zikush/mavlink.h>

typedef enum
{
	ROUTER_OK = 0,
	ROUTER_NOBUFF = 1,
	ROUTER_TIMEOUT = 2,
	ROUTER_MALFUNCTION = 4,
} router_status_t;

router_status_t router_send_CAN(mavlink_message_t * msg);
router_status_t router_send_radio(mavlink_message_t * msg);
router_status_t router_send_IRIDIUM(mavlink_message_t * msg);

router_status_t router_route(mavlink_message_t * msg);

#endif /* ROUTER_H_ */
