/*
 * LM35_Cfg.h
 *
 *  Created on: Aug 7, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef LM35_CFG_H_
#define LM35_CFG_H_
/*
 * Set LM35 ADC channel
 */
#define LM35_PIN	PA0
/*
 * If you choose to enable this mode, additional digit will be add to represent
 * the fractional part of the temperature
 * 		@Example:
 * 			when the reading temperature is 305 this mean that temperature is 30.5
 * If you don't need to read the fraction then you can disable this mode and then temperature
 * will be 30 rather than 305 such as the last example.
 *
 * 		@Options:
 * 			1-	"ENABLE"
 * 			2-  "DISABLE"
 */
#define LM35_0C5_SENSE_MODE		DISABLE


#endif /* LM35_CFG_H_ */
