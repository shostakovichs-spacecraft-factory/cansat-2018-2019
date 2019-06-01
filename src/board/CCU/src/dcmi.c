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

#include "zikush_config.h"

/* counters */
volatile uint8_t image_counter = 0;
volatile uint32_t frame_counter;
volatile uint8_t dcmi_calibration_counter = 0;

/* state variables */
volatile uint8_t dcmi_image_buffer_memory0 = 1;
volatile uint8_t dcmi_image_buffer_memory1 = 2;
volatile uint8_t dcmi_image_buffer_unused = 3;
volatile uint8_t calibration_used;
volatile uint8_t calibration_unused;
volatile uint8_t calibration_mem0;
volatile uint8_t calibration_mem1;

/* image buffers */
uint8_t dcmi_image_buffer_8bit_1[FULL_IMAGE_SIZE];
uint8_t dcmi_image_buffer_8bit_2[FULL_IMAGE_SIZE];
uint8_t dcmi_image_buffer_8bit_3[FULL_IMAGE_SIZE];

uint32_t time_between_images;
uint16_t buffer_size;

/* extern functions */
extern void delay(unsigned msec);

/* extern variables */
extern CAN_HandleTypeDef hcan;

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
	dcmi_dma_init(CCU_SPECTRUM_WIDTH * CCU_SPECTRUM_HEIGHT);
	mt9v034_context_configuration();
	dcmi_dma_enable();
}

/**
 * @brief Calibration image collection routine restart
 */
void dcmi_restart_calibration_routine(void)
{
	/* wait until we have all 4 parts of image */
	while(frame_counter < 4){}
	frame_counter = 0;
	dcmi_dma_enable();
}

/**
 * @brief Interrupt handler of DCMI
 */
void DCMI_IRQHandler(void)
{
	if(DCMI->MISR & DCMI_MIS_FRAME_MIS)
		DCMI->ICR |= DCMI_ICR_FRAME_ISC;

	return;
}

static inline uint8_t _get_current_memory_target(DMA_Stream_TypeDef * stream)
{
	return stream->CR & DMA_SxCR_CT;
}

/**
 * @brief Interrupt handler of DCMI DMA stream
 */
void DMA2_Stream1_IRQHandler(void)
{
	/* transfer completed */
	if (DMA2->LISR & DMA_LISR_TCIF1)
	{
		DMA2->LIFCR |= DMA_LIFCR_CTCIF1;
		frame_counter++;

		if (frame_counter >= 4)
		{
			dcmi_dma_disable();
			calibration_used = _get_current_memory_target(DMA2_Stream1);
			calibration_unused = dcmi_image_buffer_unused;
			calibration_mem0 = dcmi_image_buffer_memory0;
			calibration_mem1 = dcmi_image_buffer_memory1;
		}

		return;
	}

	/* transfer half completed
	 *
	 * We use three buffers and switch the buffers if dma transfer
	 * is in half state.
	 */
	if (DMA2->LISR & DMA_LISR_HTIF1)
	{
		DMA2->LIFCR |= DMA_LIFCR_CHTIF1;
	}

	dma_swap_buffers();
}

/**
 * @brief Swap DMA image buffer addresses
 */
void dma_swap_buffers(void)
{
	/* check which buffer is in use */
	if (_get_current_memory_target(DMA2_Stream1))
	{
		/* swap dcmi image buffer */
		if (dcmi_image_buffer_unused == 1)
			HAL_DMAEx_ChangeMemory(&hdma, (uint32_t) dcmi_image_buffer_8bit_1, MEMORY0);
		else if (dcmi_image_buffer_unused == 2)
			HAL_DMAEx_ChangeMemory(&hdma, (uint32_t) dcmi_image_buffer_8bit_2, MEMORY0);
		else
			HAL_DMAEx_ChangeMemory(&hdma, (uint32_t) dcmi_image_buffer_8bit_3, MEMORY0);

		int tmp_buffer = dcmi_image_buffer_memory0;
		dcmi_image_buffer_memory0 = dcmi_image_buffer_unused;
		dcmi_image_buffer_unused = tmp_buffer;
	}
	else
	{
		/* swap dcmi image buffer */
		if (dcmi_image_buffer_unused == 1)
			HAL_DMAEx_ChangeMemory(&hdma, (uint32_t) dcmi_image_buffer_8bit_1, MEMORY1);
		else if (dcmi_image_buffer_unused == 2)
			HAL_DMAEx_ChangeMemory(&hdma, (uint32_t) dcmi_image_buffer_8bit_2, MEMORY1);
		else
			HAL_DMAEx_ChangeMemory(&hdma, (uint32_t) dcmi_image_buffer_8bit_3, MEMORY1);

		int tmp_buffer = dcmi_image_buffer_memory1;
		dcmi_image_buffer_memory1 = dcmi_image_buffer_unused;
		dcmi_image_buffer_unused = tmp_buffer;
	}

	/* set new image true and increment frame counter*/
	image_counter += 1;

	return;
}

