#ifndef  ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

typedef union{
    u8 AllBits;
    struct 
    {
        u8 MUX  :5; //Bits of selecting channel
        u8 ADLAR:1; //Bit  of left adjust
        u8 REFS :2; //Bits to select reference volt   
    };
    
}ADC_ADMUX_REG_t;
volatile ADC_ADMUX_REG_t *ADC_ADMUX_REG = (volatile ADC_ADMUX_REG_t*)(0x27);

typedef union{
    u8 AllBits;
    struct 
    {
        u8 ADPS :3; //ADC pre-scalar bits
        u8 ADIE :1; //ADC interrupt enable bit
        u8 ADIF :1; //ADC interrupt flag bit
        u8 ADATE:1; //ADC Auto Trigger Enable bit  
        u8 ADSC :1; //ADC Start Conversion bit
        u8 ADEN :1; //ADC Enable bit
    };
    
}ADC_ADCSRA_REG_t;
volatile ADC_ADCSRA_REG_t *ADC_ADCSRA_REG = (volatile ADC_ADCSRA_REG_t*)(0x26);
    
#define ADC_ADCSRA_REG_R *(volatile u8*)(0x26)

#define ADC_ADCH_REG    (*(volatile u8*)(0x25))
#define ADC_ADCL_REG    (*(volatile u8*)(0x24))


#define PRESCALAR_2_    0x01
#define PRESCALAR_4_    0x02
#define PRESCALAR_8_    0x03
#define PRESCALAR_16_   0x04
#define PRESCALAR_32_   0x05
#define PRESCALAR_64_   0x06
#define PRESCALAR_128_  0x07

#define AREF_WITH_IN_REF_OFF            0x00
#define AVCC_WITH_EXT_CAP_AT_AREF       0x01
#define IN_2V56_WITH_EXT_CAP_AT_AREF    0x03

#define HIGH_RESOLUTION         0x00
#define LOW_RESOLUTION          0x01


#endif
