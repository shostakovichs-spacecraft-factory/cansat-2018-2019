#ifndef CAMERA_INTERFACE_H
#define CAMERA_INTERFACE_H


#include <stdint.h>

#include "my_uart.h"

#define VC0706_640x480 0x00
#define VC0706_320x240 0x11
#define VC0706_160x120 0x22

#define CAMERA_BUF_SIZE 100
#define CAMERADELAY 1000

typedef uint16_t camera_type;

typedef struct{
	MY_UART *uart_des;
	//Номер байта начала чтения изображения в буфере камеры.
	camera_type frame_ptr;
	uint8_t serial_num;
	camera_type image_size;
} CAMERA;

void print_buffer(uint8_t *buffer, size_t size);


int camera_init(CAMERA *hcam, MY_UART *huart);

void camera_deinit(CAMERA *cam);

size_t camera_read_picture(CAMERA *cam, uint8_t *buffer, size_t size);

int camera_restore_picture(CAMERA *cam);

int camera_is_all_image_loaded(CAMERA* cam);

int camera_take_picture(CAMERA *cam);

int camera_reset(CAMERA *cam);

int camera_load_and_save_picture(CAMERA *cam, FILE *file);

int camera_load_image_size(CAMERA *cam);

int camera_prepare_to_read(CAMERA *cam);

int camera_set_image_size(CAMERA *cam, uint8_t size);

int camera_run_command(CAMERA *cam, uint8_t command, uint8_t *args, uint8_t argn,
		uint8_t *reply, size_t count, int flush_flag);

#endif