uint32_t get_frame_counter(void){
	return frame_counter;
}

/**
 * @brief Copy image to fast RAM address
 *
 * @param current_image Current image buffer
 * @param previous_image Previous image buffer
 * @param image_size Image size of the image to copy
 * @param image_step Image to wait for (if 1 no waiting)
 */
void dma_copy_image_buffers(uint8_t ** current_image, uint8_t ** previous_image, uint16_t image_size, uint8_t image_step){

	/* swap image buffers */
	uint8_t * tmp_image = *current_image;
	*current_image = *previous_image;
	*previous_image = tmp_image;

	/* wait for new image if needed */
	while(image_counter < image_step) {

	}

	image_counter = 0;

	/* copy image */
	if (dcmi_image_buffer_unused == 1)
	{
		for (uint16_t pixel = 0; pixel < image_size; pixel++)
			(*current_image)[pixel] = (uint8_t)(dcmi_image_buffer_8bit_1[pixel]);
	}
	else if (dcmi_image_buffer_unused == 2)
	{
		for (uint16_t pixel = 0; pixel < image_size; pixel++)
			(*current_image)[pixel] = (uint8_t)(dcmi_image_buffer_8bit_2[pixel]);
	}
	else
	{
		for (uint16_t pixel = 0; pixel < image_size; pixel++)
			(*current_image)[pixel] = (uint8_t)(dcmi_image_buffer_8bit_3[pixel]);
	}
}


/**
 * @brief Send calibration image with MAVLINK over USB
 *
 * @param image_buffer_fast_1 Image buffer in fast RAM
 * @param image_buffer_fast_2 Image buffer in fast RAM
 */
