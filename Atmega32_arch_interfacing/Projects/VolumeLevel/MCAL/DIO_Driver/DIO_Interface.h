/*
 * AT32_DIO_interface.h
 *
 *  Created on: Jul 27, 2023
 *      Author: eng-abdelrahman
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../LIB/Std_Types.h"

typedef enum{
	PD0,     /* PORTD pin0 */
	PD1,     /* PORTD pin1 */
	PD2,     /* PORTD pin2 */
	PD3,     /* PORTD pin3 */
	PD4,     /* PORTD pin4 */              /* PORTD */
	PD5,     /* PORTD pin5 */
	PD6,     /* PORTD pin6 */
	PD7,     /* PORTD pin7 */
	/************************************************************/
	PC0,     /* PORTC pin0 */
	PC1,     /* PORTC pin1 */
	PC2,     /* PORTC pin2 */
	PC3,     /* PORTC pin3 */
	PC4,     /* PORTC pin4 */               /* PORTC */
	PC5,     /* PORTC pin5 */
	PC6,     /* PORTC pin6 */
	PC7,     /* PORTC pin7 */
	/*************************************************************/
	PB0,     /* PORTB pin0 */
	PB1,     /* PORTB pin1 */
	PB2,     /* PORTB pin2 */
	PB3,     /* PORTB pin3 */
	PB4,     /* PORTB pin4 */               /* PORTB */
	PB5,     /* PORTB pin5 */
	PB6,     /* PORTB pin6 */
	PB7,     /* PORTB pin7 */
	/*************************************************************/
	PA0,     /* PORTA pin0 */
	PA1,     /* PORTA pin1 */
	PA2,     /* PORTA pin2 */
	PA3,     /* PORTA pin3 */
	PA4,     /* PORTA pin4 */				  /* PORTA */
	PA5,     /* PORTA pin5 */
	PA6,     /* PORTA pin6 */
	PA7,     /* PORTA pin7 */
	TOTAL_PINs

	}DIO_PIN_NAME_e; /* new data type to contain pins' name */

typedef enum{
	PD=0,
	PC,
	PB,
	PA

	}DIO_PORT_NAME_e;

typedef enum{
	INFREE,
	OUTPUT,
	INPULL

	}DIO_PIN_MODE_e; /* new data type to contain pins' mode */

typedef enum{
	LOW,
	HIGH

	}DIO_PIN_VOLT_e; /* new data type to contain pins' state */

void DIO_vidInit(void);

void DIO_vidPin_Write(DIO_PIN_NAME_e Cpy_PinName, DIO_PIN_VOLT_e Cpy_PinVolt);
DIO_PIN_VOLT_e DIO_u8Pin_Read  (DIO_PIN_NAME_e Cpy_PinName);

void DIO_vidPort_Write(DIO_PORT_NAME_e Cpy_PortName, u8 Cpy_PortVal);
u8   DIO_u8Port_Read  (DIO_PORT_NAME_e Cpy_PortName);

void DIO_ANDING_PORT(DIO_PORT_NAME_e Cpy_PortName, u8 Cpy_u8ANDingVal);
void DIO_ORING_PORT(DIO_PORT_NAME_e Cpy_PortName, u8 Cpy_u8ORingVal);


#endif /* DEBUG_AT32_DIO_INTERFACE_H_ */
