#include "camera_interface.h"

#include <diag/Trace.h>

#define printf trace_printf
#define perror trace_printf

//#define PRINT_RESPONSE
//#define PRINT_UART

#define VC0706_RESET  0x26
#define VC0706_GEN_VERSION 0x11
#define VC0706_READ_FBUF 0x32
#define VC0706_GET_FBUF_LEN 0x34
#define VC0706_FBUF_CTRL 0x36
#define VC0706_DOWNSIZE_CTRL 0x54
#define VC0706_DOWNSIZE_STATUS 0x55
#define VC0706_READ_DATA 0x30
#define VC0706_WRITE_DATA 0x31
//#define VC0706_COMM_MOTION_CTRL 0x37
//#define VC0706_COMM_MOTION_STATUS 0x38
//#define VC0706_COMM_MOTION_DETECTED 0x39
//#define VC0706_MOTION_CTRL 0x42
//#define VC0706_MOTION_STATUS 0x43
//#define VC0706_TVOUT_CTRL 0x44
//#define VC0706_OSD_ADD_CHAR 0x45

#define VC0706_STOPCURRENTFRAME 0x0
#define VC0706_STOPNEXTFRAME 0x1
#define VC0706_RESUMEFRAME 0x2
#define VC0706_STEPFRAME 0x3


#define VC0706_MOTIONCONTROL 0x0
#define VC0706_UARTMOTION 0x01
#define VC0706_ACTIVATEMOTION 0x01

#define VC0706_SET_ZOOM 0x52
#define VC0706_GET_ZOOM 0x53

#define VC0706_WRITE_CHIP 0x01
#define VC0706_WRITE_SENSOR_REGISTER 0x02
#define VC0706_WRITE_CCIR656REGISTER 0x03
#define VC0706_WRITE_I2C_EEPROM 0x04
#define VC0706_WRITE_SPI_EEPROM 0x05
#define VC0706_WRITE_SPI_FLASH 0x06

#define VC0706_IMAGE_SIZE_ADDRESS 0x0019

#define CAMERA_TIMEOUT 10000
#ifdef PRINT_RESPONSE
void print_buffer(uint8_t *buffer, size_t size)
{
	for(int i = 0; i < size; i++)
	{
		printf("0x%02x ", buffer[i]);
	}
	printf("\n");
}
#else
void print_buffer(uint8_t *buffer, size_t size)
{
}
#endif

#ifdef PRINT_UART
void debug(uint8_t *buffer, size_t size)
{
	for(int i = 0; i < size; i++)
	{
		printf("0x%02x ", buffer[i]);
	}
	printf("\n");
}
#else
void debug(uint8_t *buffer, size_t size)
{}
#endif

uint32_t get_time_ms()
{
	return HAL_GetTick();
}

ssize_t cam_send_buf(CAMERA *cam, uint8_t *buffer, size_t size, uint32_t timeout)
{
	ssize_t written = my_uart_tx(cam->uart_des, buffer, size, timeout);
	return written;
}

ssize_t cam_send_byte(CAMERA *cam, uint8_t byte, uint32_t timeout)
{
	uint8_t bytes[] = {byte};
	ssize_t written = my_uart_tx(cam->uart_des, bytes, 1, timeout);
	return written;
}

ssize_t cam_get_buf(CAMERA *cam, uint8_t *buffer, size_t size, uint32_t timeout)
{
	ssize_t readed = my_uart_rx(cam->uart_des, buffer, size, timeout);
	debug(buffer, size);
	return readed;
}



ssize_t send_command(CAMERA *cam, uint8_t cmd, uint8_t *args, uint8_t argn)
{
	ssize_t sent = 0;
	uint8_t arr[4 + argn];
	arr[0] = 0x56;
	arr[1] = cam->serial_num;
	arr[2] = cmd;
	arr[3] = argn;
	for(int i = 0; i < argn; i++)
	{
		arr[4 + i] = args[i];
	}

	int is_ok = 0;

	is_ok = cam_send_buf(cam, arr, 4 + argn, CAMERA_TIMEOUT);

		if(is_ok < 0)
			return is_ok;
		else if(is_ok != (int)sizeof(arr))
			return -1;

		sent += is_ok;


	return sent;
}

ssize_t skip_response(CAMERA *cam, size_t size, uint32_t timeout_ms)
{
	if(size == 0)
		return 0;

	return my_uart_skip_rx(cam->uart_des, size, timeout_ms);
}

//uint8_t wait_response()

ssize_t read_response(CAMERA *cam, uint8_t *buffer, size_t size, uint32_t timeout_ms)
{
	if(size == 0)
		return 0;

	uint32_t t0, t1;
	size_t readed = 0;

	t0 = get_time_ms();

/*
	do
	{
		ssize_t len = cam_get_buf(cam, buffer + readed, 1, timeout_ms);

		if(len < 0)
		{
			perror("can't get response");
			return -1;
		}

		readed += len;
		t1 = get_time_ms();

	}while(size > readed && timeout_ms > t1 - t0);

	if(timeout_ms <= t1 - t0)
	{
		printf("Error: read response timeout\n");
	}
*/

	readed = cam_get_buf(cam, buffer, size, timeout_ms);

	print_buffer(buffer, readed);

	return readed;
}


int is_response_ok(CAMERA *cam, uint8_t *buffer, uint8_t command)
{
	if(buffer[0] == 0x76 && buffer[1] == cam->serial_num && buffer[2] == command && buffer[3] == 0)
	{
		return 1;
	}
	return 0;
}

