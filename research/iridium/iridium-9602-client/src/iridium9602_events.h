/*
 * iridium9602_events.h
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#ifndef IRIDIUM9602_EVENTS_H_
#define IRIDIUM9602_EVENTS_H_


//! Типы ответов, которые может давать модем в ответ на команду
typedef enum
{
	//! Типовой ответ на любую команду о том, что она принята и выполнена
	IRIDIUM_9602_RESP_OK 	= 0x01,
	//! Сообщение о том, что что-то пошло не так с предыдущей командой
	IRIDIUM_9602_RESP_ERROR = 0x04,
	//! Модем готов к приёму бинарных данных от МК
	IRIDIUM_9602_RESP_READY = 0x02,
} ir9602_resp_code_t;



//! Типы событий, которые модем может давать просто так
typedef enum
{
	//! Сигнал о получении RINGALERT от шлюза
	IRIDIUM_9602_EVT_SBDRING,
	//! Сообщение о том, что сломалось что-то аппаратное!
	IRIDIUM_9602_EVT_HARDWARE_FAILURE,
	//! Сообщение о событии связанном с авторегистрацией
	IRIDIUM_9602_EVT_AREG,
	//! Сообщение об изменении уровня сигнала сети
	IRIDIUM_9602_EVT_CIEV,
} ir9602_evt_code_t;



#endif /* IRIDIUM9602_EVENTS_H_ */
