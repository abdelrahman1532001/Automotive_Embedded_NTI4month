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

USART_STATUS_t USART_STATUS;

//Control sending char Asynchronous
static void (*g_pTxCharNotifyFunc)(void) = NULL;
//Control sending string Asynchronous
static void (*g_pTxStringNotifyFunc)(void) = NULL;
volatile static       u8  g_u8TxStringIndex;
volatile static const u8* g_pU8TxStringBuffer;

//Control reading char Asynchronous
static void (*g_pRxCharNotifyFunc)(void) = NULL;
volatile static u8* g_pU8RxCharBuffer;
//Control reading string Asynchronous
static void (*g_pRxStringNotifyFunc)(void) = NULL;
volatile static u8  g_u8RxStringIndex;
volatile static u8  g_u8RxStringSize;
volatile static u8* g_pU8RxStringBuffer;


void USART_vidInit(void)
{
	//USART idle by default
	USART_STATUS = USART_IDLE;

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
	USART_ERROR_t ERR = ES_SUCCESS;
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
		ERR = ES_TIMEOUT;
	}

	//Clear flag
	SET_BIT(USART_UCSRA_REG, UCSRA_TXC);

	return ERR;

}

USART_ERROR_t USART_ErrReadCharSync(u8* Cpy_pu8DataFrame)
{
	USART_ERROR_t ERR = ES_SUCCESS;

	if(Cpy_pu8DataFrame == NULL)
	{
		ERR = ES_NULL_POINTER;
	}
	else
	{
		//Wait reading to complete
		while(!(GET_BIT(USART_UCSRA_REG, UCSRA_RXC)));

		//Read UDR register
		*Cpy_pu8DataFrame = USART_UDR_REG;
	}

	return ERR;
}

USART_ERROR_t USART_ErrReadStringSync(u8* const Cpy_pU8String, u8 Cpy_u8Size)
{
	USART_ERROR_t ERR = ES_SUCCESS; //Default status
	u8 Local_u8iLoop = 0;

	if(Cpy_pU8String == NULL)
	{
		ERR = ES_NULL_POINTER;
	}
	else
	{
		do{
			//Read UDR
			ERR = USART_ErrReadCharSync(&(Cpy_pU8String[Local_u8iLoop]));

			//Check Reading status
			if(ERR == ES_NULL_POINTER)
			{
				break;
			}

			//Move to next char
			Local_u8iLoop++;

		}while((Cpy_pU8String[Local_u8iLoop-1] != END_READING_KEY) && (Local_u8iLoop < Cpy_u8Size));

		//terminate string
		Cpy_pU8String[Local_u8iLoop-1] = '\0'; //case of terminate key
		Cpy_pU8String[Cpy_u8Size-1] = '\0'; //case of size limit
	}

	return ERR;
}


USART_ERROR_t USART_ErrSendStringSync(const u8* Cpy_pU8String)
{
	USART_ERROR_t ERR = ES_SUCCESS; //Default status of sending
	u8 Local_u8iLoop = 0; //Counter to loop on string

	if(Cpy_pU8String == NULL)
	{
		ERR = ES_NULL_POINTER;
	}
	else
	{
		//Loop until find string terminator
		while(Cpy_pU8String[Local_u8iLoop] != '\0')
		{
			//Sending the current character
			ERR = USART_ErrSendCharSync(Cpy_pU8String[Local_u8iLoop]);

			//Check sending status
			if(ERR == ES_TIMEOUT)
			{
				break; //Terminate sending
			}

			Local_u8iLoop++; //Increase counter string to send next data
		}//end while loop
	}
	return ERR;
}


USART_ERROR_t USART_ErrPrintNewLine(void)
{
	//Status of sending
	USART_ERROR_t ERR;

	//Sending ASCII of ENTER key
	ERR = USART_ErrSendCharSync('\r');

	return ERR;
}

