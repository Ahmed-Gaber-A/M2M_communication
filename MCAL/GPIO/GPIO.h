/*
 * GPIO.h
 *
 *  Created on: Oct 1, 2019
 *      Author: hp
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "tm4c123gh6pm.h"


#define OUTPUT                      1u
#define INPUT                       0u

#define HIGH                      1u
#define LOW                       0u

#define PIN_AS_GPIO                 0u
#define PIN_AS_ALTERNATE            1u

#define DIGITAL_ENABLE              0u
#define DIGITAL_DISABLE             1u

/*GPIO Pins*/
#define GPIO_PIN0                   0u
#define GPIO_PIN1                   1u
#define GPIO_PIN2                   2u
#define GPIO_PIN3                   3u
#define GPIO_PIN4                   4u
#define GPIO_PIN5                   5u
#define GPIO_PIN6                   6u
#define GPIO_PIN7                   7u
//
///*GPIO Port*/
//#define GPIO_PARTA                  0u
//#define GPIO_PARTB                  1u
//#define GPIO_PARTC                  2u
//#define GPIO_PARTD                  3u
//#define GPIO_PARTE                  4u
//#define GPIO_PARTF                  5u

#define DATA_REGISTER_OFFSET          0xFFu
#define DIRECTION_OFFSET              0x100u
#define ALTERNATE_GPIO_SELECT_OFFSET  0x105u
#define CURRENT_8MA                   0x142u
#define OPENDRAIN_OFFSET              0x143u
#define PULLUP_OFFSET                 0x144u
#define PULLDOWN_OFFSET               0x145u
#define SLEW_RATE_OFFSET              0x146u
#define DIGITAL_OFFSET                0x147u
#define LOCK_OFFSET                   0x148u
#define COMMIT_REGISTER_OFFSET        0x149u




void GPIO_SetPinDirection(uint32_t * PortBase , uint8_t Pin , uint8_t Direction , uint8_t DigitalEnable);
void Alternate_GPIO_Select(uint32_t * PortBase , uint8_t Pin);
void GPIO_WritePin(uint32_t * PortBase , uint8_t Pin , uint32_t Value);
uint8_t GPIO_ReadPin(uint32_t * PortBase , uint8_t Pin );
void GPIO_UnlockPin(uint32_t * PortBase , uint8_t Pin , uint8_t CommitValue);




#endif /* GPIO_H_ */
