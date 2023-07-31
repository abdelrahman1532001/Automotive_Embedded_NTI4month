/*
 * main.c
 *
 *  Created on: Jul 27, 2023
 *      Author: eng-abdelrahman
 */

#include <util/delay.h>
#include "stdtypes.h"

#include "AT32_DIO_interface.h"

int main()
{
	int port, pin;

	AT32_DIO_u8PortInit(porta, 0xff);

	AT32_DIO_u8SetPortValue(porta, 0xff);

	AT32_DIO_u8SetPinValue(porta, pin7, low);

	while(1)
	{
		for(int port = porta; port <= portd; port++)
		{
			AT32_DIO_u8PortInit(port, 0xff);
			AT32_DIO_u8SetPortValue(port, 0xff);

			for(pin = pin0; pin <= pin7; pin++)
			{
				AT32_DIO_u8SetPinValue(port, pin, low);
				_delay_ms(250);
			}
		}
	}
	return 0;
}
