/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

void blink_num( uint pin, int n )
{
	while( n > 0 ) {
		gpio_put( pin, 1 );
		sleep_ms( 250 );
		gpio_put( pin, 0 );
		sleep_ms( 250 );
		n--;
	}
}

int main()
{
#ifndef PICO_DEFAULT_LED_PIN
#	warning blink example requires a board with a regular LED
#else
	const uint LED_PIN = PICO_DEFAULT_LED_PIN;
	gpio_init( LED_PIN );
	gpio_set_dir( LED_PIN, GPIO_OUT );

	int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
	int i = 0;
	
	while( true ) {
		blink_num( LED_PIN, primes[i] );
		sleep_ms( 1000 );
		i = (i+1) % 8;
	}
#endif
}
