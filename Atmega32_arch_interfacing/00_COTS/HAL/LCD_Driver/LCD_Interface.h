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
 * @Description ! Function to print entire string on LCD screen
 *      @Output ! none
 *      @Input  ! pointer to you string
 ************************************************************************************************************/
void LCD_vidPrintString(const u8 *Cpy_pU8String);

/************************************************************************************************************
 * @Description ! Function to shift all data on LCD screen right by one cell
 *      @Output ! none
 *      @Input  ! number of cells to shift
 ************************************************************************************************************/
void LCD_vidShiftDataRight(u8 Cpy_u8NumOfShift);

/************************************************************************************************************
 * @Description ! Function to shift all data on LCD screen left by one cell
 *      @Output ! none
 *      @Input  ! number of cells to shift
 ************************************************************************************************************/
void LCD_vidShiftDataLeft(u8 Cpy_u8NumOfShift);

/************************************************************************************************************
 * @Description ! Function to shift only the cursor right by one cell
 *      @Output ! none
 *      @Input  ! number of cells to shift
 ************************************************************************************************************/
void LCD_vidShiftCursorRight(u8 Cpy_u8NumOfShift);

/************************************************************************************************************
 * @Description ! Function to shift only the cursor left by one cell
 *      @Output ! none
 *      @Input  ! number of cells to shift
 ************************************************************************************************************/
void LCD_vidShiftCursorLeft(u8 Cpy_u8NumOfShift);

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