USART_ERROR_t USART_ErrSendCharAsync(u8  Cpy_u8Char, void (*ptrNotificationFunc)(void))
{
    USART_ERROR_t ERR;

    if(USART_STATUS == USART_IDLE)
    {
    	//Make USART busy until transmit complete
    	USART_STATUS = USART_BUSY;

    	//Set ISR source to tx_char
    	TX_ISR_SOURCE = TX_CHAR;

        //Passing notification function to ISR
        g_pTxCharNotifyFunc = ptrNotificationFunc;

        //Put data in the UDR register
        USART_UDR_REG = Cpy_u8Char;

        //Enable UDR empty interrupt
        SET_BIT(USART_UCSRB_REG, UCSRB_UDRIE);

    	//Sending success
    	ERR = ES_SUCCESS;

    }
    else
    {
    	ERR = ES_BUSY_FUNC;
    }

    return ERR;
}

USART_ERROR_t USART_ErrSendStringAsync(const u8  *Cpy_pu8String ,void (*ptrNotificationFunc)(void))
{
    USART_ERROR_t ERR;
    if(USART_STATUS == USART_IDLE)
    {
        //Check if data pointer is valid
        if(Cpy_pu8String == NULL)
        {
        	//If not valid return error null pointer
        	ERR = ES_NULL_POINTER;
        }
        else
        {
        	//Make USART busy until transmit complete
        	USART_STATUS = USART_BUSY;

        	//Set ISR source to tx_char
        	TX_ISR_SOURCE = TX_STRING;

        	//Start from first char in the string
        	g_u8TxStringIndex = 0;

        	//Save address of string buffer
        	g_pU8TxStringBuffer = Cpy_pu8String;

        	//Passing notification function to ISR
        	g_pTxStringNotifyFunc = ptrNotificationFunc;

            //Enable UDR empty interrupt
            SET_BIT(USART_UCSRB_REG, UCSRB_UDRIE);

        	//Sending success
        	ERR = ES_SUCCESS;
        }
    }
    else
    {
    	ERR = ES_BUSY_FUNC;
    }

	return ERR;
}

USART_ERROR_t USART_ErrReadCharAsync(u8 *Cpy_pu8Char, void (*ptrNotificationFunc)(void))
{
    USART_ERROR_t ERR;
    //Check valid pointer
    if(Cpy_pu8Char == (u8 *)NULL)
    {
    	//Return null pointer error state
    	ERR = ES_NULL_POINTER;
    }
    else
    {
    	//Check if USART ready to read or not
    	if(USART_STATUS == USART_BUSY)
    	{
    		//Return busy function error
    		ERR = ES_BUSY_FUNC;
    	}
    	else
    	{
    		//Change USART status to busy until finish reading process
    		USART_STATUS = USART_BUSY;

    		//Set ISR source
    		RX_ISR_SOURCE = RX_CHAR;

    		//Save address of reading place
    		g_pU8RxCharBuffer = Cpy_pu8Char;

    		//Save address of notification function
    		g_pRxCharNotifyFunc = ptrNotificationFunc;

    		//Enable receive complete interrupt
    		SET_BIT(USART_UCSRB_REG, UCSRB_RXCIE);

        	//Sending success
        	ERR = ES_SUCCESS;
    	}//End inner if
    }//End outer if

	return ERR;
}

