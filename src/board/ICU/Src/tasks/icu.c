/*
 * ICU main task. Runs state machine to control all the probe.
 * */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <main.h>


void ICU_task (void *pvParameters)
{
	while(1)
	{

	}

	vTaskDelete(NULL);
}
