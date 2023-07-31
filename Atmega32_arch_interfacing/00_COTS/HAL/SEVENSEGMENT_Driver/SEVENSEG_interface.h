/*
 * SEVENSEG_interface.h
 *
 *  Created on: Jul 28, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef SEVENSEG_INTERFACE_H_
#define SEVENSEG_INTERFACE_H_
/*****************************************************************************************************
 *  Description ::: function to Initiate ports of the seven segment                                  *
 *___________________________________________________________________________________________________*
 *        input ::: none                                                                             *
 *___________________________________________________________________________________________________*
 *       output ::: none									                                         *
 *                                                                                                   *
 *****************************************************************************************************/
void SevenSeg_voidInit();
/*****************************************************************************************************
 *  Description ::: function to show number one digit or two digit                                   *
 *___________________________________________________________________________________________________*
 *        input ::: one or two digits number                                                         *
 *___________________________________________________________________________________________________*
 *       output ::: none									                                         *
 *                                                                                                   *
 *****************************************************************************************************/
void SevenSeg_voidShowNumber(u8 Cpy_u8Number);
/*****************************************************************************************************
 *  Description ::: function to count with delay                                                     *
 *___________________________________________________________________________________________________*
 *        input ::: 3 arguments                                                                      *
 *       		    	1st- start of counter                                                        *
 *       		    	2nd- end of the counter                                                      *
 *       		    	3rd- delay 											                         *
 *___________________________________________________________________________________________________*
 *       output ::: none									                                         *
 *                                                                                                   *
 *****************************************************************************************************/
void SevenSeg_voidCounts(u8 Cpy_u8Count_Start, u8 Cpy_u8Count_End, u32 Cpy_u32Count_msDelay);


#endif /* HAL_SEVENSEG_DRIVER_SEVENSEG_INTERFACE_H_ */
