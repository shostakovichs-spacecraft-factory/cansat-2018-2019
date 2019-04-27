/**
  ******************************************************************************
  * @file    stm32f4xx_hal_msp_template.c
  * @author  MCD Application Team
  * @version V1.5.0
  * @date    06-May-2016
  * @brief   This file contains the HAL System and Peripheral (PPP) MSP initialization
  *          and de-initialization functions.
  *          It should be copied to the application folder and renamed into 'stm32f4xx_hal_msp.c'.           
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

// [ILG]
#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#endif

/** @addtogroup STM32F4xx_HAL_Driver
  * @{
  */

/** @defgroup HAL_MSP HAL MSP
  * @brief HAL MSP module.
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions HAL MSP Private Functions
  * @{
  */


void HAL_UART1_MspInit(void);
void HAL_UART1_MspDeInit(void);
void HAL_I2C1_MspInit(void);
void HAL_I2C1_MspDeInit(void);

/**
  * @brief  Initializes the Global MSP.
  * @note   This function is called from HAL_Init() function to perform system
  *         level initialization (GPIOs, clock, DMA, interrupt).
  * @retval None
  */
void HAL_MspInit(void)
{
	__GPIOA_CLK_ENABLE();
	__GPIOB_CLK_ENABLE();
	HAL_UART1_MspInit();
	HAL_I2C1_MspInit();
}

/**
  * @brief  DeInitializes the Global MSP.
  * @note   This functiona is called from HAL_DeInit() function to perform system
  *         level de-initialization (GPIOs, clock, DMA, interrupt).
  * @retval None
  */
void HAL_MspDeInit(void)
{
	HAL_UART1_MspDeInit();
	HAL_I2C1_MspDeInit();
	__GPIOA_CLK_DISABLE();
	__GPIOB_CLK_DISABLE();
}

/**
  * @brief  Initializes the PPP MSP.
  * @note   This functiona is called from HAL_PPP_Init() function to perform 
  *         peripheral(PPP) system level initialization (GPIOs, clock, DMA, interrupt)
  * @retval None
  */
void HAL_PPP_MspInit(void)
{

}

/**
  * @brief  DeInitializes the PPP MSP.
  * @note   This functiona is called from HAL_PPP_DeInit() function to perform 
  *         peripheral(PPP) system level de-initialization (GPIOs, clock, DMA, interrupt)
  * @retval None
  */
void HAL_PPP_MspDeInit(void)
{

}

void HAL_UART1_MspInit(void)
{
	__USART1_CLK_ENABLE();

	GPIO_InitTypeDef pa_init;
	pa_init.Alternate = GPIO_AF7_USART1;
	pa_init.Mode = GPIO_MODE_AF_PP;
	pa_init.Pin = GPIO_PIN_9;
	pa_init.Pull = GPIO_NOPULL;
	pa_init.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOA, &pa_init);

	pa_init.Alternate = GPIO_AF7_USART1;
	pa_init.Mode = GPIO_MODE_INPUT;
	pa_init.Pin = GPIO_PIN_10;
	pa_init.Pull = GPIO_NOPULL;
	pa_init.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOA, &pa_init);
}

void HAL_UART1_MspDeInit(void)
{
	__USART1_CLK_DISABLE();

	HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9);
	HAL_GPIO_DeInit(GPIOA, GPIO_PIN_10);
}

void HAL_SPI1_MspInit(void)
{
	__SPI1_CLK_ENABLE();

	GPIO_InitTypeDef pa_init;
	pa_init.Alternate = GPIO_AF5_SPI1;
	pa_init.Mode = GPIO_MODE_AF_PP;
	pa_init.Pin = GPIO_PIN_4;
	pa_init.Pull = GPIO_NOPULL;
	pa_init.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOA, &pa_init);

	pa_init.Mode = GPIO_MODE_AF_PP;
	pa_init.Pin = GPIO_PIN_5;
	HAL_GPIO_Init(GPIOA, &pa_init);

	pa_init.Mode = GPIO_MODE_AF_PP;
	pa_init.Pin = GPIO_PIN_6;
	HAL_GPIO_Init(GPIOA, &pa_init);

	pa_init.Mode = GPIO_MODE_AF_PP;
	pa_init.Pin = GPIO_PIN_7;
	HAL_GPIO_Init(GPIOA, &pa_init);
}

void HAL_SPI1_MspDeInit(void)
{
	HAL_GPIO_DeInit(GPIOA, GPIO_PIN_4);
	HAL_GPIO_DeInit(GPIOA, GPIO_PIN_5);
	HAL_GPIO_DeInit(GPIOA, GPIO_PIN_6);
	HAL_GPIO_DeInit(GPIOA, GPIO_PIN_7);

	__SPI1_CLK_DISABLE();
}


void HAL_I2C1_MspInit(void)
{
	__I2C1_CLK_ENABLE();


	GPIO_InitTypeDef pa_init;
	pa_init.Alternate = GPIO_AF4_I2C1;
	pa_init.Mode = GPIO_MODE_AF_OD;
	pa_init.Pin = GPIO_PIN_6;
	pa_init.Pull = GPIO_PULLUP;
	pa_init.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOB, &pa_init);

	pa_init.Mode = GPIO_MODE_AF_OD;
	pa_init.Pin = GPIO_PIN_7;
	HAL_GPIO_Init(GPIOB, &pa_init);
}

void HAL_I2C1_MspDeInit(void)
{
	HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6);
	HAL_GPIO_DeInit(GPIOB, GPIO_PIN_7);

	__I2C1_CLK_DISABLE();
}
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

// [ILG]
#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
