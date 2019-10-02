 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Hesham Hafez & Ahmed El-Dakhly
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

/*************************************************
 * 				Included libraries
 *************************************************/
#include "lcd_cfg.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* LCD Commands */
#define CLEAR_COMMAND 					0x01
#define FOUR_BITS_DATA_MODE 			0x02
#define TWO_LINE_LCD_Four_BIT_MODE 		0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 	0x38
#define CURSOR_OFF 						0x0C
#define CURSOR_ON 						0x0E
#define SET_CURSOR_LOCATION 			0x80

/*******************************************************************************
 *                      Functions Prototypes                                   *
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
void LCD_init(void);

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
void LCD_sendCommand(uint8_t command);

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
void LCD_displayCharacter(uint8_t data);

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
void LCD_displayString(const uint8_t *Str);

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
void LCD_clearScreen(void);

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
void LCD_displayStringRowColumn(uint8_t row,uint8_t col,const uint8_t *Str);

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
void LCD_goToRowColumn(uint8_t row,uint8_t col);


#endif /* LCD_H_ */
