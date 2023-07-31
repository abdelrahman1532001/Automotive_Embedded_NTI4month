/*
 * KPD_program.c
 *
 *  Created on: Jul 29, 2023
 *      Author: ENG-Abdelrahman
 */

#include "../../LIB/stdtypes.h"

#include "../../MCAL/AT32_DIO_Driver/AT32_DIO_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

u8 KPD_u8KeyMap[KPD_NUM_OF_ROWS][KPD_NUM_OF_COLS] = KPD_KEY_MAP;
u8 KPD_u8Row_Pins[KPD_NUM_OF_ROWS] = KPD_ROW_PINS;
u8 KPD_u8Col_Pins[KPD_NUM_OF_COLS] = KPD_COL_PINS;
/*****************************************************************************************************
 *  Description ::: function to initiate the keypad                                                  *
 *___________________________________________________________________________________________________*
 *        input ::: none                                                                             *
 *___________________________________________________________________________________________________*
 *       output ::: none                                                                             *
 *                                                                                                   *
 *****************************************************************************************************/
void KPD_voidInit(void)
{
	//variables
	u8 Local_u8Pin;

	//loop on rows and set it as output
	for(Local_u8Pin = 0; Local_u8Pin < KPD_NUM_OF_ROWS; Local_u8Pin++)
	{
		AT32_DIO_u8PinInit(KPD_ROW_PORT, KPD_u8Row_Pins[Local_u8Pin], output); //set as output
		AT32_DIO_u8SetPinValue(KPD_ROW_PORT, KPD_u8Row_Pins[Local_u8Pin], high); //set high as default
	}//end for

	//loop on columns and set it as input and active pull up
	for(Local_u8Pin = 0; Local_u8Pin < KPD_NUM_OF_COLS; Local_u8Pin++)
	{
		AT32_DIO_u8PinInit(KPD_COL_PORT, KPD_u8Col_Pins[Local_u8Pin], input_pullup); //set as output
	}//end for

}//end function
/*****************************************************************************************************
 *  Description ::: function to read from the keypad                                                 *
 *___________________________________________________________________________________________________*
 *        input ::: none                                                                             *
 *___________________________________________________________________________________________________*
 *       output ::: none                                                                             *
 *                                                                                                   *
 *****************************************************************************************************/
u8 KPD_voidReadKey(void)
{
	//Variables
	u8 Loca_u8RowPin, Loca_u8ColPin, Local_u8ColRead, Local_u8PressedKey = KPD_NOT_PRESSED;
	//loop on rows and set one row to high
	for(Loca_u8RowPin = 0; Loca_u8RowPin < KPD_NUM_OF_ROWS; Loca_u8RowPin++)
	{
		//set one row as low
		AT32_DIO_u8SetPinValue(KPD_ROW_PORT, KPD_u8Row_Pins[Loca_u8RowPin], low);
		//loop on columns and check
		for(Loca_u8ColPin = 0; Loca_u8ColPin < KPD_NUM_OF_COLS; Loca_u8ColPin++)
		{
			//read each column to find the pressed key
			AT32_DIO_u8GetPinValue(&Local_u8ColRead, KPD_COL_PORT, KPD_u8Col_Pins[Loca_u8ColPin]);
			if(Local_u8ColRead == 0) //this happen when a key be pressed
			{
				Local_u8PressedKey = KPD_u8KeyMap[Loca_u8RowPin][Loca_u8ColPin]; //save the pressed key
				AT32_DIO_u8SetPinValue(KPD_ROW_PORT, KPD_u8Row_Pins[Loca_u8RowPin], high); //make the row high again
				break; //get out after find the key
			}//end if
		}//end columns loop
		AT32_DIO_u8SetPinValue(KPD_ROW_PORT, KPD_u8Row_Pins[Loca_u8RowPin], high); //make the row high again
	}//end rows loop

	//if press none key return with no press
	return Local_u8PressedKey;
}//end function
