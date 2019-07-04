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

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_rcc.h"

#include <mavlink/zikush/mavlink.h>

#include <zikush_config.h>

#define TXBUFFERSIZE   	(64*64) // 4 KByte
#define RXBUFFERSIZE   	(64*64)

/* prototypes */
uint8_t usart2_tx_ringbuffer_push(const uint8_t* ch, uint16_t len);
uint8_t usart3_tx_ringbuffer_push(const uint8_t* ch, uint16_t len);
int usart2_char_available(void);
int usart3_char_available(void);
uint8_t usart2_rx_ringbuffer_pop(void);
uint8_t usart3_rx_ringbuffer_pop(void);
uint8_t usart2_rx_ringbuffer_push_from_usart(void);
uint8_t usart3_rx_ringbuffer_push_from_usart(void);
uint8_t usart2_tx_ringbuffer_pop_to_usart(void);
uint8_t usart3_tx_ringbuffer_pop_to_usart(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);
void usart_init(void);

/* fill output buffers with some asciis to start with */
uint8_t usart2_tx_buffer[TXBUFFERSIZE] = "\n\r    ____ _  ____ __  ________    ____ _       __\n\r   / __ \\ |/ / // / / ____/ /   / __ \\ |     / /\n\r  / /_/ /   / // /_/ /_  / /   / / / / | /| / / \n\r / ____/   /__  __/ __/ / /___/ /_/ /| |/ |/ /  \n\r/_/   /_/|_| /_/ /_/   /_____/\\____/ |__/|__/   \n\r                                                \n\r";
uint8_t usart2_rx_buffer[RXBUFFERSIZE] = "";
uint8_t usart3_tx_buffer[TXBUFFERSIZE] = "\n\r    ____ _  ____ __  ________    ____ _       __\n\r   / __ \\ |/ / // / / ____/ /   / __ \\ |     / /\n\r  / /_/ /   / // /_/ /_  / /   / / / / | /| / / \n\r / ____/   /__  __/ __/ / /___/ /_/ /| |/ |/ /  \n\r/_/   /_/|_| /_/ /_/   /_____/\\____/ |__/|__/   \n\r                                                \n\r";
uint8_t usart3_rx_buffer[RXBUFFERSIZE] = "";

int usart2_tx_counter_read = 0;
int usart2_tx_counter_write = 0;
int usart2_rx_counter_read = 0;
int usart2_rx_counter_write = 0;
int usart3_tx_counter_read = 0;
int usart3_tx_counter_write = 0;
int usart3_rx_counter_read = 0;
int usart3_rx_counter_write = 0;

UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

/**
  * @brief  Push mavlink message to usart2
  */
void usart2_mavlink_transmit(const mavlink_message_t * msg)
{
	uint8_t buff[MAVLINK_MAX_PACKET_LEN];
	uint16_t len = mavlink_msg_to_send_buffer(buff, msg);

	while(!usart2_tx_ringbuffer_push(buff, len))
	{
		HAL_Delay(2);
	}
}

/**
  * @brief  Push mavlink message to usart3 (for debug only)
  */
void usart3_mavlink_transmit(const mavlink_message_t * msg)
{
	uint8_t buff[MAVLINK_MAX_PACKET_LEN];
	uint16_t len = mavlink_msg_to_send_buffer(buff, msg);

	while(!usart3_tx_ringbuffer_push(buff, len))
	{
		HAL_Delay(2);
	}
}

/**
  * @brief  Push one byte to ringbuffer of USART2
  */
uint8_t usart2_tx_ringbuffer_push(const uint8_t* ch, uint16_t len)
{
	huart2.Instance->CR1 &= ~(USART_CR1_TXEIE);

	/* if there is free space in buffer */
	if ((((usart2_tx_counter_read - usart2_tx_counter_write) - 1) + TXBUFFERSIZE) % TXBUFFERSIZE > len)
	{
		uint16_t i;
		for (i = 0; i < len; i++)
		{
			usart2_tx_buffer[usart2_tx_counter_write] = ch[i];
			usart2_tx_counter_write = (usart2_tx_counter_write + 1) % TXBUFFERSIZE;
		}

		huart2.Instance->CR1 |= USART_CR1_TXEIE;
		return 1;
	}

	huart2.Instance->CR1 |= USART_CR1_TXEIE;
	return 0;
}

