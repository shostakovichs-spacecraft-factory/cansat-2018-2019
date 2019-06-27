/*
 * iridium9602.h
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#ifndef IR9602_H_
#define IR9602_H_

#include <stdint.h>
#include <stddef.h>

#include "ir9602_commands.h"
#include "ir9602_events.h"

//! Размер для буфера для сериализации команд и аккумулирования событий
/*! FIXME: 50 байт хватит ведь? */
#define IR9602_CMDEVT_BUFFER_SIZE (50)

//! Максимальный размер MO сообщения для 9602
#define IR9602_MO_MSG_MAX_SIZE (340)

//! Максимальный размер MT сообщения для 9602
#define IR9602_MT_MSG_MAX_SIZE (279)


//! Указатель на функцию для чтения данных из уарта связанного с модемом
/*! Функция читает ровно один байт, если может. Если не может - дает ошибку <0 */
typedef int (*ir9602_uart_getch_t)(void * user_arg);

//! Указатель на функцию для записи данных в уарт связанный с модемом
/*! Функция пишет ровно один байт, если может. Если не может - дает ошибку <0 */
typedef int (*ir9602_uart_putch_t)(void * user_arg, uint8_t byte);

//! Пользовательский хук для обработки абсолютно любых событий, получаемых от модема
/*! Можно использовать а можно и нет */
typedef void (*ir9602_evt_hook_t)(void * user_arg, const ir9602_evt_t * event);

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
	void * user_arg;
	ir9602_uart_getch_t getch;
	ir9602_uart_putch_t putch;
	ir9602_evt_hook_t evt_hook;
	char cmdevt_buffer[IR9602_CMDEVT_BUFFER_SIZE];
} ir9602_t;



//! Инициализация дескриптора модема
/*! Настривает все поля дескриптора и больше ничего. */
void ir9602_init(ir9602_t * device, void * user_arg,
		ir9602_uart_getch_t getch, ir9602_uart_putch_t putch,
		ir9602_evt_hook_t evt_hook
);

int ir9602_sbdwb(ir9602_t * device, const void * data, int data_size, ir9602_evt_errcode_t * err_evt);

int ir9602_sbdi(ir9602_t * device, ir9602_evt_sbdi_t * evt_sbdi);

#endif /* IR9602_H_ */
