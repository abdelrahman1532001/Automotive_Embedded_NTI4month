#ifndef  ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*================================ User Typedef ===============================================*/


typedef enum{
	ADC_Free,
	ADC_Busy,
}ADC_Status_t;

typedef struct
{
	volatile u8 MUX  :5; //Bits of selecting channel
	volatile u8 ADLAR:1; //Bit  of left adjust
	volatile u8 REFS :2; //Bits to select reference volt

}ADC_ADMUX_REG_t;


typedef struct
{
	volatile u8 ADPS :3; //ADC pre-scalar bits
	volatile u8 ADIE :1; //ADC interrupt enable bit
	volatile u8 ADIF :1; //ADC interrupt flag bit
	volatile u8 ADATE:1; //ADC Auto Trigger Enable bit
	volatile u8 ADSC :1; //ADC Start Conversion bit
	volatile u8 ADEN :1; //ADC Enable bit

}ADC_ADCSRA_REG_t;

/*======================================================================================*/

/*========================== Register Instants =========================================*/

#define  ADC_ADMUX_REG   ((ADC_ADMUX_REG_t  *)0x27)
#define  ADC_ADCSRA_REG  ((ADC_ADCSRA_REG_t *)0x26)


#define ADC_ADCH_REG     (*(volatile u8*)(0x25))
#define ADC_ADCL_REG     (*(volatile u8*)(0x24))

/*=============================== Modes Commands Values ======================================*/

/* Values of pre-scalar */
#define PRESCALAR_2_    0x01
#define PRESCALAR_4_    0x02
#define PRESCALAR_8_    0x03
#define PRESCALAR_16_   0x04
#define PRESCALAR_32_   0x05
#define PRESCALAR_64_   0x06
#define PRESCALAR_128_  0x07

/* Voltage reference value */
#define AREF_WITH_IN_REF_OFF            0x00
#define AVCC_WITH_EXT_CAP_AT_AREF       0x01
#define IN_2V56_WITH_EXT_CAP_AT_AREF    0x03

/* Resolution modes value */
#define HIGH_RESOLUTION         0x00
#define LOW_RESOLUTION          0x01


#endif
