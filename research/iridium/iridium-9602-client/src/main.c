/*
 * main.c
 *
 *  Created on: 5 мая 2019 г.
 *      Author: snork
 */

#include <stdio.h>

#include "iridium9602_commands.h"


int main()
{

	ir9602_cmd_t  cmd;
	cmd.code = IR9602_CMD_SBDREG;
	cmd.arg.sbdreg.lat = -10.1234567;
	cmd.arg.sbdreg.lon = 003.6545364;

	char buffer[1000];
	int size = ir9602_serialize_command(buffer, sizeof(buffer), &cmd);

	buffer[size] = '\0';
	printf("!%s!\n", buffer);

	return 0;
}
