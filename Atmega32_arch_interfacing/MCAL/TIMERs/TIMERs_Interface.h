/*
 * TIMER_Interface.h
 *
 *  Created on: Aug 9, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

/*____________________________________________ TIMER0 _______________________________________________*/


void TIMER0_vidInit(void);

void TIMER0_vidEnalbe(void);
void TIMER0_vidDisable(void);

void TIMER0_vidSetPreLoadValue(u8 Cpy_u8Preload);
void TIMER0_vidSetCompareMarchValue(u8 Cpy_u8ComValue);
void TIMER0_vidSetDutyCycle(u8 Cpy_u8DutyPercent);


typedef enum{
	OVF_ID,
	CTC_ID
}TIMER0_ISR_ID_t;
void TIMER0_vidSetCallBackFunc(void(*ptrCallBackFunc)(void), TIMER0_ISR_ID_t Cpy_IsrID);

/*____________________________________________________________________________________________________*/


#endif /* TIMERS_INTERFACE_H_ */