USART_ERROR_t USART_ErrReadStringAsync(u8 *const Cpy_pu8Char, u8 Cpy_u8Size, void (*ptrNotificationFunc)(void))
{
    USART_ERROR_t ERR;

    //Check valid pointer
    if(Cpy_pu8Char == (u8 *const)NULL)
    {
    	//Return null pointer error state
    	ERR = ES_NULL_POINTER;
    }
    else
    {
    	//Check if USART ready to read or not
    	if(USART_STATUS == USART_BUSY)
    	{
    		//Return busy function error
    		ERR = ES_BUSY_FUNC;
    	}
    	else
    	{
    		//Change USART status to busy until finish reading process
    		USART_STATUS = USART_BUSY;

    		//Set ISR source
    		RX_ISR_SOURCE = RX_STRING;

    		//Save address of reading place
    		g_pU8RxStringBuffer = Cpy_pu8Char;

    		//Save size of the string
    		g_u8RxStringSize = Cpy_u8Size;

    		//Reset string index
    		g_u8RxStringIndex = 0;

    		//Save notification function
    		g_pRxStringNotifyFunc = ptrNotificationFunc;

    		//Enable receive complete interrupt
    		SET_BIT(USART_UCSRB_REG, UCSRB_RXCIE);

        	//Sending success
        	ERR = ES_SUCCESS;
    	}//End inner if
    }//End outer if

	return ERR;
}


//UDR empty interrupt routine service
ISR(UDRE_VECT)
{

	//If ISR coming from sending single char
	if(TX_ISR_SOURCE == TX_CHAR)
	{
		//Make USART idle so that can sending again
		USART_STATUS = USART_IDLE;

	    //Disable UDR empty interrupt
	    CLR_BIT(USART_UCSRB_REG, UCSRB_UDRIE);

		//Make sure valid pointer to function
		if(g_pTxCharNotifyFunc != NULL)
		{
			//Call notification function
			g_pTxCharNotifyFunc();
		}

	}
	//If ISR coming from sending a whole string
	else if(TX_ISR_SOURCE == TX_STRING)
	{
		//Check if reach string end or not
		if(g_pU8TxStringBuffer[g_u8TxStringIndex] != '\0')
		{
			//Load char into UDR register to be sent
			USART_UDR_REG = g_pU8TxStringBuffer[g_u8TxStringIndex];
			//Increase string index to send next char
			g_u8TxStringIndex++;
		}
		//If reach string end
		else
		{
			//Release USART so that it can send and read
			USART_STATUS = USART_IDLE;

			//Disable UDR empty interrupt
			CLR_BIT(USART_UCSRB_REG, UCSRB_UDRIE);

			//If there is a notification function call it
			if(g_pTxStringNotifyFunc != NULL)
			{
				g_pTxStringNotifyFunc();
			}
		}//End inner if
	}//End outer if
}//End ISR


//RXC interrupt routine service
ISR(RXC_VECT)
{
	//If ISR occur due to reading single char
	if(RX_ISR_SOURCE == RX_CHAR)
	{
		//Read UDR register
		*g_pU8RxCharBuffer = USART_UDR_REG;

		//Release USART and make it available
		USART_STATUS = USART_IDLE;

		//Disable RXIE
		CLR_BIT(USART_UCSRB_REG, UCSRB_RXCIE);

		//Check if there is a notification or not
		if(g_pRxCharNotifyFunc != NULL)
		{
			//Call notification function
			g_pRxCharNotifyFunc();
		}

	}
	//Else if ISR occur due to reading a whole string
	else if(RX_ISR_SOURCE == RX_STRING)
	{
		//Load UDR register in the reading buffer
		g_pU8RxStringBuffer[g_u8RxStringIndex] = USART_UDR_REG;

		//Increase index to load next char
		g_u8RxStringIndex++;

		//Check limits of size or find terminate key
		if((g_u8RxStringIndex >= g_u8RxStringSize) || (g_pU8RxStringBuffer[g_u8RxStringIndex-1] == END_READING_KEY))
		{
			//Add string terminator
			g_pU8RxStringBuffer[g_u8RxStringIndex-1] = '\0';

			//Release USART and make it available
			USART_STATUS = USART_IDLE;

			//Disable RXIE
			CLR_BIT(USART_UCSRB_REG, UCSRB_RXCIE);

			//Check if there is a notification or not
			if(g_pRxStringNotifyFunc != NULL)
			{
				//Call notification function
				g_pRxStringNotifyFunc();
			}

		}//End inner if
	}//End outer if
}//End function
