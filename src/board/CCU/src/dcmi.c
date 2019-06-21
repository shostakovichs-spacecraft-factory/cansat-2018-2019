/****************************************************************************
 *
 *   Copyright (C) 2013 PX4 Development Team. All rights reserved.
 *   Author: Laurens Mackay <mackayl@student.ethz.ch>
 *   		 Dominik Honegger <dominik.honegger@inf.ethz.ch>
 *   		 Petri Tanskanen <tpetri@inf.ethz.ch>
 *   		 Samuel Zihlmann <samuezih@ee.ethz.ch>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#include "dcmi.h"

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_i2c.h"
#include "stm32f4xx_hal_dcmi.h"
#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_tim.h"
#include "stm32f4xx_hal_can.h"

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>
#include <usart.h>
#include <zikush_config.h>

#define MIN(a, b) ((a)<(b)?(a):(b))

void can_mavlink_transmit(mavlink_message_t * msg);

/* counters */
volatile uint8_t image_counter = 0;
volatile uint32_t frame_counter;
volatile uint8_t dcmi_calibration_counter = 0;

/* image buffers */
uint8_t dcmi_image_buffer_8bit[FULL_IMAGE_SIZE * 4];

uint32_t buffer_size;

/* extern variables */
extern CAN_HandleTypeDef hcan;

extern uint16_t spectrum_processing_y_start, spectrum_processing_y_end, spectrum_processing_x_start, spectrum_processing_x_end;

/* Global variables */
I2C_HandleTypeDef hi2c2;
DCMI_HandleTypeDef hdcmi;
DMA_HandleTypeDef hdma;
/**
 * @brief Initialize DCMI DMA and enable image capturing
 */
void enable_image_capture(void)
{
	dcmi_clock_init();
	dcmi_hw_init();
	dcmi_dma_init(FULL_IMAGE_ROW_SIZE * FULL_IMAGE_COLUMN_SIZE * 4);
	mt9v034_context_configuration();
	dcmi_dma_enable();
}

/**
 * @brief Calibration image collection routine restart
 */
void dcmi_restart_calibration_routine(void)
{
	/* wait until we have an image */
	while(frame_counter < 1){}
	frame_counter = 0;
	dcmi_dma_enable();
}

/**
 * @brief Interrupt handler of DCMI DMA stream
 */
void DMA2_Stream1_IRQHandler(void)
{
	/* transfer completed - we've received a frame!*/
	if (DMA2->LISR & DMA_LISR_TCIF1)
	{
		DMA2->LIFCR |= DMA_LIFCR_CTCIF1;
		frame_counter++;
		dcmi_dma_disable();
	}
}

uint32_t get_frame_counter(void){
	return frame_counter;
}

/**
 * @brief Send spectrum image with MAVLINK over CAN
 *
 * @param image_buffer_fast_1 Image buffer in fast RAM
 * @param image_buffer_fast_2 Image buffer in fast RAM
 */
