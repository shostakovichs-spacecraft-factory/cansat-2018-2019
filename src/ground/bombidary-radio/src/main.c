#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>

#include <pigpio.h>
#include <sx1268.h>

#define RXBUFFLEN 1024

#define CSPIN	8
#define BUSYPIN	6
#define IRQPIN	5
#define NRSTPIN	13

void irqcallback(int gpio, int level, uint32_t tick, void * userdata);

#define INADDR(A,B,C,D) ((A << 24) | (B << 16) | (C << 8) | D)

int main(int argc, char ** argv)
{
	int  err;
	sx1268_t radio;
	uint8_t rxbuff[RXBUFFLEN];
	uint8_t tmpbuff[RXBUFFLEN];

	printf("Ouuff... You did it!\n");

	if (( err = gpioInitialise() ) < 0)
	{
		printf("pigpio initialisation failed with code %d! Exitting\n", err);
		return 0;
	}

	int spihandle = spiOpen(0,32000, (1 << 5)); //spi0.0@10kHz, self-controlling CS

	gpioSetMode(CSPIN, PI_OUTPUT);
	gpioWrite(CSPIN, 1);

	gpioSetMode(BUSYPIN, PI_INPUT);

	gpioSetMode(IRQPIN, PI_INPUT);
	gpioSetISRFuncEx(IRQPIN, RISING_EDGE, 0, irqcallback, &radio);

	gpioSetMode(NRSTPIN, PI_OUTPUT);
	gpioWrite(NRSTPIN, PI_HIGH);

	sx1268_rpi_t radio_specific =
	{
		.bus_handle = spihandle,
		.busy_pin = BUSYPIN,
		.cs_pin = CSPIN,
		.nrst_pin = NRSTPIN,
	};
	sx1268_struct_init(&radio, &radio_specific, rxbuff, RXBUFFLEN, NULL, 0);

	sx1268_init(&radio);

	int sock = socket(PF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in addr =
	{
		.sin_family = AF_INET,
		.sin_addr = INADDR(127,0,0,1),
		.sin_port = 3000,
	};

	while(1) {
		if( RXLEN(radio) != 0)
		{
			int rxlen = RXLEN(radio);
			sx1268_receive(&radio, tmpbuff, rxlen);
			sendto(sock, tmpbuff, rxlen, 0, (struct sockaddr *)&addr, sizeof(addr));
		}
		usleep(10000);
	}


	return 0;
}

void irqcallback(int gpio, int level, uint32_t tick, void * userdata)
{
	printf("IRQ!\n");
	sx1268_event(userdata);
}
