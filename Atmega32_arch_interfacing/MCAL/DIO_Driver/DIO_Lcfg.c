/*
 * DIO_config.c
 *
 *  Created on: Jul 30, 2023
 *      Author: ENG-Abdelrahman
 */

#include "DIO_Interface.h"


const DIO_PIN_MODE_e PinsArrModes[TOTAL_PINs] = {

		OUTPUT,     /* PORTD pin0 */
		OUTPUT,     /* PORTD pin1 */
		OUTPUT,     /* PORTD pin2 */
		OUTPUT,     /* PORTD pin3 */               /* PORTD */
		INPULL,     /* PORTD pin4 */               /* Modes "OUTPUT" "INFREE" "INPULL" */
		INPULL,     /* PORTD pin5 */
		INPULL,     /* PORTD pin6 */
		INPULL,     /* PORTD pin7 */
		/************************************************************/
		OUTPUT,     /* PORTC pin0 */
		OUTPUT,     /* PORTC pin1 */
		OUTPUT,     /* PORTC pin2 */
		OUTPUT,     /* PORTC pin3 */
		OUTPUT,     /* PORTC pin4 */               /* PORTC */
		OUTPUT,     /* PORTC pin5 */               /* Modes "OUTPUT" "INFREE" "INPULL" */
		OUTPUT,     /* PORTC pin6 */
		OUTPUT,     /* PORTC pin7 */
		/*************************************************************/
		OUTPUT,     /* PORTB pin0 */
		OUTPUT,     /* PORTB pin1 */
		OUTPUT,     /* PORTB pin2 */
		OUTPUT,     /* PORTB pin3 */               /* PORTB */
		OUTPUT,     /* PORTB pin4 */               /* Modes "OUTPUT" "INFREE" "INPULL" */
		OUTPUT,     /* PORTB pin5 */
		OUTPUT,     /* PORTB pin6 */
		OUTPUT,     /* PORTB pin7 */
		/*************************************************************/
		OUTPUT,     /* PORTA pin0 */
		OUTPUT,     /* PORTA pin1 */
		OUTPUT,     /* PORTA pin2 */
		OUTPUT,     /* PORTA pin3 */                  /* PORTA */
		OUTPUT,     /* PORTA pin4 */				  /* Modes "OUTPUT" "INFREE" "INPULL" */
		OUTPUT,     /* PORTA pin5 */
		OUTPUT,     /* PORTA pin6 */
		OUTPUT,     /* PORTA pin7 */
};
