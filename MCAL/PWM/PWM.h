/*
 * PWM.h
 *
 *  Created on: Oct 2, 2019
 *      Author: hp
 */

#ifndef PWM_H_
#define PWM_H_
#include "tm4c123gh6pm.h"
#include "PWM_cfg.h"
#include "Macro.h"
#include "GPIO.h"

void PWM_Init(void);
void PWM_DutyCycle(uint16_t duty);



#endif /* PWM_H_ */
