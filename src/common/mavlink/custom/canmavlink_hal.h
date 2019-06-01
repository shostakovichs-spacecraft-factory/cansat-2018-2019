#ifndef CANMAVLINK
#define CANMAVLINK

#include <mavlink/protocol.h> //FIXME not a proper way I think
#include <mavlink/mavlink_types.h>

#ifdef STM32F407xx
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_can.h>

#define CANMAVLINK_TX_FRAME_T		CanTxMsgTypeDef
#define CANMAVLINK_RX_FRAME_T		CanRxMsgTypeDef
#define CANDATA(FRAMEP)	FRAMEP->Data
#define CANHEADER(FRAMEP)	(*FRAMEP)

#elif defined STM32F103xE
#include <stm32f1xx_hal.h>
#include "stm32f1xx_hal_can.h"

typedef struct {
	CAN_TxCANHEADERTypeDef CANHEADER;
	uint8_t Data[8];
} canmavlink_TX_frame_t;

typedef struct {
	CAN_RxCANHEADERTypeDef CANHEADER;
	uint8_t Data[8];
} canmavlink_RX_frame_t;

#define CANMAVLINK_TX_FRAME_T		canmavlink_TX_frame_t
#define CANMAVLINK_RX_FRAME_T		canmavlink_RX_frame_t
#define CANDATA(FRAMEP)	FRAMEP->Data
#define CANHEADER(FRAMEP)	FRAMEP->CANHEADER

#endif

#ifdef MIN //FIXME is it correct?
#define THEIRMIN MIN
#undef MIN
#endif
#define MIN(a, b) (a < b ? a : b)

#define DIVIDE_ROUND_UP(DIVIDEE, DIVIDER)	(DIVIDEE / DIVIDER + ( (DIVIDEE % DIVIDER) != 0) )

#define CAN2_MAX_DLC	8

#define FIRSTFRAME_FLAG	1

#define CAN_STDID_PACK(COMPID, FFFLAG, MSGID) ( (COMPID & 0x03) << 9 | \
												(FFFLAG & 0x01) << 8 | (MSGID & 0xFF) )
#define CAN_STDID_COMPID(FRAMEP)	( (CANHEADER(FRAMEP).StdId >> 9) & 0x03 )
#define CAN_STDID_FFFLAG(FRAMEP)	( (CANHEADER(FRAMEP).StdId >> 8) & 0x01 )
#define CAN_STDID_MSGID(FRAMEP)		( (CANHEADER(FRAMEP).StdId >> 0) & 0xFF )

#define ISFIRSTFRAME(FRAMEP) (CAN_STDID_FFFLAG(FRAMEP) & FIRSTFRAME_FLAG)
#define FIRSTFRAMEDATALEN	4

#define CHANLENGTH(MSG)	(MSG->len + 2)


/**
 * @brief Pack a message to send it over a CAN bus
 *
 * @arg frames - pointer to a buffer for frames to be sent. Assumed to be big enough (34 frames maximum)
 * @arg msg - message to encode
 *
 * @return A number of CAN frames used to encode a message
 */
MAVLINK_HELPER uint8_t canmavlink_msg_to_frames(CANMAVLINK_TX_FRAME_T * frames, const mavlink_message_t *msg)
{
	uint8_t length = msg->len;
	CANMAVLINK_TX_FRAME_T * firstframe = frames;

	if (msg->magic == MAVLINK_STX_MAVLINK1) {
		CANHEADER(firstframe).IDE = CAN_ID_STD;
		CANHEADER(firstframe).RTR = CAN_RTR_DATA;
		CANHEADER(firstframe).DLC = 4;
		CANHEADER(firstframe).StdId = CAN_STDID_PACK(msg->compid, FIRSTFRAME_FLAG, msg->msgid);
		firstframe->Data[0] = length;
		firstframe->Data[1] = msg->seq;
		firstframe->Data[2] = msg->sysid;
		firstframe->Data[3] = msg->compid;

		for(uint8_t i = 0; true;)
		{
			uint8_t framenum = i / CAN2_MAX_DLC + 1;
			CANMAVLINK_TX_FRAME_T * currframe = frames + framenum;

			uint8_t copylen = MIN(length - i, CAN2_MAX_DLC);
			memcpy(currframe->Data, _MAV_PAYLOAD(msg) + i, copylen);
			i += copylen;

			CANHEADER(currframe).IDE = CAN_ID_STD;
			CANHEADER(currframe).RTR = CAN_RTR_DATA;
			CANHEADER(currframe).DLC = copylen;
			CANHEADER(currframe).StdId = CAN_STDID_PACK(msg->compid, !FIRSTFRAME_FLAG, msg->msgid);

			if(copylen < 7) //We should append CRC
			{
				currframe->Data[copylen] = (uint8_t)(msg->checksum & 0xFF);
				currframe->Data[copylen + 1] = (uint8_t)(msg->checksum >> 8);
				CANHEADER(currframe).DLC += 2;

				break;
			}
		}

		return DIVIDE_ROUND_UP( (length + 2), CAN2_MAX_DLC) + 1; //Length counted with CRC, added one for FF

	} else {
		//TODO MAVLINK 2 support not implemented yet
	}

	return 0;
}

/**
 * @brief Parse a can frame. Does implicit logic channels separation based on compid (0-3)
 *
 * @arg frame - pointer to a frame to be parsed
 * @arg r_message - pointer to a message location where a parsing result would be written
 * @arg r_mavlink_status - pointer to a status structure
 *
 * @return A parsing status
 */
