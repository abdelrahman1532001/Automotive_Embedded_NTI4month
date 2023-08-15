/*
 * USART_Private.h
 *
 *  Created on: Aug 12, 2023
 *      Author: ENG-Abdelrahman
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

static enum{
	TX_CHAR,
	TX_STRING
}TX_ISR_SOURCE;

static enum{
	RX_CHAR,
	RX_STRING
}RX_ISR_SOURCE;

//Interrupts vectors
#define RXC_VECT	__vector_13
#define UDRE_VECT	__vector_14
#define TXC_VECT	__vector_15

//ISR macro
#define ISR(__vect_n)	void __vect_n (void) __attribute__((signal));\
						void __vect_n (void)

/*_______________________________________Registers________________________________________________*/

//USART I/O Data Register - UDR
#define USART_UDR_REG		(*(volatile u8*)(0x2C))

//USART Control and Status RegisterA – UCSRA
#define USART_UCSRA_REG		(*(volatile u8*)(0x2B))
#define UCSRA_RXC           7 //USART Receive Complete
#define UCSRA_TXC           6 //USART Transmit Complete
#define UCSRA_UDRE          5 //USART Data Register Empty
#define UCSRA_FE            4 //Frame Error
#define UCSRA_DOR           3 //Data OverRun
#define UCSRA_PE            2 //Parity Error
#define UCSRA_U2X           1 //Double the USART Transmission Speed
#define UCSRA_MPCM          0 //Multi-processor Communication Mode

//USART Control and Status RegisterB – UCSRB
#define USART_UCSRB_REG		(*(volatile u8*)(0x2A))
#define UCSRB_RXCIE         7 //RX Complete Interrupt Enable
#define UCSRB_TXCIE         6 //RX Complete Interrupt Enable
#define UCSRB_UDRIE         5 //USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN          4 //Receiver Enable
#define UCSRB_TXEN          3 //Transmitter Enable
#define UCSRB_UCSZ2         2 //Character Size bit 2
#define UCSRB_RXB8          1 //Receive Data Bit 8
#define UCSRB_TXB8          0 //Transmit Data Bit 8

//USART Control and Status RegisterC – UCSRC
#define USART_UCSRC_REG		(*(volatile u8*)(0x40))
#define UCSRC_URSEL         7 //This bit selects between accessing the UCSRC or the UBRRH Register
#define UCSRC_UMSEL         6 //This bit selects between Asynchronous and Synchronous mode
#define UCSRC_UPM1          5 //Parity Mode
#define UCSRC_UPM0          4 //Parity Mode
#define UCSRC_USBS          3 //This bit selects the number of Stop Bits
#define UCSRC_UCSZ1         2 //Character Size bit 1
#define UCSRC_UCSZ0         1 //Character Size bit 0
#define UCSRC_UCPOL         0 //Clock Polarity, This bit is used for Synchronous mode only


//USART Baud Rate Registers – UBRRL and UBRRH
#define USART_UBRRL_REG		(*(volatile u8*)(0x29)) //Writing UBRRL will trigger an immediate update of the baud rate pre-scaler
#define USART_UBRRH_REG		(*(volatile u8*)(0x40)) //The UBRRH Register shares the same I/O location as the UCSRC Register
#define UBRRH_URSEL         7 //This bit selects between accessing the UCSRC or the UBRRH Register

/*__________________________________________________________________________________________________*/

/*___________________________________________Options Value__________________________________________*/

//Options of character size 'frame size'
#define FIVE_BIT	 		0x00
#define SIX_BIT	  			0x01
#define SEVEN_BIT		 	0x02
#define EIGHT_BIT			0x03
#define NINE_BIT	 		0x07


//'USART_TX_STATUS' && 'USART_RX_STATUS' => Options
#define ENABLE              0x01
#define DISABLE             0x00


//'USART_MODE_SELECT' => Options
#define ASYNC_NORMAL_MODE	0x00
#define ASYNC_SPEEDx2_MODE	0x01
#define SYNC_MODE			0x02

//'USART_PARITY_MODE' => Options
#define NO_PARITY			0x00
#define EVEN_PARITY			0x02
#define ODD_PARITY			0x03


//Stop bit Options :
#define ONE_BIT				0x00
#define TWO_BIT				0x01


//Some Standard Baud Rate Options
#define BD_2400_			0x960  //2400
#define BD_4800_			0x12C0 //4800
#define BD_9600_			0x2580 //9600


/*__________________________________________________________________________________________________*/

#endif /* USART_PRIVATE_H_ */
