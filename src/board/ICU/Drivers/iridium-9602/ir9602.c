/*
 * iridium9602.c
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#include "ir9602.h"

#include <string.h>
#include <assert.h>
#include <errno.h>


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


// ================================================================
// ================================================================


static int _send_cmd(ir9602_t * device, const ir9602_cmd_t * command)
{
	int len = ir9602_serialize_command(device->cmdevt_buffer, IR9602_CMDEVT_BUFFER_SIZE, command);
	if (len <= 0)
		return len;

	const char * carret = device->cmdevt_buffer;
	while(*carret)
	{
		const uint8_t ch = *(uint8_t*)(carret++);
		int rc = device->putch(device->user_arg, ch);
		if (rc < 0)
			return rc;
	}

	return len;
}


static int _read_event(ir9602_t * device, ir9602_evt_t * evt, bool should_block)
{
	int carret = 0;
	uint8_t * const buffer = (uint8_t*)device->cmdevt_buffer;

	while (1)
	{
		// Если наш буфер переполнен
		if (carret >= IR9602_CMDEVT_BUFFER_SIZE)
			return -EOVERFLOW;

		// Есть чего?
		int character = device->getch(device->user_arg, should_block);
		if (character < 0)
			return character;

		// окей, это символ, а не ошибка - акумулируем его
		buffer[carret] = (uint8_t)(character & 0xFF);
		carret++;

		if (carret < 2)
			continue;	// если у нас нет и двух символов - строки у нас точно нет

		if (buffer[carret-2] == '\r' && buffer[carret-1] == '\n')
		{
			// Модем имеет дурную привычку часто скидывать пустые \r\n без ничего кроме
			// Будем их игнорить
			if (2 == carret)
				carret = 0;
			else
				break; // Если не пустой \r\n - то нужно обрабатывать
		}
	}

	// Если мы дошли до сюда, значит мы накопили строку!

	// Тут же её терминируем
	// Если буфер не станет переполнен
	if (carret >= IR9602_CMDEVT_BUFFER_SIZE)
		return -EOVERFLOW;

	buffer[carret] = '\0';

	// Парсим пришедшее событие
	const bool parsed = ir9602_probe_events((char*)buffer, evt);

	if (!parsed)
		return -EBADMSG; 	// Это какая-то неожиданная дичь

	// Все ок! Передаем пользовательскому хуку (если он конечно у нас есть)
	if (device->evt_hook != NULL)
		device->evt_hook(device->user_arg, evt);

	return 0;
}


static int _wait_for_events(ir9602_t * device, const ir9602_evt_code_t * expected_events,
		bool should_block, ir9602_evt_t * evt
)
{
	int rcved_event_counter = 0;
	int rc;
again:
	rc = _read_event(device, evt, should_block);
	if (rc < 0)
		return rc;

	rcved_event_counter++;
	const ir9602_evt_code_t * expected_events_carret = expected_events;
	for (; *expected_events_carret != 0; expected_events_carret++)
	{
		if (*expected_events_carret == evt->code)
			return rcved_event_counter;
	}

	goto again;
}

static int _send_mo_data(ir9602_t * device, const uint8_t * data, int datasize)
{
	// проверяем что у нас все влезает с размером и контрольной суммой
	if (datasize > IR9602_MO_MSG_MAX_SIZE)
		return -EOVERFLOW;

	// отправляем сообщение
	for (int i = 0; i < datasize; i++)
	{
		int rc = device->putch(device->user_arg, data[i]);
		if (rc < 0)
			return rc;
	}

	// считаем и отправляем контрольную сумму
	uint16_t checksum_word = _swap_endian(_sbd_checksum(data, datasize));
	const uint8_t * ptr = (uint8_t*)&checksum_word;
	for (int i = 0; i < sizeof(checksum_word); i++)
	{
		int rc = device->putch(device->user_arg, ptr[i]);
		if (rc < 0)
			return rc;
	}

	return 0;
}


static int _read_blob(ir9602_t * device, void * buffer, int buffer_size, bool should_block)
{
	uint8_t * const u8_buffer = (uint8_t *)buffer;
	for (int i = 0; i < buffer_size; i++)
	{
		int rc = device->getch(device->user_arg, should_block);
		if (rc < 0)
		{
			if (!should_block && -EWOULDBLOCK == rc)
				return i;
			else
				return rc;
		}

		u8_buffer[i] = (uint8_t)(rc & 0xFF);
	}

	return buffer_size;
}


// ===========================================================================
// ===========================================================================

void ir9602_init(ir9602_t * device, void * user_arg,
		ir9602_uart_getch_t getch, ir9602_uart_putch_t putch,
		ir9602_evt_hook_t evt_hook
)
{
	device->getch = getch;
	device->putch = putch;
	device->user_arg = user_arg;
	device->evt_hook = evt_hook;
	device->cmdevt_buffer[0] = 0;
}


int ir9602_sbdwb(ir9602_t * device, const void * data, int data_size, ir9602_evt_errcode_t * err_evt)
{
	int rc;

	// Готовим команду и отправляем
	ir9602_cmd_t cmd = {
			.code = IR9602_CMD_SBDWB,
			.arg = { .sbdwb = { .message_length = data_size }}
	};
	rc = _send_cmd(device, &cmd);
	if (rc < 0 )
		return rc;

	// ждем события READY или кода ошибки, если что-то не так
	ir9602_evt_code_t expected_events[] = {
			IR9602_EVT_READY,
			IR9602_EVT_ERROR,
			IR9602_EVT_ERRCODE,
			0
	};

	ir9602_evt_t evt;
	rc = _wait_for_events(device, expected_events, true, &evt);
	if (rc < 0)
		return rc;

	// Мы должны были получить READY
	switch (evt.code)
	{
	// Если это вот прям сразу ошибка - возвращаем ошибку
	case IR9602_EVT_ERRCODE:
		if (err_evt != NULL)
			*err_evt = evt.arg.errcode;

		return evt.arg.errcode.code;
		break;

	case IR9602_EVT_ERROR:
		return -EINVAL;
		break;

	// если это READY, то продолжаем
	case IR9602_EVT_READY:
		break;

	// если это черт знает что такое - возвращаем соответствующую ошибку
	default:
		return -EBADMSG;
		break;
	};

	// Окей! мы получили реди - продолжаем
	rc = _send_mo_data(device, data, data_size);
	if (rc < 0)
		return rc;

	// Теперь ждем код ошибки (и только его)
	// Делаем хитрый хак и используем тот же самый массив-список
	rc = _wait_for_events(device, expected_events+2, true, &evt);
	if (rc < 0)
		return rc;

	if (IR9602_EVT_ERRCODE != evt.code)
		return -EBADMSG;

	if (err_evt != NULL)
		*err_evt = evt.arg.errcode;

	// Там еще должен быть OK от модема (наверное)
	// но мы его проигнорируем
	return evt.arg.errcode.code; // Если все ок - должно вернуть нолик
}


int ir9602_sbdi(ir9602_t * device, ir9602_evt_sbdi_t * evt_sbdi)
{
	int rc;

	// Прям вот так сходу берем и отправляем команду. Чего ждать то
	ir9602_cmd_t cmd;
	cmd.code = IR9602_CMD_SBDI;
	rc = _send_cmd(device, &cmd);
	if (rc < 0)
		return rc;

	ir9602_evt_code_t expected_events[] = {
			IR9602_EVT_ERROR,
			IR9602_EVT_SBDI,
			0
	};

	ir9602_evt_t evt;
	rc = _wait_for_events(device, expected_events, true, &evt);
	switch (evt.code)
	{
	case IR9602_EVT_ERROR:
		return -EINVAL;
		break;

	case IR9602_EVT_SBDI:
		if (evt_sbdi)
			*evt_sbdi = evt.arg.sbdi;
		break;

	default:
		return -EBADMSG;
		break;
	};

	return 0;
}


int ir9602_sbdrb(ir9602_t * device, void * buffer, int buffer_size)
{
	int rc;

	// Действуем тонко.
	// Сперва засылаем модему команду SBDRB, но не шлем \r\n
	const char * cmd = "AT+SBDRB";
	while (*cmd != 0)
	{
		rc = device->putch(device, *cmd++);
		if (rc < 0)
			return rc;
	}

	// Теперь вычитываем из нашего RX буфера все все все что там лежит
	// что модем мог успеть накидать до этих пор
	// Эксперименты показали, что модем молчит, если кто-то начал отправлять
	// ему команду, но еще не отправил \r\n
	// поэтому считаем что лишнего он нам не накидает
	ir9602_evt_t evt;
	rc = _wait_for_events(device, NULL, false, &evt);
	if (rc < 0 && rc != -EWOULDBLOCK)
		return rc;

	// Теперь засылаем \r\n
	cmd = "\r\n";
	while (*cmd != 0)
	{
		rc = device->putch(device, *cmd++);
		if (rc < 0)
			return rc;
	}

	// Теперь вычитываем два байта - это длина сообщения
	uint16_t msglen;
	rc = _read_blob(device, &msglen, sizeof(msglen), true);
	if (rc < 0)
		return rc;

	msglen = _swap_endian(msglen);

	// в буфере место то хватит?
	if (msglen > buffer_size)
		return -EMSGSIZE;

	// вычитываем тело сообщения
	rc = _read_blob(device, buffer, buffer_size, true);
	if (rc < 0)
		return rc;

	// вычитываем контрольную сумму
	uint16_t chksum;
	rc = _read_blob(device, &chksum, sizeof(chksum), true);
	if (rc < 0)
		return rc;

	chksum = _swap_endian(chksum);

	// Не совпало - ну значит не совпало
	if (chksum != _sbd_checksum(buffer, msglen))
		return - EBADMSG;

	// А совпало - так совпало!
	return 0;
}
