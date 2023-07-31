/*
 * SEVENSEG_private.h
 *
 *  Created on: Jul 28, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef SEVENSEG_PRIVATE_H_
#define SEVENSEG_PRIVATE_H_

#define COM_CATHODE 	1
#define COM_ANODE   	2

#define ONE_DIGIT		1
#define TWO_DIGITS		2

//array to define each bits of the port of 7seg to show the number
const u8 g_7SegCC_Num[] = {
		0b00111111,
		0b00000110,
		0b01011011,
		0b01001111,
		0b01100110,
		0b01101101,
		0b01111101,
		0b00000111,
		0b01111111,
		0b01101111
};

#endif /* HAL_SEVENSEG_DRIVER_SEVENSEG_PRIVATE_H_ */
