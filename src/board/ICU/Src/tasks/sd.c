/*
 * SD task. Handles logging to SD for all the telemetry passing through ICU
 * */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <main.h>

#include "fatfs.h"


SD_HandleTypeDef hsd;


static void MX_SDIO_SD_Init(void);
static void sd_init();


void sd_task (void *pvParameters)
{

	while(1)
	{
		MX_SDIO_SD_Init();
		MX_FATFS_Init();

		sd_startlog();

	}

	vTaskDelete(NULL);
}

static void sd_startlog()
{
	FRESULT fileworkresult;
	char filename[ICU_SD_MAXFILENAMELEN];

	fileworkresult = f_mkdir("0:/zikush");
	if( !( fileworkresult == FR_OK || fileworkresult == FR_EXIST ) )
		printf("Problem %d with zikush folder creation\n", fileworkresult); //FIXME error handlers

	for(zikush_runsessnum = 0; zikush_runsessnum < ICU_SD_SESSNUMBOUNDARY; zikush_runsessnum++)
	{
		sprintf(filename, ICU_SD_SESSFOLDERNAMEFMT, zikush_runsessnum);
		fileworkresult = f_stat(filename, NULL);

		if(fileworkresult != FR_OK)
			break;

		if(zikush_runsessnum == ICU_SD_SESSNUMBOUNDARY)
			zikush_runsessnum = -2; //FIXME proper error handling
	}

	f_mkdir(filename);
}


//Those functions has been fetched from CubeMX generated code
/**
  * @brief SDIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_SDIO_SD_Init(void)
{
	hsd.Instance = SDIO;
	hsd.Init.ClockEdge = SDIO_CLOCK_EDGE_RISING;
	hsd.Init.ClockBypass = SDIO_CLOCK_BYPASS_DISABLE;
	hsd.Init.ClockPowerSave = SDIO_CLOCK_POWER_SAVE_DISABLE;
	hsd.Init.BusWide = SDIO_BUS_WIDE_1B;
	hsd.Init.HardwareFlowControl = SDIO_HARDWARE_FLOW_CONTROL_DISABLE;
	hsd.Init.ClockDiv = 100;
}

