/*
 * TIMERs_Cfg.h
 *
 *  Created on: Aug 9, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef TIMERS_CFG_H_
#define TIMERS_CFG_H_
/*____________________________________________ Timer0 Settings _________________________________________*/
/********************************************************************************************************/

/* ```````````````````````````````````
 * ```` # "TIMER0_MODE" Options # ````
 * ```````````````````````````````````
 *		1- TIMER0_NORMAL_MODE
 *		2- TIMER0_PWM_PHASE_CORRECT_MODE
 *		3- TIMER0_CTC_MODE
 *		4- TIMER0_FAST_PWM_MODE
 *
 * ``````````````````````````````````
 * ```` # "TIMER0_CLK" Options # ````
 * ``````````````````````````````````
 * 		1- TIMER0_NO_CLK
 * 		2- TIMER0_CLK_NO_PRESCALAR
 * 		3- TIMER0_CLK_8_PRESCALAR
 * 		4- TIMER0_CLK_64_PRESCALAR
 * 		5- TIMER0_CLK_256_PRESCALAR
 * 		6- TIMER0_CLK_1024_PRESCALAR
 * 		7- TIMER0_CLK_EXT_ON_T0_FALLING_EDGE
 * 		7- TIMER0_CLK_EXT_ON_T0_RISING_EDGE
 */
#define TIMER0_MODE		TIMER0_FAST_PWM_MODE
#define TIMER0_CLK		TIMER0_CLK_8_PRESCALAR

/* ````````````````````````````````````
 * ```` # "OC0_PIN_MODE" Options # ````
 * ````````````````````````````````````
 *
 *  @COMPARE MATCH MODE || @NORMAL MODE
 *  ___________________________________
 *		1- NORMAL_OUTPUT
 *		2- TOGGLE_ON_COMPARE_MATCH
 *		3- CLR_ON_COMPARE_MATCH
 *		4- SET_ON_COMAPRE_MATCH
 *
 *  @FAST PWM MODE || @PHASE CORRECT PWM
 *  ____________________________________
 *		1- NORMAL_OUTPUT
 *		2- NON_INVERTING
 *		3- INVERTING
 *
 */
#define TIMER0_OC0_PIN_MODE	INVERTING
/*
 * @Options
 * ________
 *
 * 		1- INTERRUPT_EN
 * 		2- INTERRUPT_DIS
 *
 * 	!!! If you choose to enable it DON'T forget to enable global interrupt
 */
#define TIMER0_CTC_INTERRUPT_STATUS		INTERRUPT_DIS
#define TIMER0_OVF_INTERRUPT_STATUS		INTERRUPT_DIS

#endif /* TIMERS_CFG_H_ */
