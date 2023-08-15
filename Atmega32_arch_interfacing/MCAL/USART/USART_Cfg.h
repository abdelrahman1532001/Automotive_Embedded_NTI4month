/*
 * USART_Cfg.h
 *
 *  Created on: Aug 12, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef USART_CFG_H_
#define USART_CFG_H_

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

/* ```````````````````````````````
 * 'USART_MODE' => Options
 * ```````````````````````````````
 * 		1- ASYNC_NORMAL_MODE
 * 		1- ASYNC_SPEEDx2_MODE
 * 		2- SYNC_MODE
 */
#define USART_MODE			ASYNC_NORMAL_MODE

/* ``````````````````````````````
 * Character size Options :
 * ``````````````````````````````
 * 		1- FIVE_BIT
 * 		2- SIX_BIT
 * 		3- SEVEN_BIT
 * 		4- EIGHT_BIT
 * 		5- NINE_BIT
 */
#define CHAR_SIZE			EIGHT_BIT
/* `````````````````````````````
 * 'TX_MODE'
 * 'RX_MODE' => Options
 * `````````````````````````````
 * 		1- ENABLE
 * 		2- DISABLE
 */
#define TX_MODE				ENABLE
#define RX_MODE				ENABLE


/* ````````````````````````````````
 * Some Standard Baud Rate Options
 * ````````````````````````````````
 * 		1- BD_2400_
 * 		2- BD_4800_
 * 		3- BD_9600_
 */
#define USART_BAUD_RATE		BD_9600_
/* ```````````````````````````````
 * Parity mode Options :
 * ```````````````````````````````
 * 		1- NO_PARITY
 * 		2- EVEN_PARITY
 * 		3- ODD_PARITY
 */
#define PARITY_MODE			NO_PARITY

/* ```````````````````````````````
 * Stop bit Options :
 * ```````````````````````````````
 * 		1- ONE_BIT
 * 		2- TWO_BIT
 */
#define SBIT_MODE			TWO_BIT

/*
 * Stop sending if exceeds this time limit
 */
#define USART_TIMEOUT		1000UL
/*
 * number of try re-sending data if failed
 */
#define USART_RESEND_NUM	3
/*
 * key to terminate reading
 */
#define END_READING_KEY		 '\r'

#endif /* USART_CFG_H_ */