void send_calibration_image(uint8_t ** image_buffer_fast_1, uint8_t ** image_buffer_fast_2) {

	/*  transmit raw 8-bit image */
	/* TODO image is too large for this transmission protocol (too much packets), but it works */

	mavlink_data_transmission_handshake_t handshake = {
		.type = MAVLINK_DATA_STREAM_IMG_RAW8U,
		.size = FULL_IMAGE_SIZE * 4,
		.width = FULL_IMAGE_ROW_SIZE * 2,
		.height = FULL_IMAGE_COLUMN_SIZE * 2,
		.packets = FULL_IMAGE_SIZE * 4 / MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN + 1,
		.payload = MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN,
		.jpg_quality = 100
	};
	mavlink_encapsulated_data_t encdata = {};
	mavlink_message_t msg;
	CANMAVLINK_TX_FRAME_T canframes[34];

	mavlink_msg_data_transmission_handshake_encode(0, ZIKUSH_CCU, &msg, &handshake);
	uint8_t canframecount = canmavlink_msg_to_frames(canframes, &msg);
	for(int i = 0; i < canframecount; i++) //FIXME rewrite with IRQs
	{
		hcan.pTxMsg = canframes + i; //DELICIOUS!!
		HAL_CAN_Transmit(&hcan, 1000);
	}

	uint16_t frame = 0;
	uint8_t image = 0;
	uint8_t * frame_buffer = encdata.data;

	for (int i = 0; i < FULL_IMAGE_SIZE * 4; i++) //TODO messy, rewrite with memcpy
	{

		if (i % FULL_IMAGE_SIZE == 0 && i != 0)
		{
			image++;
		}

		if (i % MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN == 0 && i != 0)
		{
			encdata.seqnr = frame;
			mavlink_msg_encapsulated_data_encode(0, ZIKUSH_CCU, &msg, &encdata);
			canframecount = canmavlink_msg_to_frames(canframes, &msg);
			for(int i = 0; i < canframecount; i++) //FIXME rewrite with IRQs
			{
				hcan.pTxMsg = canframes + i; //DELICIOUS!!
				HAL_CAN_Transmit(&hcan, 1000);
			}

			frame++;
			delay(2);
		}

		if (image == 0 )
		{
			frame_buffer[i % MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN] = (uint8_t)(*image_buffer_fast_1)[i % FULL_IMAGE_SIZE];
		}
		else if (image == 1 )
		{
			frame_buffer[i % MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN] = (uint8_t)(*image_buffer_fast_2)[i % FULL_IMAGE_SIZE];
		}
		else if (image == 2)
		{
			if (calibration_unused == 1)
				frame_buffer[i % MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN] = dcmi_image_buffer_8bit_1[i % FULL_IMAGE_SIZE];
			else if (calibration_unused == 2)
				frame_buffer[i % MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN] = dcmi_image_buffer_8bit_2[i % FULL_IMAGE_SIZE];
			else
				frame_buffer[i % MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN] = dcmi_image_buffer_8bit_3[i % FULL_IMAGE_SIZE];
		}
		else
		{
			if (calibration_used)
			{
				if (calibration_mem0 == 1)
					frame_buffer[i % MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN] = dcmi_image_buffer_8bit_1[i % FULL_IMAGE_SIZE];
				else if (calibration_mem0 == 2)
					frame_buffer[i % MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN] = dcmi_image_buffer_8bit_2[i % FULL_IMAGE_SIZE];
				else
					frame_buffer[i % MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN] = dcmi_image_buffer_8bit_3[i % FULL_IMAGE_SIZE];
			}
			else
			{
				if (calibration_mem1 == 1)
					frame_buffer[i % MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN] = dcmi_image_buffer_8bit_1[i % FULL_IMAGE_SIZE];
				else if (calibration_mem1 == 2)
					frame_buffer[i % MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN] = dcmi_image_buffer_8bit_2[i % FULL_IMAGE_SIZE];
				else
					frame_buffer[i % MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN] = dcmi_image_buffer_8bit_3[i % FULL_IMAGE_SIZE];
			}
		}
	}

	encdata.seqnr = frame;
	mavlink_msg_encapsulated_data_encode(0, ZIKUSH_CCU, &msg, &encdata);
	canframecount = canmavlink_msg_to_frames(canframes, &msg);
	for(int i = 0; i < canframecount; i++) //FIXME rewrite with IRQs
	{
		hcan.pTxMsg = canframes + i; //DELICIOUS!!
		HAL_CAN_Transmit(&hcan, 1000);
	}
}

/**
 * @brief Initialize/Enable DCMI Interrupt
 */
void dcmi_it_init()
{
	/* Enable the DCMI global Interrupt */
	HAL_NVIC_SetPriority(DCMI_IRQn, 5, 2);
	HAL_NVIC_EnableIRQ(DCMI_IRQn);

	//Enable FRAME interrupt
	DCMI->ICR |= DCMI_ICR_FRAME_ISC;
}

/**
 * @brief Initialize/Enable DMA Interrupt
 */
void dma_it_init()
{
	/* Enable the DMA global Interrupt */
	HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 5, 2);
	HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);

	// Enable HT and TC interrupts
	DMA2_Stream1->CR |= DMA_SxCR_HTIE | DMA_SxCR_TCIE;
}

/**
 * @brief Enable DCMI DMA stream
 */
