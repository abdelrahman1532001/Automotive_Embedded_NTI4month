/*
 * GIE_Private.h
 *
 *  Created on: Aug 8, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef GIE_PRIVATE_H_
#define GIE_PRIVATE_H_

typedef union{
	struct{
		u8 Reserved:7;
		u8 I:1;
	};
}SREG_REG_t;
volatile SREG_REG_t* SREG_REG = (volatile SREG_REG_t*)(0x5F);

#endif /* MCAL_GIE_GIE_PRIVATE_H_ */
