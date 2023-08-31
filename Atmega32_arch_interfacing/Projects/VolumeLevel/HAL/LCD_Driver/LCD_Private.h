/*
 * LCD_Private.h
 *
 *  Created on: Jul 31, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

//Modes Of Cursor
#define CURSOR_ON_B			0b00001111
#define CURSOR_ON_NB		0b00001110
#define CURSOR_OFF			0b00001100

//Modes Of LCD
#define LCD_EIGHT_PINS_MODE	0
#define LCD_FOUR_PINS_MODE  1

//Number As Macros
#define ZERO			    0
#define ONE  		        1
#define TWO  		        2
#define THREE  			    3
#define FOUR  			    4
#define FIVE  			    5
#define SIX  			    6
#define SEVEN  			    7
#define EIGHT  			    8
#define NINE  			    9

//Private Functions' Prototype
static void LCD_vidWriteU8Command(u8 Cpy_u8Command);
static void LCD_vidWriteU8Data(u8 Cpy_u8Data);
static void LCD_vidSendUsEnablePulse(u32 Cpy_u32MicroDelay);


#endif /* HAL_LCD_DRIVER_LCD_PRIVATE_H_ */
