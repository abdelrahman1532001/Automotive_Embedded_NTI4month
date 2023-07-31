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
#define CLEAR_BIT(REG, BIT_NUM) (REG &= ~(1 << BIT_NUM))
#define TOG_BIT(REG, BIT_NUM)   (REG ^=  (1 << BIT_NUM))

#endif /* BITMATH_H_ */
