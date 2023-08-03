/*
 * KPD_program.c
 *
 *  Created on: Jul 29, 2023
 *      Author: ENG-Abdelrahman
 */

#include "../../LIB/Std_Types.h"

#include "../../MCAL/DIO_Driver/DIO_Interface.h"


#include "KPD_Cfg.h"
#include "KPD_Interface.h"
#include "KPD_Private.h"

u8 KPD_u8KeyMap[KPD_NUM_OF_ROWS][KPD_NUM_OF_COLS] = KPD_KEYS_MAP;
u8 KPD_u8Row_Pins[KPD_NUM_OF_ROWS] = KPD_ROWS_PINS;
u8 KPD_u8Col_Pins[KPD_NUM_OF_COLS] = KPD_COLS_PINS;
/*****************************************************************************************************
 *  Description ::: function to initiate the keypad pins                                                *
 *___________________________________________________________________________________________________*
 *        input ::: none                                                                             *
 *___________________________________________________________________________________________________*
 *       output ::: none                                                                             *
 *                                                                                                   *
 *****************************************************************************************************/
void KPD_vidInit(void)
{
	//variables
	u8 Local_u8Pin;

	//Loop On Rows' Pins And Make Them HIGH
	for(Local_u8Pin = 0; Local_u8Pin < KPD_NUM_OF_ROWS; Local_u8Pin++)
	{
		DIO_vidPin_Write(KPD_u8Row_Pins[Local_u8Pin], HIGH); //Set High As Default
	}//End For

}
/*****************************************************************************************************
 *  Description ::: function to read from the keypad                                                 *
 *___________________________________________________________________________________________________*
 *        input ::: none                                                                             *
 *___________________________________________________________________________________________________*
 *       output ::: none                                                                             *
 *                                                                                                   *
 *****************************************************************************************************/
u8 KPD_u8ReadKey(void)
{
	//Variables
	u8 Loca_u8RowPin; //counter to loop on rows
	u8 Loca_u8ColPin; //counter to loop on columns
	DIO_PIN_VOLT_e Local_u8ColRead; //variable to save pin value
	u8 Local_u8PressedKey = KPD_NOT_PRESSED; //variable to save pressed key
	//loop on rows and set one row to high
	for(Loca_u8RowPin = 0; Loca_u8RowPin < KPD_NUM_OF_ROWS; Loca_u8RowPin++)
	{
		//set one row as low
		DIO_vidPin_Write(KPD_u8Row_Pins[Loca_u8RowPin], LOW);
		//loop on columns and check
		for(Loca_u8ColPin = 0; Loca_u8ColPin < KPD_NUM_OF_COLS; Loca_u8ColPin++)
		{
			//read each column to find the pressed key
			Local_u8ColRead = DIO_Pin_Read(KPD_u8Col_Pins[Loca_u8ColPin]);
			if(Local_u8ColRead == LOW) //this happen when a key be pressed
			{
				Local_u8PressedKey = KPD_u8KeyMap[Loca_u8RowPin][Loca_u8ColPin]; //save the pressed key
				while(DIO_Pin_Read(KPD_u8Col_Pins[Loca_u8ColPin]) == LOW); //make sure the key is released
				DIO_vidPin_Write(KPD_u8Row_Pins[Loca_u8RowPin], HIGH); //make the row high again
				return Local_u8PressedKey; //exit with the pressed key
			}//end if
		}//end columns loop
		DIO_vidPin_Write(KPD_u8Row_Pins[Loca_u8RowPin], HIGH); //make the row high again
	}//end rows loop

	//if press none key return with no press
	return Local_u8PressedKey;
}//end function
