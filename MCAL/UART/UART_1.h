/*
 * UART_1.h
 *
 *  Created on: Oct 2, 2019
 *      Author: abdul
 */

#ifndef UART_1_H_
#define UART_1_H_

#include "GPIO_22.h"
#include "RCC_Control.h"

void     UART1_Init(void);
void     UART1_SendChar(char c);
int32_t  UART1_ReceiveChar (void);

#endif /* UART_1_H_ */
