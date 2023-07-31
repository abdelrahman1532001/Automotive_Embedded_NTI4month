/*
 * AT32_DIO_private.h
 *
 *  Created on: Jul 27, 2023
 *      Author: eng-abdelrahman
 */

#ifndef AT32_DIO_PRIVATE_H_
#define AT32_DIO_PRIVATE_H_

#include "stdtypes.h"

#define AT32_DIO_START ((volatile u8 *) 0x30)
#define AT32_DIO_END   ((volatile u8 *) 0x3B)

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


#endif /* AT32_DIO_PRIVATE_H_ */
