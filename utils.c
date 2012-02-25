#include <avr/io.h>

void delay_us(uint16_t delay)
{
	while (delay > 256)
	{
		TIFR0 = (1<<TOV0); /* Clear any interrupt flags on Timer0 */
		TCNT0 = 0;
		while ( (TIFR0 & (1<<TOV0)) == 0);

		delay -= 256;
	}

	TIFR0 = (1<<TOV0); 	/* Clear any interrupt flags on Timer0 */
	/*
	 * 256 - 125 = 131 : Preload timer 0 for x clicks.
	 * Should be 1us per click
	 */
	TCNT0 = 256 - delay;
	while ((TIFR0 & (1<<TOV0)) == 0) {
		/* do nothing */
	}
}
