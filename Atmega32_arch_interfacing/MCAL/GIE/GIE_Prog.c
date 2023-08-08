/*
 * GIE_Prog.c
 *
 *  Created on: Aug 8, 2023
 *      Author: ENG-Abdelrahman
 */

#include "../../LIB/Std_Types.h"

#include "GIE_Interface.h"
#include "GIE_Private.h"

/*
 * @Function to enable general interrupt bit
 */
void GIE_vidEnable(void)
{
	SREG_REG->I = 1;
}
/*
 * @Function to disable general interrupt bit
 */
void GIE_vidDisable(void)
{
	SREG_REG->I = 0;
}
