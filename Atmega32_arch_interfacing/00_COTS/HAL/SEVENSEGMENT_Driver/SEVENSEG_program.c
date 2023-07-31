/*
 * SEVENSEG_program.c
 *
 *  Created on: Jul 28, 2023
 *      Author: ENG-Abdelrahman
 */

//include some main libraries
#include "util/delay.h"
#include "../../LIB/stdtypes.h"
#include "../../LIB/bitmath.h"
//include GPIO driver to control input/output pins
#include "../../MCAL/AT32_DIO_Driver/AT32_DIO_interface.h"
//include header file of seven segment driver
#include "../SevenSeg_Driver/SEVENSEG_config.h"
#include "../SevenSeg_Driver/SEVENSEG_interface.h"
#include "../SevenSeg_Driver/SEVENSEG_private.h"

void SevenSeg_voidInit()
{
	/*********************************************** IF ONE DIGIT *********************************************************/
#if SEVENSEG_DIGITS_NUM == ONE_DIGIT //if the user will use one digit seven segment
	AT32_DIO_u8PortInit(SEVENSEG_1st_DIGIT_PORT, 0xff); //set the port as output
	//check type of the seven segment
	#if SEVENSEG_1st_DIGIT_TYPE == COM_CATHODE //if the user choose to use common cathode seven segment
		AT32_DIO_u8SetPortValue(SEVENSEG_1st_DIGIT_PORT, 0x00); //turn off seven segment at first

	#elif SEVENSEG_1st_DIGIT_TYPE == COM_ANODE //if the user choose to use common anode seven segment
		AT32_DIO_u8SetPortValue(SEVENSEG_1st_DIGIT_PORT, 0xFF); //turn off seven segment at first

	#else
		#error "'SEVENSEG_TYPE', in configuration file, isn't set well!"

	#endif /* end if that check number of digits */

	/*********************************************** IF TWO DIGITS ********************************************************/
#elif SEVENSEG_DIGITS_NUM == TWO_DIGITS //if the user will use two digits seven segment
		AT32_DIO_u8PortInit(SEVENSEG_1st_DIGIT_PORT, 0xff); //set the port as output
		AT32_DIO_u8PortInit(SEVENSEG_2nd_DIGIT_PORT, 0xff); //set the port as output

		//check type of the first digit
		#if SEVENSEG_1st_DIGIT_TYPE == COM_CATHODE //if the user choose to use common cathode seven segment
			AT32_DIO_u8SetPortValue(SEVENSEG_1st_DIGIT_PORT, 0x00); //turn off seven segment at first

		#elif SEVENSEG_1st_DIGIT_TYPE == COM_ANODE //if the user choose to use common anode seven segment
			AT32_DIO_u8SetPortValue(SEVENSEG_1st_DIGIT_PORT, 0xFF); //turn off seven segment at first

		#else
			#error "'SEVENSEG_1st_DIGIT_TYPE', in configuration file, isn't set well!"
		#endif

		//check type of the first digit
		#if SEVENSEG_2nd_DIGIT_TYPE == COM_CATHODE //if the user choose to use common cathode seven segment
			AT32_DIO_u8SetPortValue(SEVENSEG_2nd_DIGIT_PORT, 0x00); //turn off seven segment at first

		#elif SEVENSEG_2nd_DIGIT_TYPE == COM_ANODE //if the user choose to use common anode seven segment
			AT32_DIO_u8SetPortValue(SEVENSEG_2nd_DIGIT_PORT, 0xFF); //turn off seven segment at first

		#else
			#error "'SEVENSEG_2nd_DIGIT_TYPE', in configuration file, isn't set well!"
		#endif

#else
	#error "'SEVENSEG_DIGITS_NUM', in configuration file, isn't set well!"

#endif /* end if that check digits */
}

