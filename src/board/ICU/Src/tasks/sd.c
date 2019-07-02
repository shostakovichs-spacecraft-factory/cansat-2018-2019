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
static void sd_startlog(void);


void sd_task (void *pvParameters)
{
	static int8_t _extfilenum = -1, _intfilenum = -1;
	static FIL	_extfile = {0}, _intfile = {0};
	static FIL * currentfile;
	static int8_t * currentfilenum;
	static uint8_t buf[MAVLINK_MAX_PACKET_LEN];
	static mavlink_message_t msg;

	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;

	MX_SDIO_SD_Init();
	MX_FATFS_Init();

	sd_startlog();

	while(1)
	{
		xQueueReceive(sd_queue_handle, &msg, 0xFFFFFFFF);

		if(msg.sysid == 0) //internal
			{ currentfile = &_intfile; currentfilenum = &_intfilenum;}

		else //external
			{ currentfile = &_extfile; currentfilenum = &_extfilenum;}


		if(currentfile->fs == NULL || currentfile->fsize > ICU_SD_MAXFILELEN)
		{
			*currentfilenum += 1;

			if(currentfile->fs != NULL)
			{
				f_sync(currentfile);
				f_close(currentfile);
			}

			char filename[ICU_SD_MAXFILENAMELEN];
			sprintf(filename, ICU_SD_TELFILENAMEFMT, zikush_runsessnum, msg.sysid==0?"int":"ext", *currentfilenum);

			f_open(currentfile, filename, FA_CREATE_NEW | FA_WRITE);
		}

		uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
		UINT infactwritten;

		FRESULT result = f_write(currentfile, buf, len, &infactwritten);
		//if(result != FR_OK || infactwritten != len)

		result = f_sync(currentfile);
	}

	vTaskDelete(NULL);
}

static void sd_startlog(void)
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

