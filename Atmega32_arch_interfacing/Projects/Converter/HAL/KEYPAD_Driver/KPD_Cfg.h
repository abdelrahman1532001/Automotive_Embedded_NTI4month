/*
 * KPD_config.h
 *
 *  Created on: Jul 29, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef KPD_CFG_H_
#define KPD_CFG_H_

/*
 * Set Number Of Rows And Columns
 */
#define KPD_NUM_OF_ROWS 	4
#define KPD_NUM_OF_COLS 	5
/*
 * 	- Set Rows' Pins Array And Columns' Pins Array Like This.
 *
 * 		#define KPD_ROW_PINS {PA0, PA1, PA2, ..........}
 * 		#define KPD_COL_PINS {PB0, PB1, PB2, ..........}
 *
 * 	- You Can Change The Names Of Pins Of Rows Or Columns, But Make Sure
 * 	  That The Number Of Pins Is The Same As "KPD_NUM_OF_ROWS" And "KPD_NUM_OF_COLS".
 *
 * 	<< List Of Available List Depending On My DIO Driver. >>
 *
 * 	        - PD0    - PC0    - PB0    - PA0
 * 	        - PD1    - PC1    - PB1    - PA1
 * 	        - PD2    - PC2    - PB2    - PA2
 * 	        - PD3    - PC3    - PB3    - PA3
 * 	        - PD4    - PC4    - PB4    - PA4
 * 	        - PD5    - PC5    - PB5    - PA5
 * 	        - PD6    - PC6    - PB6    - PA6
 * 	        - PD7    - PC7    - PB7    - PA7
 *
 * 	<< Warning !>> << Make Rows Pins Output And Columns Pins Input With PullUp >>
 *
 */
#define KPD_ROWS_PINS        {PC0, PC1, PC2, PC3}
#define KPD_COLS_PINS        {PC4, PC5, PC6, PC7, PD0}
/*
 * -This Is The KeyPad Map.
 *
 * -Make Sure That Number Of Rows And Columns Matches The Value Of "KPD_NUM_OF_COLS" and
 *  "KPD_NUM_OF_ROWS".
 *
 * -Feel Free To Change The Values Of Keys.
 *
 */
#define KPD_KEYS_MAP         {{'A', '1', '2', '3' , '='} , {'B', '4', '5', '6' , 'R'} , {'C', '7', '8', '9' , '<'} , {'D', 'E', 'F', '0' , '>'}}
/*
 * -Set The Not Pressed Key So That KeyPad Return It When None Key Is Pressed.
 *
 * -Make Sure That This Key Isn't Exist In Your KeyPad Keys Map
 */
#define KPD_NOT_PRESSED		255

#endif /* HAL_KEYPAD_DRIVER_KPD_CFG_H_ */
