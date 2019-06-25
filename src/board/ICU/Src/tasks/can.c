/*
 * CAN task. Handles communication over CAN
 * */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <main.h>

#include <canmavlink_hal.h>


static CAN_HandleTypeDef hcan;


void can_init();


void can_task (void *pvParameters)
{
	can_init();

	while(1)
	{

	}

	vTaskDelete(NULL);
}

void can_init()
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
	hcan.Init.Prescaler = 100;
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
