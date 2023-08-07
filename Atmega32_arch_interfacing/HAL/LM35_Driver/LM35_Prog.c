/*
 * LM35_Prog.c
 *
 *  Created on: Aug 7, 2023
 *      Author: ENG-Abdelrahman
 */

#include "../../LIB/Std_Types.h"

#include "../../MCAL/ADC_Driver/ADC_Interface.h"
#include "../../MCAL/DIO_Driver/DIO_Interface.h"

#include "../LM35_Driver/LM35_Cfg.h"
#include "../LM35_Driver/LM35_Interface.h"
#include "../LM35_Driver/LM35_Private.h"
/**************************************************************************************************
 * @Description ! Use This function to read temperature using lm35, make sure to include ADC file *
 * 				  and enable it so that this function can do its job.                             *
 * @return      ! u16 temperature                                                                 *
 * @input       ! none.                                                                           *
 **************************************************************************************************/
u16 LM35_u16GetTemp(void)
{
	u16 Local_u16Temp;

	#if LM35_0C5_SENSE_MODE == DISABLE
		Local_u16Temp  = ADC_u8BusyReadChannel(LM35_PIN);
		Local_u16Temp  = ADC_u32MapAnalogReading(Local_u16Temp, 0, 5000, 0, 1024);
		Local_u16Temp /= 10;
		return Local_u16Temp;
	#endif

	#if LM35_0C5_SENSE_MODE == ENABLE
		*Cpy_s16TempRead = ADC_u32MapAnalogReading(Local_u16AdcReading, 0, 5000, 0, 1024);
		return 1;
	#endif

}
