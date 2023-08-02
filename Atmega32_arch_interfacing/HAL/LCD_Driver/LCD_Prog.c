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
#if LCD_PINS_MODE == LCD_EIGHT_PINS_MODE
	DIO_vidPin_Write(LCD_RS_PIN, LOW);
	DIO_vidPin_Write(LCD_RW_PIN, LOW);
	DIO_vidPort_Write(LCD_DATA_PORT, Cpy_u8Command);
#endif
	/*______________________________________________________ Four Bits Mode __________________________________________________*/
#if LCD_PINS_MODE == LCD_FOUR_PINS_MODE
	//clear RS pin to select command mode
	DIO_vidPin_Write(LCD_RS_PIN, LOW);
	DIO_vidPin_Write(LCD_RW_PIN, LOW);
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
#if LCD_PINS_MODE == LCD_EIGHT_PINS_MODE
	DIO_vidPin_Write(LCD_RS_PIN, HIGH);
	DIO_vidPin_Write(LCD_RW_PIN, LOW);
	DIO_vidPort_Write(LCD_DATA_PORT, Cpy_u8Data);
#endif
	/*______________________________________________________ Four Bits Mode __________________________________________________*/
	#if LCD_PINS_MODE == LCD_FOUR_PINS_MODE
	//set RS pin to select data mode
	DIO_vidPin_Write(LCD_RS_PIN, HIGH);
	DIO_vidPin_Write(LCD_RW_PIN, LOW);
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
#if LCD_PINS_MODE == LCD_FOUR_PINS_MODE //LCD FOUT BITS MODE
	//Function Set
	DIO_vidPin_Write(LCD_D7_PIN,  LOW);
	DIO_vidPin_Write(LCD_D6_PIN,  LOW);
	DIO_vidPin_Write(LCD_D5_PIN, HIGH);
	DIO_vidPin_Write(LCD_D4_PIN,  LOW);
	//Wait
	LCD_vidSendUsEnablePulse(1000); //Send Enable Pulse, So That LCD Response
	//Complete Function Set
	LCD_vidWriteU8Command(0b00101000);
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
#if LCD_PINS_MODE == LCD_EIGHT_PINS_MODE //LCD EIGHT BITS MODE
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
 * @Description ! Function to print Unsigned Integer Number on LCD screen
 *      @Output ! none
 *      @Input  ! Integer Number To Be Printed
 ************************************************************************************************************/
void LCD_vidPrintU32Number(u32 Cpy_u32Number)
{
	u32 Local_u32Divisor = 10;
	u8  Local_u8Digit;

	while((Cpy_u32Number / Local_u32Divisor) != 0) //loop until reach last digit
	{
		Local_u32Divisor *= 10; //multiply by ten to go to next digit
	} //end while loop
	Local_u32Divisor /= 10;
	while(Local_u32Divisor != 0) //loop until take all digits
	{
		Local_u8Digit = ((Cpy_u32Number / Local_u32Divisor) % 10); //extract all digits but start from higher one
		Local_u8Digit = Local_u8Digit + '0'; //convert integer data to character, so that LCD can print
		LCD_vidPrintU8Char(Local_u8Digit); //print the converted data on LCD
		Local_u32Divisor /= 10; //divide by ten to get the the next digit
	} //end while loop

}
/************************************************************************************************************
 * @Description ! Function to print Signed Integer Number on LCD screen
 *      @Output ! none
 *      @Input  ! Integer Number To Be Printed
 ************************************************************************************************************/
