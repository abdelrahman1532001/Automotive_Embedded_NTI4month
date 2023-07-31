/*
 * AT32_DIO_prorgram.c
 *
 *  Created on: Jul 27, 2023
 *      Author: eng-abdelrahman
 */

#include "stdtypes.h"
#include "bitmath.h"

#include "AT32_DIO_config.h"
#include "AT32_DIO_private.h"
#include "AT32_DIO_interface.h"


/*****************************************************************************************************
 *  Description ::: function to set a pin in atmega32 as output or input                             *
 *___________________________________________________________________________________________________*
 *        input ::: 3 arguments                                                                      *
 *  					1st- a port from (porta, portb, portc, portd)                                *
 *  					2nd- a pin from (pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7)             *
 *  					3rd- a direction from (output, input)                                        *
 *___________________________________________________________________________________________________*
 *       output ::: error or noerror (error = 0 and noerror = 1)                                     *
 *                                                                                                   *
 *****************************************************************************************************/
u8 AT32_DIO_u8PinInit (u8 Cpy_u8Port, u8 Cpy_u8Pin, u8 Cpy_u8PinMode)
{
	if((Cpy_u8Pin >= pin0) && (Cpy_u8Pin <= pin7)) //make sure that the entered pin is with in possible range (pin0 to pin7)
	{
		switch(Cpy_u8Port) //check for port
		{
			/******************************** in case of choosing port a *******************************/
			case porta:
				switch(Cpy_u8PinMode) //check mode of the pin
				{
					case output:
						SET_BIT(AT32_DDRA, Cpy_u8Pin); //set the bit in DDRA register
												break;
					case input :
						CLEAR_BIT(AT32_DDRA, Cpy_u8Pin); //set the bit in DDRA register
												  break;
					default    : return error;
				} //end switch(Cpy_u8PinMode)
				break;
			/******************************** in case of choosing port b *******************************/
			case portb:
				switch(Cpy_u8PinMode) //check mode of the pin
				{
					case output:
						SET_BIT(AT32_DDRB, Cpy_u8Pin); //set the bit in DDRB register
												break;
					case input :
						CLEAR_BIT(AT32_DDRB, Cpy_u8Pin); //set the bit in DDRB register
												  break;
					default    : return error;
				} //end switch(Cpy_u8PinMode)
				break;
			/******************************** in case of choosing port c *******************************/
			case portc:
				switch(Cpy_u8PinMode) //check mode of the pin
				{
					case output:
						SET_BIT(AT32_DDRC, Cpy_u8Pin); //set the bit in DDRC register
												break;
					case input :
						CLEAR_BIT(AT32_DDRC, Cpy_u8Pin); //set the bit in DDRC register
												  break;
					default    : return error;
				} //end switch(Cpy_u8PinMode)
				break;
			/******************************** in case of choosing port d *******************************/
			case portd:
				switch(Cpy_u8PinMode) //check mode of the pin
				{
					case output:
						SET_BIT(AT32_DDRD, Cpy_u8Pin); //set the bit in DDRD register
												break;
					case input :
						CLEAR_BIT(AT32_DDRD, Cpy_u8Pin); //set the bit in DDRD register
												  break;
					default    : return error;
				} //end switch(Cpy_u8PinMode)
				break;
			/******************************** in case of invalid port *********************************/
			default    : return error;
		} //end switch(Cpy_u8Port)

	} //end if
	else //if the pin is out of possible range
	{
		return error; //terminate the function with error
	}
	return noerror; //terminate function and return one
} //end function

/*****************************************************************************************************
 *  Description ::: function to set or clear a pin in atmega32 to get logic high or low              *
 *___________________________________________________________________________________________________*
 *        input ::: 3 arguments                                                                      *
 *  					1st- a port from (porta, portb, portc, portd)                                *
 *  					2nd- a pin from (pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7)             *
 *  					3rd- a value from (high, low)                                                *
 *___________________________________________________________________________________________________*
 *       output ::: error or noerror (error = 0 and noerror = 1)                                     *
 *                                                                                                   *
 *****************************************************************************************************/