MAVLINK_HELPER uint8_t canmavlink_parse_frame(CANMAVLINK_RX_FRAME_T * frame, mavlink_message_t* r_message, mavlink_status_t* r_mavlink_status)
{
	if(CANHEADER(frame).IDE != CAN_ID_STD) return MAVLINK_FRAMING_INCOMPLETE;

	uint8_t chan = CAN_STDID_COMPID(frame); // Implicit logic channel separation

	mavlink_message_t * msgbuf = mavlink_get_channel_buffer(chan);
	mavlink_status_t * msgstat = mavlink_get_channel_status(chan);
	uint8_t copylen = 0;

	if(ISFIRSTFRAME(frame)) //We should process 1st frame differently
	{
		if(CANHEADER(frame).DLC != FIRSTFRAMEDATALEN) return 0;
		copylen = CANHEADER(frame).DLC;

		msgbuf->msgid = CAN_STDID_MSGID(frame);
		msgbuf->magic = MAVLINK_STX_MAVLINK1; //FIXME maybe we should add 2.0?
		mavlink_start_checksum(msgbuf);
		msgbuf->len = frame->Data[0];
		msgbuf->seq = frame->Data[1];
		msgbuf->sysid = frame->Data[2];
		msgbuf->compid = frame->Data[3];

		msgstat->packet_idx = 0;

		msgstat->flags = MAVLINK_STATUS_FLAG_IN_MAVLINK1;
		msgbuf->incompat_flags = 0;
		msgbuf->compat_flags = 0;
		msgstat->parse_state = MAVLINK_PARSE_STATE_GOT_MSGID3;

		msgstat->msg_received = MAVLINK_FRAMING_INCOMPLETE;

	} else	// If it's a consecutive frame, just copy
	{
		copylen = MIN(msgbuf->len - msgstat->packet_idx, CANHEADER(frame).DLC); //copy only data, not CRC

		memcpy(_MAV_PAYLOAD_NON_CONST(msgbuf) + msgstat->packet_idx, frame->Data, copylen);
		msgstat->packet_idx += copylen;
	}

	for(int i = 0; i < copylen; i++) //Handle CRC for CANHEADER and data
	{
		mavlink_update_checksum(msgbuf, frame->Data[i]);
	}

	if( ISFIRSTFRAME(frame) )
				mavlink_update_checksum(msgbuf, msgbuf->msgid & 0xFF);

	if(CANHEADER(frame).DLC - copylen == 2) //We've got CRC
	{
		//Proper handling of predefined messages' properties (copied from mavlink code)
		const mavlink_msg_entry_t *e = mavlink_get_msg_entry(msgbuf->msgid);
		uint8_t crc_extra = e?e->crc_extra:0;
		mavlink_update_checksum(msgbuf, crc_extra);

		if (e && msgstat->packet_idx < e->msg_len) {
			memset(_MAV_PAYLOAD_NON_CONST(msgbuf) + msgstat->packet_idx, 0, e->msg_len - msgstat->packet_idx);
		}

		//Checking for received and calculated CRC equality
		msgbuf->ck[0] = frame->Data[copylen];
		msgbuf->ck[1] = frame->Data[copylen + 1];

		if( *(uint16_t *)msgbuf->ck != msgbuf->checksum )
		{
			msgstat->msg_received = MAVLINK_FRAMING_BAD_CRC;
		}

		else
		{
			msgstat->msg_received = MAVLINK_FRAMING_OK;
		}

		memcpy(r_message, msgbuf, sizeof(mavlink_message_t));
	}

	// Also a piece from original mavlink
	// If a message has been sucessfully decoded, check index
	if (msgstat->msg_received == MAVLINK_FRAMING_OK)
	{
		// Count all the dropped packets
		int16_t drop = msgbuf->seq - msgstat->current_rx_seq - 1;
		drop = drop > 0 ? drop:0;
		msgstat->packet_rx_drop_count += drop;
		// Set the current msg seq
		msgstat->current_rx_seq = msgbuf->seq;
		// Initial condition: If no packet has been received so far, drop count is undefined
		if (msgstat->packet_rx_success_count == 0) msgstat->packet_rx_drop_count = 0;
		// Count this packet as received
		msgstat->packet_rx_success_count++;
	}

	// Provide user info about parsing
	r_message->len = msgbuf->len; // Provide visibility on how far we are into current msg
	r_mavlink_status->parse_state = msgstat->parse_state;
	r_mavlink_status->packet_idx = msgstat->packet_idx;
	r_mavlink_status->current_rx_seq = msgstat->current_rx_seq+1;
	r_mavlink_status->packet_rx_success_count = msgstat->packet_rx_success_count;
	r_mavlink_status->packet_rx_drop_count = msgstat->parse_error;
	r_mavlink_status->flags = msgstat->flags;
	msgstat->parse_error = 0;

	if (msgstat->msg_received == MAVLINK_FRAMING_BAD_CRC) {
		/*
		  the CRC came out wrong. We now need to overwrite the
		  msg CRC with the one on the wire so that if the
		  caller decides to forward the message anyway that
		  mavlink_msg_to_send_buffer() won't overwrite the
		  checksum
		 */
		r_message->checksum = msgbuf->ck[0] | (msgbuf->ck[1]<<8);
	}

	return msgstat->msg_received;
}

#undef MIN
#ifdef THEIRMIN
#define MIN THEIRMIN
#endif

#endif //#ifndef CANMAVLINK