/**
  * @brief  Push one byte to ringbuffer of USART3
  */
uint8_t usart3_tx_ringbuffer_push(const uint8_t* ch, uint16_t len)
{
	huart3.Instance->CR1 &= ~(USART_CR1_TXEIE);

	/* if there is free space in buffer */
	if ((((usart3_tx_counter_read - usart3_tx_counter_write) - 1) + TXBUFFERSIZE) % TXBUFFERSIZE > len)
	{
		uint16_t i;
		for (i = 0; i < len; i++)
		{
			usart3_tx_buffer[usart3_tx_counter_write] = ch[i];
			usart3_tx_counter_write = (usart3_tx_counter_write + 1) % TXBUFFERSIZE;
		}

		huart3.Instance->CR1 |= USART_CR1_TXEIE;
		return 1;
	}

	huart3.Instance->CR1 |= USART_CR1_TXEIE;
	return 0;
}

/**
  * @brief  Check character availability USART2
  */
int usart2_char_available(void)
{
	return (usart2_rx_counter_read != usart2_rx_counter_write);
}

/**
  * @brief  Check character availability USART3
  */
int usart3_char_available(void)
{
	return (usart3_rx_counter_read != usart3_rx_counter_write);
}

/**
  * @brief  Pop one byte from ringbuffer of USART2
  */
uint8_t usart2_rx_ringbuffer_pop(void)
{
	huart2.Instance->CR1 &= ~(USART_CR1_RXNEIE);

	uint8_t value = usart2_rx_buffer[usart2_rx_counter_read];
	usart2_rx_counter_read = (usart2_rx_counter_read + 1) % TXBUFFERSIZE;

	huart2.Instance->CR1 |= USART_CR1_RXNEIE;
	return value;
}

/**
  * @brief  Pop one byte from ringbuffer of USART3
  */
uint8_t usart3_rx_ringbuffer_pop(void)
{
	huart3.Instance->CR1 &= ~(USART_CR1_RXNEIE);

	uint8_t value = usart3_rx_buffer[usart3_rx_counter_read];
	usart3_rx_counter_read = (usart3_rx_counter_read + 1) % TXBUFFERSIZE;

	huart3.Instance->CR1 |= USART_CR1_RXNEIE;
	return value;
}

/**
  * @brief  Copy from USART2 to ringbuffer
  */
uint8_t usart2_rx_ringbuffer_push_from_usart(void)
{
	//USART_ITConfig(USART2, USART_IT_TXE, DISABLE);
	HAL_UART_Receive(&huart2, usart2_rx_buffer + usart2_rx_counter_write, 1, 1000);
	int temp = (usart2_rx_counter_write + 1) % TXBUFFERSIZE;

	if(temp == usart2_rx_counter_read)
	{
		return 0;
	}

	usart2_rx_counter_write = temp;
	return 1;
}

/**
  * @brief  Copy from USART3 to ringbuffer
  */
uint8_t usart3_rx_ringbuffer_push_from_usart(void)
{
	//USART_ITConfig(USART3, USART_IT_TXE, DISABLE);
	HAL_UART_Receive(&huart3, usart3_rx_buffer + usart3_rx_counter_write, 1, 1000);
	int temp = (usart3_rx_counter_write + 1) % TXBUFFERSIZE;

	if(temp == usart3_rx_counter_read)
	{
		return 0;
	}

	usart3_rx_counter_write = temp;
	return 1;
}

/**
  * @brief  Copy from ringbuffer to USART2
  */
uint8_t usart2_tx_ringbuffer_pop_to_usart(void)
{
	if (usart2_tx_counter_read != usart2_tx_counter_write)
	{
		HAL_UART_Transmit(&huart2, usart2_tx_buffer + usart2_tx_counter_read, 1, 1000);
		usart2_tx_counter_read= (usart2_tx_counter_read+1) % TXBUFFERSIZE;
		return 1;
	}
	return 0;
}

/**
  * @brief  Copy from ringbuffer to USART3
  */