int camera_run_command(CAMERA *cam, uint8_t command, uint8_t *args, uint8_t argn,
		uint8_t *reply, size_t count, int flush_flag)
{
	if(flush_flag)
		skip_response(cam, 100, 1000);


	ssize_t sent = send_command(cam, command, args, argn);

	if(sent != argn + 4)
	{
		printf("Error: can't send command\n");
		return -1;
	}
	uint8_t *arr = reply;
	uint8_t pff[4];
	for(int i = 0; i < 4; i++)
		pff[i] = 0;
	if(!reply || count < 4)
	{
		arr = pff;
		count = 4;
	}
	read_response(cam, arr, count, CAMERA_TIMEOUT);

	if(!is_response_ok(cam, arr, command))
	{
		printf("Error: cam error. Cam sends error or it sends something strange\n");
		return -3;
	}

	return 0;
}


int camera_frame_buff_ctrl(CAMERA *cam, uint8_t command) {
	uint8_t args[] = {0x1, command};
	return camera_run_command(cam, VC0706_FBUF_CTRL, args, sizeof(args), 0, 0, 1);
}

int camera_write_data(CAMERA *cam, uint16_t address, uint8_t *data, uint8_t count)
{
	size_t size = 4 + count;
	uint8_t args[size];

	args[0] = VC0706_WRITE_SPI_EEPROM;
	args[1] = count;
	args[2] = ((uint8_t*)(&address))[1];
	args[3] = ((uint8_t*)(&address))[0];

	for(int i = 0; i < count; i++)
	{
		args[4 + i] = data[i];
	}

	return camera_run_command(cam, VC0706_WRITE_DATA, args, sizeof(args), 0, 0, 1);
}

int camera_set_image_size(CAMERA *cam, uint8_t size)
{
	return camera_write_data(cam, VC0706_IMAGE_SIZE_ADDRESS, &size, 1);
}

void camera_reset_image(CAMERA *cam)
{
   cam->frame_ptr = 0;
   cam->image_size = 0;
}

int camera_reset(CAMERA *cam)
{
	int a = camera_run_command(cam, VC0706_RESET, NULL, 0, 0, 0, 1);
	skip_response(cam, 100, 100);
	return a;
}

int camera_resume(CAMERA *cam)
{
	return camera_frame_buff_ctrl(cam, VC0706_RESUMEFRAME);
}

int camera_stop(CAMERA *cam)
{
	camera_reset_image(cam);
	int res = camera_frame_buff_ctrl(cam, VC0706_STOPCURRENTFRAME);
	return res;
}

int camera_load_image_size(CAMERA *cam)
{
	uint8_t reply[9];
	uint8_t args[] = {0x1, 0x0};
	int rc = camera_run_command(cam, VC0706_GET_FBUF_LEN, args, sizeof(args), reply, 9, 1);
	cam->image_size = reply[5] << 24 | reply[6] << 16 | reply[7] << 8 | reply[8];
	return rc;
}
int camera_prepare_to_read(CAMERA *cam)
{
	skip_response(cam, 100, 100);
	return 0;
}
size_t camera_read_picture(CAMERA *cam, uint8_t *buffer, size_t size)
{

	if(size <= 10)
	{
		trace_printf("ERROR: too small buffer size\n");
	}
	size -= 10;
	if(size > cam->image_size - cam->frame_ptr)
	{
		size = cam->image_size - cam->frame_ptr;
	}
	uint8_t args[] = {0x0, 0x0F,
	                  0, 0, cam->frame_ptr >> 8, cam->frame_ptr & 0xFF,
	                  0, 0, size >> 8, size & 0xFF,
	                  0, 0x00
					};


	if(camera_run_command(cam, VC0706_READ_FBUF, args, sizeof(args), buffer, size + 10, 0))
		perror("can't run command: read buffer");


	cam->frame_ptr += size;

	return size;
}

int camera_init(CAMERA *hcam, MY_UART *huart)
{

	hcam->frame_ptr = 0;
	hcam->serial_num = 0;
	hcam->image_size = 0;
	hcam->uart_des = huart;

	skip_response(hcam, 100, 100);

	return 0;
}

void camera_deinit(CAMERA *cam)
{
	my_uart_deinit(cam->uart_des);
	free(cam);
}


int camera_take_picture(CAMERA *cam)
{
	if(camera_stop(cam))
	{
		printf("error: can't stop cam\n");
		return 1;
	}

	camera_load_image_size(cam);

	return 0;
}

int camera_is_all_image_loaded(CAMERA* cam)
{
	return cam->frame_ptr == cam->image_size;
}

int camera_restore_picture(CAMERA *cam)
{
	camera_reset_image(cam);

	if(camera_resume(cam))
	{
		printf("error: can't resume cam\n");
		return 1;
	}
	return 0;
}
/*
int camera_load_and_save_picture(CAMERA *cam, FILE *file)
{
	const size_t buf_size = 100;
	uint8_t buffer[buf_size];
	uint8_t *pointer = buffer;

	usleep(100000);
	while(!camera_is_all_image_loaded(cam))
	{
		ssize_t len = camera_read_picture(cam, buffer, 80);

		fwrite(pointer, sizeof(uint8_t), len, file);
		usleep(10000);
	}

	return 0;
}


*/
