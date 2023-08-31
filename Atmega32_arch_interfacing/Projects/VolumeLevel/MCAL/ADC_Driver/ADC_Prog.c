#include "../../LIB/Std_Types.h"
#include "../../LIB/Bit_Math.h"

#include "../DIO_Driver/DIO_Interface.h"

#include "ADC_Cfg.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

static u8 global_u8ReadFlag = 1; //Reading ADC flag
static void ADC_vidStartConversion(ADC_ChannelName_t Cpy_ChannelName);
ADC_Status_t global_xADCStatus;

/*********************************************************************
	@FUNC       : ADC_ErrStatus_t ADC_xInit(void);
	@PARAM[ IN] : none
	@PARAM[OUT] : none
	@RET_VAL    : return error status of type @ADC_ErrStatus_t

	NOTE		: none
 *********************************************************************/
ADC_ErrStatus_t ADC_xInit(void)
{
	ADC_ErrStatus_t Local_xErrorStatus = ADC_NoError;

	global_xADCStatus = ADC_Free;

	ADC_ADCSRA_REG->ADPS = ADC_PRESCALAR;  //Set ADC pre-scalar

	ADC_ADMUX_REG->REFS  = ADC_REF_VOL;    //Set reference volt

	ADC_ADMUX_REG->ADLAR = ADC_RESOLUTION; //ADC Left Adjust Result Enable/Disable

	ADC_ADCSRA_REG->ADEN = 1;              //Enable ADC

	return Local_xErrorStatus;
}

/*********************************************************************
	@FUNC       : ADC_xReadChannelBusyWait(Cpy_pu16ReadBuffer, Cpy_ChannelName).
	@PARAM[ IN] : [Cpy_pu16ReadBuffer] replace this with the address of your reading variable.
	@PARAM[ IN] : [Cpy_ChannelName   ] replace this with the name of channel you want to read-
				  from and this take a value from @ADC_ChannelName_t typedef.
	@PARAM[OUT] : none
	@RET_VAL    : return error status of type @ADC_ErrStatus_t

	NOTE		: none
 *********************************************************************/
ADC_ErrStatus_t  ADC_xReadChannelBusyWait(u16 *Cpy_pu16ReadBuffer,ADC_ChannelName_t Cpy_ChannelName)
{
	ADC_ErrStatus_t Local_xErrorStatus = ADC_NoError;

	if(global_xADCStatus == ADC_Busy) //if ADC is busy reading another channel
	{
		Local_xErrorStatus = ADC_BusyError; //set error to busy error
	}
	else if(global_xADCStatus == ADC_Free) //else if ADC is free for reading
	{
		if(Cpy_pu16ReadBuffer == NULL) //check if reading address is valid or not
		{
			Local_xErrorStatus = ADC_NullError; //if address not valid set error to null error
		}
		else //if address is valid start the reading process
		{
			global_xADCStatus = ADC_Busy; //make ADC busy before starting

			ADC_vidStartConversion(Cpy_ChannelName); //start conversion on the selected channel

			while(ADC_ADCSRA_REG->ADIF == 0) //Loop until the reading flag become 1
			{
				//Wait until reading finish
			}

			ADC_ADCSRA_REG->ADIF = 1; //set reading to clear it

#if ADC_RESOLUTION == HIGH_RESOLUTION
			*Cpy_pu16ReadBuffer = (ADC_ADCL_REG | ((u16)ADC_ADCH_REG) << 8); //read ADC register
#elif ADC_RESOLUTION == LOW_RESOLUTION
#error "This option hasn't been set until now!"
#endif

			global_xADCStatus = ADC_Free; //make ADC free after finish reading

		} /* end if(Cpy_pu16ReadBuffer == NULL) */

	}/* end if(global_xADCStatus == ADC_Busy) */

	return Local_xErrorStatus;
}

/*********************************************************************
    @Description ! Function to start conversion
    @return      ! none
    @arguments   ! channel name to start conversion on it
 *********************************************************************/
void ADC_vidStartConversion(ADC_ChannelName_t Cpy_ChannelName)
{

	ADC_ADMUX_REG->MUX   = Cpy_ChannelName; //Select channel to start conversion
	ADC_ADCSRA_REG->ADSC = 1; //Set start conversion bit
	global_u8ReadFlag    = 0; //Clear reading flag until reading the new ADC value

}

/*********************************************************************
    @Description ! Function to convert from one range to another
    @return      ! The value in the new range
    @arguments   ! 1st, value in the old range
    			   2nd, new range start
    			   3rd, new range end
    			   4th, old range start
    			   5th, old range end
 *********************************************************************/
u32 ADC_u32MapAnalogReading(u16 Cpy_u16AnalogVal, u16 Cpy_u16MapStart, u16 Cpy_u16MapEnd, u16 Cpy_u16AnalogStart, u16 Cpy_u16AnalogEnd)
{
	u32 local_u32NewValue;
	/*
	 * (Y - Y1) / (X - X1) = (Y2 - Y1) / (X2 - X1)
	 * X = (((Y - Y1)(X2 - X1)) / (Y2 - Y1)) + X1
	 */
	local_u32NewValue = (((u32)(Cpy_u16AnalogVal - Cpy_u16AnalogStart)*(Cpy_u16MapEnd - Cpy_u16MapStart)) / (Cpy_u16AnalogEnd - Cpy_u16AnalogStart)) + Cpy_u16MapStart;
	return local_u32NewValue; //return the value in the new value
}




