/*
 * Strings.c
 *
 *  Created on: Aug 31, 2023
 *      Author: ENG-Abdelrahman
 */
#include "../Std_Types.h"

void vStrings_SNumtoStr(u8 Cpy_pu8Str[],u8 Cpy_u8Size, s32 Cpy_s32Number)
{
	u8  Local_u8Counter = 0; //Counter To Save In Digits' Array
	u32 Local_u32Divisor=10;

	//Check If The Number Is Negative Or Not
	if(Cpy_s32Number < 0)  //If Negative
	{
		Cpy_pu8Str[Local_u8Counter] = '-'; //add
		Local_u8Counter++;
		Cpy_s32Number = Cpy_s32Number * -1; //Convert Number To Positive
	} //End If

	while((Cpy_s32Number / Local_u32Divisor) != 0) //loop until reach last digit
	{
		Local_u32Divisor *= 10; //multiply by ten to go to next digit
	} //end while loop
	Local_u32Divisor /= 10;

	while(Local_u32Divisor != 0 && Local_u8Counter < Cpy_u8Size) //loop until take all digits
	{
		Cpy_pu8Str[Local_u8Counter] = ((Cpy_s32Number / Local_u32Divisor) % 10) + '0'; //extract all digits but start from higher one
		Local_u8Counter++; //move to store next digit
		Local_u32Divisor /= 10; //divide by ten to get the the next digit
	} //end while loop
	Cpy_pu8Str[Local_u8Counter] = '\0'; //terminate the string

}

void vStrings_UNumtoStr(u8 Cpy_pu8Str[], u8 Cpy_u8Size, u32 Cpy_u32Number)
{
	u8  Local_u8Counter = 0; //Counter To Save In Digits' Array
	u32 Local_u32Divisor=10;

	while((Cpy_u32Number / Local_u32Divisor) != 0) //loop until reach last digit
	{
		Local_u32Divisor *= 10; //multiply by ten to go to next digit
	} //end while loop
	Local_u32Divisor /= 10;

	while(Local_u32Divisor != 0 && Local_u8Counter < Cpy_u8Size) //loop until take all digits
	{
		Cpy_pu8Str[Local_u8Counter] = ((Cpy_u32Number / Local_u32Divisor) % 10) + '0'; //extract all digits but start from higher one
		Local_u8Counter++; //move to store next digit
		Local_u32Divisor /= 10; //divide by ten to get the the next digit
	} //end while loop
	Cpy_pu8Str[Local_u8Counter] = '\0'; //terminate the string

}


