/*
 * EXTI_Private.h
 *
 *  Created on: Aug 8, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

typedef union{
	struct{
		u8 ISC0:2; //Interrupt Sense Control 0
		u8 ISC1:2; //Interrupt Sense Control 1
		u8 Reserved:4;
	};
}EXTI_MCUCR_REG_t;
volatile EXTI_MCUCR_REG_t* EXTI_MCUCR_REG = (volatile EXTI_MCUCR_REG_t*)(0x55);

typedef union{
	struct{
		u8 Reserved:5;
		u8 ISC2:1;
	};
}EXTI_MCUCSR_REG_t;
volatile EXTI_MCUCSR_REG_t *EXTI_MCUCSR_REG = (volatile EXTI_MCUCSR_REG_t *)(0x54);



typedef union{
	struct{
		u8 Reserved:5;
		u8 INT0:1; //External Interrupt Request 1 Enable
		u8 INT1:1; //External Interrupt Request 2 Enable
		u8 INT2:1; //External Interrupt Request 3 Enable

	};
}EXTI_GICR_REG_t;
volatile EXTI_GICR_REG_t *EXTI_GICR_REG = (volatile EXTI_GICR_REG_t *)(0x5B);

typedef union{
	struct{
		u8 Reserved:5;
		u8 INTF2:1; //External Interrupt flag
		u8 INTF0:1; //External Interrupt flag
		u8 INTF1:1; //External Interrupt flag

	};
}EXTI_GIFR_REG_t;
volatile EXTI_GIFR_REG_t *EXTI_GIFR_REG = (volatile EXTI_GIFR_REG_t *)(0x5A);
/*
ISC01 ISC00 Description
  0 	0  	The low level of INT0 generates an interrupt request.
  0 	1 	Any logical change on INT0 generates an interrupt request.
  1 	0 	The falling edge of INT0 generates an interrupt request.
  1 	1 	The rising edge of INT0 generates an interrupt request.
*/
#define	INT0_LOW_LEVEL		0x00
#define INT0_LOGIC_CHANGE	0x01
#define INT0_FALLING_EDGE	0x02
#define INT0_RISING_EDGE	0x03
/*
ISC11 ISC10 Description
  0 	0 	The low level of INT1 generates an interrupt request.
  0 	1 	Any logical change on INT1 generates an interrupt request.
  1 	0 	The falling edge of INT1 generates an interrupt request.
  1 	1	The rising edge of INT1 generates an interrupt request.
*/
#define	INT1_LOW_LEVEL		0x00
#define INT1_LOGIC_CHANGE	0x01
#define INT1_FALLING_EDGE	0x02
#define INT1_RISING_EDGE	0x03
/*
ISC2  Description
  0  	The falling edge of INT2 generates an interrupt request.
  1 	The rising edge of INT2 generates an interrupt request.
*/
#define INT2_FALLING_EDGE	0x00
#define INT2_RISING_EDGE	0x01

#define EXTI_ENABLE			0x01
#define EXTI_DISABLE		0x00

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
