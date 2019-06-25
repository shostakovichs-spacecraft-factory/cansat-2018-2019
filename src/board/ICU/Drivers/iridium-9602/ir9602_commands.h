/*
 * iridium9602low.h
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#ifndef IR9602_COMMANDS_H_
#define IR9602_COMMANDS_H_

#include <stdbool.h>
#include <stdint.h>


//! Команды для модема 9602
typedef enum
{
	// Значение 0 резервированно

	//! Включение отчетов об уровнях сигнала сети
	/*! Аргументы :
	 * 1: включить=1 или выключить=0 отчеты в целом
	 * 2: включить=1 или выключить=0 отчеты об уровне сигнала
	 * 3: включить=1 или выключить=0 отчеты о наличии связи с сетью
	 * Ответ на команду OK/ERROR
	 */
	IR9602_CMD_CIER = 1,

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
	 * Ответ довольно сложный и содержит кучу информации о проведении сессии */
	IR9602_CMD_SBDI,

	//! Очистка буферов сообщений модема
	IR9602_CMD_SBDD,
} ir9602_cmd_code_t;


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


//! Обобщенная структура команды для модема
typedef struct
{
	//! Код команды
	ir9602_cmd_code_t code;

	//! Её аргументы
	union
	{
		struct
		{
			//! Включить события по изменению уровня сигнала
			uint8_t enable_signal_level_events;
			//! Включить события по наличию/отсутствию сети
			uint8_t enable_network_present_events;
		} cier;

		struct
		{
			//! Длина отправляемого сообщения
			uint8_t message_length;
		} sbdwb;

		struct
		{
			//! Что именно чистим
			uint8_t clear_type;
		} sbdd;
	} arg;
} ir9602_cmd_t;


int ir9602_serialize_command(char * buffer, int buffer_size, const ir9602_cmd_t * command);

#endif /* IR9602_COMMANDS_H_ */
