/*
 * LCD_Interface.h
 *
 *  Created on: Jul 31, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
/************************************************************************************************************
 * @Description ! Function to make LCD ready before using it, call this function before using LCD
 *      @Output ! none
 *      @Input  ! none
 ************************************************************************************************************/
void LCD_vidInit(void);

/************************************************************************************************************
 * @Description ! Function to print character on LCD screen
 *      @Output ! none
 *      @Input  ! character
 ************************************************************************************************************/
void LCD_vidPrintU8Char(u8 Cpy_u8Char);

/************************************************************************************************************
 * @Description ! Function to print four byte integer number on LCD screen
 *      @Output ! none
 *      @Input  ! four byte integer
 ************************************************************************************************************/
void LCD_vidPrintU32Number(u32 Cpy_u32Number);

/************************************************************************************************************
 * @Description ! Function to print Signed Integer Number on LCD screen
 *      @Output ! none
 *      @Input  ! Integer Number To Be Printed
 ************************************************************************************************************/
void LCD_vidPrintS32Number(s32 Cpy_s32Number);

/************************************************************************************************************
 * @Description ! Function to print entire string on LCD screen
 *      @Output ! none
 *      @Input  ! pointer to you string
 ************************************************************************************************************/
void LCD_vidPrintString(const u8 *Cpy_pU8String);

/************************************************************************************************************
 * @Description ! Function to make cursor go to a specific position on LCD to write on
 *      @Output ! none
 *      @Input  ! number of row, number of column
 ************************************************************************************************************/
void LCD_vidCursorGoTo(u8 Cpy_u8Row, u8 Cpy_u8Col);

/************************************************************************************************************
 * @Description ! Function to generate a new character in CGRAM
 *      @Output ! none
 *      @Input  ! pointer to your pattern, number of you pattern from 0 to 7
 ************************************************************************************************************/
void LCD_vidGeneratePattern(const u8 *Cpy_pu8Pattern, u8 Cpy_u8PatternID);

/************************************************************************************************************
 * @Description ! Function to print a special character you already generate
 *      @Output ! none
 *      @Input  ! number of your pattern to print
 ************************************************************************************************************/
void LCD_vidPrintSpecialChar(u8 Cpy_u8PatternID);

/************************************************************************************************************
 * @Description ! Function to shift all data on LCD screen right by one cell
 *      @Output ! none
 *      @Input  ! number of cells to shift
 ************************************************************************************************************/
void LCD_vidDataShiftRight(u8 Cpy_u8NumOfShift);

/************************************************************************************************************
 * @Description ! Function to shift all data on LCD screen left by one cell
 *      @Output ! none
 *      @Input  ! number of cells to shift
 ************************************************************************************************************/
void LCD_vidDataShiftLeft(u8 Cpy_u8NumOfShift);

/************************************************************************************************************
 * @Description ! Function to shift only the cursor right by one cell
 *      @Output ! none
 *      @Input  ! number of cells to shift
 ************************************************************************************************************/
void LCD_vidCursorShiftRight(u8 Cpy_u8NumOfShift);

/************************************************************************************************************
 * @Description ! Function to shift only the cursor left by one cell
 *      @Output ! none
 *      @Input  ! number of cells to shift
 ************************************************************************************************************/
void LCD_vidCursorShiftLeft(u8 Cpy_u8NumOfShift);

/************************************************************************************************************
 * @Description ! Function to make the cursor return to the first cell
 *      @Output ! none
 *      @Input  ! none
 ************************************************************************************************************/
void LCD_vidGoHome(void);

/************************************************************************************************************
 * @Description ! Function to turn LCD screen off without losing data
 *      @Output ! none
 *      @Input  ! none
 ************************************************************************************************************/
void LCD_vidDisplayOff(void);

/************************************************************************************************************
 * @Description ! Function to turn LCD screen on to to show its data
 *      @Output ! none
 *      @Input  ! none
 ************************************************************************************************************/
void LCD_vidDisplayOn(void);

/************************************************************************************************************
 * @Description ! Function to clear all data on the screen
 *      @Output ! none
 *      @Input  ! none
 ************************************************************************************************************/
void LCD_vidCLear(void);

#endif /* HAL_LCD_DRIVER_LCD_INTERFACE_H_ */
