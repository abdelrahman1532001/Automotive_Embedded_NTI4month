#ifndef  ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum{
    ADC0=0, /*PORTA pin0*/
    ADC1,   /*PORTA pin1*/
    ADC2,   /*PORTA pin2*/
    ADC3,   /*PORTA pin3*/
    ADC4,   /*PORTA pin4*/
    ADC5,   /*PORTA pin5*/
    ADC6,   /*PORTA pin6*/
    ADC7,   /*PORTA pin7*/

    }ADC_ChannelName_t; //Enum Of Available Channels For Analog Read

/*********************************************************************
    @Description ! Function to initialize ADC to start using it
    @return      ! none
    @arguments   ! none
*********************************************************************/
void ADC_vidInit(void);

/*********************************************************************
    @Description ! Function to read ADC after conversion complete.
    @return      ! 0 for incomplete reading.
    			   1 for complete reading.
    @arguments   ! Address of reading variable(u16 *).
*********************************************************************/
u8  ADC_u8PeriodicReadChannel(u16 *Cpy_pu16AdcReading);

/*********************************************************************
    @Description ! Function to start conversion
    @return      ! none
    @arguments   ! channel name to start conversion on it
*********************************************************************/
void ADC_vidStartConversion(ADC_ChannelName_t Cpy_ChannelName);

/*********************************************************************
    @Description ! Function to convert from one range to another
    @return      ! The value in the new range
    @arguments   ! 1st, value in the old range
    			   2nd, new range start
    			   3rd, new range end
    			   4th, old range start
    			   5th, old range end
*********************************************************************/
u16 ADC_u32MapAnalogReading(u16 Cpy_u16AnalogVal, u16 Cpy_u16MapStart, u16 Cpy_u16MapEnd, u16 Cpy_u16AnalogStart, u16 Cpy_u16AnalogEnd);

#endif
