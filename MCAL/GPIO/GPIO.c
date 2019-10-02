/*
 * GPIO.c
 *
 *  Created on: Oct 1, 2019
 *      Author: hp
 */


#include "GPIO.h"
#include "Macro.h"


void GPIO_SetPinDirection(uint32_t * PortBase , uint8_t Pin , uint8_t Direction , uint8_t DigitalEnable)
{
    uint32_t Value = (1<<Pin);
    if(PortBase == GPIO_PORTA_DATA_BITS_R)
    {
        SET_BIT(SYSCTL_RCGCGPIO_R , GPIO_PIN0);
        while(!GET_BIT(SYSCTL_PRGPIO_R , GPIO_PIN0));
        *(PortBase + CURRENT_8MA ) |= Value;
    }
    else if(PortBase==GPIO_PORTB_DATA_BITS_R)
    {
        SET_BIT(SYSCTL_RCGCGPIO_R , GPIO_PIN1);
        while(!GET_BIT(SYSCTL_PRGPIO_R , GPIO_PIN1));
        *(PortBase + CURRENT_8MA ) |= Value;
    }
    else if(PortBase==GPIO_PORTC_DATA_BITS_R)
    {
        SET_BIT(SYSCTL_RCGCGPIO_R , GPIO_PIN2);
        while(!GET_BIT(SYSCTL_PRGPIO_R , GPIO_PIN2));
        *(PortBase + CURRENT_8MA ) |= Value;
    }
    else if(PortBase==GPIO_PORTD_DATA_BITS_R)
    {
        SET_BIT(SYSCTL_RCGCGPIO_R , GPIO_PIN3);
        while(!GET_BIT(SYSCTL_PRGPIO_R , GPIO_PIN3));
        *(PortBase + CURRENT_8MA ) |= Value;
    }
    else if(PortBase==GPIO_PORTE_DATA_BITS_R)
    {
        SET_BIT(SYSCTL_RCGCGPIO_R , GPIO_PIN4);
        while(!GET_BIT(SYSCTL_PRGPIO_R , GPIO_PIN4));
        *(PortBase + CURRENT_8MA ) |= Value;
    }
    else if(PortBase==GPIO_PORTF_DATA_BITS_R)
    {
        SET_BIT(SYSCTL_RCGCGPIO_R , GPIO_PIN5);
        while(!GET_BIT(SYSCTL_PRGPIO_R , GPIO_PIN5));
        *(PortBase + CURRENT_8MA ) |= Value;
    }
    else
    {
        /*Do nothing*/
    }

    if(Direction == OUTPUT)
    {
        *(PortBase + DIRECTION_OFFSET ) |= Value;
    }
    else if(Direction == INPUT)
    {
        *(PortBase + DIRECTION_OFFSET ) &= ~Value;
    }
    else
    {
        /*Do nothing*/
    }
    if(DigitalEnable == DIGITAL_ENABLE)
    {
        *(PortBase + DIGITAL_OFFSET ) |= Value;
    }
    else if(DigitalEnable == DIGITAL_DISABLE)
    {
        *(PortBase + DIGITAL_OFFSET ) &= ~Value;
    }
    else
    {
        /*Do nothing*/
    }
    *(PortBase + ALTERNATE_GPIO_SELECT_OFFSET ) &= ~Value;
    *(PortBase + PULLUP_OFFSET ) |= Value;
    *(PortBase + PULLDOWN_OFFSET ) &= ~Value;
    *(PortBase + OPENDRAIN_OFFSET ) &= ~Value;
    *(PortBase + SLEW_RATE_OFFSET ) &= ~Value;

}

void Alternate_GPIO_Select(uint32_t * PortBase , uint8_t Pin)
{
    uint32_t Value = (1<<Pin);
    if(PortBase == GPIO_PORTA_DATA_BITS_R)
    {
        SET_BIT(SYSCTL_RCGCGPIO_R , GPIO_PIN0);
        while(!GET_BIT(SYSCTL_PRGPIO_R , GPIO_PIN0));
    }
    else if(PortBase==GPIO_PORTB_DATA_BITS_R)
    {
        SET_BIT(SYSCTL_RCGCGPIO_R , GPIO_PIN1);
        while(!GET_BIT(SYSCTL_PRGPIO_R , GPIO_PIN1));
    }
    else if(PortBase==GPIO_PORTC_DATA_BITS_R)
    {
        SET_BIT(SYSCTL_RCGCGPIO_R , GPIO_PIN2);
        while(!GET_BIT(SYSCTL_PRGPIO_R , GPIO_PIN2));
    }
    else if(PortBase==GPIO_PORTD_DATA_BITS_R)
    {
        SET_BIT(SYSCTL_RCGCGPIO_R , GPIO_PIN3);
        while(!GET_BIT(SYSCTL_PRGPIO_R , GPIO_PIN3));
    }
    else if(PortBase==GPIO_PORTE_DATA_BITS_R)
    {
        SET_BIT(SYSCTL_RCGCGPIO_R , GPIO_PIN4);
        while(!GET_BIT(SYSCTL_PRGPIO_R , GPIO_PIN4));
    }
    else if(PortBase==GPIO_PORTF_DATA_BITS_R)
    {
        SET_BIT(SYSCTL_RCGCGPIO_R , GPIO_PIN5);
        while(!GET_BIT(SYSCTL_PRGPIO_R , GPIO_PIN5));
    }
    else
    {
        /*Do nothing*/
    }
    *(PortBase + ALTERNATE_GPIO_SELECT_OFFSET ) |= Value;
}

void GPIO_WritePin(uint32_t * PortBase , uint8_t Pin , uint32_t Value)
{
    if(Value == HIGH)
    {
        *(PortBase + DATA_REGISTER_OFFSET ) |= (1<<Pin);
    }
    else if(Value == LOW)
    {
        *(PortBase + DATA_REGISTER_OFFSET ) &= (~(1<<Pin));
    }
    else
    {
        /*Do Nothing*/
    }
}

uint8_t GPIO_ReadPin(uint32_t * PortBase , uint8_t Pin )
{
    uint32_t Value ;
    Value = ((*(PortBase + DATA_REGISTER_OFFSET ))>>Pin) & 0x01;
    return Value;
}

void GPIO_UnlockPin(uint32_t * PortBase , uint8_t Pin , uint8_t CommitValue )
{
    *(PortBase + LOCK_OFFSET) = 0x4C4F434B;
    *(PortBase + COMMIT_REGISTER_OFFSET) |= (CommitValue << Pin);
    *(PortBase + LOCK_OFFSET) = 0x00000000;

}
