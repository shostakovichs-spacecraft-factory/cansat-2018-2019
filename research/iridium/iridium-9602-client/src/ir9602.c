/*
 * iridium9602.c
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#include "ir9602.h"

#include <string.h>
#include <assert.h>
#include <printf.h>
#include <errno.h>


static void _reset_data_buffer(ir9602_t * device)
{
	device->data_carret = 0;
	device->data_size = 0;
	device->data_buffer[0] = '\0';
}


static void _reset_cmd_buffer(ir9602_t * device)
{
	device->cmd_size = 0;
	device->cmd_carret = 0;
	device->cmd_buffer[0] = '\0';
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


// ================================================================
// ================================================================

// "Действия" драйвера
typedef enum
{
	// значение 0 зарезервированно
	IR9602_ACTION_OUTCMD = 1,		//!< Отправляем команду
	IR9602_ACTION_OUTDATA,			//!< Отправляем данные (SBDWB)
	IR9602_ACTION_INEVENT,			//!< Читаем ответ на команду
	IR9602_ACTION_INDATA,			//!< Читаем данные (SBDRB)
} ir9602_action_code_t;


// Аргумент "действия" драйвера
typedef union
{
	struct
	{
		// Код ожидаемого события
		/*! Имеет хитрые значения:
		 *  0 - ничего такого не ждем - проверяем spurious эвенты
		 *  > 0 - ждем конкретный эвент. После парсинга эвент кладется в дескриптор
		 *  < 0 - ждем конкретный эвент (но его код записан с минусом). После парсинга эвент не сохраняется в дескриптор
		 */
		int8_t expected_evt; /* ir9602_evt_code_t */
	} inevent;
} ir9602_action_arg_t;


typedef struct
{
	uint8_t code /*ir9602_cmd_code_t*/;
	ir9602_action_arg_t arg;
} ir9602_action_t;


// Указатель на "актор" действия
/* Возвращаемые значения:
 * 0 - действие выполнено и все
 * 1 - действите выполнено и получено новое событие от модема
 */
typedef int (*ir9602_actor_t)(ir9602_t *, const ir9602_action_arg_t *);


static int _actor_out_cmd(ir9602_t * device, const ir9602_action_arg_t * arg);
static int _actor_out_data(ir9602_t * device, const ir9602_action_arg_t * arg);
static int _actor_in_event(ir9602_t * device, const ir9602_action_arg_t * arg);
static int _actor_in_data(ir9602_t * device, const ir9602_action_arg_t * arg);


static ir9602_actor_t _get_actor(ir9602_action_code_t action_code)
{
	switch (action_code)
	{
	case IR9602_ACTION_OUTCMD:	return _actor_out_cmd;
	case IR9602_ACTION_OUTDATA:	return _actor_out_data;
	case IR9602_ACTION_INEVENT:	return _actor_in_event;
	case IR9602_ACTION_INDATA:	return _actor_in_data;
	default:
		return NULL;
	};
}

static int _actor_out_cmd(ir9602_t * device, const ir9602_action_arg_t * arg)
{
	(void)arg;

	if (device->cmd_carret >= device->cmd_size)
		return -ENODATA; // значит буфер пуст изначально?

	while(device->cmd_carret < device->cmd_size)
	{
		// окей, что там нужно отправить
		uint8_t ch = device->cmd_buffer[device->cmd_carret];
		int rc = device->putch(device, ch);
		if (rc < 0)
			return rc;

		// отправилось
		device->cmd_carret++;
	}

	// Если провалились сюда, значит все готово
	return 0;
}


