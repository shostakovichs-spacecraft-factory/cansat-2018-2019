#include "camera_interface.h"



#define PRINT_RESPONSE
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
#define VC0706_RESUMEFRAME 0x3
#define VC0706_STEPFRAME 0x2

#define VC0706_640x480 0x00
#define VC0706_320x240 0x11
#define VC0706_160x120 0x22

#define VC0706_MOTIONCONTROL 0x0
#define VC0706_UARTMOTION 0x01
#define VC0706_ACTIVATEMOTION 0x01

#define VC0706_SET_ZOOM 0x52
#define VC0706_GET_ZOOM 0x53



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

uint64_t get_time_ms()
{
	struct timeval a;
	gettimeofday(&a, NULL);

	uint64_t res = a.tv_usec/1000.0 + a.tv_sec*1000.0;

	return res;
}

ssize_t cam_send_buf(CAMERA *cam, uint8_t *buffer, size_t size)
{
	ssize_t written = my_uart_tx(cam->uart_des, buffer, size);
	return written;
}

ssize_t cam_send_byte(CAMERA *cam, uint8_t byte)
{
	uint8_t bytes[] = {byte};
	ssize_t written = my_uart_tx(cam->uart_des, bytes, 1);
	return written;
}

ssize_t cam_get_buf(CAMERA *cam, uint8_t *buffer, size_t size)
{
	ssize_t readed = my_uart_rx(cam->uart_des, buffer, size);
	debug(buffer, size);
	return readed;
}



ssize_t send_command(CAMERA *cam, uint8_t cmd, uint8_t *args, uint8_t argn)
{
	ssize_t sent = 0;
	uint8_t arr[] = {0x56, cam->serial_num, cmd, argn};

	int is_ok = 0;

	is_ok = cam_send_buf(cam, arr, sizeof(arr));

		if(is_ok < 0)
			return is_ok;
		else if(is_ok != sizeof(arr))
			return -1;

		sent += is_ok;

	is_ok = cam_send_buf(cam, args, argn);

		if(is_ok < 0)
			return is_ok;
		else if(is_ok != argn)
			return -2;

		sent += is_ok;

	return sent;
}

ssize_t skip_response(CAMERA *cam, size_t size, int timeout_ms)
{
	if(size == 0)
		return 0;

	uint64_t t0, t1;
	size_t readed = 0;

	t0 = t1 = get_time_ms();

	uint8_t temp;

	do{
		ssize_t len = cam_get_buf(cam, &temp, 1);

		if(len < 0)
		{
			perror("can't skip response");
			return -1;
		}

		readed += len;
		t1 = get_time_ms();
	}while(size > readed && timeout_ms > t1 - t0);

	return readed;
}

//uint8_t wait_response()

ssize_t read_response(CAMERA *cam, uint8_t *buffer, size_t size, int timeout_ms)
{
	if(size == 0)
		return 0;

	uint64_t t0, t1;
	size_t readed = 0;

	t0 = get_time_ms();


	do
	{
		ssize_t len = cam_get_buf(cam, buffer + readed, 1);

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

	print_buffer(buffer, readed);

	return readed;
}


int is_response_ok(CAMERA *cam, uint8_t *buffer, size_t size, uint8_t command)
{
	if(buffer[0] == 0x76 && buffer[1] == cam->serial_num && buffer[2] == command && buffer[3] == 0)
	{
		return 1;
	}
	return 0;
}
/*
int run_command(CAMERA *cam, uint8_t command, uint8_t *args, uint8_t argn)
{
	ssize_t sent = send_command(cam, command, args, argn);

	if(sent != argn + 4)
		return -1;
	return 0;
}
*/
int run_command(CAMERA *cam, uint8_t command, uint8_t *args, uint8_t argn, size_t reply_size, int flush_flag)
{
	if(flush_flag)
		skip_response(cam, 100, 1000);


	ssize_t sent = send_command(cam, command, args, argn);

	if(sent != argn + 4)
	{
		printf("Error: can't send command\n");
		return -1;
	}

	size_t length;

	if(reply_size == 4 || reply_size == 5)
	{
		length = 0;
	}
	else if(reply_size <= 3)
	{
		printf("Error: invalid reply_size in run_command. Should be >= 4\n");
		return -10;
	}
	else
	{
		length = reply_size - 4;
		reply_size = 4;
	}

	uint8_t response[5];
	ssize_t readed = read_response(cam, response, reply_size, CAMERADELAY);

	skip_response(cam, length, CAMERADELAY);

	if(readed != reply_size)
	{
		printf("Epic error: cam sends something strange (run_command)\n");
		return -2;
	}

	if(!is_response_ok(cam, response, reply_size, command))
	{
		printf("Error: cam error. Cam sends error or it sends something strange\n");
		return -3;
	}

	return 0;
}


int camera_frame_buff_ctrl(CAMERA *cam, uint8_t command) {
	uint8_t args[] = {0x1, command};
	return run_command(cam, VC0706_FBUF_CTRL, args, sizeof(args), 5, 1);
}

void camera_reset_image(CAMERA *cam)
{
   cam->frame_ptr = 0;
}

int camera_reset(CAMERA *cam)
{
	int a = run_command(cam, VC0706_RESET, NULL, 0, 4, 1);
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

ssize_t camera_get_image_buffer_size(CAMERA *cam)
{
	uint8_t args[] = {0x1, 0x0};
	return run_command(cam, VC0706_GET_FBUF_LEN, args, sizeof(args), 4, 1);
}

ssize_t camera_read_picture(CAMERA *cam, uint8_t *buffer, camera_type size)
{

	uint8_t args[] = {0x0, 0x0F,
	                  0, 0, cam->frame_ptr >> 8, cam->frame_ptr & 0xFF,
	                  0, 0, size >> 8, size & 0xFF,
	                  0, 0x0F
					};

	if(run_command(cam, VC0706_READ_FBUF, args, sizeof(args), 5, 0))
		perror("can't run command: read buffer");

	ssize_t len = read_response(cam, buffer, size, 100);
	len += skip_response(cam, 5, CAMERADELAY) - 5;

	if(len != size)
		perror("bad response: read buffer");

	cam->frame_ptr += len;

	return len;
}

CAMERA *camera_init()
{
	CAMERA *cam = (CAMERA*)malloc(sizeof(CAMERA));

	cam->frame_ptr = 0;
	cam->serial_num = 0;
	cam->uart_des = my_uart_init("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_SYNC);

	skip_response(cam, 100, 100);

	return cam;
}

void camera_deinit(CAMERA *cam)
{
	my_uart_deinit(cam->uart_des);
	free(cam);
}

int camera_load_and_save_picture(CAMERA *cam, FILE *file)
{
	camera_reset_image(cam);
	const size_t buf_size = 100;
	uint8_t buffer[buf_size];
	uint8_t *pointer = buffer;

	printf("skipping: %d \n", skip_response(cam, 100, 100));
	camera_get_image_buffer_size(cam);

	read_response(cam, buffer, 5, CAMERADELAY);

	unsigned long long length = (buffer[1] << 24) + (buffer[2] << 16) + (buffer[3] << 8) + buffer[4];

	int remaining = length;

	while(remaining > 0)
	{
		int buf_size_litte = buf_size - 20;

		if(remaining < buf_size_litte)
			buf_size_litte = remaining;

		ssize_t len = camera_read_picture(cam, buffer, buf_size_litte);

		fwrite(pointer, sizeof(uint8_t), len, file);
		remaining -= len;
		printf("%d\n", remaining);
		usleep(10000);
	}

	return 0;
}


