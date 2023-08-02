/*
 * SEVENSEG_config.h
 *
 *  Created on: Jul 28, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef SEVENSEG_CONFIG_H_
#define SEVENSEG_CONFIG_H_

/*****************************************************************************************************
 *  Description ::: set configuration for ports of the used digits                                   *
 *___________________________________________________________________________________________________*
 *      Options ::: four options ("porta" or "portb" or "portc" or "portd")                          *
 *      			**note** if you will use two digits make sure to choose different ports          *
 *                                                                                                   *
 *****************************************************************************************************/
#define	SEVENSEG_1st_DIGIT_PORT			portb
#define SEVENSEG_2nd_DIGIT_PORT			porta

/*****************************************************************************************************
 *  Description ::: set configuration for types of the used digits                                   *
 *___________________________________________________________________________________________________*
 *      Options ::: two options ("COM_CATHODE" or "COM_ANODE")                                       *
 *                                                                                                   *
 *****************************************************************************************************/
#define	SEVENSEG_1st_DIGIT_TYPE			COM_CATHODE
#define	SEVENSEG_2nd_DIGIT_TYPE			COM_ANODE

/*****************************************************************************************************
 *  Description ::: set configuration for number of the used digits                                  *
 *___________________________________________________________________________________________________*
 *      Options ::: two options ("ONE_DIGIT" or "TWO_DIGITS")                                        *
 *                                                                                                   *
 *****************************************************************************************************/
#define SEVENSEG_DIGITS_NUM 	ONE_DIGIT



#endif /* HAL_SEVENSEG_DRIVER_SEVENSEG_CONFIG_H_ */
