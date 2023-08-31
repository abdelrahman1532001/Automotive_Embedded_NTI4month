/*
 * main.c
 *
 *  Created on: Aug 31, 2023
 *      Author: ENG-Abdelrahman
 */

#include <util/delay.h>

#include "LIB/Std_Types.h"

#include "MCAL/DIO_Driver/DIO_Interface.h"

#include "MCAL/ADC_Driver/ADC_Interface.h"

#include "HAL/LCD_Driver/LCD_Interface.h"
#include "HAL/LCD_Driver/LCD_SpecialChar.h"

#define POT_PIN ADC0

int main()
{

	u16 Local_u8PotReadingNew=0;
	u16 Local_u8PotReadingOld=0;
	u8  Local_u8Level, Local_u8Percentage;

	DIO_vidInit();
	ADC_xInit();
	LCD_vidInit();
	_delay_ms(2);

	for(int i=0; i<8; i++) //Loop to add all needed characters in CGRAM
	{
		LCD_vidGeneratePattern(DigitLevel[i], i); //add one pattern to CGRAM
	} //end for loop

	LCD_vidPrintString((u8 *)"Volume");

	for(;;) //Infinite loop
	{
		ADC_xReadChannelBusyWait(&Local_u8PotReadingNew, POT_PIN); //Read the potentiometer voltage

		Local_u8Level      = ADC_u32MapAnalogReading(Local_u8PotReadingNew, 1,   8, 0, 1023); //Map analog reading to the number of available level
		Local_u8Percentage = ADC_u32MapAnalogReading(Local_u8PotReadingNew, 0, 100, 0, 1023); //Map analog reading to the percentage value

		if(Local_u8PotReadingOld != Local_u8PotReadingNew) //Update LCD only when reading change
		{
			LCD_vidCursorGoTo(1, 12); //Go to row2 and columne12
			LCD_vidPrintString((u8 *)"    "); //Clear the line before writing
			LCD_vidCursorGoTo(1, 12); //Go to row2 and columne12
			LCD_vidPrintUNum(Local_u8Percentage); //print percentage on LCD screen
			LCD_vidPrintU8Char('%'); //print one char on LCD screen

			LCD_vidCursorGoTo(1, 0); //Go to row2 and columne1
			LCD_vidPrintString((u8 *)"        "); //Clear the line before writing
			LCD_vidCursorGoTo(1, 0); //return to position again to start writing
			for(int i = 0; i < Local_u8Level; i++) //Print the level
			{
				LCD_vidPrintU8Char(i); //print one char on LCD screen
			}

			Local_u8PotReadingOld = Local_u8PotReadingNew; //Update old value
		}
	}
}
