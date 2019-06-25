/*
 * iridium9602_events.c
 *
 *  Created on: 7 мая 2019 г.
 *      Author: snork
 */

#include "ir9602_events.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <stddef.h>

#define IR9602_MIN(x, y) (((x) < (y)) ? (x) : (y))


// Функции-пробы для разных эвентов
// =========================================================
// =========================================================

//! Аргументы для пробящей функции
typedef union
{
	struct
	{
		const char * fmt;
	} simple;
} ir9602_probe_args_t;

//! Функция пробящая определенное событие
typedef bool (*ir9602_evt_probe_t)(const char *, const ir9602_probe_args_t *, ir9602_evt_t *);


static bool _probe_hardfault(const char * buffer, const ir9602_probe_args_t * arg, ir9602_evt_t * evt)
{
	const int rc = sscanf(buffer, "HARDWARE FAILURE: %d, %d", &evt->arg.hardfault.subsys, &evt->arg.hardfault.error);
	return 2 == rc;
}


static bool _probe_ciev(const char * buffer, const ir9602_probe_args_t * arg, ir9602_evt_t * evt)
{
	int type;
	const int rc = sscanf(buffer, "+CIEV: %d, %"SCNd8"", &type, &evt->arg.ciev.value);
	if (2 != rc)
		return false;

	evt->arg.ciev.type = type;
	return true;
}


//! Простая проверка на совпадение
static bool _probe_simple(const char * buffer, const ir9602_probe_args_t * arg, ir9602_evt_t * evt)
{
	const int cmpres = strncmp(arg->simple.fmt, buffer, strlen(arg->simple.fmt));
	return 0 == cmpres;
}


static bool _probe_errcode(const char * buffer, const ir9602_probe_args_t * arg, ir9602_evt_t * evt)
{
	int value;
	const int rc = sscanf(buffer, "%d\r\n", &value);
	if (1 != rc)
		return false;

	evt->arg.errcode.code = value;
	return true;
}


static bool _probe_sbdi(const char * buffer, const ir9602_probe_args_t * arg, ir9602_evt_t * evt)
{
	int mo_status_raw;
	int mt_status_raw;

	const int rc = sscanf(
			buffer,
			"+SBDI: %d, %"SCNu16", %d, %"SCNu16", %"SCNu16", %"SCNu16"",
			&mo_status_raw,
			&evt->arg.sbdi.momsn,
			&mt_status_raw,
			&evt->arg.sbdi.mtmsn,
			&evt->arg.sbdi.mt_size,
			&evt->arg.sbdi.mt_queed
	);

	if (6 != rc)
		return false;

	evt->arg.sbdi.mo_status = mo_status_raw;
	evt->arg.sbdi.mt_status = mt_status_raw;
	return true;
}

//! Структура определяющая то или иное событие
typedef struct
{
	ir9602_evt_probe_t probe;
	ir9602_probe_args_t args;
} ir9602_evt_def_t;


static ir9602_evt_def_t _evt_defs[] = {
		// Тут важно помнить, что массив идет от нуля, а коды событий от 1
		{ _probe_hardfault,	{} },
		{ _probe_ciev,		{} },
		{ _probe_simple,	{ .simple ={ .fmt="OK"} } },
		{ _probe_simple,	{ .simple ={ .fmt="ERROR"} } },
		{ _probe_simple,	{ .simple ={ .fmt="READY"} } },
		{ _probe_errcode,	{} },
		{ _probe_sbdi,		{} },
};


// Добывает описатор события по его коду
static const ir9602_evt_def_t *_get_evt_def(ir9602_evt_code_t code)
{
	assert(code-1 < sizeof(_evt_defs)/sizeof(*_evt_defs));
	return &_evt_defs[code-1];
}


bool ir9602_probe_events(const char * buffer, ir9602_evt_t * evt)
{
	int i;
	for (i = IR9602_EVT_HARDWARE_FAILURE; i <= IR9602_EVT_SBDI; i++)
	{
		const ir9602_evt_def_t * def = _get_evt_def(i);
		bool result = def->probe(buffer, &def->args, evt);
		if (result)
		{
			evt->code = i;
			return true;
		}
	}
	return false;
}
