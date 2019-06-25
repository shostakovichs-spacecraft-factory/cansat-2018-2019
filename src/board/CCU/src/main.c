// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "diag/Trace.h"

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_can.h>

#include <dcmi.h>
#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>
#include <usart.h>

#include "zikush_config.h"

/* coprocessor control register (fpu) */
#ifndef SCB_CPACR
#define SCB_CPACR (*((uint32_t*) (((0xE000E000UL) + 0x0D00UL) + 0x088)))
#endif

// ----- main() ---------------------------------------------------------------
// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

uint16_t spectrum_processing_y_start = CCU_SPECTRUM_Y_START,\
		spectrum_processing_y_end	= CCU_SPECTRUM_Y_END,\
		spectrum_processing_x_start = CCU_SPECTRUM_X_START,\
		spectrum_processing_x_end	= CCU_SPECTRUM_X_END;

enum {
	SPRQ_NO = 0,
	SPQR_DATAONLY = 1,
	SPRQ_FULL = 2
} spectrum_request = SPRQ_NO;

bool nadircam_request = false;
bool zenithcam_request = false;

CAN_HandleTypeDef hcan;

void spectrum_take(bool sendphoto)
{
	dcmi_restart_calibration_routine();

	/* waiting for all parts */
	while(get_frame_counter() < 1){}

	if(sendphoto)
		send_spectrum_photo();

	//send_spectrum_data();
}

void can_init()
{
	__GPIOA_CLK_ENABLE();
	__CAN1_CLK_ENABLE();

	GPIO_InitTypeDef gpio_init =
	{
		.Mode = GPIO_MODE_AF_OD,
		.Alternate = GPIO_AF9_CAN1,
		.Pull = GPIO_NOPULL,
		.Speed = GPIO_SPEED_LOW,
		.Pin = GPIO_PIN_12 | GPIO_PIN_11
	};
	HAL_GPIO_Init(GPIOA, &gpio_init);

	hcan.Instance = CAN1;
	hcan.Init.Prescaler = 466;
	hcan.Init.Mode = CAN_MODE_NORMAL;
	hcan.Init.SJW = CAN_SJW_1TQ;
	hcan.Init.BS1 = CAN_BS1_5TQ;
	hcan.Init.BS2 = CAN_BS2_2TQ;
	hcan.Init.TTCM = DISABLE;
	hcan.Init.ABOM = DISABLE;
	hcan.Init.AWUM = DISABLE;
	hcan.Init.NART = ENABLE;
	hcan.Init.RFLM = DISABLE;
	hcan.Init.TXFP = DISABLE;
	HAL_CAN_Init(&hcan);

	CAN_FilterConfTypeDef filter = {
		.FilterMaskIdHigh = 0,
		.FilterMaskIdLow = 0,
		.FilterMode = CAN_FILTERMODE_IDMASK,
		.FilterActivation = ENABLE,
		.FilterFIFOAssignment = CAN_FILTER_FIFO0,
		.FilterScale = CAN_FILTERSCALE_16BIT,
		.BankNumber = 0
	};

	HAL_CAN_ConfigFilter(&hcan, &filter);

	NVIC_EnableIRQ(CAN1_RX0_IRQn);
	hcan.Instance->IER |= CAN_IER_FMPIE0;
}

void can_mavlink_transmit(mavlink_message_t * msg)
{
	CANMAVLINK_TX_FRAME_T canframes[34];
	uint8_t canframecount = canmavlink_msg_to_frames(canframes, msg);
	for(int i = 0; i < canframecount; i++) //FIXME rewrite with IRQs
	{
		hcan.pTxMsg = canframes + i; //DELICIOUS!!
		HAL_CAN_Transmit(&hcan, 100);
	}
}

void USB_LP_CAN1_RX0_IRQHandler(void)
{
  /* USER CODE BEGIN USB_LP_CAN1_RX0_IRQn 0 */
	CANMAVLINK_RX_FRAME_T frame;
	static mavlink_message_t msg;
	static mavlink_status_t status;
	static mavlink_zikush_cmd_take_photo_t cmd_photo;
	static mavlink_zikush_cmd_take_spectrum_t cmd_spectrum;

	hcan.pRxMsg = &frame;
	HAL_CAN_Receive(&hcan, 0, 0);

	volatile uint8_t result = canmavlink_parse_frame(&frame, &msg, &status);

	if(result == MAVLINK_FRAMING_OK)
	{
		switch(msg.msgid)
		{
		case MAVLINK_MSG_ID_ZIKUSH_CMD_TAKE_SPECTRUM:
			if(!spectrum_request)
			{
				mavlink_msg_zikush_cmd_take_spectrum_decode(&msg, &cmd_spectrum);

				if(cmd_spectrum.send_picture)
					spectrum_request = SPRQ_FULL;
				else
					spectrum_request = SPQR_DATAONLY;

				spectrum_processing_x_start = cmd_spectrum.x_start;
				spectrum_processing_x_end = cmd_spectrum.x_end;
				spectrum_processing_y_start = cmd_spectrum.y_start;
				spectrum_processing_y_end = cmd_spectrum.y_end;

			} //else TODO maybe we should send some info msg?

			break;

		case MAVLINK_MSG_ID_ZIKUSH_CMD_TAKE_PHOTO:
			mavlink_msg_zikush_cmd_take_photo_decode(&msg, &cmd_photo);

			if(cmd_photo.camid == ZIKUSH_CAM_NADIR)
				nadircam_request = true;

			else if(cmd_photo.camid == ZIKUSH_CAM_ZENITH)
				zenithcam_request = true;

			break;

		default:
			break;
		}
	}

	return;
  /* USER CODE END USB_LP_CAN1_RX0_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan);
  /* USER CODE BEGIN USB_LP_CAN1_RX0_IRQn 1 */

  /* USER CODE END USB_LP_CAN1_RX0_IRQn 1 */
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}

int main(int argc, char* argv[])
{
	/* enable FPU on Cortex-M4F core */
	SCB_CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2)); /* set CP10 Full Access and set CP11 Full Access */

	SysTick_Config(SystemCoreClock / 1000);

#ifdef CCU_TESTMODE
	usart_init();
#endif

	enable_image_capture();
	can_init();

	while(true)
	{
		if(spectrum_request)
		{
			spectrum_take(spectrum_request == SPRQ_FULL);
			spectrum_request = SPRQ_NO;
		}

		//TODO add cam requests processing


		//HAL_Delay(200); //TODO Add transition into true sleep mode?

#ifdef CCU_TESTMODE
		spectrum_request = SPRQ_FULL;
		//HAL_Delay(800);
#endif
	}
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
