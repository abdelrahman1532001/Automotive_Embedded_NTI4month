/*
 * EXTI_Interface.h
 *
 *  Created on: Aug 8, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
/*
 * @DESCRIPTION  ! Function to set all interrupts sense and their initial state enable or not
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI_vidInit(void);


/*_______________________________________ INT0 ________________________________________*/
/*
 * @DESCRIPTION  ! Function to disable only interrupt INT0
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI0_vidDisable(void);
/*
 * @DESCRIPTION  ! Function to enable only interrupt INT0
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI0_vidEnable(void);
/*
 * @DESCRIPTION  ! Function to set interrupt0 task
 * @OUTPUT       ! none
 * @INPUT        ! pointer to the function will happen in interrupt
 *
 */
void EXTI0_vidSetCallBack(void(*ext0CallBackFunction)(void));
/*_____________________________________________________________________________________*/


/*_______________________________________ INT1 ________________________________________*/
/*
 * @DESCRIPTION  ! Function to disable only interrupt INT1
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI1_vidDisable(void);
/*
 * @DESCRIPTION  ! Function to enable only interrupt INT1
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI1_vidEnable(void);
/*
 * @DESCRIPTION  ! Function to set interrupt1 task
 * @OUTPUT       ! none
 * @INPUT        ! pointer to the function will happen in interrupt
 *
 */
void EXTI1_vidSetCallBack(void(*ext1CallBackFunction)(void));
/*_____________________________________________________________________________________*/


/*_______________________________________ INT2 ________________________________________*/
/*
 * @DESCRIPTION  ! Function to disable only interrupt INT2
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI2_vidDisable(void);
/*
 * @DESCRIPTION  ! Function to enable only interrupt INT2
 * @OUTPUT       ! none
 * @INPUT        ! none
 *
 */
void EXTI2_vidEnable(void);
/*
 * @DESCRIPTION  ! Function to set interrupt2 task
 * @OUTPUT       ! none
 * @INPUT        ! pointer to the function will happen in interrupt
 *
 */
void EXTI2_vidSetCallBack(void(*ext2CallBackFunction)(void));
/*_____________________________________________________________________________________*/


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
