/*
 * SevenSegment.c
 *
 *  Created on: Oct 3, 2019
 *      Author: hp
 */

#include "SevenSegment.h"

void SevenSegment_Init(void)
{
    GPIO_SetPinDirection(GPIO_PORTE_DATA_BITS_R, GPIO_PIN2, OUTPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTE_DATA_BITS_R, GPIO_PIN3, OUTPUT, DIGITAL_ENABLE);
    GPIO_WritePin(GPIO_PORTE_DATA_BITS_R, GPIO_PIN2, HIGH);
    GPIO_WritePin(GPIO_PORTE_DATA_BITS_R, GPIO_PIN3, HIGH);
    GPIO_SetPinDirection(GPIO_PORTD_DATA_BITS_R, GPIO_PIN0, OUTPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTD_DATA_BITS_R, GPIO_PIN1, OUTPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTD_DATA_BITS_R, GPIO_PIN2, OUTPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTD_DATA_BITS_R, GPIO_PIN3, OUTPUT, DIGITAL_ENABLE);

}
void Display_7Segment(uint8_t DisplayValue)
{
    GPIO_PORTD_DATA_R &= 0xF0;
    GPIO_PORTD_DATA_R |= DisplayValue;
}


