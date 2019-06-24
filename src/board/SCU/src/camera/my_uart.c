
#include "my_uart.h"
#include <diag/Trace.h>

#define UART_TIMEOUT 100

int uart_config_default(UART_HandleTypeDef *huart)
{
	huart->Instance = USART1;
	huart->Init.BaudRate = 57600;
	huart->Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart->Init.Mode = UART_MODE_TX_RX;
	huart->Init.OverSampling = UART_OVERSAMPLING_16;
	huart->Init.Parity = UART_PARITY_NONE;
	huart->Init.StopBits = UART_STOPBITS_1;
	huart->Init.WordLength = UART_WORDLENGTH_8B;
	return 0;
}

void uart_pin_tx_init(GPIO_TypeDef *GPIOx, uint32_t pin)
{
	GPIO_InitTypeDef pa_init;
	pa_init.Alternate = GPIO_AF7_USART3;
	pa_init.Mode = GPIO_MODE_AF_PP;
	pa_init.Pin = pin;
	pa_init.Pull = GPIO_NOPULL;
	pa_init.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOx, &pa_init);
}
void uart_pin_rx_init(GPIO_TypeDef *GPIOx, uint32_t pin)
{
	GPIO_InitTypeDef pa_init;
	pa_init.Alternate = GPIO_AF7_USART3;
	pa_init.Mode = GPIO_MODE_AF_PP;
	pa_init.Pin = pin;
	pa_init.Pull = GPIO_NOPULL;
	pa_init.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOx, &pa_init);
}
int uart_init(MY_UART *des)
{

	int rc = HAL_UART_Init(&des->huart);
	if(rc)
	{
		trace_printf("ERROR: can't init uart\n");
	}
	return rc;
}


int my_uart_tx(MY_UART *des, uint8_t *buffer, size_t size, uint32_t timeout)
{
	int rc = HAL_UART_Transmit(&des->huart, buffer, size, timeout);
	if(rc)
	{
		trace_printf("ERROR: can't transmit uart data: %d\n", rc);
		return -1;
	}
	return size;
}

int my_uart_rx(MY_UART *des, uint8_t *buffer, size_t size,uint32_t timeout)
{
	int rc = HAL_UART_Receive(&des->huart, buffer, size, timeout);
	if(rc)
	{
		trace_printf("ERROR: can't receive uart data: %d\n", rc);
		//return -1;
	}
	return size;
}

int my_uart_skip_rx(MY_UART *des, size_t count, uint32_t timeout)
{
	uint8_t buf[count];

	HAL_UART_Receive(&des->huart, buf, count, timeout);
	return count;
}


///////////////////////////////////////////////////////////////

