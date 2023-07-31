/*
 * KPD_config.h
 *
 *  Created on: Jul 29, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

/*
 * 		Options :
 * 			- porta
 * 			- portb
 * 			- portc
 * 			- portd
 */
#define KPD_ROW_PORT        porta
#define KPD_COL_PORT        porta

#define KPD_NUM_OF_ROWS 	4
#define KPD_NUM_OF_COLS 	3

#define KPD_ROW_PINS        {pin0, pin1, pin2, pin3}
#define KPD_COL_PINS        {pin4, pin5, pin6}
#define KPD_KEY_MAP         { 			  \
					          {1, 2, 3}, \
					          {4, 5, 6}, \
					          {7, 8, 9}, \
					          {0, 0, 0}  \
					        }            \

#endif /* HAL_KEYPAD_DRIVER_KPD_CONFIG_H_ */
