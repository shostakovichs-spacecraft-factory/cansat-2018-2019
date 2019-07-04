/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define BME_CS_Pin GPIO_PIN_4
#define BME_CS_GPIO_Port GPIOA
#define BME_SCK_Pin GPIO_PIN_5
#define BME_SCK_GPIO_Port GPIOA
#define BME_MISO_Pin GPIO_PIN_6
#define BME_MISO_GPIO_Port GPIOA
#define BME_MOSI_Pin GPIO_PIN_7
#define BME_MOSI_GPIO_Port GPIOA
#define MAG_SCL_Pin GPIO_PIN_10
#define MAG_SCL_GPIO_Port GPIOB
#define MAG_SDA_Pin GPIO_PIN_11
#define MAG_SDA_GPIO_Port GPIOB
#define LSM_CS_Pin GPIO_PIN_12
#define LSM_CS_GPIO_Port GPIOB
#define LSM_SCK_Pin GPIO_PIN_13
#define LSM_SCK_GPIO_Port GPIOB
#define LSM_MISO_Pin GPIO_PIN_14
#define LSM_MISO_GPIO_Port GPIOB
#define LSM_MOSI_Pin GPIO_PIN_15
#define LSM_MOSI_GPIO_Port GPIOB
#define ADC_SCL_Pin GPIO_PIN_6
#define ADC_SCL_GPIO_Port GPIOB
#define ADC_SDA_Pin GPIO_PIN_7
#define ADC_SDA_GPIO_Port GPIOB


/* USER CODE BEGIN Private defines */
extern SPI_HandleTypeDef hspi1;
extern I2C_HandleTypeDef hi2c1;
extern SPI_HandleTypeDef hspi2;
extern CAN_HandleTypeDef hcan;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
