/*
 * TIMER_Private.h
 *
 *  Created on: Aug 9, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_
/*````````````````````````````````````````````````````````````````````````````````````````````````````*/
/*`````````````````````````````````````````` Registers ```````````````````````````````````````````````*/
/*````````````````````````````````````````````````````````````````````````````````````````````````````*/

//Timer/Counter Register
#define TIMER0_TCNT0_REG (*(volatile u8*)(0x52))

//Output Compare Register
#define TIMER0_OCR0_REG  (*(volatile u8*)(0x5C))

//Timer/Counter Control Register
typedef union{
	u8 AllBits; //to access all register one time
	struct{
		u8 CS0x :3; //Clock Select bits
		u8 WGM01:1; //Waveform Generation Mode Bit 1
		u8 COM0x:2; //Compare Match Output Mode bits
		u8 WGM00:1; //Waveform Generation Mode Bit 0
		u8 FOC0 :1; //Force Output Compare bit
	}; //to access the bits of the register

}TIMER0_TCCR0_REG_t;
volatile TIMER0_TCCR0_REG_t* TIMER0_TCCR0_REG = (volatile TIMER0_TCCR0_REG_t*)(0x53);

//Timer/Counter Interrupt Mask Register
typedef union{
	u8 AllBits; //to access all register one time
	struct{
		u8 TOIE0 :1; //Timer/Counter0 Overflow Interrupt Enable bit
		u8 OCIE0 :1; //Timer/Counter0 Output Compare Match Interrupt Enable bit
		u8 TOIE1 :1;
		u8 OCIE1B:1;
		u8 OCIE1A:1;
		u8 TICIE1:1;
		u8 TOIE2 :1;
		u8 OCIE2 :1;
	}; //to access the bits of the register

}TIMERs_TIMSK_REG_t;
volatile TIMERs_TIMSK_REG_t* TIMERs_TIMSK_REG = (volatile TIMERs_TIMSK_REG_t*)(0x59);


//Timer/Counter Interrupt Flag
//OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0
typedef union{
	u8 AllBits; //to access all register one time
	struct{
		u8 TOV0 :1; //Timer/Counter0 Overflow Interrupt Enable bit
		u8 OCF0 :1; //Timer/Counter0 Output Compare Match Interrupt Enable bit
		u8 TOV1 :1;
		u8 OCF1B:1;
		u8 OCF1A:1;
		u8 ICF1 :1;
		u8 TOV2 :1;
		u8 OCF2 :1;
	}; //to access the bits of the register

}TIMERs_TIFR_REG_t;
volatile TIMERs_TIFR_REG_t* TIMERs_TIFR_REG = (volatile TIMERs_TIFR_REG_t*)(0x58);

/*````````````````````````````````````````````````````````````````````````````````````````````````````*/
/*`````````````````````````````````````````` Some Constants ``````````````````````````````````````````*/
/*````````````````````````````````````````````````````````````````````````````````````````````````````*/

//Timer 0 modes value
#define TIMER0_NORMAL_MODE                 0x00
#define TIMER0_PWM_PHASE_CORRECT_MODE      0x01
#define TIMER0_CTC_MODE                    0x02
#define TIMER0_FAST_PWM_MODE               0x03
//Timer 0 clock options
#define TIMER0_NO_CLK                      0x00
#define TIMER0_CLK_NO_PRESCALAR            0x01
#define TIMER0_CLK_8_PRESCALAR             0x02
#define TIMER0_CLK_64_PRESCALAR            0x03
#define TIMER0_CLK_256_PRESCALAR           0x04
#define TIMER0_CLK_1024_PRESCALAR          0x05
#define TIMER0_CLK_EXT_ON_T0_FALLING_EDGE  0x06
#define TIMER0_CLK_EXT_ON_T0_RISING_EDGE   0x07
//Timer 0 OC0 pin output mode
#define NORMAL_OUTPUT					   0x00
#define TOGGLE_ON_COMPARE_MATCH			   0x01
#define CLR_ON_COMPARE_MATCH			   0x02
#define SET_ON_COMAPRE_MATCH               0x03
#define NON_INVERTING					   0x02
#define INVERTING						   0x03
//Interrupt options
#define INTERRUPT_EN					   0x01
#define INTERRUPT_DIS 					   0x00


#endif /* TIMERS_PRIVATE_H_ */
