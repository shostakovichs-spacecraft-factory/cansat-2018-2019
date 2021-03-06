/*
 * iridium9602_events.h
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#ifndef IR9602_EVENTS_H_
#define IR9602_EVENTS_H_

#include <stdint.h>
#include <stdbool.h>

//! Типы событий, которые модем может давать просто так
typedef enum
{
	// значние 0 резервировано для определения концов списков

	//! Сообщение о том, что сломалось что-то аппаратное!
	IR9602_EVT_HARDWARE_FAILURE = 1,
	//! Сообщение об изменении уровня сигнала сети
	IR9602_EVT_CIEV,
	//! Типовой ответ на любую команду о том, что она принята и выполнена
	IR9602_EVT_OK,
	//! Сообщение о том, что что-то пошло не так с предыдущей командой
	IR9602_EVT_ERROR,
	//! Модем готов к приёму бинарных данных от МК
	IR9602_EVT_READY,
	//! Код ошибки после выполнения некоторых команд (SBDD, SBDWB например)
	IR9602_EVT_ERRCODE,
	//! Сообщение о проведенной SBD сессии
	IR9602_EVT_SBDI,
	//! Сообщение вида size=<size> о размере скопированного сообщения
	IR9602_EVT_SBDTC,
} ir9602_evt_code_t;


// ===========================================================================
// ===========================================================================

//! Аргументы события HARDWARE_FAILURE
typedef struct
{
	//! Код подсистемы
	int subsys;
	//! Код ошибки
	int error;
} ir9602_evt_hardfault_t;


// ===========================================================================
// ===========================================================================

//! Тип события CIEV
typedef enum
{
	//! Сообщение об уровне сигнала
	IR9602_EVT_CIEV_KIND_SIGIND = 0,
	//! Сообщение о наличии сети
	IR9602_EVT_CIEV_KIND_NETAVAIL = 1,
} ir9602_evt_ciev_type_t;

//! Аргументы события CIEV
typedef struct
{
	//! Тип события
	ir9602_evt_ciev_type_t type;
	//! Значение (0 или 1 для NETAVAIL и 0..5 для SIGIND)
	uint8_t value;
} ir9602_evt_ciev_t;


// ===========================================================================
// ===========================================================================

//! Код ошибки в ответ на SBDWB
typedef enum
{
	//! Нет ошибки
	IR9602_EVT_SBDWBERR_OK = 0,
	//! Таймаут
	IR9602_EVT_SBDWBERR_TIMEOUT = 1,
	//! Несовпадение контрольной сумы
	IR9602_EVT_SBDWBERR_CHECKSUM = 2,
	//! Некорректный размер
	IR9602_EVT_SBDWBERR_INVSIZE = 3,
} ir9602_evt_sbdwberr_t;


//! Код результата удаления сообщений
typedef enum
{
	//! Нет ошибки
	IR9602_EVT_SBDDERR_OK = 0,
	//! Есть ошибка!
	IR9602_EVT_SBDDERR_ERR = 1,
} ir9602_evt_sbdderr_t;


//! Отчет о выполнении команды SBDWB
typedef struct
{
	int code;
} ir9602_evt_errcode_t;

// ===========================================================================
// ===========================================================================

//! Статус отправки/получения SDB сообщения в рамках SBD сессии
typedef enum
{
	//! Не было никакого сообщения
	IR9602_EVT_SBDMSTATUS_NO = 0,
	//! Сообщение успешно передано/получено
	IR9602_EVT_SBDMSTATUS_YES = 1,
	//! Ошибка при передаче/получении сообщения
	IR9602_EVT_SBDMSTATUS_ERROR = 2,
} ir9602_evt_sbd_mstatus_t;


//! Отчет о проведенной SBD сессии
typedef struct
{
	//! Статус отправки MO сообщения
	ir9602_evt_sbd_mstatus_t mo_status;
	//! Номер отправленного сообщения
	uint16_t momsn;
	//! Статус получения MT сообщения
	ir9602_evt_sbd_mstatus_t mt_status;
	//! Номер полученного сообщения
	uint16_t mtmsn;
	//! Длина полученного MT сообщения
	uint16_t mt_size;
	//! Количетсво ожидающих MT сообщений в небе
	uint16_t mt_queed;
} ir9602_evt_sbdi_t;


//! Сообщение об успешном копировании SBD буфера MO в MT
typedef struct
{
	uint16_t size;
} ir9602_evt_sbdtc_t;

// ===========================================================================
// ===========================================================================
// ===========================================================================

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
		ir9602_evt_errcode_t errcode;
		ir9602_evt_sbdi_t sbdi;
		ir9602_evt_sbdtc_t sbdtc;
	} arg;
} ir9602_evt_t;


//! Проверка входного буфера на какое-либо событие
bool ir9602_probe_events(const char * buffer, ir9602_evt_t * evt);


#endif /* IR9602_EVENTS_H_ */