//! Полящая отправка данных (для команды SBDWB разумеется)
static int _actor_out_data(ir9602_t * device, const ir9602_action_arg_t * arg)
{
	(void)arg;

	if (device->data_carret >= device->data_size)
		return -ENODATA; // значит буфер пуст изначально?

	while(1)
	{
		// окей, что там нужно отправить
		uint8_t ch = device->data_buffer[device->data_carret];
		int rc = device->putch(device, ch);
		if (rc < 0)
			return rc;

		// отправилось
		device->data_carret++;

		// Это еще не все?
		if (device->data_carret == device->data_size)
			break;
	}

	// Если провалились сюда, значит все готово
	return 0;
}


static int _actor_in_event(ir9602_t * device, const ir9602_action_arg_t * arg)
{
	char * const buffer = device->data_buffer;

	while (1)
	{
		// Если наш буфер переполнен
		if (device->data_carret >= IR9602_DATA_BUFFER_SIZE)
			return -EOVERFLOW;

		// Есть чего?
		int character = device->getch(device->rwarg);
		if (character < 0)
			return character;

		// окей, это символ, а не ошибка - акумулируем его
		buffer[device->data_carret] = (uint8_t)(character & 0xFF);
		device->data_carret++;

		if (device->data_carret < 2)
			continue;	// если у нас нет и двух символов - строки у нас точно нет

		if (buffer[device->data_carret-2] == '\r' && buffer[device->data_carret-1] == '\n')
		{
			// Модем имеет дурную привычку часто скидывать пустые \r\n без ничего кроме
			// Будем их игнорить
			if (2 == device->data_carret)
				_reset_data_buffer(device);
			else
				break; // Если не пустой \r\n - то нужно обрабатывать
		}
	}

	// Если мы дошли до сюда, значит мы накопили строку!

	// Тут же её терминируем
	// Если буфер не станет переполнен
	if (device->data_carret >= IR9602_DATA_BUFFER_SIZE)
		return -EOVERFLOW;

	device->data_buffer[device->data_carret] = '\0';

	// Смотрим чего мы там ждем
	ir9602_evt_code_t expected_evt;
	bool should_be_ignored;
	if (arg->inevent.expected_evt >= 0)
	{
		expected_evt = arg->inevent.expected_evt;
		should_be_ignored = false;
	}
	else
	{
		expected_evt = -arg->inevent.expected_evt;
		should_be_ignored = true;
	}

	// Парсим пришедшее событие
	ir9602_evt_t evtbuf;
	const bool parsed = ir9602_probe_events(device->data_buffer, &evtbuf);
	if (parsed)
	{
		// Событие распарсилось. Это то, что мы ждали? если мы вообще чего-то ждали
		if (0 == expected_evt || evtbuf.code == expected_evt)
		{
			if (!should_be_ignored)
				device->evt = evtbuf;

			return 0;
		}

		// Это какая-то неожиданная дичь
		return -EBADMSG;
	}

	// Сообщение не распарсилось
	return -ENOMSG;
}


static int _actor_in_data(ir9602_t * device, const ir9602_action_arg_t * arg)
{
	uint8_t * const buffer = (uint8_t*)device->data_buffer;

	// Будем работать так.
	// При первом запуске функции мы будем делать, что datasize = 0
	// это будет означать. что какие-то данные мы читаем, но мы не знаем их длины
	// будем читать два байта и потом перекидывать их в datasize
	// сбрасываем каретку в 0 и продолжаем читать
	while(1)
	{
		// Если наш буфер переполнен
		if (device->data_carret >= IR9602_DATA_BUFFER_SIZE)
			return -EOVERFLOW;

		// Есть чего?
		int character = device->getch(device->rwarg);
		if (character < 0)
			return character;

		// окей, это байт, а не ошибка - акумулируем его
		buffer[device->data_carret] = (uint8_t)(character & 0xFF);
		device->data_carret++;

		// Мы все еще копим длину
		if (device->data_size == 0)
		{
			// А вот и накопили
			if (device->data_carret >= sizeof(uint16_t))
			{
				// Вычитываем длину
				device->data_size = (buffer[0] << 8) | buffer[1]; // помним об MSB
				// допонительно к данным модем даёт контрольную сумму
				device->data_size += sizeof(uint16_t);
				// Сбрасываем каретку на 0 для чтения данных на место
				device->data_carret = 0;
			}
			continue;
		}

		// Мы копим уже сами данные
		if (device->data_carret == device->data_size)
		{
			// и мы их накопили
			break;
		}
	}

	// Если мы оказались тут - мы накопили все данные
	// Ну и собственно все. Контрольную сумму будем проверять при выдаче
	return 0;
}

