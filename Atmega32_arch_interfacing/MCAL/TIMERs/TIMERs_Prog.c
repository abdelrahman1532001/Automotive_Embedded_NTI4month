/*
 * TIMERs_Prog.c
 *
 *  Created on: Aug 9, 2023
 *      Author: ENG-Abdelrahman
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/Std_Types.h"

#include "TIMERs_Cfg.h"
#include "TIMERs_Interface.h"
#include "TIMERs_Private.h"

static void(*ptrCallBackFuncArr[2])(void) = {NULL};

/*
 * @OBJ    : Function to initialize setting of timer 0
 * @OUTPUT : none
 * @INPUT  : none
 */
void TIMER0_vidInit()
{
	/*Set timer 0 mode*/ /*from configuration file*/
	TIMER0_TCCR0_REG->WGM00 = GET_BIT(TIMER0_MODE, 0);
	TIMER0_TCCR0_REG->WGM01 = GET_BIT(TIMER0_MODE, 1);


     /*Set pin oc0 output mode*/ /*from configuration file*/
	TIMER0_TCCR0_REG->COM0x = TIMER0_OC0_PIN_MODE;


	/*Disable timer at first*/ /*from configuration file*/
	TIMER0_TCCR0_REG->CS0x = TIMER0_NO_CLK;

	/*Set interrupts*/ /*from configuration file*/
	TIMERs_TIMSK_REG->TOIE0 = TIMER0_OVF_INTERRUPT_STATUS;
	TIMERs_TIMSK_REG->OCIE0 = TIMER0_CTC_INTERRUPT_STATUS;
}

/*
 * @OBJ    : Function to Enable timer 0
 * @OUTPUT : none
 * @INPUT  : none
 */
void TIMER0_vidEnalbe(void)
{
	/*Set pre-scalar of the timer*/
	TIMER0_TCCR0_REG->CS0x = TIMER0_CLK;
}

/*
 * @OBJ    : Function to Disable timer 0
 * @OUTPUT : none
 * @INPUT  : none
 */
void TIMER0_vidDisable(void)
{
	/*Set pre-scalar to 0 to stop timer 0*/
	TIMER0_TCCR0_REG->CS0x = TIMER0_NO_CLK;
}

/*
 * @OBJ    : Function to put a pre-load value in tcnt0 register to start count from
 * @OUTPUT : none
 * @INPUT  : one byte value
 */
void TIMER0_vidSetPreLoadValue(u8 Cpy_u8Preload)
{
	/*Put the value in TCNT0 register*/
	TIMER0_TCNT0_REG = Cpy_u8Preload;
}

/*
 * @OBJ    : Function to put a compare value in ocr0 register to compare with
 * @OUTPUT : none
 * @INPUT  : one byte value
 */
void TIMER0_vidSetCompareMarchValue(u8 Cpy_u8ComValue)
{
	/*Put a compare value in ocr0 register*/
	TIMER0_OCR0_REG = Cpy_u8ComValue;
}


/*
 * @OBJ    : Function to set duty cycle in PWM modes
 * @OUTPUT : none
 * @INPUT  : take duty cycle percentage
 */
void TIMER0_vidSetDutyCycle(u8 Cpy_u8DutyPercent)
{
	/*Put a compare value in ocr0 register*/
#if (TIMER0_OC0_PIN_MODE == NON_INVERTING)
	TIMER0_OCR0_REG = ((Cpy_u8DutyPercent * 256UL)/(100));

#elif(TIMER0_OC0_PIN_MODE == INVERTING)
	TIMER0_OCR0_REG = (256 - ((Cpy_u8DutyPercent * 256UL)/(100)));

#endif
}

/*
 * @OBJ    : Function to set interrupt routine for overflow and compare match modes
 * @OUTPUT : none
 * @INPUT  : pointer to void function, ISR ID
 */
void TIMER0_vidSetCallBackFunc(void(*ptrCallBackFunc)(void), TIMER0_ISR_ID_t Cpy_IsrID)
{
	if(ptrCallBackFunc != NULL)
	{
		ptrCallBackFuncArr[Cpy_IsrID] = ptrCallBackFunc;
	}
}

void __vector_10()	__attribute__((signal));
void __vector_10()
{
	if(ptrCallBackFuncArr[CTC_ID] != NULL)
	{
		ptrCallBackFuncArr[CTC_ID]();
	}
}


void __vector_11()	__attribute__((signal));
void __vector_11()
{
	if(ptrCallBackFuncArr[OVF_ID] != NULL)
	{
		ptrCallBackFuncArr[OVF_ID]();
	}
}


/*______________________________________________________________________________________________________*/




