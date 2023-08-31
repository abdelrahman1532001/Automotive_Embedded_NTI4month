#ifndef  ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/************** USER TYPEDEFINITION **********************/

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

typedef enum{
	ADC_NoError,
	ADC_BusyError,
	ADC_NullError,
}ADC_ErrStatus_t;


/************************************************************/


/******************** FUNCTION PROTOTYPE ********************************************/


/*********************************************************************
	@FUNC       : ADC_ErrStatus_t ADC_xInit(void);
	@PARAM[ IN] : none
	@PARAM[OUT] : none
	@RET_VAL    : return error status of type @ADC_ErrStatus_t

	NOTE		: none
 *********************************************************************/
ADC_ErrStatus_t ADC_xInit(void);

/*********************************************************************
	@FUNC       : ADC_xReadChannelBusyWait(Cpy_pu16ReadBuffer, Cpy_ChannelName).
	@PARAM[ IN] : [Cpy_pu16ReadBuffer] replace this with the address of your reading variable.
	@PARAM[ IN] : [Cpy_ChannelName   ] replace this with the name of channel you want to read-
				  from and this take a value from @ADC_ChannelName_t typedef.
	@PARAM[OUT] : none
	@RET_VAL    : return error status of type @ADC_ErrStatus_t

	NOTE		: none
 *********************************************************************/
ADC_ErrStatus_t  ADC_xReadChannelBusyWait(u16 *Cpy_pu16ReadBuffer,ADC_ChannelName_t Cpy_ChannelName);


/*********************************************************************
    @Description ! Function to convert from one range to another
    @return      ! The value in the new range
    @arguments   ! 1st, value in the old range
    			   2nd, new range start
    			   3rd, new range end
    			   4th, old range start
    			   5th, old range end
 *********************************************************************/
u32 ADC_u32MapAnalogReading(u16 Cpy_u16AnalogVal, u16 Cpy_u16MapStart, u16 Cpy_u16MapEnd, u16 Cpy_u16AnalogStart, u16 Cpy_u16AnalogEnd);



/******************************************************************************************************/
#endif
