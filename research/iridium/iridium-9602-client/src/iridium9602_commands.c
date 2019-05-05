/*
 * iridium9602_commands.c
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#include "iridium9602_commands.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

//! Фукция сериализатор для команды
/*! Возвращает количество символов, которые занимает сериализованная команда
 *  даже если эта команда не влезла в результирующий буфер
 */
typedef int (*ir9602_cmd_serializer_t)(char *, int, const ir9602_cmd_t*);


// Набор функций сериализаторов для различных команд
// =================================================
static int _serialize_at(char * buffer, int buffer_size, const ir9602_cmd_t * command)
{
	(void)command;

	const char cmd[] = "AT\r\n";
	const int cmd_len = sizeof(cmd)-1; // -1 на терминирующий ноль
	if (cmd_len > buffer_size)
		return buffer_size;

	memcpy(buffer, cmd, cmd_len);
	return cmd_len;
}


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

	memcpy(buffer, command, cmd_len);
	return cmd_len;
}


static int _serialize_sbdix(char * buffer, int buffer_size, const ir9602_cmd_t * command)
{
	// Если это ответ на RA, то нужно дописать A к команде
	const int rc = snprintf(
			buffer, buffer_size,
			"AT+SBDIX%s\r\n",
			command->arg.sbdix.response_to_ra ? "a" : ""
	);
	return rc;
}


static int _serialize_sbdreg(char * buffer, int buffer_size, const ir9602_cmd_t * command)
{
	const ir9602_cmd_sbdreg_t * arg = &command->arg.sbdreg;

	const int int_lat = (int)arg->lat;
	const int int_lon = (int)arg->lon;

	const float minutes_lat = fabs((arg->lat - int_lat) * 60.0f);
	const float minutes_lon = fabs((arg->lon - int_lon) * 60.0f);

	const int rc = snprintf(
			buffer, buffer_size,
			"AT+SBDREG=%02d%06.3f,%03d%06.3f\r\n",
			int_lat, minutes_lat,
			int_lon, minutes_lon
	);

	return rc;
}


// Стуктура с различными параметрами команды
typedef struct
{
	//! Сериализатор для команды
	int (*serializer)(char *, int, const ir9602_cmd_t *);
} ir9602_cmd_def_t;


static const ir9602_cmd_def_t _cmd_defs[] = {
		{ &_serialize_at     },
		{ &_serialize_cier   },
		{ &_serialize_sbdwb  },
		{ &_serialize_sbdrb  },
		{ &_serialize_sbdix  },
		{ &_serialize_sbdreg },
};


int ir9602_serialize_command(char * buffer, int buffer_size, const ir9602_cmd_t * command)
{
	// проверка на валидность кода команды
	assert(command->code > 0 && command->code < sizeof(_cmd_defs)/sizeof(*_cmd_defs));

	const ir9602_cmd_def_t * const cmd_def = &_cmd_defs[command->code];
	const ir9602_cmd_serializer_t serializer = cmd_def->serializer;

	int cmdsize = serializer(buffer, buffer_size, command);
	if (cmdsize > buffer_size)
		return -EOVERFLOW;

	return cmdsize;
}

