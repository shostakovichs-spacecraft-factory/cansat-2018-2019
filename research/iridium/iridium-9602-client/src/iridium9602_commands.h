/*
 * iridium9602low.h
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#ifndef IRIDIUM9602_COMMANDS_H_
#define IRIDIUM9602_COMMANDS_H_

#include <stdbool.h>
#include <stdint.h>

//! Аргумент команды на очистку буферов модема
typedef enum
{
	//! Чистить MO буфер
	IR9202_CMD_SBDD_CLEAR_MO = 0,
	//! Чистить MT буфер
	IR9202_CMD_SBDD_CLEAR_MT = 1,
	//! Чистить оба буфера
	IR9202_CMD_SBDD_CLEAR_BOTH = 2,
} ir9602_cmd_sbdd_cltype;

//! Команды для модема 9602
typedef enum
{
	//! Простая AT команда
	/*! Без аргументов
	 *  Ответ на команду OK/ERROR
	 */
	IR9602_CMD_AT = 0,

	//! Включение отчетов об уровнях сигнала сети
	/*! Аргументы :
	 * 1: включить=1 или выключить=0 отчеты в целом
	 * 2: включить=1 или выключить=0 отчеты об уровне сигнала
	 * 3: включить=1 или выключить=0 отчеты о наличии связи с сетью
	 * Ответ на команду OK/ERROR
	 */
	IR9602_CMD_CIER,

	//! Подготовка к отправке бинарного SDB сообщения
	/*! Аргументы:
	 * 1: длина отправляемого сообщения (максимум 340 байт)
	 * Ответ на команду READY либо цифра с кодом ошибки и ОК (который не ОК на самом деле)
	 * */
	IR9602_CMD_SBDWB,

	//! Чтение полученного SBD сообщения
	/*! Без аргументов
	 * Ответ на команду - сразу же само сообщение
	 */
	IR9602_CMD_SBDRB,

	//! Проведение SBD сессии
	/*! Аргументы:
	 * 1: является ли этот запрос ответом на Ring Alert? дописывает [A] к коду команды
	 * Ответ довольно сложный и содержит кучу информации о проведении сессии
	*/
	IR9602_CMD_SBDIX,

	//! Регистрация в сети IRIDIUM для получения Mobile Terminated сообщений
	/*! Аргументы:
	 * 1: lat - долгота модема
	 * 2: lon - широта модема
	 */
	IR9602_CMD_SBDREG,

	//! Очистка буферов сообщений модема
	IR9602_CMD_SBDD,
} ir9602_cmd_code_t;


//! Аргументы команды CIER
typedef struct
{
	//! Включить события по изменению уровня сигнала
	bool enable_signal_level_events;
	//! Включить события по наличию/отсутствию сети
	bool enable_network_present_events;
} ir9602_cmd_cier_t;


//! Аргументы команды SBDWB
typedef struct
{
	//! Длина отправляемого сообщения
	uint8_t message_length;
} ir9602_cmd_sbdwb_t;


//! Аргументы команды SBDIX
typedef struct
{
	//! Является ли эта сессия ответом на RingAlert
	bool response_to_ra;
} ir9602_cmd_sbdix_t;


//! Аргументы команды SBDREG
typedef struct
{
	//! Широта модема
	float lat;
	//! Долгота модема
	float lon;
} ir9602_cmd_sbdreg_t;


//! Аргументы команды SBDD
typedef struct
{
	//! Что именно чистим
	ir9602_cmd_sbdd_cltype clear_type;
} ir9602_cmd_sbdd_t;

//! Обобщенная структура команды для модема
typedef struct
{
	//! Код команды
	ir9602_cmd_code_t code;

	//! Её аргументы
	union
	{
		ir9602_cmd_cier_t cier;
		ir9602_cmd_sbdwb_t sbdwb;
		ir9602_cmd_sbdix_t sbdix;
		ir9602_cmd_sbdreg_t sbdreg;
		ir9602_cmd_sbdd_t sbdd;
	} arg;
} ir9602_cmd_t;


int ir9602_serialize_command(char * buffer, int buffer_size, const ir9602_cmd_t * command);

#endif /* IRIDIUM9602_COMMANDS_H_ */
