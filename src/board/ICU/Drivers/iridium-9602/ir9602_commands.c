/*
 * iridium9602_commands.c
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "ir9602_commands.h"

//! Фукция сериализатор для команды
/*! Возвращает количество символов, которые занимает сериализованная команда
 *  даже если эта команда не влезла в результирующий буфер
 */
typedef int (*ir9602_cmd_serializer_t)(char *, int, const ir9602_cmd_t*);


// Набор функций сериализаторов для различных команд
// =================================================
static int _serialize_cier(char * buffer, int buffer_size, const ir9602_cmd_t * command)
{
	const int enable_global =
			command->arg.cier.enable_network_present_events || command->arg.cier.enable_signal_level_events;

	const int rc = snprintf(
			buffer, buffer_size,
			"AT+CIER=%d,%d,%d\r\n",
			enable_global,
			(int)command->arg.cier.enable_signal_level_events,
			(int)command->arg.cier.enable_network_present_events
	);

	return rc;
}

static int _serialize_sbdwb(char * buffer, int buffer_size, const ir9602_cmd_t * command)
{
	const int rc = snprintf(
			buffer, buffer_size,
			"AT+SBDWB=%d\r\n",
			(int)command->arg.sbdwb.message_length
	);

	return rc;
}


static int _serialize_sbdrb(char * buffer, int buffer_size, const ir9602_cmd_t * command)
{
	(void)command;
	const char cmd[] = "SBDRB\r\n";
	const int cmd_len = sizeof(cmd)-1; // -1 на терминирующий ноль
	if (cmd_len > buffer_size)
		return buffer_size;

	memcpy(buffer, cmd, cmd_len);
	return cmd_len;
}


static int _serialize_sbdi(char * buffer, int buffer_size, const ir9602_cmd_t * command)
{
	(void)command;
	const char cmd[] = "AT+SBDI\r\n";
	const int cmd_len = sizeof(cmd)-1;
	if (cmd_len > buffer_size)
		return buffer_size;

	memcpy(buffer, cmd, cmd_len);
	return cmd_len;
}


static int _serialize_sbdd(char * buffer, int buffer_size, const ir9602_cmd_t * command)
{
	// Если это ответ на RA, то нужно дописать A к команде
	const int rc = snprintf(
			buffer, buffer_size,
			"AT+SBDD=%d\r\n",
			(int)command->arg.sbdd.clear_type
	);
	return rc;
}


static int _serialize_sbdtc(char * buffer, int buffer_size, const ir9602_cmd_t * command)
{
	(void)command;
	const char cmd[] = "AT+SBDTC\r\n";
	const int cmd_len = sizeof(cmd)-1;
	if (cmd_len > buffer_size)
		return buffer_size;

	memcpy(buffer, cmd, cmd_len);
	return cmd_len;
}


// Стуктура с различными параметрами команды
typedef struct
{
	//! Сериализатор для команды
	int (*serializer)(char *, int, const ir9602_cmd_t *);
} ir9602_cmd_def_t;


static const ir9602_cmd_def_t _cmd_defs[] = {
		{ &_serialize_cier   },
		{ &_serialize_sbdwb  },
		{ &_serialize_sbdrb  },
		{ &_serialize_sbdi   },
		{ &_serialize_sbdd   },
		{ &_serialize_sbdtc  },
};


static const ir9602_cmd_def_t * _get_def(ir9602_cmd_code_t code)
{
	assert(code >= 1 && code-1 < sizeof(_cmd_defs)/sizeof(*_cmd_defs));
	return &_cmd_defs[code-1];
}


int ir9602_serialize_command(char * buffer, int buffer_size, const ir9602_cmd_t * command)
{
	// проверка на валидность кода команды
	const ir9602_cmd_def_t * const cmd_def = _get_def(command->code);
	const ir9602_cmd_serializer_t serializer = cmd_def->serializer;

	int cmdsize = serializer(buffer, buffer_size, command);
	if (cmdsize > buffer_size)
		return -EOVERFLOW;

	buffer[cmdsize] = 0;
	return cmdsize;
}

