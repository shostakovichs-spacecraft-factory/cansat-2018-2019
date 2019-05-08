/*
 * iridium9602_events.c
 *
 *  Created on: 7 мая 2019 г.
 *      Author: snork
 */

#include "iridium9602_events.h"

#include <string.h>
#include <stdio.h>
#include <inttypes.h>

#define IR9602_MIN(x, y) (((x) < (y)) ? (x) : (y))


typedef bool (*ir9602_evt_probe_t)(const char *, int, ir9602_evt_t * evt, const char *, int);

//! Структура определяющая то или иное событие
typedef struct
{
	ir9602_evt_probe_t probe;
	const char * fmt;
	int fmt_size;
} ir9602_evt_def_t;


static bool _probe_simple(const char * buffer, int buffer_size, ir9602_evt_t * evt, const char * fmt, int fmt_size)
{
	if (buffer_size < fmt_size)
		return false;

	const int cmpres = strncmp(fmt, buffer, fmt_size);
	return 0 == cmpres;
}


static bool _probe_hardfault(const char * buffer, int buffer_size, ir9602_evt_t * evt, const char * fmt, int fmt_size)
{
	const int rc = sscanf(buffer, "HARDWARE FAILURE: %d, %d \r\n", &evt->arg.hardfault.subsys, &evt->arg.hardfault.error);
	return rc == 2;
}


static bool _probe_ciev(const char * buffer, int buffer_size, ir9602_evt_t * evt, const char * fmt, int fmt_size)
{
	int type;
	const int rc = sscanf(buffer, "+CIEV: %d, %"SCNd8" \r\n", &type, &evt->arg.ciev.value);
	if (rc == 2)
	{
		evt->arg.ciev.type = type;
		return true;
	}
	else
		return false;
}


static ir9602_evt_def_t _evt_defs[] = {
		{ _probe_simple, "OK", 2 },
		{ _probe_simple, "ERROR", 5 },
		{ _probe_simple, "READY", 5 },
		{ _probe_simple, "SBDRING", 7 },
		{ _probe_ciev, NULL, 0 },
		{ _probe_hardfault, NULL, 0 },
};


bool ir9602_probe_event(const char * buffer, int buffer_size, ir9602_evt_t * evt)
{
	for (int i = 0; i < sizeof(_evt_defs)/sizeof(*_evt_defs); i++)
	{
		const ir9602_evt_def_t * def = &_evt_defs[i];
		if (def->probe(buffer, buffer_size, evt, def->fmt, def->fmt_size))
			return true;
	}

	return false;
}
