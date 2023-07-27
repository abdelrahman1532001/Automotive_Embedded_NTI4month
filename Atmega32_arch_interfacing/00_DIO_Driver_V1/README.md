# 🌟 ATmega32 GPIO Driver Version 1 🌟

## Demo 📷


This is a simple driver that provides functions to interact with the General Purpose Input/Output (GPIO) pins on the ATmega32 microcontroller. The library contains functions to set pins as input or output, set or clear pin values, toggle pins, and read pin values.

## Functions 🛠️

```c
u8 AT32_DIO_u8PinInit(u8 Cpy_u8Port, u8 Cpy_u8Pin, u8 Cpy_u8PinMode);
u8 AT32_DIO_u8SetPinValue(u8 Cpy_u8Port, u8 Cpy_u8Pin, u8 Cpy_u8PinVal);
u8 AT32_DIO_u8TogPinValue(u8 Cpy_u8Port, u8 Cpy_u8Pin);
u8 AT32_DIO_u8GetPinValue(u8 *Cpy_pu8Read, u8 Cpy_u8Port, u8 Cpy_u8Pin);
u8 AT32_DIO_u8PortInit(u8 Cpy_u8Port, u8 Cpy_u8PortDir);
u8 AT32_DIO_u8SetPortValue(u8 Cpy_u8Port, u8 Cpy_u8PortVal);
u8 AT32_DIO_u8GetPortValue(u8 *Cpy_pu8Read, u8 Cpy_u8Port);