uint8_t usart3_tx_ringbuffer_pop_to_usart(void)
{
	if (usart3_tx_counter_read != usart3_tx_counter_write)
	{
		HAL_UART_Transmit(&huart3, usart3_tx_buffer + usart3_tx_counter_read, 1, 1000);
		usart3_tx_counter_read= (usart3_tx_counter_read+1) % TXBUFFERSIZE;
		return 1;
	}
	return 0;
}

/**
  * @brief  USART2 interrupt handler
  */
void USART2_IRQHandler(void)
{
	if(huart2.Instance->SR & USART_SR_RXNE)
	{
		if(usart2_rx_ringbuffer_push_from_usart() == 0)
		{
			/* Disable the Receive interrupt if buffer is full */
			huart2.Instance->CR1 &= ~(USART_CR1_RXNEIE);
		}
		return;
	}

	if(huart2.Instance->SR & USART_SR_TXE)
	{
		if(usart2_tx_ringbuffer_pop_to_usart() == 0)
		{
			/* Disable the Transmit interrupt if buffer is empty */
			huart2.Instance->CR1 &= ~(USART_CR1_TXEIE);
		}

		return;
	}
}

/**
  * @brief  USART3 interrupt handler
  */
void USART3_IRQHandler(void)
{
	if(huart3.Instance->SR & USART_SR_RXNE)
	{
		if(usart3_rx_ringbuffer_push_from_usart() == 0)
		{
			/* Disable the Receive interrupt if buffer is full */
			huart3.Instance->CR1 &= ~(USART_CR1_RXNEIE);
		}
		return;
	}

	if(huart3.Instance->SR & USART_SR_TXE)
	{
		if(usart3_tx_ringbuffer_pop_to_usart() == 0)
		{
			/* Disable the Transmit interrupt if buffer is empty */
			huart3.Instance->CR1 &= ~(USART_CR1_TXEIE);
		}

		return;
	}
}

/**
  * @brief  Configures USART2 and USART3 for communication
  */
void usart_init(void)
{
	/* Configures the nested vectored interrupt controller */
	NVIC_SetPriority(USART2_IRQn, 0);
	NVIC_EnableIRQ(USART2_IRQn);

	NVIC_SetPriority(USART3_IRQn, 0);
	NVIC_EnableIRQ(USART3_IRQn);

	GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable the USART clocks */
	__USART2_CLK_ENABLE();
	__USART3_CLK_ENABLE();

	/* Enable GPIO clock */
	__GPIOA_CLK_ENABLE();
	__GPIOD_CLK_ENABLE();

	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStructure.Alternate = GPIO_AF7_USART3;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Pin = GPIO_PIN_8 | GPIO_PIN_9; //Tx and Rx

	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = GPIO_PIN_5 | GPIO_PIN_6;
	GPIO_InitStructure.Alternate = GPIO_AF7_USART2;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* USARTx configured as follow:
		- BaudRate = 921600 baud
		- Word Length = 8 Bits
		- One Stop Bit
		- No parity
		- Hardware flow control disabled (RTS and CTS signals)
		- Receive and transmit enabled
	*/

	huart3.Instance = USART3;
	huart3.Init.WordLength = USART_WORDLENGTH_8B;
	huart3.Init.StopBits = USART_STOPBITS_1;
	huart3.Init.Parity = USART_PARITY_NONE;
	huart3.Init.Mode = USART_MODE_RX | USART_MODE_TX;
	huart3.Init.BaudRate = 921600;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init(&huart3);

	huart2.Instance = USART2;
	huart2.Init.WordLength = USART_WORDLENGTH_8B;
	huart2.Init.StopBits = USART_STOPBITS_1;
	huart2.Init.Parity = USART_PARITY_NONE;
	huart2.Init.Mode = USART_MODE_RX | USART_MODE_TX;
	huart2.Init.BaudRate = CCU_CBBNE_BAUDRATE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init(&huart2);

	/* Enable the Transmit interrupt: this interrupt is generated when
	* the transmit data register is empty
	*/
	USART2->CR1 |= USART_CR1_TXEIE;
	USART3->CR1 |= USART_CR1_TXEIE;

	/* Enable the Receive interrupt: this interrupt is generated when
	* the receive data register is not empty
	*/
	USART2->CR1 |= USART_CR1_RXNEIE;
	USART3->CR1 |= USART_CR1_RXNEIE;
}
