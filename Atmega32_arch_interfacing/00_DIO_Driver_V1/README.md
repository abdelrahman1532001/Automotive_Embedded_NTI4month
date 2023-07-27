# 🌟 ATmega32 GPIO Library 🌟

## Demo 📷

![ATmega32 GPIO Demo](https://github.com/abdelrahman1532001/Automotive_Embedded_NTI4month/blob/main/Atmega32_arch_interfacing/00_DIO_Driver_V1/TestVideo/DIO_V1.gif)

This is a simple library that provides functions to interact with the General Purpose Input/Output (GPIO) pins on the ATmega32 microcontroller. The library contains functions to set pins as input or output, set or clear pin values, toggle pins, and read pin values.

## Functions 🛠️

```c
u8 AT32_DIO_u8PinInit(u8 Cpy_u8Port, u8 Cpy_u8Pin, u8 Cpy_u8PinMode);
u8 AT32_DIO_u8SetPinValue(u8 Cpy_u8Port, u8 Cpy_u8Pin, u8 Cpy_u8PinVal);
u8 AT32_DIO_u8TogPinValue(u8 Cpy_u8Port, u8 Cpy_u8Pin);
u8 AT32_DIO_u8GetPinValue(u8 *Cpy_pu8Read, u8 Cpy_u8Port, u8 Cpy_u8Pin);
u8 AT32_DIO_u8PortInit(u8 Cpy_u8Port, u8 Cpy_u8PortDir);
u8 AT32_DIO_u8SetPortValue(u8 Cpy_u8Port, u8 Cpy_u8PortVal);
u8 AT32_DIO_u8GetPortValue(u8 *Cpy_pu8Read, u8 Cpy_u8Port);
