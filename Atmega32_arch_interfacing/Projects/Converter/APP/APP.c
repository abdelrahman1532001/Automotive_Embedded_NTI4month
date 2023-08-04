/*
 * APP.c
 *
 *  Created on: Aug 4, 2023
 *      Author: ENG-Abdelrahman
 */

#include "util/delay.h"
#include "../LIB/Std_Types.h"

#include "../MCAL/DIO_Driver/DIO_Cfg.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"

#include "../HAL/LCD_Driver/LCD_Cfg.h"
#include "../HAL/LCD_Driver/LCD_Interface.h"

#include "../HAL/KEYPAD_Driver/KPD_Cfg.h"
#include "../HAL/KEYPAD_Driver/KPD_Interface.h"

void APP_LCD_Welcome(void);
void APP_LCD_OptionsScreen1(void);
void APP_LCD_OptionsScreen2(void);
void KPD_ScanOption1(void);
void KPD_ScanHex(void);
void KPD_ScanBin(void);
void KPD_ScanDec(void);
void KPD_ScanOption2(void);




typedef enum{
	LCD_Screen1_task,
	KPD_ScanOption1_task,
	KPD_ScanHex_task,
	KPD_ScanBin_task,
	KPD_ScanDec_task,
	LCD_Screen2_task,
	KPD_ScanOption2_task,
	LCD_PrintHex_task,
	LCD_PrintBin_task,
	LCD_PrintDec_task,
	APP_WaitResart
}APP_Tasks_t;

typedef enum{
	HexOption=1,
	BinOption,
	DecOption
}APP_Options_t;

APP_Tasks_t   CurrentTask = LCD_Screen1_task; //To Move Between Tasks
APP_Options_t global_Option; //To Save Available Options
u32 		  global_u8PressedKey; //To Save Pressed Key
u32           global_ScannedNumber = 0; //To Save Scanned Number As Decimal Value

int main()
{

	DIO_vidInit();
	LCD_vidInit();
	KPD_vidInit();

	APP_LCD_Welcome(); //Print Some Messages On LCD Screen

	while(1)
	{
		switch(CurrentTask) //Switch Case To Move Between Tasks
		{
		case LCD_Screen1_task :
			APP_LCD_OptionsScreen1(); //Print option On LCD
			CurrentTask = KPD_ScanOption1_task; //Change Current Task To Scan The Option
										 break; //Exit From Switch Case

		case KPD_ScanOption1_task :
			KPD_ScanOption1(); //Keypad Scan Option1
			  		    break; //Exit From Switch Case

		case KPD_ScanHex_task :
			KPD_ScanHex(); //Start Reading Hex Number From Keypad
			break; //Exit From Switch Case

		case KPD_ScanBin_task :
			KPD_ScanBin(); //Start Reading Binary Number From Keypad
			break; //Exit From Switch Case

		case KPD_ScanDec_task :
			KPD_ScanDec(); //Start Reading Decimal Number From Keypad
					break; //Exit From Switch Case

		case LCD_Screen2_task :
			APP_LCD_OptionsScreen2(); //Print option On LCD
			CurrentTask = KPD_ScanOption2_task; //Change Current Task To Scan The Option
				    				     break; //Exit From Switch Case

		case KPD_ScanOption2_task :
			KPD_ScanOption2(); //Keypad Scan Option2
			   		    break; //Exit From Switch Case

		case LCD_PrintHex_task :
			LCD_vidCLear(); //Clear Display
			LCD_vidPrintU32Hex(global_ScannedNumber); //Print Hex Value On Screen
			CurrentTask = APP_WaitResart; //Go To Wait Screen Until Press Restart Key
								   break; //Exit From Switch Case

		case LCD_PrintBin_task :
			LCD_vidCLear(); //Clear Display
			LCD_vidPrintU32Binary(global_ScannedNumber); //Print Binary Value On Screen
			CurrentTask = APP_WaitResart; //Go To Wait Screen Until Press Restart Key
								   break; //Exit From Switch Case

		case LCD_PrintDec_task :
			LCD_vidCLear(); //Clear Display
			LCD_vidPrintU32Number(global_ScannedNumber); //Print Decimal Value On Screen
			CurrentTask = APP_WaitResart; //Go To Wait Screen Until Press Restart Key
								   break; //Exit From Switch Case

		case APP_WaitResart :
			global_u8PressedKey = KPD_u8ReadKey(); //Read From The Key Pad
			if(global_u8PressedKey != KPD_NOT_PRESSED) //Check If Key Pressed Or Not
			{
				if(global_u8PressedKey == 'R') //If Restart Key Is Pressed
				{
					global_ScannedNumber = 0; //Clear Number To Take New One
					CurrentTask = LCD_Screen1_task; //Move To First Screen Option
				}//End If
			}//End If
		}//End Switch Case
	}//End Switch Case
	return 0;
}

