// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "diag/Trace.h"

#include <stm32f4xx_hal_can.h>

#include <dcmi.h>

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>

#include "zikush_config.h"

/* coprocessor control register (fpu) */
#ifndef SCB_CPACR
#define SCB_CPACR (*((uint32_t*) (((0xE000E000UL) + 0x0D00UL) + 0x088)))
#endif

/* fast image buffers for calculations */
uint8_t image_buffer_8bit_1[FULL_IMAGE_SIZE] __attribute__((section(".ccm")));
uint8_t image_buffer_8bit_2[FULL_IMAGE_SIZE] __attribute__((section(".ccm")));
uint8_t * current_image = image_buffer_8bit_1;
uint8_t * previous_image = image_buffer_8bit_2;
uint8_t buffer_reset_needed;

// ----- main() ---------------------------------------------------------------
// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

uint8_t spectrum_photo[CCU_SPECTRUM_WIDTH * CCU_SPECTRUM_HEIGHT];
bool spectrum_photo_ready;

uint8_t spectrum_processing_y_start = CCU_SPECTRUM_Y_START,\
		spectrum_processing_y_end	= CCU_SPECTRUM_Y_END,\
		spectrum_processing_x_start = CCU_SPECTRUM_X_START,\
		spectrum_processing_x_end	= CCU_SPECTRUM_X_END;

enum {
	SPRQ_NO = 0,
	SPQR_DATAONLY = 1,
	SPRQ_FULL = 2
} spectrum_request = SPRQ_NO;

enum {
	CAMRQ_NO = 0,
	CAMQR_NADIR = 1,
	CAMRQ_ZENITH = 2
} cam_request = CAMRQ_NO;

void spectrum_take()
{
	dcmi_restart_calibration_routine();

	/* waiting for first quarter of image */
	while(get_frame_counter() < 2){}
	dma_copy_image_buffers(&current_image, &previous_image, FULL_IMAGE_SIZE, 1);

	/* waiting for second quarter of image */
	while(get_frame_counter() < 3){}
	dma_copy_image_buffers(&current_image, &previous_image, FULL_IMAGE_SIZE, 1);

	/* waiting for all image parts */
	while(get_frame_counter() < 4){}

	send_calibration_image(&previous_image, &current_image);


}

void can_init()
{
	GPIO_InitTypeDef gpio_init =
	{
		.Mode = GPIO_MODE_AF_PP,
		.Alternate = GPIO_AF9_CAN1,
		.Pull = GPIO_NOPULL,
		.Speed = GPIO_SPEED_LOW,
		.Pin = GPIO_PIN_12
	};
	HAL_GPIO_Init(GPIOA, &gpio_init);

	gpio_init.Mode = GPIO_MODE_INPUT;
	gpio_init.Pin = GPIO_PIN_11;
	HAL_GPIO_Init(GPIOA, &gpio_init);

	GPIOA->AFR[1] &= ~(0x0F << 12);
	GPIOA->AFR[1] |= GPIO_AF9_CAN1 << 12;

	GPIOA->MODER &= ~GPIO_MODER_MODER11;
	GPIOA->MODER |= GPIO_MODER_MODER11_1;

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

	HAL_CAN_Start(&hcan);

	CAN_FilterConfTypeDef filter = {
		.FilterMaskIdHigh = 0,
		.FilterMaskIdHigh = 0,
		.FilterMode = CAN_FILTERMODE_IDMASK,
		.FilterActivation = ENABLE,
		.FilterFIFOAssignment = CAN_FILTER_FIFO0,
		.FilterScale = CAN_FILTERSCALE_16BIT,
		.FilterBank = 0,
		.SlaveStartFilterBank = 14,
	};

	HAL_CAN_ConfigFilter(&hcan, &filter);

	NVIC_EnableIRQ(CAN1_RX0_IRQn);
	hcan.Instance->IER |= CAN_IER_FMPIE0;

	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;
}

void USB_LP_CAN1_RX0_IRQHandler(void)
{
  /* USER CODE BEGIN USB_LP_CAN1_RX0_IRQn 0 */
	volatile CANMAVLINK_RX_FRAME_T frame;
	static volatile mavlink_message_t msg;
	static volatile mavlink_status_t status;

	HAL_CAN_GetRxMessage(&hcan, 0, &frame, frame.Data);

	volatile uint8_t result = canmavlink_parse_frame(&frame, &msg, &status);

	if(result == MAVLINK_FRAMING_OK)
	{
		switch(msg.msgid)
		{
		case MAVLINK_MSG_ID_ZIKUSH_CMD_TAKE_SPECTRUM:
			if(!spectrum_request)
			{
				mavlink_zikush_cmd_take_spectrum_t cmd;
				mavlink_msg_zikush_cmd_take_spectrum_decode(&msg, &cmd);

				if(cmd.send_picture)
					spectrum_request = SPRQ_FULL;
				else
					spectrum_request = SPQR_DATAONLY;

			} //else TODO maybe we should send some info msg?

			break;

		case MAVLINK_MSG_ID_ZIKUSH_CMD_TAKE_PHOTO:
			mavlink_zikush_cmd_take_photo_t
			break;
		}
	}

	return;
  /* USER CODE END USB_LP_CAN1_RX0_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan);
  /* USER CODE BEGIN USB_LP_CAN1_RX0_IRQn 1 */

  /* USER CODE END USB_LP_CAN1_RX0_IRQn 1 */
}

int main(int argc, char* argv[])
{
	/* enable FPU on Cortex-M4F core */
	SCB_CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2)); /* set CP10 Full Access and set CP11 Full Access */

	enable_image_capture();
	/* init and clear fast image buffers */
	for (int i = 0; i < FULL_IMAGE_SIZE; i++)
	{
		image_buffer_8bit_1[i] = 0;
		image_buffer_8bit_2[i] = 0;
	}

	can_init();


}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
