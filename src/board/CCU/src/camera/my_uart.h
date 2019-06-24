#ifndef MY_UART_H
#define MY_UART_H



#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <stm32f4xx_hal.h>



int configure_port(int fd);

typedef struct {
	char *port_name;
	int fd;
	UART_HandleTypeDef huart;
} MY_UART;

MY_UART *my_uart_init(const char port_name[], int flags);

void my_uart_deinit(MY_UART* des);

void uart_pin_rx_init(GPIO_TypeDef *GPIOx, uint32_t pin);

void uart_pin_tx_init(GPIO_TypeDef *GPIOx, uint32_t pin);

int uart_config_default(UART_HandleTypeDef *huart);

int uart_init(MY_UART* des);

int my_uart_tx(MY_UART *des, uint8_t *buffer, size_t size, uint32_t timeout);

int my_uart_rx(MY_UART *des, uint8_t *buffer, size_t size, uint32_t timeout);

int my_uart_skip_rx(MY_UART *des, size_t count, uint32_t timeout);

///////////////////////////////////////////////////////////////
#endif
