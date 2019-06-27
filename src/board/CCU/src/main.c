// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "diag/Trace.h"

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_can.h>

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>
#include <spectrum.h>
#include <usart.h>
#include <can.h>

#include "zikush_config.h"

/* coprocessor control register (fpu) */
#ifndef SCB_CPACR
#define SCB_CPACR (*((uint32_t*) (((0xE000E000UL) + 0x0D00UL) + 0x088)))
#endif


void SysTick_Handler(void)
{
	HAL_IncTick();
}

int main(int argc, char* argv[])
{
	/* enable FPU on Cortex-M4F core */
	SCB_CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2)); /* set CP10 Full Access and set CP11 Full Access */

	SysTick_Config(SystemCoreClock / 1000);

#ifdef CCU_TESTMODE
	usart_init();
#endif

	spectrum_init_capture();
	can_init();

	while(true)
	{
		if(can_spectrum_request)
		{
			spectrum_take(can_spectrum_request == SPRQ_FULL, can_spectrum_processing_y_start, can_spectrum_processing_y_end, \
																can_spectrum_processing_x_start, can_spectrum_processing_x_end);
			can_spectrum_request = SPRQ_NO;
		}

		//TODO add cam requests processing


		HAL_Delay(200); //TODO Add transition into true sleep mode?

#ifdef CCU_TESTMODE
		can_spectrum_request = SPRQ_FULL;
		HAL_Delay(800);
#endif
	}
}
