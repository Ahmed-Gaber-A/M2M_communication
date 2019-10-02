/*
 * SysTick_Timer.h
 *
 *  Created on: Oct 2, 2019
 *      Author: hp
 */

#ifndef SYSTICK_TIMER_H_
#define SYSTICK_TIMER_H_

#include "tm4c123gh6pm.h"

#define CTRL_VALUE          0x00000007
#define SYS_TICK_LOAD       0x00013880

void SysTick_Init(void);



#endif /* SYSTICK_TIMER_H_ */
