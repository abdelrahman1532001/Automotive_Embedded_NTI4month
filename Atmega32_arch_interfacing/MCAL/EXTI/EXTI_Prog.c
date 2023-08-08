/*
 * EXTI_Prog.c
 *
 *  Created on: Aug 8, 2023
 *      Author: ENG-Abdelrahman
 */

#include "../../LIB/Std_Types.h"
#include "../../LIB/Bit_Math.h"

#include "EXTI_Cfg.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"

//array to save addresses of call back functions of INT0, INT1, INT2
static void (*global_ptrCallBackArr[3])(void)={NULL, NULL, NULL};

/*
 * @DESCRIPTION  ! Function to set all interrupts sense and their initial state enable or not
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI_vidInit(void)
{
	//Set sense of interrupt INT0, INT1, INT2
	EXTI_MCUCR_REG->ISC0  = EXTI0_SENSE; //Set INT0 sense
	EXTI_MCUCR_REG->ISC1  = EXTI1_SENSE; //Set INT1 sense
	EXTI_MCUCSR_REG->ISC2 = EXTI2_SENSE; //Set INT2 sense

	//Enable or Disable INT0, INT1, INT2
	EXTI_GICR_REG->INT0 = EXTI0_STATUS; //Enable or Disable INT0
	EXTI_GICR_REG->INT1 = EXTI1_STATUS; //Enable or Disable INT1
	EXTI_GICR_REG->INT2 = EXTI2_STATUS; //Enable or Disable INT2

}

/*_______________________________________ INT0 ________________________________________*/

/*
 * @DESCRIPTION  ! Function to disable only interrupt INT0
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI0_vidDisable(void)
{
	EXTI_GICR_REG->INT0 = EXTI_DISABLE; //Disable INT0 interrupt
}
/*
 * @DESCRIPTION  ! Function to enable only interrupt INT0
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI0_vidEnable(void)
{
	EXTI_GICR_REG->INT0 = EXTI_ENABLE; //Enable INT0 interrupt
}
/*
 * @DESCRIPTION  ! Function to set interrupt0 task
 * @OUTPUT       ! none
 * @INPUT        ! pointer to the function will happen in interrupt
 *
 */
void EXTI0_vidSetCallBack(void(*ext0CallBackFunction)(void))
{
	if(ext0CallBackFunction != NULL) //check if valid address
		global_ptrCallBackArr[0] = ext0CallBackFunction; //save the address in the array to call it in interrupt routine
}

/*_______________________________________ INT1 ________________________________________*/

/*
 * @DESCRIPTION  ! Function to disable only interrupt INT1
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI1_vidDisable(void)
{
	EXTI_GICR_REG->INT1 = EXTI_DISABLE; //Disable INT1 interrupt
}
/*
 * @DESCRIPTION  ! Function to enable only interrupt INT1
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI1_vidEnable(void)
{
	EXTI_GICR_REG->INT1 = EXTI_ENABLE; //Disable INT1 interrupt
}
/*
 * @DESCRIPTION  ! Function to set interrupt1 task
 * @OUTPUT       ! none
 * @INPUT        ! pointer to the function will happen in interrupt
 *
 */
void EXTI1_vidSetCallBack(void(*ext1CallBackFunction)(void))
{
	if(ext1CallBackFunction != NULL) //check if valid address
		global_ptrCallBackArr[1] = ext1CallBackFunction; //save the address in the array to call it in interrupt routine
}

/*_______________________________________ INT2 ________________________________________*/

/*
 * @DESCRIPTION  ! Function to disable only interrupt INT2
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI2_vidDisable(void)
{
	EXTI_GICR_REG->INT2 = EXTI_DISABLE; //Disable INT2 interrupt
}
/*
 * @DESCRIPTION  ! Function to enable only interrupt INT2
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI2_vidEnable(void)
{
	EXTI_GICR_REG->INT2 = EXTI_ENABLE; //Disable INT2 interrupt
}
/*
 * @DESCRIPTION  ! Function to set interrupt2 task
 * @OUTPUT       ! none
 * @INPUT        ! pointer to the function will happen in interrupt
 *
 */
void EXTI2_vidSetCallBack(void(*ext2CallBackFunction)(void))
{
	if(ext2CallBackFunction != NULL) //check if valid address
		global_ptrCallBackArr[2] = ext2CallBackFunction; //save the address in the array to call it in interrupt routine
}


/*________________________________ SURVICE ROUTINE _______________________________________*/

//interrupt routine of INT0
void __vector_1 () __attribute__ ((signal));
void __vector_1 ()
{
	if(global_ptrCallBackArr[0] != NULL) //check if call back correctly passed
		global_ptrCallBackArr[0]();
}

//interrupt routine of INT2
void __vector_2 () __attribute__ ((signal));
void __vector_2 ()
{
	if(global_ptrCallBackArr[1] != NULL) //check if call back correctly passed
		global_ptrCallBackArr[1]();
}

//interrupt routine of INT3
void __vector_3 () __attribute__ ((signal));
void __vector_3 ()
{
	if(global_ptrCallBackArr[2] != NULL) //check if call back correctly passed
		global_ptrCallBackArr[2]();
}
