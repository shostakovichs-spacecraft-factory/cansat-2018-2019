/*
 * iridium9602_events.h
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#ifndef IRIDIUM9602_EVENTS_H_
#define IRIDIUM9602_EVENTS_H_

#include <stdint.h>
#include <stdbool.h>

//! Типы событий, которые модем может давать просто так
typedef enum
{
	//! Типовой ответ на любую команду о том, что она принята и выполнена
	IRIDIUM_9602_RESP_OK = 0,
	//! Сообщение о том, что что-то пошло не так с предыдущей командой
	IRIDIUM_9602_RESP_ERROR,
	//! Модем готов к приёму бинарных данных от МК
	IRIDIUM_9602_RESP_READY,
	//! Сигнал о получении RINGALERT от шлюза
	IRIDIUM_9602_EVT_SBDRING,
	//! Сообщение об изменении уровня сигнала сети
	IRIDIUM_9602_EVT_CIEV,
	//! Сообщение о том, что сломалось что-то аппаратное!
	IRIDIUM_9602_EVT_HARDWARE_FAILURE,
} ir9602_evt_code_t;


//! Аргументы события HARDWARE_FAILURE
typedef struct
{
	//! Код подсистемы
	int subsys;
	//! Код ошибки
	int error;
} ir9602_evt_hardfault_t;


//! Тип события CIEV
typedef enum
{
	//! Сообщение об уровне сигнала
	IR9602_EVT_CIEV_KIND_SIGIND = 0,
	//! Сообщение о наличии сети
	IR9602_EVT_CIEV_KIND_NETAWAIL = 1,
} ir9602_evt_ciev_type_t;

//! Аргументы события CIEV
typedef struct
{
	//! Тип события
	ir9602_evt_ciev_type_t type;
	//! Значение
	uint8_t value;
} ir9602_evt_ciev_t;


//! Событие, принятое от модема
typedef struct
{
	//! Код события
	ir9602_evt_code_t code;

	//! Аргументы события
	union
	{
		ir9602_evt_hardfault_t hardfault;
		ir9602_evt_ciev_t ciev;
	} arg;
} ir9602_evt_t;


//! Проверка входного буфера на какое-либо событие
bool ir9602_probe_event(const char * buffer, int buffer_size, ir9602_evt_t * evt);


#endif /* IRIDIUM9602_EVENTS_H_ */
