/*
 * my_debug.c
 *
 *  Created on: 2 июл. 2019 г.
 *      Author: sereshotes
 */

#include "my_debug.h"
#include <stdio.h>
#include <stdarg.h>
#include <diag/Trace.h>
#include <stm32f4xx_hal.h>

static UART_HandleTypeDef debug_huart;
void my_debug_init()
{
	debug_huart.Instance = USART1;
	debug_huart.Init.BaudRate = 115200;
	debug_huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	debug_huart.Init.Mode = UART_MODE_TX_RX;
	debug_huart.Init.OverSampling = UART_OVERSAMPLING_16;
	debug_huart.Init.Parity = UART_PARITY_NONE;
	debug_huart.Init.StopBits = UART_STOPBITS_1;
	debug_huart.Init.WordLength = UART_WORDLENGTH_8B;


	HAL_UART_Init(&debug_huart);
}
#ifdef DEBUG
void my_debug(const char *fmt, ...)
{
	char str[200];
	va_list param;
	va_start(param, fmt);
	int count = vsprintf(str, fmt, param);

	HAL_UART_Transmit(&debug_huart, (uint8_t*)str, count, 100);
	//trace_printf("%s", str);
}
#else
void my_debug()
{

}
#endif



