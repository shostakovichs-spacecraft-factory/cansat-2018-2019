/*
 * main.c
 *
 *  Created on: 23 нояб. 2018 г.
 *      Author: snork
 */

#include <unistd.h>
#include <fcntl.h>
#include <termios.h>


#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


int configure_port(int fd)
{
	speed_t speed = B115200;
	int parity = 0;

	struct termios tty;
	memset (&tty, 0, sizeof tty);
	if (tcgetattr (fd, &tty) != 0)
	{
		perror("error from tcgetattr");
		return -1;
	}

	cfsetospeed (&tty, speed);
	cfsetispeed (&tty, speed);

	tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
	// disable IGNBRK for mismatched speed tests; otherwise receive break
	// as \000 chars
	tty.c_iflag &= ~IGNBRK;         // disable break processing
	tty.c_lflag = 0;                // no signaling chars, no echo,
									// no canonical processing
	tty.c_oflag = 0;                // no remapping, no delays
	tty.c_cc[VMIN]  = 0;            // read doesn't block
	tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

	tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

	tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
									// enable reading
	tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
	tty.c_cflag |= parity;
	tty.c_cflag &= ~CSTOPB;
	tty.c_cflag &= ~CRTSCTS;

	tty.c_cc[VMIN] = 0;
	tty.c_cc[VTIME] = 5;

	if (tcsetattr (fd, TCSANOW, &tty) != 0)
	{
		perror("error from tcsetattr");
		return -1;
	}


	return 0;
}



int main()
{
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


	return EXIT_SUCCESS;
}
