/*
 * UART_1.c
 *
 *  Created on: Oct 2, 2019
 *      Author: abdul
 */

#include "UART_1.h"

void Enable_CLK_UART1(void)
{
    RCC_EnableCLK(RCC_UART1_EN);    /* provide clock to UART0 */
    RCC_EnableCLK(RCC_GPIOB_EN);    /* enable clock to PORTA */
}


void UART1_Init(void)
{
    Enable_CLK_UART1();

    /* UART0 initialization */
    UART1_CTL_R &= ~UART_CTL_UARTEN ;   /* disable UART0 */

    UART1_IBRD_R=104;    /* 16MHz/16=1MHz, 1MHz/104=9600 baud rate */
    UART1_FBRD_R=11;    /* fraction part, see Example 4-4 */
    UART1_CC_R &=0X00;
    UART1_LCRH_R=(UART_LCRH_WLEN_8|UART_LCRH_FEN);  /* 8-bit, no parity, 1-stop bit, no FIFO */
    UART1_CTL_R |= (UART_CTL_UARTEN|UART_CTL_RXE|UART_CTL_TXE);     /* enable UART0, TXE, RXE */

    /* UART0 TX0 and RX0 use PA0 and PA1. Set them up. */
    GPIO_PORTB_DEN_R |= 0x03;   /* Make PA0 and PA1 as digital */
    GPIO_PORTB_AFSEL_R |=0x03;/* Use PA0,PA1 alternate function */
    GPIO_PORTB_PCTL_R |= (GPIO_PCTL_PB1_U1TX|GPIO_PCTL_PB0_U1RX);   /* configure PA0 and PA1 for UART */
}

void UART1_SendChar(char c)
{
    while((UART1_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
    UART1_DR_R = c;    /* before giving it another byte */
}


int32_t  UART1_ReceiveChar(void){
    char c;
    /*Check if UART Receive FIFO is Full */
   while( (UART1_FR_R & 0x10) != 0);

    /* Get value from UART Data Register */
   c=UART1_DR_R;
    return c;
}

