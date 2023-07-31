/*
 * LCD_Prog.c
 *
 *  Created on: Jul 31, 2023
 *      Author: ENG-Abdelrahman
 */
#include "util/delay.h"

#include "../../LIB/Std_Types.h"
#include "../../LIB/Bit_Math.h"

#include "../../MCAL/AT32_DIO_Driver/DIO_Interface.h"

#include "LCD_Cfg.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"


static void LCD_vidWriteU8Command(u8 Cpy_u8Command)
{
	/*______________________________________________________ Eight Bits Mode _________________________________________________*/
#if LCD_MODE == LCD_EIGHT_BITS_MODE
	DIO_vidPin_Write(LCD_RS_PIN, LOW);
	DIO_vidPort_Write(LCD_DATA_PORT, Cpy_u8Command);
#endif
	/*______________________________________________________ Four Bits Mode __________________________________________________*/
#if LCD_MODE == LCD_FOUR_BITS_MODE
	//clear RS pin to select command mode
	DIO_vidPin_Write(LCD_RS_PIN, LOW);
	//send higher 4 bits
	DIO_vidPin_Write(LCD_D7_PIN, GET_BIT(Cpy_u8Command, SEVEN));
	DIO_vidPin_Write(LCD_D6_PIN, GET_BIT(Cpy_u8Command,   SIX));
	DIO_vidPin_Write(LCD_D5_PIN, GET_BIT(Cpy_u8Command,  FIVE));
	DIO_vidPin_Write(LCD_D4_PIN, GET_BIT(Cpy_u8Command,  FOUR));
	//wait
	LCD_vidSendUsEnablePulse(100); //Send Enable Pulse, So That LCD Response
	//send lower 4 bits
	DIO_vidPin_Write(LCD_D7_PIN, GET_BIT(Cpy_u8Command, THREE));
	DIO_vidPin_Write(LCD_D6_PIN, GET_BIT(Cpy_u8Command,   TWO));
	DIO_vidPin_Write(LCD_D5_PIN, GET_BIT(Cpy_u8Command,   ONE));
	DIO_vidPin_Write(LCD_D4_PIN, GET_BIT(Cpy_u8Command,  ZERO));
#endif
}

static void LCD_vidWriteU8Data(u8 Cpy_u8Data)
{
	/*______________________________________________________ Eight Bits Mode _________________________________________________*/
#if LCD_MODE == LCD_EIGHT_BITS_MODE
	DIO_vidPin_Write(LCD_RS_PIN, HIGH);
	DIO_vidPort_Write(LCD_DATA_PORT, Cpy_u8Data);
#endif
	/*______________________________________________________ Four Bits Mode __________________________________________________*/
	#if LCD_MODE == LCD_FOUR_BITS_MODE
	//set RS pin to select data mode
	DIO_vidPin_Write(LCD_RS_PIN, HIGH);
	//send higher 4 bits
	DIO_vidPin_Write(LCD_D7_PIN, GET_BIT(Cpy_u8Data, SEVEN));
	DIO_vidPin_Write(LCD_D6_PIN, GET_BIT(Cpy_u8Data,   SIX));
	DIO_vidPin_Write(LCD_D5_PIN, GET_BIT(Cpy_u8Data,  FIVE));
	DIO_vidPin_Write(LCD_D4_PIN, GET_BIT(Cpy_u8Data,  FOUR));
	//wait
	LCD_vidSendUsEnablePulse(100); //Send Enable Pulse, So That LCD Response
	//send lower 4 bits
	DIO_vidPin_Write(LCD_D7_PIN, GET_BIT(Cpy_u8Data, THREE));
	DIO_vidPin_Write(LCD_D6_PIN, GET_BIT(Cpy_u8Data,   TWO));
	DIO_vidPin_Write(LCD_D5_PIN, GET_BIT(Cpy_u8Data,   ONE));
	DIO_vidPin_Write(LCD_D4_PIN, GET_BIT(Cpy_u8Data,  ZERO));
#endif
}
/************************************************************************************************************
 * @Description ! Function to make LCD ready before using it, call this function before using LCD
 *      @Output ! none
 *      @Input  ! none
 ************************************************************************************************************/
