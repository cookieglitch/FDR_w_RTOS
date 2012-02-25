/**
 * FDR etc etc
 * Copyright: John Tiernan 2012
 */
#include <avr/io.h>
#include <avr/interrupt.h>

int init_hardware();

int main()
{
	//Hardware setup
	int setup = init_hardware();

	//Startup tasks


	//Main loop
	while(1)
	{



	}

}

int init_hardware(void)
{

	return 0;
}
