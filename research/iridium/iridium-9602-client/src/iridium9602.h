/*
 * iridium9602.h
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#ifndef IRIDIUM9602_H_
#define IRIDIUM9602_H_

#include <stdint.h>
#include <stddef.h>

#include "iridium9602_commands.h"

//! Размер для буфера для сериализации команд
/*! FIXME: 50 байт хватит ведь? */
#define IR9602_CMD_BUFFER_SIZE (50)

//! Максимальный размер MO сообщения для 9602
#define IR9602_MO_MSG_MAX_SIZE (340)

//! Максимальный размер MT сообщения для 9602
#define IR9602_MT_MSG_MAX_SIZE (279)

//! Размер буфера для данных MT/MO сообщений
/*! буфер кроме сообщения хранит 2 байта для размера сообщения
 *  и 2 байта для контрольной суммы */
#define IR9602_DATA_BUFFER_SIZE  (2+340+2)


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


// Состояния драйвера
typedef enum
{
	IR9602_STATE_IDLE,
	IR9602_STATE_CMD,
	IR9602_STATE_DATA_WRITE,
	IR9602_STATE_DATA_READ,
	IR9602_STATE_AWAIT_RESP,
} ir9602_state_t;


//! Результат обработки события от модема
typedef enum
{
	//! нет новых событий (пока что)
	IR9602_POLL_RESULT_NONE,
	//! Модуль ответил каким-то неожиданным событием
	IR9602_POLL_RESULT_EVENT,
	//! Выполнение команды успешно завершено
	IR9602_POLL_RESULT_CMD_COMPLETE,
	//! Модуль ответил чем-то не понятным впринципе
	IR9602_POLL_RESULT_UNEXPECTED,
} ir9602_poll_result_t;




//! Дескриптор устройства 9602
typedef struct
{
	void * rwarg;
	ir9602_uart_read_t uart_read;
	ir9602_uart_write_t uart_write;

	ir9602_cmd_t cmd;
	char cmd_buffer[IR9602_CMD_BUFFER_SIZE];
	uint16_t cmd_size;
	uint16_t cmd_carret;

	uint8_t data_buffer[IR9602_DATA_BUFFER_SIZE];
	uint16_t data_size;
	uint16_t data_carret;

	ir9602_state_t state;
} ir9602_t;



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


//! Выполнение команды AT
int ir9602_cmd_at(ir9602_t * device);

//! Функция иницирует асинхронную операцию отправки MO сообщения на модем (при помощи команды SBDWB)
/*! Возвращает 0 если все хорошо и -EBUSY, если в данный момент выполняется какая-то другая команда */
int ir9602_cmd_sbdwb(ir9602_t * device, const void * buffer, int buffer_size);

//! Функция иницирует асинхронную операцию получения MT сообщения с модема (SBDRB)
/*! Возвращает 0 если все хорошо и -EBUSY, если в данный момент выполняется какая-то другая команда */
int ir9602_cmd_sbdrb(ir9602_t * device);


int ir9602_get_mt_data(ir9602_t * device, void * buffer, int buffer_size);

//! Пробует получить распарсить одно событие от модема
int ir9602_poll_one(ir9602_t * device);


#endif /* IRIDIUM9602_H_ */
