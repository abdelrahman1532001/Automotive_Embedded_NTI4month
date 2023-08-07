#include "../../LIB/Std_Types.h"
#include "../../LIB/Bit_Math.h"

#include "../DIO_Driver/DIO_Interface.h"

#include "ADC_Cfg.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

static u8 global_u8ReadFlag = 1; //Reading ADC flag

/*********************************************************************
    @Description ! Function to initialize ADC to start using it
    @return      ! none
    @arguments   ! none
*********************************************************************/
void ADC_vidInit(void)
{
  ADC_ADCSRA_REG->ADPS = ADC_PRESCALAR; //Set ADC pre-scalar
  ADC_ADMUX_REG->REFS  = ADC_REF_VOL; //Set reference volt
  ADC_ADMUX_REG->ADLAR = ADC_RESOLUTION; //ADC Left Adjust Result Enable/Disable
  ADC_ADCSRA_REG->ADEN = 1; //Enable ADC
}

/*********************************************************************
    @Description ! Function to start conversion
    @return      ! none
    @arguments   ! channel name to start conversion on it
*********************************************************************/
void ADC_vidStartConversion(ADC_ChannelName_t Cpy_ChannelName)
{

	ADC_ADMUX_REG->MUX = Cpy_ChannelName; //Select channel to start conversion
	ADC_ADCSRA_REG->ADSC = 1; //Set start conversion bit
	global_u8ReadFlag = 0; //Clear reading flag until reading the new ADC value

}

/*********************************************************************
    @Description ! Function to read ADC after conversion complete.
    @return      ! reading of ADC
    @arguments   ! name of channel to read.
*********************************************************************/
u16  ADC_u8BusyReadChannel(ADC_ChannelName_t Cpy_ChannelName)
{

	#if ADC_RESOLUTION == HIGH_RESOLUTION
		ADC_vidStartConversion(Cpy_ChannelName);
		while(ADC_ADCSRA_REG->ADIF == 0); //wait until finish
		ADC_ADCSRA_REG->ADIF = 0; //Clear conversion flag.
		return  (ADC_ADCL_REG | ((u16)ADC_ADCH_REG << 8)); //Read ADC registers
	#endif

	#if ADC_RESOLUTION == LOW_RESOLUTION
		#error "This option is not yet supported!"
	#endif

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
u16 ADC_u32MapAnalogReading(u16 Cpy_u16AnalogVal, u16 Cpy_u16MapStart, u16 Cpy_u16MapEnd, u16 Cpy_u16AnalogStart, u16 Cpy_u16AnalogEnd)
{
	u16 local_u16NewValue;
	/*
	 * (Y - Y1) / (X - X1) = (Y2 - Y1) / (X2 - X1)
	 * X = (((Y - Y1)(X2 - X1)) / (Y2 - Y1)) + X1
	 */
	local_u16NewValue = (((u32)(Cpy_u16AnalogVal - Cpy_u16AnalogStart)*(Cpy_u16MapEnd - Cpy_u16MapStart)) / (Cpy_u16AnalogEnd - Cpy_u16AnalogStart)) + Cpy_u16MapStart;
	return local_u16NewValue; //return the value in the new value
}

