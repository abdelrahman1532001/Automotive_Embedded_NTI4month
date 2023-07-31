/*
 * AT32_DIO_interface.h
 *
 *  Created on: Jul 27, 2023
 *      Author: eng-abdelrahman
 */

#ifndef DEBUG_AT32_DIO_INTERFACE_H_
#define DEBUG_AT32_DIO_INTERFACE_H_

#include "stdtypes.h"

//enumeration for ports and pins
enum{
	pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7,
	porta,
	portb,
	portc,
	portd,
};
//enumeration for values of pins
enum{
	low,
	high
};
//enumeration for modes of pins
enum{
	input,
	output
};
//enumeration for errors
enum{
	error,
	noerror
};


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
u8 AT32_DIO_u8PinInit (u8 Cpy_u8Port, u8 Cpy_u8Pin, u8 Cpy_u8PinMode);
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
u8 AT32_DIO_u8SetPinValue(u8 Cpy_u8Port, u8 Cpy_u8Pin, u8 Cpy_u8PinVal );
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
u8 AT32_DIO_u8TogPinValue(u8 Cpy_u8Port, u8 Cpy_u8Pin);
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
u8 AT32_DIO_u8GetPinValue(u8 *Cpy_pu8Read, u8 Cpy_u8Port, u8 Cpy_u8Pin);
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
u8 AT32_DIO_u8PortInit(u8 Cpy_u8Port, u8 Cpy_u8PortDir);
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
u8 AT32_DIO_u8SetPortValue(u8 Cpy_u8Port, u8 Cpy_u8PortVal);
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
u8 AT32_DIO_u8GetPortValue(u8 *Cpy_pu8Read, u8 Cpy_u8Port);

#endif /* DEBUG_AT32_DIO_INTERFACE_H_ */
