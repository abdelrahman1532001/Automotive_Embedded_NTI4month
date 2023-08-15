/*
 * USART_Interface.h
 *
 *  Created on: Aug 12, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

typedef enum{
	USART_IDLE,
	USART_BUSY,
}USART_STATUS_t;

typedef enum{
	ES_SUCCESS,
	ES_TIMEOUT,
	ES_NULL_POINTER,
	ES_BUSY_FUNC,
}USART_ERROR_t;

void USART_vidInit(void);

/* Synchronous Function */
USART_ERROR_t USART_ErrSendCharSync  (u8  Cpy_u8DataFrame);
USART_ERROR_t USART_ErrSendStringSync(const u8* Cpy_pU8String);
/*`````````*/
USART_ERROR_t USART_ErrReadCharSync  (u8* Cpy_pu8DataFrame);
USART_ERROR_t USART_ErrReadStringSync(u8* const Cpy_pU8String, u8 Cpy_u8Size);
/*`````````*/
USART_ERROR_t USART_ErrPrintNewLine(void);


/* Asynchronous Function */
USART_ERROR_t USART_ErrSendCharAsync  (u8  Cpy_u8Char, void (*ptrNotificationFunc)(void));
USART_ERROR_t USART_ErrSendStringAsync(const u8  *Cpy_pu8String ,void (*ptrNotificationFunc)(void));
/*`````````*/
USART_ERROR_t USART_ErrReadCharAsync  (u8 *Cpy_pu8Char, void (*ptrNotificationFunc)(void));
USART_ERROR_t USART_ErrReadStringAsync(u8 *const Cpy_pu8Char, u8 Cpy_u8Size, void (*ptrNotificationFunc)(void));



#endif /* USART_INTERFACE_H_ */
