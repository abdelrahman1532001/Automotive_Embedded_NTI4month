#ifndef  ADC_CFG_H_
#define ADC_CFG_H_

/*
    Set ADC Reference volt
    --------
    Options
    --------
        1- AREF_WITH_IN_REF_OFF
        2- AVCC_WITH_EXT_CAP_AT_AREF
        3- IN_2V56_WITH_EXT_CAP_AT_AREF
*/
#define ADC_REF_VOL     AVCC_WITH_EXT_CAP_AT_AREF
/*
    Set ADC pre-scalar
    --------
    Options
    --------
        1- PRESCALAR_2_
        2- PRESCALAR_4_
        3- PRESCALAR_8_
        4- PRESCALAR_16_
        5- PRESCALAR_32_
        6- PRESCALAR_64_
        6- PRESCALAR_128_
*/
#define ADC_PRESCALAR   PRESCALAR_64_
/*
    Set ADC Resolution 10 bits or 8 bits
    --------
    Options
    --------
        1- LOW_RESOLUTION
        2- HIGH_RESOLUTION
*/
#define ADC_RESOLUTION  HIGH_RESOLUTION

#endif