// ====================================================
// ====================================================

ir9602_action_t _idle_action_list[] = {
		{ IR9602_ACTION_INEVENT, {} } // Просто принимаем все события
};

// Порядок действий для выполнения команды SBDWB
ir9602_action_t _sbdwb_action_list[] = {
		{ IR9602_ACTION_OUTCMD 	},	// Отправляем команду
		{ IR9602_ACTION_INEVENT,	{ .inevent={ IR9602_EVT_READY	} } },	// Принимаем READY
		{ IR9602_ACTION_OUTDATA },	// Отправляем данные
		{ IR9602_ACTION_INEVENT,	{ .inevent={ IR9602_EVT_ERRCODE	} } },	// Принимаем код ошибки
		{ IR9602_ACTION_INEVENT,	{ .inevent={ -IR9602_EVT_OK		} } },	// Принимаем ок (и игнорим)
		{ 0	}	// готово
};


// Порядок действий для выполнения команды SBRB
ir9602_action_t _sbdrb_action_list[] = {
		{ IR9602_ACTION_OUTCMD	},	// Отправляем команду
		{ IR9602_ACTION_INDATA	},	// Принимаем данные
		{ IR9602_ACTION_INEVENT,	{ .inevent={ -IR9602_EVT_OK		} } },	// Принримаем ок (и игнорим)
		{ 0	} 	// готово
};


// Порядок действий для выполнения команды SBDD
ir9602_action_t _sbdd_action_list[] = {
		{ IR9602_ACTION_OUTCMD	},	// Отправляем команду
		{ IR9602_ACTION_INEVENT,	{ .inevent={ IR9602_EVT_ERRCODE	} } },	// Принримаем код ошибки
		{ IR9602_ACTION_INEVENT,	{ .inevent={ -IR9602_EVT_OK		} } },	// Принримаем ок (и игнорим)
		{ 0	}	// готово
};

// Порядок действий для выполнения команды SBDI
ir9602_action_t _sbdi_action_list[] = {
		{ IR9602_ACTION_OUTCMD	},	// Отправляем команду
		{ IR9602_ACTION_INEVENT,	{ .inevent={ IR9602_EVT_SBDI	} } },	// Принримаем отчет о сеансе
		{ IR9602_ACTION_INEVENT,	{ .inevent={ -IR9602_EVT_OK		} } },	// Принримаем ок (и игнорим)
		{ 0	}	// готово
};


// ===========================================================================
// ===========================================================================

void ir9602_init(ir9602_t * device, ir9602_uart_getch_t getch, ir9602_uart_putch_t putch,
		void * rwarg
)
{
	device->getch = getch;
	device->putch = putch;
	device->rwarg = rwarg;

	_reset_cmd_buffer(device);
	_reset_data_buffer(device);

	device->action = NULL;
}


int ir9602_sbdwb(ir9602_t * device, const void * buffer, int buffer_size)
{
	if (*device->action != IR9602_ACTION_OUTDATA)
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
	device->action = &_sbdd_action_list[0];

	return buffer_size;
}


int ir9602_sbdrb(ir9602_t * device)
{
	if (device->action != NULL)
		return -EBUSY;

	// Готовим команду к отправке
	device->cmd.code = IR9602_CMD_SBDRB;
	ir9602_serialize_command(device->cmd_buffer, IR9602_CMD_BUFFER_SIZE, &device->cmd);
	device->action = &_sbdrb_action_list;
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




