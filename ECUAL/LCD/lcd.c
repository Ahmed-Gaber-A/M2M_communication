/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Hesham Hafez & Ahmed El-Dakhly
 *
 *******************************************************************************/

/*************************************************
 * 				Included libraries
 *************************************************/
#include "lcd.h"

static void Delay(long int x);
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	LCD_init
 *
 * Description: 	Initialize LCD with Configured mode
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void LCD_init(void)
{
    /*GPIO Init*/
    GPIO_SetPinDirection(GPIO_PORTA_DATA_BITS_R, RS, OUTPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTA_DATA_BITS_R, RW, OUTPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTA_DATA_BITS_R, E, OUTPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTC_DATA_BITS_R, GPIO_PIN4, OUTPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTC_DATA_BITS_R, GPIO_PIN5, OUTPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTC_DATA_BITS_R, GPIO_PIN6, OUTPUT, DIGITAL_ENABLE);
    GPIO_SetPinDirection(GPIO_PORTC_DATA_BITS_R, GPIO_PIN7, OUTPUT, DIGITAL_ENABLE);

    LCD_sendCommand(FOUR_BITS_DATA_MODE); /* initialize LCD in 4-bit mode */
    LCD_sendCommand(TWO_LINE_LCD_Four_BIT_MODE); /* use 2-line lcd + 4-bit Data Mode + 5*7 dot display Mode */
    LCD_sendCommand(CURSOR_OFF); /* cursor off */
    LCD_sendCommand(CLEAR_COMMAND); /* clear LCD at the beginning */
}

/*******************************************************************************
 * Function Name:	LCD_sendCommand
 *
 * Description: 	To send specific Command number to LCD
 *
 * Inputs:			specific Command number (uint8_t)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void LCD_sendCommand(uint8_t command)
{
    /* Instruction Mode RS=0 */
    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R, RS, LOW);
    /* write data to LCD so RW=0 */
    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R, RW, LOW);
    Delay(610); /* delay for processing Tas = 50ns */
    /* Enable LCD E=1 */
    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R, E, HIGH);
    Delay(610); /* delay for processing Tpw - Tdws = 190ns */

    GPIO_PORTC_DATA_R = (GPIO_PORTC_DATA_R & 0x0F) | (command & 0xF0);

    Delay(610); /* delay for processing Tdsw = 100ns */
    /* disable LCD E=0 */
    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R, E, LOW);

    Delay(610); /* delay for processing Th = 13ns */

    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R, E, HIGH);

    Delay(610); /* delay for processing Tpw - Tdws = 190ns */

    /* out the lowest 4 bits of the required command to the data bus D4 --> D7 */

    GPIO_PORTC_DATA_R = (GPIO_PORTC_DATA_R & 0x0F) | ((command & 0x0F) << 4);


    Delay(610); /* delay for processing Tdsw = 100ns */

    /* disable LCD E=0 */
    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R, E, LOW);

    Delay(610); /* delay for processing Th = 13ns */


}

/*******************************************************************************
 * Function Name:	LCD_displayCharacter
 *
 * Description: 	To send Data byte to display it on LCD
 *
 * Inputs:			Data byte (uint8_t)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void LCD_displayCharacter(uint8_t data)
{
    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R, RS, HIGH);
    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R, RW, LOW);
    Delay(610); /* delay for processing Tas = 50ns */
    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R,E,HIGH);
    Delay(610); /* delay for processing Tpw - Tdws = 190ns */

    GPIO_PORTC_DATA_R = (GPIO_PORTC_DATA_R & 0x0F) | (data & 0xF0);


    Delay(610); /* delay for processing Tdsw = 100ns */
    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R,E,LOW);
    Delay(610); /* delay for processing Th = 13ns */
    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R,E,HIGH);
    Delay(610); /* delay for processing Tpw - Tdws = 190ns */

    /* out the lowest 4 bits of the required data to the data bus D4 --> D7 */
    GPIO_PORTC_DATA_R = (GPIO_PORTC_DATA_R & 0x0F) | ((data & 0x0F) << 4);

    Delay(610); /* delay for processing Tdsw = 100ns */
    GPIO_WritePin(GPIO_PORTA_DATA_BITS_R,E,LOW);
    Delay(610); /* delay for processing Th = 13ns */

}

/*******************************************************************************
 * Function Name:	LCD_displayString
 *
 * Description: 	To send Data String to display it on LCD
 *
 * Inputs:			Pointer to constant string (uint8_t*)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void LCD_displayString(const uint8_t *Str)
{
    uint8_t i = 0;
    /*use loop to send string byte by byte to display on LCD*/
    while(Str[i] != '\0')
    {
        LCD_displayCharacter(Str[i]);
        i++;
    }
    /***************** Another Method ***********************
	while((*Str) != '\0')
	{
		LCD_displayCharacter(*Str);
		Str++;
	}		
     *********************************************************/
}

/*******************************************************************************
 * Function Name:	LCD_goToRowColumn
 *
 * Description: 	To go to specific position on LCD to start displaying
 *
 * Inputs:			column (uint8_t)
 * 					row (uint8_t)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void LCD_goToRowColumn(uint8_t row,uint8_t col)
{
    uint8_t Address;

    /* first of all calculate the required address */
    switch(row)
    {
    case 0:
        Address=col;
        break;
    case 1:
        Address=col+0x40;
        break;
    case 2:
        Address=col+0x10;
        break;
    case 3:
        Address=col+0x50;
        break;
    }
    /* to write to a specific address in the LCD
     * we need to apply the corresponding command 0b10000000+Address */
    LCD_sendCommand(Address | SET_CURSOR_LOCATION);
}

/*******************************************************************************
 * Function Name:	LCD_displayStringRowColumn
 *
 * Description: 	To go to specific position on LCD to start displaying Data String
 *
 * Inputs:			column (uint8_t)
 * 					row (uint8_t)
 * 					Pointer to constant string (uint8_t*)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void LCD_displayStringRowColumn(uint8_t row,uint8_t col,const uint8_t *Str)
{
    LCD_goToRowColumn(row,col); /* go to to the required LCD position */
    LCD_displayString(Str); /* display the string */
}

/*******************************************************************************
 * Function Name:	LCD_clearScreen
 *
 * Description: 	To Clear LCD
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void LCD_clearScreen(void)
{
    LCD_sendCommand(CLEAR_COMMAND); //clear display
}


static void Delay(long int x)
{
    volatile long int loop;
    for(loop = 0;loop <x ; loop++);
}
