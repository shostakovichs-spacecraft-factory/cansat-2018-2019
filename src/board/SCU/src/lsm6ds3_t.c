/*
 * lsm6ds3_t.c
 *
 *  Created on: 13 апр. 2019 г.
 *      Author: sereshotes
 */


#include "lsm6ds3.h"
//#include <stm32f4xx_hal_uart.h>

void lsm6ds3_init()
{
	/*
	UART_HandleTypeDef uartHandler;
	uartHandler.Instance = USART1;
	uartHandler.Init.BaudRate = 115200;
	uartHandler.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uartHandler.Init.Mode = UART_MODE_TX_RX;
	uartHandler.Init.OverSampling = UART_OVERSAMPLING_16;
	uartHandler.Init.Parity = UART_PARITY_NONE;
	uartHandler.Init.StopBits = UART_STOPBITS_1;
	uartHandler.Init.WordLength = UART_WORDLENGTH_8B;

	HAL_UART_Init(&uartHandler);*/

}

/*void lsm6ds3_deinit()
{
	HAL_UART_DeInit();
}*/
