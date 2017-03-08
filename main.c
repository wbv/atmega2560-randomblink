#include <avr/io.h>
#include <avr/power.h>
#include <util/delay_basic.h>
#include <stdlib.h>

int main()
{
	uint8_t mask = 0x80;
	uint16_t delay;

	/* on atmega2560, PWM pin 13 (LED pin) = port B bit 7 */
	DDRB |= mask; /* set port B pin 7 to output */

	/* slow this jam w a a y   d o w n */
	/* (arduino clock down to 16/128 MHz = 125 kHz) */
	clock_prescale_set(clock_div_128);

	while (1)
	{
		delay = rand();

		PORTB |= mask; /* set port B pin 7 to high */
		_delay_loop_2(0x200);
		PORTB &= ~mask; /* set port B pin 7 to low */
		_delay_loop_2(delay);
	}

	return 0;
}
