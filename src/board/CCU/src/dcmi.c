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

#include "zikush_config.h"

/* counters */
volatile uint8_t image_counter = 0;
volatile uint32_t frame_counter;
volatile uint32_t time_last_frame = 0;
volatile uint32_t cycle_time = 0;
volatile uint32_t time_between_next_images;
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

/* extern functions */
extern uint32_t get_boot_time_us(void);
extern void delay(unsigned msec);

/* extern variables */
extern DMA_HandleTypeDef DMA2_handle;

/* Global variables */
I2C_HandleTypeDef I2C2_handle;

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
			HAL_DMAEx_ChangeMemory(&DMA2_handle, (uint32_t) dcmi_image_buffer_8bit_1, MEMORY0);
		else if (dcmi_image_buffer_unused == 2)
			HAL_DMAEx_ChangeMemory(&DMA2_handle, (uint32_t) dcmi_image_buffer_8bit_2, MEMORY0);
		else
			HAL_DMAEx_ChangeMemory(&DMA2_handle, (uint32_t) dcmi_image_buffer_8bit_3, MEMORY0);

		int tmp_buffer = dcmi_image_buffer_memory0;
		dcmi_image_buffer_memory0 = dcmi_image_buffer_unused;
		dcmi_image_buffer_unused = tmp_buffer;
	}
	else
	{
		/* swap dcmi image buffer */
		if (dcmi_image_buffer_unused == 1)
			HAL_DMAEx_ChangeMemory(&DMA2_handle, (uint32_t) dcmi_image_buffer_8bit_1, MEMORY1);
		else if (dcmi_image_buffer_unused == 2)
			HAL_DMAEx_ChangeMemory(&DMA2_handle, (uint32_t) dcmi_image_buffer_8bit_2, MEMORY1);
		else
			HAL_DMAEx_ChangeMemory(&DMA2_handle, (uint32_t) dcmi_image_buffer_8bit_3, MEMORY1);

		int tmp_buffer = dcmi_image_buffer_memory1;
		dcmi_image_buffer_memory1 = dcmi_image_buffer_unused;
		dcmi_image_buffer_unused = tmp_buffer;
	}

	/* set next time_between_images */
	cycle_time = get_boot_time_us() - time_last_frame;
	time_last_frame = get_boot_time_us();

	if(image_counter) // image was not fetched jet
	{
		time_between_next_images = time_between_next_images + cycle_time;
	}
	else
	{
		time_between_next_images = cycle_time;
	}

	/* set new image true and increment frame counter*/
	image_counter += 1;

	return;
}

uint32_t get_time_between_images(void){
	return time_between_images;
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

	/* time between images */
	time_between_images = time_between_next_images;

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

//TODO rewrite to use canmavlink
/**
 * @brief Send calibration image with MAVLINK over USB
 *
 * @param image_buffer_fast_1 Image buffer in fast RAM
 * @param image_buffer_fast_2 Image buffer in fast RAM
 */
/*void send_calibration_image(uint8_t ** image_buffer_fast_1, uint8_t ** image_buffer_fast_2) {

	/*  transmit raw 8-bit image */
	/* TODO image is too large for this transmission protocol (too much packets), but it works */
	/*mavlink_msg_data_transmission_handshake_send(
			MAVLINK_COMM_2,
			MAVLINK_DATA_STREAM_IMG_RAW8U,
			FULL_IMAGE_SIZE * 4,
			FULL_IMAGE_ROW_SIZE * 2,
			FULL_IMAGE_COLUMN_SIZE * 2,
			FULL_IMAGE_SIZE * 4 / MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN + 1,
			MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN,
			100);

	uint16_t frame = 0;
	uint8_t image = 0;
	uint8_t frame_buffer[MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN];

	for (int i = 0; i < FULL_IMAGE_SIZE * 4; i++)
	{

		if (i % FULL_IMAGE_SIZE == 0 && i != 0)
		{
			image++;
		}

		if (i % MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN == 0 && i != 0)
		{
			mavlink_msg_encapsulated_data_send(MAVLINK_COMM_2, frame, frame_buffer);
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

	mavlink_msg_encapsulated_data_send(MAVLINK_COMM_2, frame, frame_buffer);

}*/

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
	dma_it_init();
}