u8 AT32_DIO_u8SetPinValue(u8 Cpy_u8Port, u8 Cpy_u8Pin, u8 Cpy_u8PinVal )
{
	if((Cpy_u8Pin >= pin0) && (Cpy_u8Pin <= pin7)) //make sure that the entered pin is with in possible range (pin0 to pin7)
	{
		switch(Cpy_u8Port) //check for port
		{
			/******************************** in case of choosing port a *******************************/
			case porta:
				switch(Cpy_u8PinVal) //check mode of the pin
				{
					case high:
						SET_BIT(AT32_PORTA, Cpy_u8Pin); //set the bit in PORTA register
												break;
					case low :
						CLEAR_BIT(AT32_PORTA, Cpy_u8Pin); //set the bit in PORTA register
												  break;
					default    : return error;
				} //end switch(Cpy_u8PinMode)
				break;
			/******************************** in case of choosing port b *******************************/
			case portb:
				switch(Cpy_u8PinVal) //check mode of the pin
				{
					case high:
						SET_BIT(AT32_PORTB, Cpy_u8Pin); //set the bit in PORTB register
												break;
					case low :
						CLEAR_BIT(AT32_PORTB, Cpy_u8Pin); //set the bit in PORTB register
												  break;
					default    : return error;
				} //end switch(Cpy_u8PinMode)
				break;
			/******************************** in case of choosing port c *******************************/
			case portc:
				switch(Cpy_u8PinVal) //check mode of the pin
				{
					case high:
						SET_BIT(AT32_PORTC, Cpy_u8Pin); //set the bit in PORTC register
												break;
					case low :
						CLEAR_BIT(AT32_PORTC, Cpy_u8Pin); //set the bit in PORTC register
												  break;
					default    : return error;
				} //end switch(Cpy_u8PinMode)
				break;
			/******************************** in case of choosing port d *******************************/
			case portd:
				switch(Cpy_u8PinVal) //check mode of the pin
				{
					case high:
						SET_BIT(AT32_PORTD, Cpy_u8Pin); //set the bit in PORTD register
												break;
					case low :
						CLEAR_BIT(AT32_PORTD, Cpy_u8Pin); //set the bit in PORTD register
												  break;
					default    : return error;
				} //end switch(Cpy_u8PinMode)
				break;
			/******************************** in case of invalid port *********************************/
			default    : return error;
		} //end switch(Cpy_u8Port)

	} //end if
	else //if the pin is out of possible range
	{
		return error; //terminate the function with error
	}
	return noerror; //terminate function and return one
} //end function

/*****************************************************************************************************
 *  Description ::: function to toggle a pin in atmega32                                             *
 *___________________________________________________________________________________________________*
 *        input ::: 2 arguments                                                                      *
 *  					1st- a port from (porta, portb, portc, portd)                                *
 *  					2nd- a pin from (pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7)             *
 *___________________________________________________________________________________________________*
 *       output ::: error or noerror (error = 0 and noerror = 1)                                     *
 *                                                                                                   *
 *****************************************************************************************************/
u8 AT32_DIO_u8TogPinValue(u8 Cpy_u8Port, u8 Cpy_u8Pin)
{
	if((Cpy_u8Pin >= pin0) && (Cpy_u8Pin <= pin7)) //make sure that the entered pin is with in possible range (pin0 to pin7)
	{
		switch(Cpy_u8Port) //check for port
		{
			/******************************** in case of choosing port a *******************************/
			case porta:
				TOG_BIT(AT32_PORTA, Cpy_u8Pin); //toggle the value of the pin
				break;
			/******************************** in case of choosing port b *******************************/
			case portb:
				TOG_BIT(AT32_PORTB, Cpy_u8Pin); //toggle the value of the pin
				break;
			/******************************** in case of choosing port c *******************************/
			case portc:
				TOG_BIT(AT32_PORTC, Cpy_u8Pin); //toggle the value of the pin
				break;
			/******************************** in case of choosing port d *******************************/
			case portd:
				TOG_BIT(AT32_PORTD, Cpy_u8Pin); //toggle the value of the pin
				break;
			/******************************** in case of invalid port *********************************/
			default    : return error;
		} //end switch(Cpy_u8Port)

	} //end if
	else //if the pin is out of possible range
	{
		return error; //terminate the function with error
	}
	return noerror; //terminate function and return one
} //end function

/*****************************************************************************************************
 *  Description ::: function to read a pin in atmega32                                               *
 *___________________________________________________________________________________________________*
 *        input ::: 3 arguments                                                                      *
 *                      1st- an address to variable to save the value in it                          *
 *  					2nd- a port from (porta, portb, portc, portd)                                *
 *  					3rd- a pin from (pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7)             *
 *___________________________________________________________________________________________________*
 *       output ::: error or noerror (error = 0 and noerror = 1)                                     *
 *                                                                                                   *
 *****************************************************************************************************/
u8 AT32_DIO_u8GetPinValue(u8 *Cpy_pu8Read, u8 Cpy_u8Port, u8 Cpy_u8Pin)
{
	if((Cpy_u8Pin >= pin0) && (Cpy_u8Pin <= pin7)) //make sure that the entered pin is with in possible range (pin0 to pin7)
	{
		switch(Cpy_u8Port) //check for port
		{
	    	/******************************** in case of choosing port a *******************************/
			case porta:
				*Cpy_pu8Read = GET_BIT(AT32_PINA, Cpy_u8Pin); //get the value of the pin and assign it
			    break;
		    /******************************** in case of choosing port b *******************************/
			case portb:
				*Cpy_pu8Read = GET_BIT(AT32_PINB, Cpy_u8Pin); //get the value of the pin and assign it
				break;
			/******************************** in case of choosing port c *******************************/
			case portc:
				*Cpy_pu8Read = GET_BIT(AT32_PINC, Cpy_u8Pin); //get the value of the pin and assign it
				break;
			/******************************** in case of choosing port d *******************************/
			case portd:
				*Cpy_pu8Read = GET_BIT(AT32_PIND, Cpy_u8Pin); //get the value of the pin and assign it
				break;
			/******************************** in case of invalid port *********************************/
			default    : return error; //terminate the function with error
		} //end switch(Cpy_u8Port)

	} //end outer if
	else //if the pin is out of possible range
	{
		return error; //terminate the function with error
	}

	return noerror; //terminate function with no error
} //end function