void APP_LCD_Welcome(void)
{
	LCD_vidCursorGoTo(0, 4);
	LCD_vidPrintString("Welcome!");
	LCD_vidCursorGoTo(1, 0);
	LCD_vidPrintString("To My Converter!");
	_delay_ms(1000);
	LCD_vidCLear();
	LCD_vidCursorGoTo(0, 4);
	LCD_vidPrintString("Author");
	LCD_vidCursorGoTo(1, 0);
	LCD_vidPrintString("Eng.Abdelrahman");
	_delay_ms(1000);
	LCD_vidCLear();
}
void APP_LCD_OptionsScreen1(void)
{
	LCD_vidCLear();
	LCD_vidPrintString("convert from :"); //Print On LCd
	LCD_vidCursorGoTo(1, 0);
	LCD_vidPrintString("1-H 2-B 3-D");
}
void APP_LCD_OptionsScreen2(void)
{
	LCD_vidCLear();
	LCD_vidPrintString("convert to :"); //Print On LCd
	LCD_vidCursorGoTo(1, 0);
	LCD_vidPrintString("1-H 2-B 3-D");
}
void KPD_ScanOption1()
{
	global_u8PressedKey = KPD_u8ReadKey(); //Read From The Key Pad
	if(global_u8PressedKey != KPD_NOT_PRESSED) //Check If Key Pressed Or Not
	{
		global_Option = global_u8PressedKey - '0'; //Convert The Key To Integer Value
		switch(global_Option)
		{
		case HexOption :
			LCD_vidCLear(); //Clear LCD
			LCD_vidPrintString("Hex=0x"); //Print The Hex Prefix
			CurrentTask = KPD_ScanHex_task; //Change Current Task To Scan The Hex From Keypad
								     break; //Exit From Switch Case
		case BinOption :
			LCD_vidCLear(); //Clear LCD
			LCD_vidPrintString("Bin=0b"); //Print The Hex Prefix
			CurrentTask = KPD_ScanBin_task; //Change Current Task To Scan The Binary From Keypad
								     break; //Exit From Switch Case
		case DecOption :
			LCD_vidCLear(); //Clear LCD
			LCD_vidPrintString("Dec="); //Print The Hex Prefix
			CurrentTask = KPD_ScanDec_task; //Change Current Task To Scan The Decimal From Keypad
								     break; //Exit From Switch Case
		}
	}//End If
}

void KPD_ScanOption2()
{
	global_u8PressedKey = KPD_u8ReadKey(); //Read From The Key Pad
	if(global_u8PressedKey != KPD_NOT_PRESSED) //Check If Key Pressed Or Not
	{
		global_Option = global_u8PressedKey - '0'; //Convert The Key To Integer Value
		switch(global_Option)
		{
		case HexOption :
			CurrentTask = LCD_PrintHex_task; //Change Current Task To Scan The Hex From Keypad
								     break; //Exit From Switch Case
		case BinOption :
			CurrentTask = LCD_PrintBin_task; //Change Current Task To Scan The Binary From Keypad
								     break; //Exit From Switch Case
		case DecOption :
			CurrentTask = LCD_PrintDec_task; //Change Current Task To Scan The Decimal From Keypad
								     break; //Exit From Switch Case
		}
	}//End If
}