void SevenSeg_voidShowNumber(u8 Cpy_u8Number)
{

	/*********************************************** IF ONE DIGIT *********************************************************/
#if SEVENSEG_DIGITS_NUM == ONE_DIGIT //if the user will use one digit seven segment
	u8 Local_u8FirstDig = Cpy_u8Number % 10; //to make sure that the number will be shown if the first digit only
	//check type of the seven segment
	#if SEVENSEG_1st_DIGIT_TYPE == COM_CATHODE //if the user choose to use common cathode seven segment
		AT32_DIO_u8SetPortValue(SEVENSEG_1st_DIGIT_PORT, g_7SegCC_Num[Local_u8FirstDig]); //set the port to the represented binary code of the number

	#elif SEVENSEG_1st_DIGIT_TYPE == COM_ANODE //if the user choose to use common anode seven segment
		AT32_DIO_u8SetPortValue(SEVENSEG_1st_DIGIT_PORT, ~(g_7SegCC_Num[Cpy_u8Number])); //set the port to the represented binary code of the number

	#else
		#error "'SEVENSEG_1st_DIGIT_TYPE', in configuration file, isn't set well!"
	#endif /* end if that check number of digits */

	/*********************************************** IF TWO DIGITS ********************************************************/
#elif SEVENSEG_DIGITS_NUM == TWO_DIGITS //if the user will use two digits seven segment
		u8 Local_u8FirstDig = Cpy_u8Number % 10; //extract first digit
		u8 Local_u8SecondDig = ((Cpy_u8Number / 10) % 10); //extract the second digit
		//check type of the first digit
		#if SEVENSEG_1st_DIGIT_TYPE == COM_CATHODE //if the user choose to use common cathode seven segment
			AT32_DIO_u8SetPortValue(SEVENSEG_1st_DIGIT_PORT, g_7SegCC_Num[Local_u8FirstDig]); //set the port to the represented binary code of the number

		#elif SEVENSEG_1st_DIGIT_TYPE == COM_ANODE //if the user choose to use common anode seven segment
			AT32_DIO_u8SetPortValue(SEVENSEG_1st_DIGIT_PORT, ~(g_7SegCC_Num[Local_u8FirstDig])); //set the port to the represented binary code of the number

		#else
			#error "'SEVENSEG_1st_DIGIT_TYPE', in configuration file, isn't set well!"
		#endif

		//check type of the first digit
		#if SEVENSEG_2nd_DIGIT_TYPE == COM_CATHODE //if the user choose to use common cathode seven segment
			AT32_DIO_u8SetPortValue(SEVENSEG_2nd_DIGIT_TYPE, g_7SegCC_Num[Local_u8SecondDig]); //set the port to the represented binary code of the number

		#elif SEVENSEG_2nd_DIGIT_TYPE == COM_ANODE //if the user choose to use common anode seven segment
			AT32_DIO_u8SetPortValue(SEVENSEG_2nd_DIGIT_PORT, ~(g_7SegCC_Num[Local_u8SecondDig])); //set the port to the represented binary code of the number

		#else
			#error "'SEVENSEG_2nd_DIGIT_TYPE', in configuration file, isn't set well!"
		#endif

#else
	#error "'SEVENSEG_DIGITS_NUM', in configuration file, isn't set well!"

#endif /* end if that check digits */

}

/*****************************************************************************************************
 *  Description ::: function to count with delay                                                     *
 *___________________________________________________________________________________________________*
 *        input ::: 3 arguments                                                                      *
 *       		    	1st- start of counter                                                        *
 *       		    	2nd- end of the counter                                                      *
 *       		    	3rd- delay 											                         *
 *___________________________________________________________________________________________________*
 *       output ::: none									                                         *
 *                                                                                                   *
 *****************************************************************************************************/
void SevenSeg_voidCounts(u8 Cpy_u8Count_Start, u8 Cpy_u8Count_End, u32 Cpy_u32Count_msDelay)
{
	u8 Local_u8Count;
	if(Cpy_u8Count_Start <= Cpy_u8Count_End) //if count from lower to bigger
	{
		for(Local_u8Count = Cpy_u8Count_Start; Local_u8Count <= Cpy_u8Count_End; Local_u8Count++) //loop to show all numbers
		{
			SevenSeg_voidShowNumber(Local_u8Count); //show the number on seven segment
			_delay_ms(Cpy_u32Count_msDelay); //delay
		}
	}
	else //if count from bigger to lower
	{
		for(Local_u8Count = Cpy_u8Count_Start; Local_u8Count >= Cpy_u8Count_End; Local_u8Count--) //loop to show all numbers
		{
			SevenSeg_voidShowNumber(Local_u8Count); //show the number on seven segment
			_delay_ms(Cpy_u32Count_msDelay); //delay
		}
	}


}