void send_spectrum_photo() {

	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1; //We do it there, cause channel status is a static variable, thus not system-wide

	/*  transmit raw 8-bit image */
	/* TODO image is too large for this transmission protocol (too much packets), but it works */
	/*static int debcounter = 0;
	if(debcounter < 5)
	{
		//memcpy(dcmi_image_buffer_8bit + (CCU_SPECTRUM_WIDTH * 62), dcmi_image_buffer_8bit + (CCU_SPECTRUM_WIDTH * 60), CCU_SPECTRUM_WIDTH);
		memset(dcmi_image_buffer_8bit + (CCU_SPECTRUM_WIDTH * 60), 0, CCU_SPECTRUM_WIDTH);
		memcpy(dcmi_image_buffer_8bit + (CCU_SPECTRUM_WIDTH * 62), dcmi_image_buffer_8bit + (CCU_SPECTRUM_WIDTH * 60), CCU_SPECTRUM_WIDTH);
	}
	debcounter++;
	debcounter %= 10;*/

	mavlink_data_transmission_handshake_t handshake = {
		.type = MAVLINK_DATA_STREAM_IMG_RAW8U,
		.size = FULL_IMAGE_SIZE * 4,
		.width = FULL_IMAGE_ROW_SIZE * 2,
		.height = FULL_IMAGE_COLUMN_SIZE * 2,
		.packets = FULL_IMAGE_SIZE * 4 / MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN + 1,
		.payload = MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN,
		.jpg_quality = 100
	};

	mavlink_zikush_picture_header_t picture_header = {
		.camid = ZIKUSH_CAM_SPECTRUM,
		.size = FULL_IMAGE_SIZE * 4,
		.packets = FULL_IMAGE_SIZE * 4 / MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN + 1,
		.y_upleft_crop = spectrum_processing_y_start, //TODO what for?
		.time_boot_ms = HAL_GetTick(),
	};

	mavlink_encapsulated_data_t encdata = {};
	mavlink_message_t msg;


	/*We send both data_transmission_handshake and zikush_picture_header so it can be received by spectrum_viewer,
	 * 	QGriund control and Grain MCC
	 */
	mavlink_msg_data_transmission_handshake_encode(0, ZIKUSH_CCU, &msg, &handshake);
	can_mavlink_transmit(&msg);
	usart3_mavlink_transmit(&msg);

	mavlink_msg_zikush_picture_header_encode(0, ZIKUSH_CCU, &msg, &picture_header);
	can_mavlink_transmit(&msg);
	usart3_mavlink_transmit(&msg);

	uint16_t frame = 0;
	uint8_t * frame_buffer = encdata.data;

	for(uint32_t i = 0; i < (FULL_IMAGE_SIZE * 4); i += MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN)
	{
		int copylen = MIN(MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN, FULL_IMAGE_SIZE - i);
		memcpy(frame_buffer, dcmi_image_buffer_8bit + i, copylen);

		encdata.seqnr = frame;
		mavlink_msg_encapsulated_data_encode(0, ZIKUSH_CCU, &msg, &encdata);
		can_mavlink_transmit(&msg);
		usart3_mavlink_transmit(&msg);

		HAL_Delay(500);

		frame++;
	}
}

/**
 * @brief Send spectrum data with MAVLINK over CAN
 *
 * @param image_buffer_fast_1 Image buffer in fast RAM
 * @param image_buffer_fast_2 Image buffer in fast RAM
 */
