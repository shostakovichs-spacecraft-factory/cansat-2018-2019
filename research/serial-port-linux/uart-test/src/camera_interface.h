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
	//Номер байта начала чтения изображения в буфере камеры.
	MY_UART *uart_des;
	camera_type frame_ptr;
	uint8_t serial_num;
} CAMERA;

void print_buffer(uint8_t *buffer, size_t size);

CAMERA *camera_init();

void camera_deinit(CAMERA *cam);

ssize_t camera_read_picture(CAMERA *cam, uint8_t *buffer, camera_type size);

int camera_stop(CAMERA *cam);

int camera_resume(CAMERA *cam);

int camera_reset(CAMERA *cam);

int camera_load_and_save_picture(CAMERA *cam, FILE *file);

ssize_t read_response(CAMERA *cam, uint8_t *buffer, size_t size, int timeout_ms);

#endif
