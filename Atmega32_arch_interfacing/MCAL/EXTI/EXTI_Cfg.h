/*
 * EXTI_Cfg.h
 *
 *  Created on: Aug 8, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

/*
 * Enable needed external interrupts
 * 		@Options !
 * 			1- EXTI_ENABLE
 * 			2- EXTI_DISABLE
 *
 * 	@note ! DON'T forget to enable global interrupt before using this driver
 */
#define EXTI0_STATUS		EXTI_ENABLE
#define EXTI1_STATUS		EXTI_ENABLE
#define EXTI2_STATUS		EXTI_ENABLE
/*
 * Choose sense of external interrupt INT0
 * 		@Options !
 * 			1- INT0_LOW_LEVEL
 * 			2- INT0_LOGIC_CHANGE
 * 			3- INT0_FALLING_EDGE
 * 			4- INT0_RISING_EDGE
 */
#define EXTI0_SENSE		INT0_FALLING_EDGE
/*
 * Choose sense of external interrupt INT1
 * 		@Options !
 * 			1- INT1_LOW_LEVEL
 * 			2- INT1_LOGIC_CHANGE
 * 			3- INT1_FALLING_EDGE
 * 			4- INT1_RISING_EDGE
 */
#define EXTI1_SENSE		INT1_RISING_EDGE
/*
 * Choose sense of external interrupt INT2
 * 		@Options !
 * 			1- INT2_FALLING_EDGE
 * 			2- INT2_RISING_EDGE
 */
#define EXTI2_SENSE		INT2_FALLING_EDGE


#endif /* MCAL_EXTI_EXTI_CFG_H_ */
