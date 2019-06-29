/*
 * Time.c
 *
 *  Created on: 9 мая 2019 г.
 *      Author: sereshotes
 */

#include <stm32f4xx_hal.h>

#include "Time.h"

__IO uint32_t uTick;

void delay_us(uint32_t us)
{
	 uint32_t startTick = DWT->CYCCNT,
	             delayTicks = us * (SystemCoreClock/1000000);

	 while (DWT->CYCCNT - startTick < delayTicks);
}
void delay_us_init(void)
{
    if (1) {
    	//DWT->LAR = 0xC5ACCE55;
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
        DWT->CYCCNT = 0;
        DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    }
}
