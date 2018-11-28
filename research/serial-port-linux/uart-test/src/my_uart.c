
#include "my_uart.h"

int configure_port(int fd)
{
	speed_t speed = B57600;
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

MY_UART *my_uart_init(const char port_name[], int flags)
{
	MY_UART *descr = (MY_UART*)malloc(sizeof(MY_UART));
	descr->port_name = (char*)malloc(sizeof(char)*strlen(port_name));
	strcpy(descr->port_name, port_name);

	//printf("%s hey!", port_name);
	descr->fd = open(port_name, flags);
	if (descr->fd < 0)
	{
		perror("can`t open port");
		return NULL;
	}

	int rc = configure_port(descr->fd);
	if (rc < 0)
	{
		perror("can`t configure port");
		close(descr->fd);
		return NULL;
	}


	return descr;
}

void my_uart_deinit(MY_UART* des)
{
	close(des->fd);
	free(des->port_name);
	free(des);
}


int my_uart_tx(MY_UART *des, uint8_t *buffer, size_t size)
{
	ssize_t written = write(des->fd, buffer, size);
	return written;
}

int my_uart_rx(MY_UART *des, uint8_t *buffer, size_t size)
{
	ssize_t readed = read(des->fd, buffer, size);
	return readed;
}


///////////////////////////////////////////////////////////////

