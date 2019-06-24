/*
 * spi.h
 *
 *  Created on: 1 июн. 2019 г.
 *      Author: sereshotes
 */

#ifndef SPI_H_
#define SPI_H_

#include <stm32f4xx_hal.h>

int spi_init(SPI_HandleTypeDef * hspi);

int spi_deinit(SPI_HandleTypeDef * hspi);

int spi_config_default(SPI_HandleTypeDef * hspi);

int spi_pin_sck_init(SPI_HandleTypeDef *hspi, GPIO_TypeDef* GPIOX, uint32_t pin);

int spi_pin_miso_init(SPI_HandleTypeDef *hspi, GPIO_TypeDef* GPIOX, uint32_t pin);

int spi_pin_mosi_init(SPI_HandleTypeDef *hspi, GPIO_TypeDef* GPIOX, uint32_t pin);

int spi_pin_nss_init(SPI_HandleTypeDef *hspi, GPIO_TypeDef* GPIOX, uint32_t pin);
#endif /* SPI_H_ */