void LCD_vidPrintS32Number(s32 Cpy_s32Number)
{
	u8  Local_u8NumberDigits[11]; //Array To Save Digits As Characters
	u8  Local_u8Counter = 0; //Counter To Save In Digits' Array
	s32 Local_s32iLoop; //Counter To Print Digits On LCD
	u8  Local_u8NegativeFlag = 0; //Flag To Detect Negative Sign

	//Check If The Number Is Negative Or Not
	if(Cpy_s32Number < 0)  //If Negative
	{
		Local_u8NegativeFlag = 1; //Set The Negative Flag
		Cpy_s32Number = Cpy_s32Number * -1; //Convert Number To Positive
	} //End If

	//Loop And Extract Digits
	do{
		Local_u8NumberDigits[Local_u8Counter] = (Cpy_s32Number % 10) + '0'; //Take Least Digit Of The Number And Convert It To Char
		Local_u8Counter++; //Increase Counter To Save In Next Digit
		Cpy_s32Number /= 10; //Delete The Least Digit After Save It In Array Of Digits
	}while(Cpy_s32Number != 0); //Exit When Finishing All Digits

	//Check Negative Flag
	if(Local_u8NegativeFlag == 1)
	{
		Local_u8NumberDigits[Local_u8Counter] = '-';
		Local_u8Counter++;
	}

	//Loop Over Digits To Print Them
	for(Local_s32iLoop = Local_u8Counter - 1; Local_s32iLoop >= 0; Local_s32iLoop--)
	{
		LCD_vidPrintU8Char(Local_u8NumberDigits[Local_s32iLoop]); //Print Digits On LCD
	} //End For Loop

}
/************************************************************************************************************
 * @Description ! Function to make cursor go to a specific position on LCD to write on
 *      @Output ! none
 *      @Input  ! number of row, number of column
 ************************************************************************************************************/
void LCD_vidCursorGoTo(u8 Cpy_u8Row, u8 Cpy_u8Col)
{
	if(Cpy_u8Row == ZERO) //if first row
	{
		//The Address Is The Same The Number Of Column
		SET_BIT(Cpy_u8Col, SEVEN); //Set Bit 7 To Set DDRAM Address
		LCD_vidWriteU8Command(Cpy_u8Col); //Send The Address To LCD
		LCD_vidSendUsEnablePulse(100); //Send Enable Pulse, So That LCD Response
	}//end if
	else if(Cpy_u8Row == ONE) //if second row
	{
		Cpy_u8Col = Cpy_u8Col + 0x40; //The Address Is The Same The Number Of Column + 0x40
		SET_BIT(Cpy_u8Col, SEVEN); //Set Bit 7 To Set DDRAM Address
		LCD_vidWriteU8Command(Cpy_u8Col); //Send The Address To LCD
		LCD_vidSendUsEnablePulse(100); //Send Enable Pulse, So That LCD Response
	}//end else if
}
/************************************************************************************************************
 * @Description ! Function to generate a new character in CGRAM
 *      @Output ! none
 *      @Input  ! pointer to your pattern, number of you pattern from 0 to 7
 ************************************************************************************************************/
void LCD_vidGeneratePattern(const u8 *Cpy_pu8Pattern, u8 Cpy_u8PatternID)
{
	//Find The Address To Store Your Character
	u8 Local_u8PatternAdd = Cpy_u8PatternID * 8; //8 is the size of one char
	SET_BIT(Local_u8PatternAdd, 6); //Set Bit 6 In the Address To Access CGRAM
	LCD_vidWriteU8Command(Local_u8PatternAdd); //Set CGRAM Address
	LCD_vidSendUsEnablePulse(50); //Send Enable Pulse, So That LCD Response
	//Store Your Pattern
	for(u8 Local_u8Counter = ZERO; Local_u8Counter < EIGHT; Local_u8Counter++) //Loop To Store 8 Bytes Of Your Pattern
	{
		LCD_vidWriteU8Data(Cpy_pu8Pattern[Local_u8Counter]); //Write In The Address
		LCD_vidSendUsEnablePulse(50); //Send Enable Pulse, So That LCD Response
	} //end for
	LCD_vidWriteU8Command(0x80); //return to DDRAM
	LCD_vidSendUsEnablePulse(50); //Send Enable Pulse, So That LCD Response
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
void LCD_vidDataShiftRight(u8 Cpy_u8NumOfShift)
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
void LCD_vidDataShiftLeft(u8 Cpy_u8NumOfShift)
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
void LCD_vidCursorShiftLeft(u8 Cpy_u8NumOfShift)
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
void LCD_vidCursorShiftRight(u8 Cpy_u8NumOfShift)
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


