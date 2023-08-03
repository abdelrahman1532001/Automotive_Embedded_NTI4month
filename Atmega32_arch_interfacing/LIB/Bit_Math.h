/*
 * bitmath.h
 *
 *  Created on: Jul 27, 2023
 *      Author: eng-abdelrahman
 */

#ifndef BITMATH_H_
#define BITMATH_H_

#define GET_BIT(REG, BIT_NUM)   ((REG >> BIT_NUM) & 1)
#define SET_BIT(REG, BIT_NUM)   (REG |=  (1 << BIT_NUM))
#define CLR_BIT(REG, BIT_NUM) (REG &= ~(1 << BIT_NUM))
#define TOG_BIT(REG, BIT_NUM)   (REG ^=  (1 << BIT_NUM))
#define AND_REG(REG, MASK)		(REG &= MASK)
#define OR_REG(REG, MASK)       (REG |= MASK)

#endif /* BITMATH_H_ */
