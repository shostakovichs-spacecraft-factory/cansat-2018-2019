/*
 * main.c
 *
 *  Created on: 23 нояб. 2018 г.
 *      Author: SeresHotes
 */

#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "camera_interface.h"



int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	//printf("Hey\n");
	CAMERA *cam = camera_init();
	if(cam == NULL)
		printf("\ncan't init\n");
	camera_restore_picture(cam);

	//print_buffer(buffer , len);

	FILE * file = fopen("image.jpeg", "wb");
	if(file == NULL)
	{
		printf("can't open file\n");
		return -1;
	}
	camera_take_picture(cam);
	if(camera_load_and_save_picture(cam, file))
	{
		perror("can't save");
	}

	printf("image is saved\n");

	camera_restore_picture(cam);

	camera_deinit(cam);
	fclose(file);

	printf("\n");

	/*
	const char port_name[] = "/dev/ttyUSB0";

	int fd = open(port_name, O_RDWR | O_NOCTTY | O_SYNC);
	if (fd < 0)
	{
		perror("can`t open port");
		return EXIT_FAILURE;
	}

	printf("%s opened successfully\n", port_name);

	int rc = configure_port(fd);
	if (rc < 0)
	{
		perror("can`t configure port");
		close(fd);
		return EXIT_FAILURE;
	}
	printf("%s configured successfully\n", port_name);


	while(1)
	{

		char data[] = "this is my data";
		ssize_t written = write(fd, data, strlen(data));
		printf("written %zu bytes of %zu\n", written, strlen(data));



		char buffer[100];
		ssize_t readed = read(fd, buffer, sizeof(buffer));
		buffer[readed] = 0x00;
		printf("readed %zu bytes: %s\n", readed, buffer);
	}
	*/

	return EXIT_SUCCESS;
}
