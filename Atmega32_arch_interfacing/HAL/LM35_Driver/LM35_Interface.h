/*
 * LM32_Interface.h
 *
 *  Created on: Aug 7, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

/**************************************************************************************************
 * @Description ! Use This function to read temperature using lm35, make sure to include ADC file *
 * 				  and enable it so that this function can do its job.                             *
 * @return      ! u16 temperature                                                                 *
 * @input       ! none.                                                                           *
 **************************************************************************************************/
u16 LM35_u16GetTemp(void);

#endif /* LM35_INTERFACE_H_ */
