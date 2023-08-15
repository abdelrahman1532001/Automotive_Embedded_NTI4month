/*
 * USART_Interface.h
 *
 *  Created on: Aug 12, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_vidInit(void);
void USART_vidPrintNewLine(void);

typedef enum{
	TX_SUCCESS,
	TX_FAILED_TIMEOUT,
	TX_FAILED_RESEND_NUM,
	RX_SUCCESS,
}USART_ERROR_t;
USART_ERROR_t USART_ErrSendCharSync(u8  Cpy_u8DataFrame);
USART_ERROR_t USART_ErrReadCharSync(u8* Cpy_pu8DataFrame);
USART_ERROR_t USART_ErrSendStringSync(const u8* Cpy_pU8String);
USART_ERROR_t USART_ErrReadStringSync(u8* const Cpy_pU8String, u8 Cpy_u8Size);




#endif /* USART_INTERFACE_H_ */
