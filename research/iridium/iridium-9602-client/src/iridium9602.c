/*
 * iridium9602.c
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#include "iridium9602.h"

#include <string.h>
#include <assert.h>
#include <printf.h>
#include <errno.h>


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


//! Контрольная сумма для протокола SBD
static uint16_t _sbd_checksum(const void * data_, int datasize)
{
	const uint8_t * data = (const uint8_t*)data_;
	uint16_t sum = 0;
	for (int i = 0; i < datasize; i++)
		sum += data[i];

	return sum;
}


static uint16_t _swap_endian(uint16_t value)
{
	return (value >> 8) | (value << 8);
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

	device->data_size = 0;
	device->data_carret = 0;

	device->state = IR9602_STATE_IDLE;
}


int ir9602_cmd_at(ir9602_t * device)
{
	if (device->state != IR9602_STATE_IDLE)
		return -EBUSY;

	device->cmd.code = IR9602_CMD_AT;
	ir9602_serialize_command(device->cmd_buffer, IR9602_CMD_BUFFER_SIZE, &device->cmd);

	device->state = IR9602_STATE_CMD;
	return 0;
}


int ir9602_cmd_sbdwb(ir9602_t * device, const void * buffer, int buffer_size)
{
	if (device->state != IR9602_STATE_IDLE)
		return -EBUSY;

	// проверяем что у нас все влезает с размером и контрольной суммой
	if (sizeof(uint16_t) + buffer_size + sizeof(uint16_t) > IR9602_DATA_BUFFER_SIZE)
		return -EOVERFLOW;

	// копируем само сообщение
	memcpy(
			device->data_buffer,
			buffer,
			buffer_size
	);

	// и затем контрольную сумму
	uint16_t checksum_word = _swap_endian(_sbd_checksum(buffer, buffer_size));
	memcpy(
			device->data_buffer + buffer_size,
			&checksum_word,
			sizeof(checksum_word)
	);

	// Запоминаем сколько данных у нас в буфере
	device->data_size = buffer_size + sizeof(checksum_word);

	// Готовим команду к отправке
	device->cmd.code = IR9602_CMD_SBDWB;
	device->cmd.arg.sbdwb.message_length = buffer_size;
	ir9602_serialize_command(device->cmd_buffer, IR9602_CMD_BUFFER_SIZE, &device->cmd);
	device->state = IR9602_STATE_CMD;

	return buffer_size;
}


int ir9602_cmd_sbdrb(ir9602_t * device)
{
	// Готовим команду к отправке
	device->cmd.code = IR9602_CMD_SBDRB;
	ir9602_serialize_command(device->cmd_buffer, IR9602_CMD_BUFFER_SIZE, &device->cmd);
	device->state = IR9602_STATE_CMD;

	return 0;
}


int ir9602_get_mt_data(ir9602_t * device, void * buffer, int buffer_size)
{
	// Если мы сейчас читаем сообщение из модема, то читать его тут конечно же нельзя
	if (device->state == IR9602_STATE_DATA_READ)
		return -EBUSY;

	// Если у нас нет ни байтика кроме размера сообщения и контрольной суммы
	// то сразу сливаемся
	if (device->data_size < sizeof(uint16_t) + 1 + sizeof(uint16_t))
		return 0;

	// Мы влезаем в выходной буфер?
	const uint16_t payload_size = device->data_size - sizeof(uint16_t) - sizeof(uint16_t);
	if (payload_size > buffer_size)
		return payload_size;

	// Проверим контрольную сумму?
	uint16_t calculated_checksum = _sbd_checksum(
			device->data_buffer + sizeof(uint16_t),
			payload_size
	);

	uint16_t inbuffer_checksum;
	memcpy(
			&inbuffer_checksum,
			device->data_buffer + sizeof(uint16_t) + payload_size,
			sizeof(uint16_t)
	);

	if (_swap_endian(inbuffer_checksum) != calculated_checksum)
		return -EBADMSG;

	// Копируем в выходной буфер
	memcpy(
		buffer,
		device->data_buffer + sizeof(uint16_t),
		payload_size
	);

	return payload_size;
}


int ir9602_poll_one(ir9602_t * device)
{


	return 0;
}




