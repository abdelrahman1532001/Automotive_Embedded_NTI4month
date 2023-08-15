/*
 * USART_Prog.c
 *
 *  Created on: Aug 12, 2023
 *      Author: ENG-Abdelrahman
 */

#include "../../LIB/Std_Types.h"
#include "../../LIB/Bit_Math.h"

#include "USART_Cfg.h"
#include "USART_Interface.h"
#include "USART_Private.h"

void USART_vidInit(void)
{
	//Buffer to help in access 'UCSRC' register
	u16 Local_u16UBRR_Buffer;

/*______________________________UBRRL______UBRRH__________________________________*/

	//Set UBRRL and UBRRH Baud Rate Registers
#if (USART_MODE == ASYNC_SPEEDx2_MODE)
	Local_u16UBRR_Buffer = (F_CPU / (8UL * USART_BAUD_RATE)) - 1; //UBRR value in 2x speed mode
#elif(USART_MODE == ASYNC_NORMAL_MODE)
	Local_u16UBRR_Buffer = (F_CPU / (16UL * USART_BAUD_RATE)) - 1; //UBRR value in normal speed mode
#elif(USART_MODE == SYNC_MODE)
	Local_u16UBRR_Buffer = (F_CPU / (2UL * USART_BAUD_RATE)) - 1; //UBRR value in synchronous mode
#endif
	USART_UBRRL_REG = (u8)(Local_u16UBRR_Buffer); //Write low 8 bit
	USART_UBRRH_REG = (u8)(Local_u16UBRR_Buffer >> 8);//Write high 8 bit

/*__________________________________UCSRA_________________________________________*/

	//Set UCSRA register
	USART_UCSRA_REG = 0
#if (USART_MODE == ASYNC_SPEEDx2_MODE)
			        | (1 << UCSRA_U2X) //Set bit if USART using double speed mode
#endif
					;

/*__________________________________UCSRB___________________________________________*/

	//Set UCSRB register
	USART_UCSRB_REG = (RX_MODE << UCSRB_RXEN) //Bit 4
					| (TX_MODE << UCSRB_TXEN) //Bit 3
					| (GET_BIT(CHAR_SIZE, 2) << UCSRB_UCSZ2) //Bit 2
					;

/*__________________________________UCSRC__________________________________________*/

	//Set UCSRC register
	USART_UCSRC_REG = (1 << UCSRC_URSEL) //Bit 7 to select UCSRC set to select UCSRC
#if USART_MODE == SYNC_MODE
			        | (1 << UCSRC_UMSEL) //Bit 6 to select USART mode set if synchronous mode
#endif
			        | (PARITY_MODE << UCSRC_UPM0) //Bit 4, 5 to select parity mode
	                | (SBIT_MODE << UCSRC_USBS) //Bit 3 to set number of stop bits
                    | (GET_BIT(CHAR_SIZE, 1) << UCSRC_UCSZ1)//Bit 2 to select char size
                    | (GET_BIT(CHAR_SIZE, 0) << UCSRC_UCSZ0)//Bit 1 to select char size
#if USART_MODE == SYNC_MODE
			        | (1 << UCSRC_UCPOL)  //Bit 0 to select clock polarity set if synchronous mode
#endif
					;


}

USART_ERROR_t USART_ErrSendCharSync(u8 Cpy_u8DataFrame)
{
	//Timeout counter
	USART_ERROR_t ERR = TX_SUCCESS;
	u32 Local_u32TimeOutCounter=0;

	//Start sending data
	USART_UDR_REG = Cpy_u8DataFrame;

	//Wait sending to complete or reach time out
	while( !(GET_BIT(USART_UCSRA_REG, UCSRA_TXC)) && !(Local_u32TimeOutCounter == USART_TIMEOUT) )
	{
		Local_u32TimeOutCounter++;
	}

	//Check if exit due to time out
	if(Local_u32TimeOutCounter == USART_TIMEOUT)
	{
		ERR = TX_FAILED_TIMEOUT;
	}

	//Clear flag
	SET_BIT(USART_UCSRA_REG, UCSRA_TXC);

	return ERR;

}

USART_ERROR_t USART_ErrReadCharSync(u8* Cpy_pu8DataFrame)
{
	USART_ERROR_t ERR = RX_SUCCESS;

	//Wait reading to complete
	while(!(GET_BIT(USART_UCSRA_REG, UCSRA_RXC)));

	//Read UDR register
	*Cpy_pu8DataFrame = USART_UDR_REG;

	return ERR;
}

USART_ERROR_t USART_ErrReadStringSync(u8* const Cpy_pU8String, u8 Cpy_u8Size)
{
	USART_ERROR_t ERR = TX_SUCCESS; //Default status of sending
	u8 Local_u8iLoop = 0;

	do{
		//Read UDR
		ERR = USART_ErrReadCharSync(&(Cpy_pU8String[Local_u8iLoop]));

		//Check Reading status
		if(ERR == RX_SUCCESS)
		{
			Local_u8iLoop++;
		}
		else{
			break;
		}

	}while((Cpy_pU8String[Local_u8iLoop-1] != END_READING_KEY) && (Local_u8iLoop < Cpy_u8Size));

	//terminate string
	Cpy_pU8String[Local_u8iLoop-1] = '\0'; //case of terminate key
	Cpy_pU8String[Cpy_u8Size-1] = '\0'; //case of size limit

	return ERR;
}


USART_ERROR_t USART_ErrSendStringSync(const u8* Cpy_pU8String)
{
	USART_ERROR_t ERR = TX_SUCCESS; //Default status of sending
	u8 Local_u8iLoop = 0; //Counter to loop on string
	u8 Local_u8ResendCounter = 0; //Counter to count number of re-send data

	//Loop until find string terminator
	while(Cpy_pU8String[Local_u8iLoop] != '\0')
	{
		//Sending the current character
		ERR = USART_ErrSendCharSync(Cpy_pU8String[Local_u8iLoop]);

		//Check sending status
		if(ERR == TX_SUCCESS)
		{
			Local_u8iLoop++; //Increase counter string to send next data
		}
		//if send char failed
		else if(ERR == TX_FAILED_TIMEOUT)
		{
			Local_u8ResendCounter++; //Increase number of re-send counter
			if(Local_u8ResendCounter > USART_RESEND_NUM) //check limits
			{
				ERR = TX_FAILED_RESEND_NUM; //Save error status
				break; //Exit from sending
			}//end inner if
		}//end out if
	}//end while loop
	return ERR;
}


void USART_vidPrintNewLine(void)
{
	//Sending ASCII of ENTER key
	USART_ErrSendCharSync('\r');
}


