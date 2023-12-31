/*
 * LCD_Cfg.h
 *
 *  Created on: Jul 31, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/*_________________________________________________ SET LCD MODE __________________________________________________________*/

/**************
 	 Options :
***************
1-		 "LCD_EIGHT_PINS_MODE"
2-		 "LCD_FOUR_PINS_MODE"
*********************************************/
#define LCD_PINS_MODE		LCD_FOUR_PINS_MODE
/********************************************/

/*______________________________________________ SET LCD CONTROL PINS ______________________________________________________*/


/********************************************/
/* SET LCD CONTROL PINS */
#define LCD_EN_PIN			PB0
#define LCD_RS_PIN			PB1
#define LCD_RW_PIN			PB2
/********************************************/

/*___________________________________________ SET LCD DATA PORT 8BITS MODE _________________________________________________*/


/********************************************/
/* SET IF 8BITS MODE */
#define LCD_DATA_PORT		PC
/********************************************/

/*___________________________________________ SET LCD DATA PINS 4BITS MODE _________________________________________________*/

/********************************************/
/* SET IF 4BITS MODE */
#define LCD_D4_PIN			PC4
#define LCD_D5_PIN			PC5
#define LCD_D6_PIN			PC6
#define LCD_D7_PIN			PC7
/********************************************/

/*_______________________________________________ SET LCD CURSOR MODE ______________________________________________________*/

/**************
 	 Options :
***************
1-		 "CURSOR_ON_B"
2-		 "CURSOR_ON_NB"
3-		 "CURSOR_OFF"
*********************************************/
#define LCD_CURSOR_MODE		CURSOR_OFF



#endif /* HAL_LCD_DRIVER_LCD_CFG_H_ */