/*void send_spectrum_data(uint8_t * image_buffer_fast_1, uint8_t * image_buffer_fast_2)
{
	uint8_t * rowdata;
	mavlink_zikush_spectrum_intensity_header_t spectrum_header = {
		.size =	(spectrum_processing_y_end - spectrum_processing_y_start) * 2,
		.packets = (spectrum_processing_y_end - spectrum_processing_y_start) / \
					MAVLINK_MSG_ZIKUSH_SPECTRUM_INTENSITY_ENCAPSULATED_DATA_FIELD_DATA_LEN + 1, //FIXME correct ceiling?
		.y_upleft_crop = spectrum_processing_y_start,
		.time_boot_ms = HAL_GetTick()
	};
	mavlink_zikush_spectrum_intensity_encapsulated_data_t encdata = {
			.seqnr = 0
	};
	mavlink_message_t msg;
	CANMAVLINK_TX_FRAME_T canframes[34];


	mavlink_msg_zikush_spectrum_intensity_header_encode(0, ZIKUSH_CCU, &msg, &spectrum_header);
	uint8_t canframecount = canmavlink_msg_to_frames(canframes, &msg);
	for(int i = 0; i < canframecount; i++) //FIXME rewrite with IRQs
	{
		hcan.pTxMsg = canframes + i; //DELICIOUS!!
		HAL_CAN_Transmit(&hcan, 1000);
	}


	//iterating over rows
	for(int row = spectrum_processing_y_start; row < spectrum_processing_y_end; row++)
	{
		int relrow = row - spectrum_processing_y_start;

		//Selecting one of the many buffers in which the current row is placed
		if(row < FULL_IMAGE_COLUMN_SIZE / 2)
			rowdata = image_buffer_fast_1 + row * FULL_IMAGE_ROW_SIZE;

		else if(row < FULL_IMAGE_COLUMN_SIZE)
			rowdata = image_buffer_fast_2 + (row - FULL_IMAGE_COLUMN_SIZE / 2) * FULL_IMAGE_ROW_SIZE;

		else if(row < (FULL_IMAGE_COLUMN_SIZE + FULL_IMAGE_COLUMN_SIZE / 2) )
		{
			uint16_t shift = (row - FULL_IMAGE_COLUMN_SIZE) * FULL_IMAGE_ROW_SIZE;

			if (calibration_unused == 1)
				rowdata = dcmi_image_buffer_8bit_1 + shift;
			else if (calibration_unused == 2)
				rowdata = dcmi_image_buffer_8bit_2 + shift;
			else
				rowdata = dcmi_image_buffer_8bit_3 + shift;
		}

		else
		{
			uint16_t shift = (row - (FULL_IMAGE_COLUMN_SIZE + FULL_IMAGE_COLUMN_SIZE / 2) ) * FULL_IMAGE_ROW_SIZE;

			if(calibration_used)
			{
				if (calibration_mem0 == 1)
					rowdata = dcmi_image_buffer_8bit_1 + shift;
				else if (calibration_mem0)
					rowdata = dcmi_image_buffer_8bit_2 + shift;
				else
					rowdata = dcmi_image_buffer_8bit_3 + shift;
			}

			else
			{
				if (calibration_mem1 == 1 == 1)
					rowdata = dcmi_image_buffer_8bit_1 + shift;
				else if (calibration_mem1 == 2)
					rowdata = dcmi_image_buffer_8bit_2 + shift;
				else
					rowdata = dcmi_image_buffer_8bit_3 + shift;
			}
		}


		encdata.data[row % MAVLINK_MSG_ZIKUSH_SPECTRUM_INTENSITY_ENCAPSULATED_DATA_FIELD_DATA_LEN] = 0;
		for(int col = spectrum_processing_x_start; col < spectrum_processing_x_end; col++)
		{
			encdata.data[relrow % MAVLINK_MSG_ZIKUSH_SPECTRUM_INTENSITY_ENCAPSULATED_DATA_FIELD_DATA_LEN] += rowdata[col];
		}

		//send packet if it's full or if it is the last row
		if( ( (relrow + 1) % MAVLINK_MSG_ZIKUSH_SPECTRUM_INTENSITY_ENCAPSULATED_DATA_FIELD_DATA_LEN == 0 && row != 0) \
				|| row == (spectrum_processing_y_end - 1))
		{
			mavlink_msg_zikush_spectrum_intensity_encapsulated_data_encode(0, ZIKUSH_CCU, &msg, &encdata);
			canframecount = canmavlink_msg_to_frames(canframes, &msg);
			for(int i = 0; i < canframecount; i++) //FIXME rewrite with IRQs
			{
				hcan.pTxMsg = canframes + i; //DELICIOUS!!
				HAL_CAN_Transmit(&hcan, 1000);
			}

			encdata.seqnr++;
		}
	}
}*/

/**
 * @brief Enable DCMI DMA stream
 */
void dcmi_dma_enable()
{
	/* Enable DMA2 stream 1 and DCMI interface then start image capture */
	HAL_DMA_Start(&hdma, DCMI_DR_ADDRESS, dcmi_image_buffer_8bit, buffer_size);

	DCMI->CR &= ~(DCMI_CR_CM);
	DCMI->CR |= (DCMI_MODE_CONTINUOUS);
	DCMI->CR |= DCMI_CR_ENABLE;
	DCMI->CR |= DCMI_CR_CAPTURE;

	/* Enable the DMA global Interrupt */
	HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);

	// Enable HT and TC interrupts
	DMA2_Stream1->CR |= DMA_SxCR_HTIE | DMA_SxCR_TCIE;

	/*uint32_t dmadump[] = {DMA2_Stream1->CR, DMA2_Stream1->NDTR, DMA2_Stream1->PAR, DMA2_Stream1->M0AR, DMA2_Stream1->M1AR, DMA2_Stream1->FCR};
	usart3_tx_ringbuffer_push(dmadump, 24);

	uint32_t dcmidump[] = {DCMI->CR, DCMI->SR, DCMI->RISR, DCMI->IER, DCMI->MISR};
	usart3_tx_ringbuffer_push(dcmidump, 20);*/
}

