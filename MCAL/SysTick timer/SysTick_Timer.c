/*
 * SysTick_Timer.c
 *
 *  Created on: Oct 2, 2019
 *      Author: hp
 */
#include "SysTick_Timer.h"

void SysTick_Init(void)
{
NVIC_ST_CTRL_R = CTRL_VALUE;
NVIC_ST_RELOAD_R = SYS_TICK_LOAD;
NVIC_ST_CURRENT_R = 0;
NVIC_INT_CTRL_R |= NVIC_INT_CTRL_VEC_PEN_TICK;
}