void LCD_vidInit(void)
{
	_delay_ms(30);
	/*______________________________________________________ Four Bits Mode __________________________________________________*/
#if LCD_MODE == LCD_FOUR_BITS_MODE //LCD FOUT BITS MODE
	//Function Set
	DIO_vidPin_Write(LCD_D7_PIN,  LOW);
	DIO_vidPin_Write(LCD_D6_PIN,  LOW);
	DIO_vidPin_Write(LCD_D5_PIN, HIGH);
	DIO_vidPin_Write(LCD_D4_PIN,  LOW);
	//Wait
	LCD_vidSendUsEnablePulse(1000); //Send Enable Pulse, So That LCD Response
	//Complete Function Set
	LCD_vidWriteU8Command(0b00101011);
	LCD_vidSendUsEnablePulse(100); //Send Enable Pulse, So That LCD Response
	//Set Display On/Off Settings
	#if   LCD_CURSOR_MODE == OFF //If Choose Cursor Off
		LCD_vidWriteU8Command(0b00001100);
		LCD_vidSendUsEnablePulse(100); //Send Enable Pulse, So That LCD Response
	#endif
	#if LCD_CURSOR_MODE == ON_B //If Choose Cursor On With Blink
		LCD_vidWriteU8Command(0b00001111);
		LCD_vidSendUsEnablePulse(100); //Send Enable Pulse, So That LCD Response
	#endif
	#if LCD_CURSOR_MODE == ON_NB //If Choose Cursor On With No Blink
		LCD_vidWriteU8Command(0b00001110);
		LCD_vidSendUsEnablePulse(100); //Send Enable Pulse, So That LCD Response
	#endif
	//Clear LCD
	LCD_vidWriteU8Command(0b00000001);
	LCD_vidSendUsEnablePulse(2000); //Send Enable Pulse, So That LCD Response
#endif
	/*______________________________________________________ Eight Bits Mode _________________________________________________*/
#if LCD_MODE == LCD_EIGHT_BITS_MODE //LCD EIGHT BITS MODE
	//Function Set In Eight Bits Mode
	LCD_vidWriteU8Command(0b00111000);
	LCD_vidSendUsEnablePulse(100); //Send Enable Pulse, So That LCD Response
	//If Choose Cursor Off
	#if   LCD_CURSOR_MODE == OFF
		LCD_vidWriteU8Command(0b00001100);
		LCD_vidSendUsEnablePulse(100); //Send Enable Pulse, So That LCD Response
	#endif
	//If Choose Cursor On With Blink
	#if LCD_CURSOR_MODE == ON_B
		LCD_vidWriteU8Command(0b00001111);
		LCD_vidSendUsEnablePulse(100); //Send Enable Pulse, So That LCD Response
	#endif
	//If Choose Cursor On With No Blink
	#if LCD_CURSOR_MODE == ON_NB
		LCD_vidWriteU8Command(0b00001110);
		LCD_vidSendUsEnablePulse(100); //Send Enable Pulse, So That LCD Response
	#endif
	//Clear LCD
	LCD_vidWriteU8Command(0b00000001);
	LCD_vidSendUsEnablePulse(2000); //Send Enable Pulse, So That LCD Response
#endif
}
/************************************************************************************************************
 * @Description ! Function to print four byte integer number on LCD screen
 *      @Output ! none
 *      @Input  ! four byte integer
 ************************************************************************************************************/
void LCD_vidPrintU8Char(u8 Cpy_u8Char)
{
	LCD_vidWriteU8Data(Cpy_u8Char); //Write the data to the LCD to print it
	LCD_vidSendUsEnablePulse(100);  //Send Enable Pulse, So That LCD Response
}
/************************************************************************************************************
 * @Description ! Function to shift all data on LCD screen right by one cell
 *      @Output ! none
 *      @Input  ! none
************************************************************************************************************/
void LCD_vidPrintString(const u8 *Cpy_pU8String)
{
	u8 Local_u8Counter = 0; //counter to loop on the string

	while(Cpy_pU8String[Local_u8Counter] != '\0') //loop until reach end of the string '\0'
	{
		LCD_vidPrintU8Char(Cpy_pU8String[Local_u8Counter]); //print letters of the string one by one
		Local_u8Counter++; //move to the next letter
	} //end while
}
/************************************************************************************************************
 * @Description ! Function to print entire string on LCD screen
 *      @Output ! none
 *      @Input  ! pointer to you string
 ************************************************************************************************************/
void LCD_vidPrintU32Number(u32 Cpy_u32Number)
{
	u32 Local_u32Divisor = 10;
	u8  Local_u8Digit;

	while((Cpy_u32Number / Local_u32Divisor) > 10) //loop until reach last digit
	{
		Local_u32Divisor *= 10; //multiply by ten to go to next digit
	} //end while loop

	while(Local_u32Divisor != 0) //loop until take all digits
	{
		Local_u8Digit = ((Cpy_u32Number / Local_u32Divisor) % 10); //extract all digits but start from higher one
		Local_u8Digit = Local_u8Digit + '0'; //convert integer data to character, so that LCD can print
		LCD_vidPrintU8Char(Local_u8Digit); //print the converted data on LCD
		Local_u32Divisor /= 10; //divide by ten to get the the next digit
	} //end while loop

}
/************************************************************************************************************
 * @Description ! Function to make the cursor return to the first cell
 *      @Output ! none
 *      @Input  ! none
 ************************************************************************************************************/
void LCD_vidGoHome(void)
{
	LCD_vidWriteU8Command(0b00000010); //Send Command To The LCD
	LCD_vidSendUsEnablePulse(2000); //Send Enable Pulse, So That LCD Response
}
/************************************************************************************************************
 * @Description ! Function to turn LCD screen off without losing data
 *      @Output ! none
 *      @Input  ! none
 ************************************************************************************************************/
