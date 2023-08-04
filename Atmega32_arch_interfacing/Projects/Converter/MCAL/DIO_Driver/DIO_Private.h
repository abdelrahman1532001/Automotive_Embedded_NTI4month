/*
 * AT32_DIO_private.h
 *
 *  Created on: Jul 27, 2023
 *      Author: eng-abdelrahman
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "../../LIB/Std_Types.h"

#define AT32_PORT_REG_BASE  ((volatile u8 *) 0x32)
#define AT32_DDR_REG_BASE 	((volatile u8 *) 0x31)
#define AT32_PIN_REG_BASE 	((volatile u8 *) 0x30)

#define AT32_REG_STEP		3

//atmega32 I/O portA register
#define AT32_PORTA (*(volatile u8 *) 0x3B)
#define AT32_DDRA  (*(volatile u8 *) 0x3A)
#define AT32_PINA  (*(volatile u8 *) 0x39)
//atmega32 I/O portB register
#define AT32_PORTB (*(volatile u8 *) 0x38)
#define AT32_DDRB  (*(volatile u8 *) 0x37)
#define AT32_PINB  (*(volatile u8 *) 0x36)
//atmega32 I/O portC register
#define AT32_PORTC (*(volatile u8 *) 0x35)
#define AT32_DDRC  (*(volatile u8 *) 0x34)
#define AT32_PINC  (*(volatile u8 *) 0x33)
//atmega32 I/O portD register
#define AT32_PORTD (*(volatile u8 *) 0x32)
#define AT32_DDRD  (*(volatile u8 *) 0x31)
#define AT32_PIND  (*(volatile u8 *) 0x30)


static void DIO_vidPin_Init (DIO_PIN_NAME_e Cpy_PinName, DIO_PIN_MODE_e Cpy_PinMode);

extern const DIO_PIN_MODE_e PinsArrModes[TOTAL_PINs];

#endif /* DIO_PRIVATE_H_ */
