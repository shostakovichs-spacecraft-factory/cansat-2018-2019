#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_can.h"

#include <mavlink/zikush/mavlink.h>
#include "canmavlink.h"

volatile uint32_t msTicks;

void SysTick_Handler (void)
{
  msTicks++;
}

//-------------------------------
void Delay(uint32_t dlyTicks)
{
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks);
}

int main(int argc, char* argv[])
{
	volatile int err = 0, mb = 0;

	SystemInit();
	trace_printf("System clock: %u Hz\n", SystemCoreClock);
	SysTick_Config(SystemCoreClock/1000);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	GPIO_PinRemapConfig(GPIO_Remap1_CAN1, ENABLE);

	GPIO_InitTypeDef gpio_init;
	GPIO_StructInit(&gpio_init);

	gpio_init.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_init.GPIO_Pin = GPIO_Pin_9;
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio_init);

	gpio_init.GPIO_Mode = GPIO_Mode_IPU;
	gpio_init.GPIO_Pin = GPIO_Pin_8;
	GPIO_Init(GPIOB, &gpio_init);

	CAN_InitTypeDef can_init_structure;
	CAN_StructInit(&can_init_structure);

	can_init_structure.CAN_NART = ENABLE;
	can_init_structure.CAN_SJW = CAN_SJW_1tq;
	can_init_structure.CAN_BS1 = CAN_BS1_4tq;
	can_init_structure.CAN_BS2 = CAN_BS2_4tq;
	can_init_structure.CAN_Prescaler = 16 * 25;
	can_init_structure.CAN_Mode = CAN_Mode_LoopBack;

	CAN_FilterInitTypeDef can_filter =
	{
		.CAN_FilterMaskIdHigh = 0,
		.CAN_FilterMaskIdLow = 0,
		.CAN_FilterMode = CAN_FilterMode_IdMask,
		.CAN_FilterActivation = ENABLE,
		.CAN_FilterFIFOAssignment = CAN_FilterFIFO0,
		.CAN_FilterNumber = 0
	};

	CAN_FilterInit(&can_filter);

	err = CAN_Init(CAN1, &can_init_structure);

	NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn);
	CAN1->IER |= CAN_IER_FMPIE0;

	CanTxMsg tx_msg = {
		.StdId = 0x1a1,
		.IDE = CAN_ID_STD,
		.RTR = CAN_RTR_Data,
		.DLC = 8,
		.Data = {0x13, 0x00, 'H', 'E', 'L', 'L', 'O', '\n'}
	};

	CanTxMsg canmavlink_msgs[34];
	mavlink_message_t msg;
	mavlink_heartbeat_t heartbeat =
	{
			.type = MAV_TYPE_CAMERA,
			.autopilot = MAV_AUTOPILOT_INVALID,
			.base_mode = MAV_MODE_FLAG_TEST_ENABLED,
			.system_status = MAV_STATE_ACTIVE
	};

	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;

	mavlink_msg_heartbeat_encode(0, ZIKUSH_CCU, &msg, &heartbeat);

	while(1)
	{

		volatile uint8_t framecount = canmavlink_msg_to_frames(canmavlink_msgs, &msg);

		for(int i = 0; i < framecount; i++)
		{
			mb = CAN_Transmit(CAN1, canmavlink_msgs + i);

			do {
				err = CAN_TransmitStatus(CAN1, mb);
			} while(err == 2);
		}

		Delay(1000);
	}
}

void USB_LP_CAN1_RX0_IRQHandler(void)
{
	volatile CanRxMsg frame;
	static volatile mavlink_message_t msg;
	static volatile mavlink_status_t status;
	volatile mavlink_heartbeat_t heartbeat;

	CAN_Receive(CAN1, 0, &frame);

	volatile uint8_t result = canmavlink_parse_frame(&frame, &msg, &status);

	if(result == MAVLINK_FRAMING_OK)
		mavlink_msg_heartbeat_decode(&msg, &heartbeat);

	return;
}
