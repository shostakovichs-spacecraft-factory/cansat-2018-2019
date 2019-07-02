/*
 * CAN task. Handles communication over CAN
 * */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <main.h>

#include <canmavlink_hal.h>


static CAN_HandleTypeDef hcan;


static void MX_CAN_Init();
static void can_init();


static StaticQueue_t _rxqueue;
static CANMAVLINK_RX_FRAME_T _rxbuff[ICU_CAN_RXBUFFSIZE];
QueueHandle_t	_rxqueue_handle;


void can_task (void *pvParameters)
{
	CANMAVLINK_RX_FRAME_T receivedframe;
	mavlink_message_t msg;

	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;

	MX_CAN_Init();
	can_init();

	_rxqueue_handle = xQueueCreateStatic(ICU_CAN_RXBUFFSIZE, sizeof(CANMAVLINK_RX_FRAME_T), (uint8_t *)_rxbuff, &_rxqueue);

	while(1)
	{
		xTaskNotifyWait(0, 0, NULL, 0xFFFFFFFF);

		while( xQueueReceive(_rxqueue_handle, &receivedframe, 0) != errQUEUE_EMPTY )
		{
			static mavlink_status_t status;

			uint8_t result = canmavlink_parse_frame(&receivedframe, &msg, &status);
			global_stats.can_rx++;

			if(result == MAVLINK_FRAMING_OK)
			{
				router_route(&msg, 0);
				global_stats.can_rx_mav++;
			}
		}

		while( xQueueReceive(can_queue_handle,&msg, 0) != errQUEUE_EMPTY )
		{
			canmavlink_TX_frame_t framebuff[34];
			uint8_t framecount = canmavlink_msg_to_frames(framebuff, &msg);

			for(int i = 0; i < framecount; i++)
			{
				uint32_t mailbox;
				HAL_CAN_AddTxMessage(&hcan, &( framebuff[i].Header ), framebuff[i].Data, &mailbox);

				bool pending;
				do {
					pending = HAL_CAN_IsTxMessagePending(&hcan, mailbox); //TODO consider yielding here, but notice that for proper canmavlink functionality messages should come serially
				} while(pending);

				global_stats.can_tx++;
			}

			global_stats.can_tx_mav++;
		}
	}

	vTaskDelete(NULL);
}

static void can_init()
{
	HAL_CAN_Start(&hcan);

	CAN_FilterTypeDef filter = {
		.FilterMaskIdHigh = 0,
		.FilterMaskIdLow = 0,
		.FilterMode = CAN_FILTERMODE_IDMASK,
		.FilterActivation = CAN_FILTER_ENABLE,
		.FilterFIFOAssignment = CAN_FILTER_FIFO0,
		.FilterScale = CAN_FILTERSCALE_16BIT,
		.FilterBank = 0,
		.SlaveStartFilterBank = 14,
	};

	HAL_CAN_ConfigFilter(&hcan, &filter);

	hcan.Instance->IER |= CAN_IER_FMPIE0;
	hcan.Instance->IER |= CAN_IER_FOVIE0;
}

/**
  * @brief This function handles USB low priority or CAN RX0 interrupts.
  */
void USB_LP_CAN1_RX0_IRQHandler(void)
{
	CANMAVLINK_RX_FRAME_T receivedframe;
	BaseType_t callcontextswitch = false;

	if(hcan.Instance->RF0R & CAN_RF0R_FOVR0) //Handling overrun condition
		hcan.Instance->RF0R |= CAN_RF0R_RFOM0;

	uint8_t filllevel = hcan.Instance->RF0R & CAN_RF0R_FMP0;
	for(uint8_t i = 0; i < filllevel; i++)
	{
		if( HAL_CAN_GetRxMessage(&hcan, CAN_RX_FIFO0, &( receivedframe.Header ), receivedframe.Data) != HAL_OK)
			continue;

		xQueueSendToBackFromISR(_rxqueue_handle, &receivedframe, &callcontextswitch);
	}

	xTaskNotifyFromISR(can_task_handle, 0, eNoAction, &callcontextswitch);

	portEND_SWITCHING_ISR(callcontextswitch);
}

//Those functions has been fetched from CubeMX generated code
/**
  * @brief CAN Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN_Init(void)
{
	hcan.Instance = CAN1;
	hcan.Init.Prescaler = HAL_RCC_GetPCLK1Freq() / PROBEWIDE_CAN_TICKRATE;
	hcan.Init.Mode = CAN_MODE_NORMAL;
	hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
	hcan.Init.TimeSeg1 = CAN_BS1_5TQ;
	hcan.Init.TimeSeg2 = CAN_BS2_2TQ;
	hcan.Init.TimeTriggeredMode = DISABLE;
	hcan.Init.AutoBusOff = DISABLE;
	hcan.Init.AutoWakeUp = DISABLE;
	hcan.Init.AutoRetransmission = DISABLE;
	hcan.Init.ReceiveFifoLocked = DISABLE;
	hcan.Init.TransmitFifoPriority = DISABLE;
	if (HAL_CAN_Init(&hcan) != HAL_OK)
	{
		Error_Handler();
	}
}
