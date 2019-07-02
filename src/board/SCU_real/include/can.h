#ifndef CAN_H_
#define CAN_H_

#include <mavlink/zikush/mavlink.h>

void can_init(void);

void can_mavlink_send(mavlink_message_t * msg);


#endif //#ifndef CAN_H_