void KPD_ScanHex(void)
{
	static u8 Hexflag = 0; //Flag To Indicate First Digit Or Not

	global_u8PressedKey = KPD_u8ReadKey(); //Read Pressed Key From Keypad
	if(global_u8PressedKey != KPD_NOT_PRESSED) //Make Sure There Is Pressed Key
	{
		if(global_u8PressedKey >= 'A' && global_u8PressedKey <= 'F') //Check Limits Of Hex Letters
		{
			LCD_vidPrintU8Char(global_u8PressedKey); //Print Digit On LCD
			global_ScannedNumber = (global_ScannedNumber << 4) + (global_u8PressedKey - 55); //Update The Hex Value
			Hexflag = 1; //Set Flag
		}//End If
		else if(global_u8PressedKey >= '0' && global_u8PressedKey <= '9')
		{
			if(Hexflag == 0) //When Enter First Digit
			{
				if(global_u8PressedKey != '0') //Don't Take 0 As First Digit
				{
					LCD_vidPrintU8Char(global_u8PressedKey); //Print Digit On LCD
					global_ScannedNumber = global_u8PressedKey - '0'; //Update The Hex Value
					Hexflag = 1; //Set Flag
				}//End If
			}//End If
			else if(Hexflag == 1) //When Take Any Digit Except First Digit
			{
				LCD_vidPrintU8Char(global_u8PressedKey); //Print Digit On LCD
				global_ScannedNumber = (global_ScannedNumber << 4) + (global_u8PressedKey - '0'); //Update The Hex Value
			}//End If
		}
		else if(global_u8PressedKey == '=') //If '=' Key Is Pressed
		{
			CurrentTask = LCD_Screen2_task; //Move To Next Task After Keypad Take
			Hexflag = 0; //Clear Flag Before Exit
		}
		else if(global_u8PressedKey == 'R')
		{
			global_ScannedNumber = 0; //Clear Number To Take New One
			CurrentTask = LCD_Screen1_task; //Return To First Screen To Re choose
			Hexflag = 0; //Clear Flag Before Exit
		}//End Else If
	}//End Outer IF
}

void KPD_ScanBin(void)
{
	static u8 Binflag = 0; //Flag To Indicate First Digit Or Not

	global_u8PressedKey = KPD_u8ReadKey(); //Read Pressed Key From Keypad
	if(global_u8PressedKey != KPD_NOT_PRESSED) //Make Sure There Is Pressed Key
	{
		if(global_u8PressedKey == '0' || global_u8PressedKey == '1') //Check Limits Of Binary Digits
		{
			if(Binflag == 0) //When Enter First Digit
			{
				if(global_u8PressedKey != '0') //Don't Take 0 As First Digit
				{
					LCD_vidPrintU8Char(global_u8PressedKey); //Print Digit On LCD
					global_ScannedNumber = 1; //Update The Binary Value
					Binflag = 1; //Set Flag
				}//End If
			}//End If
			else if(Binflag == 1) //When Take Any Digit Except First Digit
			{
				LCD_vidPrintU8Char(global_u8PressedKey); //Print Digit On LCD
				global_ScannedNumber = (global_ScannedNumber << 1) + (global_u8PressedKey - '0'); //Update The Binary Value
			}//End If
		}//End If
		else if(global_u8PressedKey == '=') //If '=' Key Is Pressed
		{
			CurrentTask = LCD_Screen2_task; //Move To Next Task After Keypad Take
			Binflag = 0; //Clear Flag Before Exit
		}
		else if(global_u8PressedKey == 'R')
		{
			global_ScannedNumber = 0; //Clear Number To Take New One
			CurrentTask = LCD_Screen1_task; //Return To First Screen To Re choose
			Binflag = 0; //Clear Flag Before Exit
		}//End Else If
	}//End Outer IF
}//End Of Function

void KPD_ScanDec(void)
{
	static u8 Decflag = 0; //Flag To Indicate First Digit Or Not
	global_u8PressedKey = KPD_u8ReadKey(); //Read Pressed Key From Keypad
	if(global_u8PressedKey != KPD_NOT_PRESSED) //Make Sure There Is Pressed Key
	{
		if(global_u8PressedKey >= '0' && global_u8PressedKey <='9') //Check Limits Of Decimal Digits
		{
			if(Decflag == 0) //When Enter First Digit
			{
				if(global_u8PressedKey != '0') //Don't Take 0 As First Digit
				{
					LCD_vidPrintU8Char(global_u8PressedKey); //Print Digit On LCD
					global_ScannedNumber = (global_u8PressedKey - '0'); //Update The Decimal Value
					Decflag = 1; //Set Flag
				}//End If
			}//End If
			else if(Decflag == 1) //When Take Any Digit Except First Digit
			{
				LCD_vidPrintU8Char(global_u8PressedKey); //Print Digit On LCD
				global_ScannedNumber = (global_ScannedNumber * 10) + (global_u8PressedKey - '0'); //Update The Decimal Value
			}//End If
		}//End If
		else if(global_u8PressedKey == '=') //If '=' Key Is Pressed
		{
			CurrentTask = LCD_Screen2_task; //Move To Next Task After Keypad Take
			Decflag = 0; //Clear Flag Before Exit
		}
		else if(global_u8PressedKey == 'R')
		{
			global_ScannedNumber = 0; //Clear Number To Take New One
			CurrentTask = LCD_Screen1_task; //Return To First Screen To Re choose
			Decflag = 0; //Clear Flag Before Exit
		}//End Else If
	}//End Outer IF
}//End Function
