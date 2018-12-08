#ifndef CAMERA_INTERFACE_H
#define CAMERA_INTERFACE_H

#include <unistd.h>

#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>

#include "my_uart.h"


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

CAMERA *camera_init();

void camera_deinit(CAMERA *cam);

ssize_t camera_read_picture(CAMERA *cam, uint8_t *buffer, camera_type size);

int camera_restore_picture(CAMERA *cam);

int camera_is_all_image_loaded(CAMERA* cam);

int camera_take_picture(CAMERA *cam);

int camera_reset(CAMERA *cam);

int camera_load_and_save_picture(CAMERA *cam, FILE *file);

camera_type camera_get_image_size(CAMERA *cam);



#endif
