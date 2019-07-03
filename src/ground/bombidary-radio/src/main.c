#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include <pigpio.h>
#include <sx1268.h>

#define RXBUFFLEN (1024 * 100)

#define CSPIN	8
#define BUSYPIN	27
#define IRQPIN	17
#define NRSTPIN	22
#define RXENPIN	23
#define TXENPIN	24

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
		return err;
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
		.rxen_pin = RXENPIN,
		.txen_pin = TXENPIN,
	};
	sx1268_struct_init(&radio, &radio_specific, rxbuff, RXBUFFLEN, NULL, 0);

	sx1268_init(&radio);

	const char* hostname="192.168.0.1";

	if(argc > 1)
		hostname = argv[1];

	const char* portname="11000";
	struct addrinfo hints;
	memset(&hints,0,sizeof(hints));
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_DGRAM;
	hints.ai_protocol=0;
	hints.ai_flags=AI_ADDRCONFIG;
	struct addrinfo* addr=0;
	err = getaddrinfo(hostname,portname,&hints,&addr);

	int sock = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
	printf("addr: %s	port: %s	sock: %d   addr err: %d\n", hostname, portname, sock, err);

	char * filename = "./lastlog.bin";

	if(argc > 2)
		filename = argv[2];

	int file = open(filename, O_WRONLY | O_CREAT | O_EXCL, S_IROTH);
	if(file != 0 && errno == EEXIST)
	{
		printf("File %s already exists, I wouldn't overwrite it\n", filename);
		return errno;
	}
	printf("filename: %s	file: %d\n", filename, file);

	bool verbose = true;
	if(argc > 3)
		verbose = strcmp(argv[3], "-v") == 0;

	while(1) {
		if( RXLEN(radio) != 0)
		{
			time_t current_time;
			struct tm * time_info;
			char timeString[9];  // space for "HH:MM:SS\0"

			time(&current_time);
			time_info = localtime(&current_time);

			strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);

			int rxlen = RXLEN(radio);
			sx1268_status_t status = sx1268_receive(&radio, tmpbuff, rxlen);
			printf("%s; received %d bytes; status %d\n", timeString, rxlen, status);

			int res = sendto(sock, tmpbuff, rxlen, 0, addr->ai_addr, addr->ai_addrlen);
			if(res != rxlen || verbose)
				printf("Pushed to socket, res %d\n", res);

			res = write(file, tmpbuff, rxlen);
			if(res != rxlen || verbose)
				printf("Writed to file, res %d\n", res);
			else
			{
				if(fsync(file) != 0)
					printf("fsync failed with %d\n", errno);
			}
		}
		usleep(500);
	}


	return 0;
}

void irqcallback(int gpio, int level, uint32_t tick, void * userdata)
{
	printf("IRQ!\n");
	sx1268_event(userdata);
}
