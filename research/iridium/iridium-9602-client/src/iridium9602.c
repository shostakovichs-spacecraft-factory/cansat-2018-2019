/*
 * iridium9602.c
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#include "iridium9602.h"

#include <assert.h>
#include <printf.h>


//! Читает сколько есть полученных байт из приёмного буфера уарта связанного с модемом
/*! Возвращает количество прочитанных байт */
static int _read_some(ir9602_t * device, void * buffer, int buffer_size)
{
	return device->uart_read(device->rwarg, buffer, buffer_size);
}

//! Пишет сколько есть места в выходном буфере уарта связанного с модемом
/*! Возвращает количество записанных байт */
static int _write_some(ir9602_t * device, const void * buffer, int buffer_size)
{
	return device->uart_write(device->rwarg, buffer, buffer_size);
}


void ir9602_init(ir9602_t * device, ir9602_uart_read_t uart_read, ir9602_uart_write_t uart_write,
		void * rwarg
)
{
	device->uart_read = uart_read;
	device->uart_write = uart_write;
	device->rwarg = rwarg;

	device->cmd_size = 0;
	device->cmd_carret = 0;

	device->mo_msg_size = 0;
	device->mo_msg_carret = 0;

	device->mt_msg_size = 0;
	device->mt_msg_carret = 0;
}


