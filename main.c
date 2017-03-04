#include <avr/io.h>
#include <util/delay_basic.h>
#include <stdlib.h>

int main()
{
	uint8_t mask = 0x80;
	uint16_t delay;
	uint8_t i;

	/* on atmega2560, PWM pin 13 (LED pin) = port B bit 7 */
	DDRB |= mask; /* set port B pin 7 to output */

	while (1)
	{
		delay = rand();
		PORTB |= mask; /* set port B pin 7 to high */
		for (i = 0; i < 0x40; i++) _delay_loop_2(0x1000);
		PORTB &= ~mask; /* set port B pin 7 to low */
		for (i = 0; i < 0x40; i++) _delay_loop_2(delay);
	}


	return 0;
}
