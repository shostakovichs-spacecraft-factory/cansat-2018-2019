/*
 * tests.c
 *
 *  Created on: 9 мая 2019 г.
 *      Author: snork
 */

#include "tests.h"

#include <string.h>
#include <stdio.h>

#include "ir9602_events.h"

typedef struct
{
	const char * event_string;
	ir9602_evt_t event_struct;
	bool should_suceed;
} t1_t;


static void _perform_single_t1(ir9602_evt_code_t * evtlist, const t1_t * t)
{
	ir9602_evt_t evt = {};
	bool sucess = ir9602_probe_events(evtlist, t->event_string, &evt);

	if (sucess != t->should_suceed)
		goto failed;

	if (memcmp(&evt, &t->event_struct, sizeof(evt)) != 0)
		goto failed;

	printf("%s test succeed\n", t->event_string);
	return;

	failed:
	printf("%s test failed\n", t->event_string);
}



void evt_test1(void)
{
	t1_t set1[] =
	{
			{
				"HARDWARE FAILURE:10,10\r\n",
				{
						IR9602_EVT_HARDWARE_FAILURE,
						{ .hardfault={10,10}}
				},
				true
			},
			{
				"OK\r\n",
				{
						IR9602_EVT_OK,
						{ }
				},
				true
			},
			{
				"ERROR\r\n",
				{
						IR9602_EVT_ERROR,
						{ }
				},
				true
			},
			{
				"READY\r\n",
				{
						IR9602_EVT_READY,
						{ }
				},
				true
			},
			{
				"+CIEV:1,1\r\n",
				{
						IR9602_EVT_CIEV,
						{ .ciev = {IR9602_EVT_CIEV_KIND_NETAVAIL, 1 }}
				},
				true
			},
			{
				"0\r\n",
				{
						IR9602_EVT_SBDWB,
						{ .sbdwb = {0}}
				},
				true
			},
			{
				"+SBDI:1,1,2,0,0,10\r\n",
				{
						IR9602_EVT_SBDI,
						{ .sbdi = {1,1,2,0,0,10}}
				},
				true,

			},
	};

	ir9602_evt_code_t all_events[] = {
			IR9602_EVT_HARDWARE_FAILURE,
			IR9602_EVT_OK,
			IR9602_EVT_ERROR,
			IR9602_EVT_READY,
			IR9602_EVT_CIEV,
			IR9602_EVT_SBDWB,
			IR9602_EVT_SBDD,
			IR9602_EVT_SBDI,
			0 // терминатор
	};

	for (size_t i = 0; i < sizeof(set1)/sizeof(*set1); i++)
		_perform_single_t1(all_events, &set1[i]);


	ir9602_evt_code_t sbdd_only[] = {
			IR9602_EVT_SBDD,
			0 // терминатор
	};


	// Отдельный тест на SBDD, так как она не отличима от SBDWB
	t1_t set2[] =
	{
			{
				"1\r\n",
				{
						IR9602_EVT_SBDD,
						{ .sbdd={1}}
				},
				true
			},
	};

	for (size_t i = 0; i < sizeof(set2)/sizeof(*set2); i++)
		_perform_single_t1(sbdd_only, &set2[i]);


	// отдельный тест на билеберду
	t1_t set3[] =
	{
			{
				"qoeorwldgkjdfklgjweljglwrklkdjjgjel;rjewhjioejpqej;djflsdkjglfjglkdfj",
				{},
				false
			},
	};

	for (size_t i = 0; i < sizeof(set3)/sizeof(*set3); i++)
		_perform_single_t1(all_events, &set3[i]);


}