void dcmi_dma_enable()
{
	/* Enable DMA2 stream 1 and DCMI interface then start image capture */
	DMA2_Stream1->CR |= (uint32_t)DMA_SxCR_EN;
	DCMI->CR |= (uint32_t)DCMI_CR_ENABLE;
	DCMI->CR |= (uint32_t)DCMI_CR_CAPTURE;

	HAL_DMAEx_MultiBufferStart(&hdma, DCMI_DR_ADDRESS, (uint32_t) dcmi_image_buffer_8bit_1, \
			(uint32_t) dcmi_image_buffer_8bit_2, buffer_size);


	{ /* starting DCMI without even touching DMA (HAL doesn't have this, but it's mostly
			copied from HAL_DCMI_Start_DMA) */
		/* Process Locked */
		hdcmi.Lock = HAL_LOCKED;

		/* Lock the DCMI peripheral state */
		hdcmi.State = HAL_DCMI_STATE_BUSY;

		/* Enable DCMI by setting DCMIEN bit */
		__HAL_DCMI_ENABLE(&hdcmi);

		/* Configure the DCMI Mode */
		hdcmi.Instance->CR &= ~(DCMI_CR_CM);
		hdcmi.Instance->CR |=  (uint32_t)(DCMI_MODE_CONTINUOUS);

		/* Reset transfer counters value */
		hdcmi.XferCount = 0;
		hdcmi.XferTransferNumber = 0;

		/* Get the number of buffer */
		while(hdcmi.XferSize > 0xFFFFU)
		{
			hdcmi.XferSize = (hdcmi.XferSize/2U);
			hdcmi.XferCount = hdcmi.XferCount*2U;
		}

		/* Update DCMI counter  and transfer number*/
		hdcmi.XferCount = (hdcmi.XferCount - 2U);
		hdcmi.XferTransferNumber = hdcmi.XferCount;

		/* Enable Capture */
		hdcmi.Instance->CR |= DCMI_CR_CAPTURE;

		/* Release Lock */
		__HAL_UNLOCK(&hdcmi);
	}

	dma_it_init();
}

/**
 * @brief Disable DCMI DMA stream
 */
void dcmi_dma_disable()
{
	/* Disable DMA2 stream 1 and DCMI interface then stop image capture */
	DMA2_Stream1->CR &= ~( (uint32_t)DMA_SxCR_EN );
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
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
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
	TIM_OCInitStructure.OCPolarity = TIM_OCNPOLARITY_HIGH;
	TIM_OCInitStructure.OCIdleState = TIM_OCIDLESTATE_SET;
	TIM_OCInitStructure.Pulse = 2; // TIM_TimeBaseStructure.TIM_Period/2;

	HAL_TIM_PWM_ConfigChannel(&htim, &TIM_OCInitStructure, TIM_CHANNEL_3);

	/* TIM3 enable counter */
	HAL_TIM_Base_Start(TIM3);
}

/**
 * @brief HW initialization DCMI
 */
void dcmi_hw_init(void)
{
	uint16_t image_size = CCU_SPECTRUM_WIDTH * CCU_SPECTRUM_HEIGHT;
	GPIO_InitTypeDef gpio_init;

	/* Reset image buffers */
	for (int i = 0; i < image_size; i++) {
		dcmi_image_buffer_8bit_1 [i] = 0;
		dcmi_image_buffer_8bit_2 [i] = 0;
		dcmi_image_buffer_8bit_3 [i] = 0;
	}

	/*** Configures the DCMI GPIOs to interface with the OV2640 camera module ***/
	/* Enable DCMI GPIOs clocks */
	__GPIOA_CLK_ENABLE();
	__GPIOB_CLK_ENABLE();
	__GPIOC_CLK_ENABLE();
	__GPIOD_CLK_ENABLE();
	__GPIOE_CLK_ENABLE();

	/* DCMI GPIO configuration */
	gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
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
	gpio_init.Mode = GPIO_MODE_OUTPUT_OD;
	gpio_init.Pull = GPIO_NOPULL;
	gpio_init.Speed = GPIO_SPEED_FREQ_LOW;
	gpio_init.Alternate = GPIO_AF4_I2C2;
	gpio_init.Pin = GPIO_PIN_10 | GPIO_PIN_11;

	hi2c2.Instance = I2C2;

	/* I2C DeInit */
	HAL_I2C_DeInit(&hi2c2);

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
void dcmi_dma_init(uint16_t buffsize)
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
	hdma.Init.PeriphInc = DMA_PINC_ENABLE;
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