void LCD_vidDisplayOff(void)
{
#if   LCD_CURSOR_MODE == OFF 	//When Cursor Off
	LCD_vidWriteU8Command(0b00001000);
	LCD_vidSendUsEnablePulse(1000); //Send Enable Pulse, So That LCD Response
#endif
#if LCD_CURSOR_MODE == ON_B 	//When Cursor Turns On With Blinking
	LCD_vidWriteU8Command(0b00001011);
	LCD_vidSendUsEnablePulse(1000); //Send Enable Pulse, So That LCD Response
#endif
#if LCD_CURSOR_MODE == ON_NB 	//When Cursor Turns On With No Blinking
	LCD_vidWriteU8Command(0b00001010);
	LCD_vidSendUsEnablePulse(1000); //Send Enable Pulse, So That LCD Response
#endif
}
/************************************************************************************************************
 * @Description ! Function to turn LCD screen on to to show its data
 *      @Output ! none
 *      @Input  ! none
 ************************************************************************************************************/
void LCD_vidDisplayOn(void)
{
#if   LCD_CURSOR_MODE == OFF 	//When Cursor Off
	LCD_vidWriteU8Command(0b00001100);
	LCD_vidSendUsEnablePulse(1000); //Send Enable Pulse, So That LCD Response
#endif
#if LCD_CURSOR_MODE == ON_B		//When Cursor Turns On With Blinking
	LCD_vidWriteU8Command(0b00001111);
	LCD_vidSendUsEnablePulse(1000); //Send Enable Pulse, So That LCD Response
#endif
#if LCD_CURSOR_MODE == ON_NB 	//When Cursor Turns On With No Blinking
	LCD_vidWriteU8Command(0b00001110);
	LCD_vidSendUsEnablePulse(1000); //Send Enable Pulse, So That LCD Response
#endif
}
/************************************************************************************************************
 * @Description ! Function to shift all data on LCD screen right by one cell
 *      @Output ! none
 *      @Input  ! number of cells to shift
 ************************************************************************************************************/
void LCD_vidShiftDataRight(u8 Cpy_u8NumOfShift)
{
	while(Cpy_u8NumOfShift) //Loop Until Finish Number Of Shifts
	{
		LCD_vidWriteU8Command(0b00011100); //Write The Data Shift Right Command
		LCD_vidSendUsEnablePulse(1000); //Send Enable Pulse, So That LCD Response

		Cpy_u8NumOfShift--; //Decrease Number Of Shifts After Making One Shift
	} //End Loop
}
/************************************************************************************************************
 * @Description ! Function to shift all data on LCD screen left by one cell
 *      @Output ! none
 *      @Input  ! number of cells to shift
 ************************************************************************************************************/
void LCD_vidShiftDataLeft(u8 Cpy_u8NumOfShift)
{
	while(Cpy_u8NumOfShift) //Loop Until Finish Number Of Shifts
	{
		LCD_vidWriteU8Command(0b00011000); //Write The Data Shift Left Command
		LCD_vidSendUsEnablePulse(1000); //Send Enable Pulse, So That LCD Response

		Cpy_u8NumOfShift--; //Decrease Number Of Shifts After Making One Shift
	} //End Loop
}
/************************************************************************************************************
 * @Description ! Function to shift only the cursor left by one cell
 *      @Output ! none
 *      @Input  ! number of cells to shift
 ************************************************************************************************************/
void LCD_vidShiftCursorLeft(u8 Cpy_u8NumOfShift)
{
	while(Cpy_u8NumOfShift) //Loop Until Finish Number Of Shifts
	{
		LCD_vidWriteU8Command(0b00010000); //Write The Cursor Shift Left Command
		LCD_vidSendUsEnablePulse(1000); //Send Enable Pulse, So That LCD Response

		Cpy_u8NumOfShift--; //Decrease Number Of Shifts After Making One Shift
	} //End Loop
}
/************************************************************************************************************
 * @Description ! Function to shift only the cursor right by one cell
 *      @Output ! none
 *      @Input  ! number of cells to shift
 ************************************************************************************************************/
void LCD_vidShiftCursorRight(u8 Cpy_u8NumOfShift)
{
	while(Cpy_u8NumOfShift) //Loop Until Finish Number Of Shifts
	{
		LCD_vidWriteU8Command(0b00010100); //Write The Cursor Shift Right Command
		LCD_vidSendUsEnablePulse(1000); //Send Enable Pulse, So That LCD Response

		Cpy_u8NumOfShift--; //Decrease Number Of Shifts After Making One Shift
	} //End Loop
}
/************************************************************************************************************
 * @Description ! Function to clear all data on the screen
 *      @Output ! none
 *      @Input  ! none
 ************************************************************************************************************/
void LCD_vidCLear(void)
{
	LCD_vidWriteU8Command(0b0000001);
	LCD_vidSendUsEnablePulse(2000); //Send Enable Pulse, So That LCD Response
}

static void LCD_vidSendUsEnablePulse(u32 Cpy_u32MicroDelay)
{
	DIO_vidPin_Write(LCD_EN_PIN, HIGH);
	_delay_us(Cpy_u32MicroDelay);
	DIO_vidPin_Write(LCD_EN_PIN, LOW);
}