/**
 * @brief Disable DCMI DMA stream
 */
void dcmi_dma_disable()
{
	/* Disable DMA2 stream 1 and DCMI interface then stop image capture */
	DMA_Cmd(DMA2_Stream1, DISABLE);
	DCMI_Cmd(DISABLE);
	DCMI_CaptureCmd(DISABLE);
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
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;

	/* TIM3 clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	/* GPIOC clock enable */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	/* GPIOC Configuration:  TIM3 CH3 (PC8)  */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* Connect TIM3 pins to AF2 */;
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);

	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = 3;
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	/* PWM1 Mode configuration: Channel3 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 2;// TIM_TimeBaseStructure.TIM_Period/2;

	TIM_OC3Init(TIM3, &TIM_OCInitStructure);

	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM3, ENABLE);

	/* TIM3 enable counter */
	TIM_Cmd(TIM3, ENABLE);
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

	I2C2_handle.Instance = I2C2;

	/* I2C DeInit */
	HAL_I2C_DeInit(&I2C2_handle);

	/* Enable the I2C peripheral */
	I2C2_handle.Init.DutyCycle = I2C_DUTYCYCLE_2;
	I2C2_handle.Init.OwnAddress1 = 0xFE;
	I2C2_handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	I2C2_handle.Init.ClockSpeed = 100000;

	I2C2_handle.Instance->CR1 |= I2C_CR1_ACK;

	HAL_I2C_Init(I2C2_handle);

	/* Initialize GPIOs for EXPOSURE and STANDBY lines of the camera */
	gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_init.Speed = GPIO_SPEED_FREQ_LOW;
	gpio_init.Pull = GPIO_NOPULL;
	gpio_init.Alternate = 0
	gpio_init.Pin = GPIO_PIN_2 | GPIO_PIN_3;

	HAL_GPIO_Init(GPIOA, gpio_init);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
}



/**
  * @brief  Configures DCMI/DMA to capture image from the mt9v034 camera.
  *
  * @param  buffer_size Buffer size in bytes
  */
void dcmi_dma_init(uint16_t buffer_size)
{
	reset_frame_counter();

	DCMI_InitTypeDef DCMI_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;

	/*** Configures the DCMI to interface with the mt9v034 camera module ***/
	/* Enable DCMI clock */
	RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_DCMI, ENABLE);

	/* DCMI configuration */
	DCMI_InitStructure.DCMI_CaptureMode = DCMI_CaptureMode_Continuous;
	DCMI_InitStructure.DCMI_SynchroMode = DCMI_SynchroMode_Hardware;
	DCMI_InitStructure.DCMI_PCKPolarity = DCMI_PCKPolarity_Falling;
	DCMI_InitStructure.DCMI_VSPolarity = DCMI_VSPolarity_Low;
	DCMI_InitStructure.DCMI_HSPolarity = DCMI_HSPolarity_Low;
	DCMI_InitStructure.DCMI_CaptureRate = DCMI_CaptureRate_All_Frame;
	DCMI_InitStructure.DCMI_ExtendedDataMode = DCMI_ExtendedDataMode_8b;

	/* Configures the DMA2 to transfer Data from DCMI */
	/* Enable DMA2 clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);

	/* DMA2 Stream1 Configuration */
	DMA_DeInit(DMA2_Stream1);

	DMA_InitStructure.DMA_Channel = DMA_Channel_1;
	DMA_InitStructure.DMA_PeripheralBaseAddr = DCMI_DR_ADDRESS;
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t) dcmi_image_buffer_8bit_1;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
	DMA_InitStructure.DMA_BufferSize = buffer_size / 4; // buffer size in date unit (word)
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

	DMA_DoubleBufferModeConfig(DMA2_Stream1,(uint32_t) dcmi_image_buffer_8bit_2, DMA_Memory_0);
	DMA_DoubleBufferModeCmd(DMA2_Stream1,ENABLE);

	/* DCMI configuration */
	DCMI_Init(&DCMI_InitStructure);

	/* DMA2 IRQ channel Configuration */
	DMA_Init(DMA2_Stream1, &DMA_InitStructure);
}
