#ifndef CAN_H_
#define CAN_H_

#include <mavlink/zikush/mavlink.h>

typedef enum {
	SPRQ_NO = 0,
	SPQR_DATAONLY = 1,
	SPRQ_FULL = 2
} can_spectrum_request_t;
extern can_spectrum_request_t can_spectrum_request;

extern uint16_t can_spectrum_processing_y_start, can_spectrum_processing_y_end, can_spectrum_processing_x_start, can_spectrum_processing_x_end;
extern bool can_nadircam_request, can_zenithcam_request;


void can_init(void);
void can_mavlink_transmit(mavlink_message_t * msg);

#endif //#ifndef CAN_H_
