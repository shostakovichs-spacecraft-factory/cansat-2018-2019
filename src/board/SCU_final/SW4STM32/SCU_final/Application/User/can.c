/*
 * can.c
 *
 *  Created on: Jun 28, 2019
 *      Author: kirs
 */

#include "can.h"

#include "main.h"

#include <zikush_config.h>

#include "canmavlink_hal.h"

void can_init(void)
{
    mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;

    __HAL_RCC_CAN1_FORCE_RESET();
    HAL_Delay(100);
    __HAL_RCC_CAN1_RELEASE_RESET();

    hcan.Instance = CAN1;
    hcan.Init.Prescaler = HAL_RCC_GetPCLK1Freq() / PROBEWIDE_CAN_TICKRATE;
    hcan.Init.Mode = CAN_MODE_NORMAL;
    hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
    hcan.Init.TimeSeg1 = CAN_BS1_5TQ;
    hcan.Init.TimeSeg2 = CAN_BS2_2TQ;
    hcan.Init.TimeTriggeredMode = DISABLE;
    hcan.Init.AutoBusOff = DISABLE;
    hcan.Init.AutoWakeUp = DISABLE;
    hcan.Init.AutoRetransmission = DISABLE; //ENABLE;
    hcan.Init.ReceiveFifoLocked = DISABLE;
    hcan.Init.TransmitFifoPriority = DISABLE;
    HAL_StatusTypeDef rc;
    rc = HAL_CAN_Init(&hcan);
    if (rc != HAL_OK)
        Error_Handler();

    mavlink_get_channel_status(ZIKUSH_SCU)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;

    HAL_CAN_Start(&hcan);
}

void can_mavlink_send(mavlink_message_t * msg)
{
    CANMAVLINK_TX_FRAME_T frames[CANMAVLINK_MAXFRAMES];
    volatile uint8_t framecount = canmavlink_msg_to_frames(frames, msg);
    for(int i = 0; i < framecount; i++)
#include "mavlink/zikush/mavlink.h"

    {
        uint32_t mailbox;
        CANMAVLINK_TX_FRAME_T * frame = frames+i;
        HAL_CAN_AddTxMessage(&hcan, &frame->Header, frame->Data, &mailbox);

        bool pending;
        do {
            pending = HAL_CAN_IsTxMessagePending(&hcan, mailbox); //TODO consider yielding here, but notice that for proper canmavlink functionality messages should come serially
        } while(pending);

        //hcan = frames + i; //DELICIOUS!!
    }
}
