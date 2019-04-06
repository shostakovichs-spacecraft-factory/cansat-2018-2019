#include <stdio.h>

#include "ahrs.h"
int main()
{
	ahrs_init();
	ahrs_setKoefB(0.3);


    return 0;
}
