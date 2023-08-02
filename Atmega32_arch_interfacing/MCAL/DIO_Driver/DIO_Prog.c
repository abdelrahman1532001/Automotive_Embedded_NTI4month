/*
 * AT32_DIO_prorgram.c
 *
 *  Created on: Jul 27, 2023
 *      Author: eng-abdelrahman
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/Std_Types.h"

#include "DIO_Cfg.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

void DIO_vidInit(void)
{
	DIO_PIN_NAME_e Pin;
	for(Pin = PD0; Pin < TOTAL_PINs; Pin++)
	{
		DIO_vidPin_Init(Pin, PinsArrModes[Pin]);
	}
}

void DIO_vidPort_Write(DIO_PORT_NAME_e Cpy_PortName, u8 Cpy_PortVal)
{
	(*(AT32_PORT_REG_BASE + Cpy_PortName * AT32_REG_STEP)) = Cpy_PortVal;
}
u8   DIO_u8Port_Read  (DIO_PORT_NAME_e Cpy_PortName)
{
	return (u8)(*(AT32_PIN_REG_BASE + Cpy_PortName * AT32_REG_STEP));
}


static void DIO_vidPin_Init(DIO_PIN_NAME_e Cpy_PinName, DIO_PIN_MODE_e Cpy_PinMode)
{
	u16 Local_u16PortOffest = Cpy_PinName / 8; //get the port offset
	u16 Local_u16PinOffest  = Cpy_PinName % 8; //get the pin number

	//check the pin mode
	switch(Cpy_PinMode)
	{
	case OUTPUT:
		SET_BIT((*(AT32_DDR_REG_BASE  + Local_u16PortOffest * AT32_REG_STEP)), Local_u16PinOffest);
		CLR_BIT((*(AT32_PORT_REG_BASE + Local_u16PortOffest * AT32_REG_STEP)), Local_u16PinOffest);
		break;
	case INFREE:
		CLR_BIT((*(AT32_DDR_REG_BASE  + Local_u16PortOffest * AT32_REG_STEP)), Local_u16PinOffest);
		CLR_BIT((*(AT32_PORT_REG_BASE + Local_u16PortOffest * AT32_REG_STEP)), Local_u16PinOffest);
		break;
	case INPULL:
		CLR_BIT((*(AT32_DDR_REG_BASE  + Local_u16PortOffest * AT32_REG_STEP)), Local_u16PinOffest);
		SET_BIT((*(AT32_PORT_REG_BASE + Local_u16PortOffest * AT32_REG_STEP)), Local_u16PinOffest);
		break;
	} //end switch
} //end function

void DIO_vidPin_Write(DIO_PIN_NAME_e Cpy_PinName, DIO_PIN_VOLT_e Cpy_PinState)
{
	u16 Local_u16PortOffest = Cpy_PinName / 8; //get the port offset
	u16 Local_u16PinOffest  = Cpy_PinName % 8; //get the pin number

	//check the pin mode
	switch(Cpy_PinState)
	{
	case HIGH:
		SET_BIT((*(AT32_PORT_REG_BASE + Local_u16PortOffest * AT32_REG_STEP)), Local_u16PinOffest);
		break;
	case LOW :
		CLR_BIT((*(AT32_PORT_REG_BASE + Local_u16PortOffest * AT32_REG_STEP)), Local_u16PinOffest);
		break;
	} //end switch
} //end function

DIO_PIN_VOLT_e DIO_u8Pin_Read (DIO_PIN_NAME_e Cpy_PinName)
{
	u16 Local_u16PortOffest = Cpy_PinName / 8; //get the port offset
	u16 Local_u16PinOffest  = Cpy_PinName % 8; //get the pin number

	DIO_PIN_VOLT_e Local_u8Read = GET_BIT((*(AT32_PORT_REG_BASE + Local_u16PortOffest * AT32_REG_STEP)), Local_u16PinOffest);

	return Local_u8Read;

}

void DIO_ANDING_PORT(DIO_PORT_NAME_e Cpy_PortName, u8 Cpy_u8ANDingVal)
{
	AND_REG((*(AT32_PORT_REG_BASE + Cpy_PortName * AT32_REG_STEP)), Cpy_u8ANDingVal); //mask the port
}

void DIO_ORING_PORT(DIO_PORT_NAME_e Cpy_PortName, u8 Cpy_u8ORingVal)
{
	OR_REG((*(AT32_PORT_REG_BASE + Cpy_PortName * AT32_REG_STEP)), Cpy_u8ORingVal); //mask the port
}



