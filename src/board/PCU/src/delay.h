/*
 * delay.h
 *
 *  Created on: Jun 10, 2019
 *      Author: kirs
 */

#ifndef DELAY_H_
#define DELAY_H_

#include <stdint.h>

extern volatile uint32_t global_ms;

void delay_until(uint32_t ms);

inline void delay(uint32_t ms)
{ //TODO could implement some checks, but what for?
	delay_until(global_ms + ms);
}

#endif /* DELAY_H_ */
