// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>

#include "zikush_config.h"

/* coprocessor control register (fpu) */
#ifndef SCB_CPACR
#define SCB_CPACR (*((uint32_t*) (((0xE000E000UL) + 0x0D00UL) + 0x088)))
#endif

// ----- main() ---------------------------------------------------------------
// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

uint8_t spectrum_photo[CCU_SPECTRUM_WIDTH * CCU_SPECTRUM_HEIGHT];
boolean spectrum_photo_ready;

int main(int argc, char* argv[])
{
	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;

	/* enable FPU on Cortex-M4F core */
	SCB_CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2)); /* set CP10 Full Access and set CP11 Full Access */


}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
