/*
 * iridium9602.h
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#ifndef IRIDIUM9602_H_
#define IRIDIUM9602_H_

#include <stdint.h>

#include "iridium9602_commands.h"

//! Размер для буфера для сериализации команд
/*! FIXME: 50 байт хватит ведь? */
#define IR9602_CMD_BUFFER_SIZE (50)

//! Размер буфера для Mobile Originated сообщения
/*! MO сообщение для 9602 не может быть больше 340 байт
 *  И требует контрольную сумму в 2 байта в конце */
#define IR9602_MO_BUFFER_SIZE  (340+2)

//! Размер буфера для Mobile Terminated сообщения
/*! MT сообщение для 9602 не может быть больше 270 байт
 *  После сообщения модем присылает два байта контрольной суммы */
#define IR9602_MT_BUFFER_SIZE (270+2)

//! Указатель на функцию для чтения данных из уарта связанного с модемом
/*! Функция должна читать сколько может без блокировки вызывающего потока,
 *  но не больше чем есть места в предоставленном буфере.
 *  Возвращает количество прочитанных байт. В случае ошибки возвращает код ошибки < 0 */
typedef int (*ir9602_uart_read_t)(void * rwarg, void * buffer, int buffer_size);

//! Указатель на функцию для записи данных в уарт связанный с модемом
/*! Функция должна писать сколько может без блокировки вызывающего потока,
 *  но конечно не больше чем предоставлено.
 *  Возвращает количество записанных байт. В случае ошибки возвращает код ошибки < 0 */
typedef int (*ir9602_uart_write_t)(void * rwarg, const void * buffer, int buffer_size);


//! Дескриптор устройства 9602
typedef struct
{
	void * rwarg;
	ir9602_uart_read_t uart_read;
	ir9602_uart_write_t uart_write;

	ir9602_cmd_t cmd;
	char cmd_buffer[IR9602_CMD_BUFFER_SIZE];
	int cmd_size;
	int cmd_carret;

	uint8_t mo_buffer[IR9602_MO_BUFFER_SIZE];
	uint16_t mo_msg_size;
	uint16_t mo_msg_carret;

	uint8_t mt_msg_buffer[IR9602_MT_BUFFER_SIZE];
	uint16_t mt_msg_size;
	uint16_t mt_msg_carret;

} ir9602_t;


//! Результат обработки события от модема
typedef enum
{
	//! нет новых событий (пока что)
	IR9602_POLL_RESULT_NONE,
	//! Модуль ответил каким-то неожиданным событием
	IR9602_POLL_RESULT_EVENT,
	//! Модуль ответил на предидущую команду
	IR9602_POLL_RESULT_CMD_RESP,
	//! Модуль ответил чем-то не понятным впринципе
	IR9602_POLL_RESULT_ERROR,
} ir9602_poll_result_t;


//! Инициализация дескриптора модема
/*! Настривает все поля дескриптора и больше ничего.
 *  Аргументы:
 *  \arg device - указатель на дескриптор устройства
 *  \arg uart_read - указатель на функцию чтения из уарта модем. Подробнее в описании типа.
 *  \arg uart_write - указатель на функцию записи в уарт модема. Подробнее в описании типа.
 *  \arg rwarg - указатель на пользовательский аргумент, передаваемый функция для работы с уартом
 *  */
void ir9602_init(ir9602_t * device, ir9602_uart_read_t uart_read, ir9602_uart_write_t uart_write,
		void * rwarg
);

//! Пробует получить и распарсить одно событие от модема
int ir9602_poll_one(ir9602_t * device);


#endif /* IRIDIUM9602_H_ */