/**
 * @brief Disable DCMI DMA stream
 */
void dcmi_dma_disable()
{
	HAL_NVIC_DisableIRQ(DMA2_Stream1_IRQn);

	/* Disable DMA2 stream 1 and DCMI interface then stop image capture */
	HAL_DMA_Abort(&hdma);

	DCMI->CR &= ~( (uint32_t)DCMI_CR_ENABLE );
	DCMI->CR &= ~( (uint32_t)DCMI_CR_CAPTURE );
}

void reset_frame_counter()
{
	frame_counter = 0;
}

/**
 * @brief HW initialization of DCMI clock
 */
void dcmi_clock_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_HandleTypeDef htim;
	TIM_OC_InitTypeDef TIM_OCInitStructure;

	/* TIM3 & GPIOC clock enable */
	__TIM3_CLK_ENABLE();
	__GPIOC_CLK_ENABLE();

	/* GPIOC Configuration:  TIM3 CH3 (PC8)  */
	GPIO_InitStructure.Pin = GPIO_PIN_8;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Alternate = GPIO_AF2_TIM3;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* Time base configuration */
	htim.Instance = TIM3;
	htim.Channel = TIM_CHANNEL_3;
	htim.Init.Period = 3;
	htim.Init.Prescaler = 0;
	htim.Init.ClockDivision = 0;
	htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&htim);

	/* PWM1 Mode configuration: Channel3 */
	TIM_OCInitStructure.OCMode = TIM_OCMODE_PWM1;
	TIM_OCInitStructure.OCPolarity = TIM_OCPOLARITY_HIGH;
	TIM_OCInitStructure.OCIdleState = TIM_OCIDLESTATE_SET;
	TIM_OCInitStructure.Pulse = 2; // TIM_TimeBaseStructure.TIM_Period/2;
	TIM_OCInitStructure.OCFastMode = TIM_OCFAST_DISABLE;

	HAL_TIM_PWM_ConfigChannel(&htim, &TIM_OCInitStructure, TIM_CHANNEL_3);
	TIM3->CR1 |= TIM_CR1_ARPE;

	/* TIM3 enable counter */
	//HAL_TIM_Base_Start(&htim);
	HAL_TIM_PWM_Start(&htim, TIM_CHANNEL_3);
}

/**
 * @brief HW initialization DCMI
 */
