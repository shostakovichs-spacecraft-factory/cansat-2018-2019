#ifndef MY_UART_H
#define MY_UART_H

#include <unistd.h>
#include <fcntl.h>
#include <termios.h>


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


int configure_port(int fd);

typedef struct {
	char *port_name;
	int fd;
} MY_UART;

MY_UART *my_uart_init(const char port_name[], int flags);

void my_uart_deinit(MY_UART* des);


int my_uart_tx(MY_UART *des, uint8_t *buffer, size_t size);

int my_uart_rx(MY_UART *des, uint8_t *buffer, size_t size);


///////////////////////////////////////////////////////////////
#endif