/*****************************************************************************************************
 *  Description ::: function to set direction of a whole port in atmega32                            *
 *___________________________________________________________________________________________________*
 *        input ::: 2 arguments                                                                      *
 *  					1st- a port from (porta, portb, portc, portd)                                *
 *  					2nd- a value from 0(all input) to 255(all output)                            *
 *___________________________________________________________________________________________________*
 *       output ::: error or noerror (error = 0 and noerror = 1)                                     *
 *                                                                                                   *
 *****************************************************************************************************/
u8 AT32_DIO_u8PortInit(u8 Cpy_u8Port, u8 Cpy_u8PortDir)
{
	switch(Cpy_u8Port) //check for port
	{
		/******************************** in case of choosing port a *******************************/
		case porta:
			AT32_DDRA = Cpy_u8PortDir; //set the port direction
			break;
		/******************************** in case of choosing port b *******************************/
		case portb:
			AT32_DDRB = Cpy_u8PortDir; //set the port direction
			break;
		/******************************** in case of choosing port c *******************************/
		case portc:
			AT32_DDRC = Cpy_u8PortDir; //set the port direction
			break;
		/******************************** in case of choosing port d *******************************/
		case portd:
			AT32_DDRD = Cpy_u8PortDir; //set the port direction
			break;
		/******************************** in case of invalid port *********************************/
		default    : return error; //terminate the function with error
	} //end switch(Cpy_u8Port)

	return noerror; //terminate function with no error
} //end function

/*****************************************************************************************************
 *  Description ::: function to set value of a whole port in atmega32                                *
 *___________________________________________________________________________________________________*
 *        input ::: 2 arguments                                                                      *
 *  					1st- a port from (porta, portb, portc, portd)                                *
 *  					2nd- a value from 0(all input) to 255(all output)                            *
 *___________________________________________________________________________________________________*
 *       output ::: error or noerror (error = 0 and noerror = 1)                                     *
 *                                                                                                   *
 *****************************************************************************************************/
u8 AT32_DIO_u8SetPortValue(u8 Cpy_u8Port, u8 Cpy_u8PortVal)
{
	switch(Cpy_u8Port) //check for port
	{
		/******************************** in case of choosing port a *******************************/
		case porta:
			AT32_PORTA = Cpy_u8PortVal; //set the port value
			break;
		/******************************** in case of choosing port b *******************************/
		case portb:
			AT32_PORTB = Cpy_u8PortVal; //set the port value
			break;
		/******************************** in case of choosing port c *******************************/
		case portc:
			AT32_PORTC = Cpy_u8PortVal; //set the port value
			break;
		/******************************** in case of choosing port d *******************************/
		case portd:
			AT32_PORTD = Cpy_u8PortVal; //set the port value
			break;
		/******************************** in case of invalid port *********************************/
		default    : return error; //terminate the function with error
	} //end switch(Cpy_u8Port)

	return noerror; //terminate function with no error
} //end function

/*****************************************************************************************************
 *  Description ::: function to read a whole port in atmega32                                        *
 *___________________________________________________________________________________________________*
 *        input ::: 2 arguments                                                                      *
 *                      1st- an address to variable to save the value in it                          *
 *  					2nd- a port from (porta, portb, portc, portd)                                *
 *___________________________________________________________________________________________________*
 *       output ::: error or noerror (error = 0 and noerror = 1)                                     *
 *                                                                                                   *
 *****************************************************************************************************/
u8 AT32_DIO_u8GetPortValue(u8 *Cpy_pu8Read, u8 Cpy_u8Port)
{
	switch(Cpy_u8Port) //check for port
	{
		/******************************** in case of choosing port a *******************************/
		case porta:
			*Cpy_pu8Read = AT32_PINA; //get the value of the port and assign it
			break;
		/******************************** in case of choosing port b *******************************/
		case portb:
			*Cpy_pu8Read = AT32_PINB; //get the value of the port and assign it
			break;
		/******************************** in case of choosing port c *******************************/
		case portc:
			*Cpy_pu8Read = AT32_PINC; //get the value of the port and assign it
			break;
		/******************************** in case of choosing port d *******************************/
		case portd:
			*Cpy_pu8Read = AT32_PIND; //get the value of the port and assign it
			break;
		/******************************** in case of invalid port *********************************/
		default    : return error; //terminate the function with error
	} //end switch(Cpy_u8Port)
	return noerror; //terminate function with no error
} //end function