void dcmi_hw_init(void)
{
	uint16_t image_size = FULL_IMAGE_ROW_SIZE * FULL_IMAGE_COLUMN_SIZE * 4;
	GPIO_InitTypeDef gpio_init;

	/* Reset image buffers */
	memset(dcmi_image_buffer_8bit, 0, image_size);

	/*** Configures the DCMI GPIOs to interface with the OV2640 camera module ***/
	/* Enable DCMI GPIOs clocks */
	__GPIOA_CLK_ENABLE();
	__GPIOB_CLK_ENABLE();
	__GPIOC_CLK_ENABLE();
	__GPIOD_CLK_ENABLE();
	__GPIOE_CLK_ENABLE();

	/* DCMI GPIO configuration */
	gpio_init.Mode = GPIO_MODE_AF_PP;
	gpio_init.Pull = GPIO_PULLUP;
	gpio_init.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	gpio_init.Alternate = GPIO_AF13_DCMI;

	gpio_init.Pin = GPIO_PIN_4 | GPIO_PIN_6;
	HAL_GPIO_Init(GPIOA, &gpio_init);

	gpio_init.Pin = GPIO_PIN_6 | GPIO_PIN_7;
	HAL_GPIO_Init(GPIOB, &gpio_init);

	gpio_init.Pin = GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_10 | GPIO_PIN_12;
	HAL_GPIO_Init(GPIOC, &gpio_init);

	gpio_init.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6;
	HAL_GPIO_Init(GPIOE, &gpio_init);

	/* I2C2 clock enable */
	__I2C2_CLK_ENABLE();

	/* Configure I2C2 GPIOs */
	gpio_init.Mode = GPIO_MODE_AF_OD;
	gpio_init.Pull = GPIO_NOPULL;
	gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
	gpio_init.Alternate = GPIO_AF4_I2C2;
	gpio_init.Pin = GPIO_PIN_10 | GPIO_PIN_11;
	HAL_GPIO_Init(GPIOB, &gpio_init);

	hi2c2.Instance = I2C2;

	/* I2C DeInit */
	//HAL_I2C_DeInit(&hi2c2);
	__HAL_RCC_I2C2_FORCE_RESET();
	__HAL_RCC_I2C2_RELEASE_RESET();

	/* Enable the I2C peripheral */
	hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c2.Init.OwnAddress1 = 0xFE;
	hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c2.Init.ClockSpeed = 100000;

	hi2c2.Instance->CR1 |= I2C_CR1_ACK;

	HAL_I2C_Init(&hi2c2);

	/* Initialize GPIOs for EXPOSURE and STANDBY lines of the camera */
	gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_init.Speed = GPIO_SPEED_FREQ_LOW;
	gpio_init.Pull = GPIO_NOPULL;
	gpio_init.Pin = GPIO_PIN_2 | GPIO_PIN_3;

	HAL_GPIO_Init(GPIOA, &gpio_init);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
}



/**
  * @brief  Configures DCMI/DMA to capture image from the mt9v034 camera.
  *
  * @param  buffer_size Buffer size in bytes
  */
void dcmi_dma_init(uint32_t buffsize)
{
	reset_frame_counter();

	/*** Configures the DCMI to interface with the mt9v034 camera module ***/
	/* Enable DCMI clock */
	__DCMI_CLK_ENABLE();

	/* DCMI configuration */
	hdcmi.Instance = DCMI;

	hdcmi.Init.SynchroMode = DCMI_SYNCHRO_HARDWARE;
	hdcmi.Init.PCKPolarity = DCMI_PCKPOLARITY_FALLING;
	hdcmi.Init.VSPolarity = DCMI_VSPOLARITY_LOW;
	hdcmi.Init.HSPolarity = DCMI_HSPOLARITY_LOW;
	hdcmi.Init.CaptureRate = DCMI_CR_ALL_FRAME;
	hdcmi.Init.ExtendedDataMode = DCMI_EXTEND_DATA_8B;

	HAL_DCMI_Init(&hdcmi);

	/* Configures the DMA2 to transfer Data from DCMI */
	/* Enable DMA2 clock */
	__DMA2_CLK_ENABLE();

	/* DMA2 Stream1 Configuration */
	hdma.Instance = DMA2_Stream1;
	hdma.Init.Channel = DMA_CHANNEL_1;

	HAL_DMA_DeInit(&hdma);

	hdma.Init.Direction = DMA_PERIPH_TO_MEMORY;
	hdma.Init.PeriphInc = DMA_PINC_DISABLE;
	hdma.Init.MemInc = DMA_MINC_ENABLE;
	hdma.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
	hdma.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
	hdma.Init.Mode = DMA_CIRCULAR;
	hdma.Init.Priority = DMA_PRIORITY_HIGH;
	hdma.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	hdma.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
	hdma.Init.MemBurst = DMA_MBURST_SINGLE;
	hdma.Init.PeriphBurst = DMA_PBURST_SINGLE;

	buffer_size = buffsize / 4; // buffer size in date unit (word)

	HAL_DMA_Init(&hdma);
}
