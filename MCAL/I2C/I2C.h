/*
* Header file of the I2C module
*/

#ifndef I2C_H__
#define I2C_H__
#include <stdint.h>
#include "I2C_PBCfg.h"

/****
 * pre Definitions
 */
#define I2C_MAX_CHANNELnum 4u
/*******
 *typedefs enums
 ******/
typedef enum {I2C_NOK=0, I2C_OK=1}I2C_ErrorCheck_t; /*Return Error_Check  */
typedef enum {I2C0=0x40020000, I2C1=0x40021000, I2C2=0x40022000, I2C3=0x40023000}ChannelID_t;
typedef enum {PORTA=0x40004000, PORTB=0x40005000, PORTD=0x40007000, PORTE=0x40024000}PortID_t;
typedef enum {MASTER=0, SLAVE=1}ModuleType_t;
/****
 * configuration structure
 ***/

typedef struct {
    ChannelID_t ChannelId; /* 0, 1, 2, or 3 */
    PortID_t PortId;    /* PORTA-> 0 , PORTB-> 1 , PORTD-> 3 , PORTE-> 4*/
    ModuleType_t ModuleType; /* Master -> 0 - Slave  -> 1 */
    uint8_t SDAPinNum; /* According to the module; 1,3,5, or 7 */
    uint8_t SCLPinNum; /* According to the module, 0,2,4, or 6 */
    uint8_t Prescalar; /* Solving for TPR: SCL_PERIOD = 2×(1 + TPR)×(SCL_LP + SCL_HP)×CLK_PRD */
}I2C_CFG_t;

extern const I2C_CFG_t I2C_CFG_arr[I2C_CHANELLS_NUMBER];

/*
 * Function declarations
 */

I2C_ErrorCheck_t I2C_init(void);

I2C_ErrorCheck_t I2C_SetSlaveAddress (uint8_t SlaveAddress, uint8_t ReadWrite, ChannelID_t ChannelID);

I2C_ErrorCheck_t I2C_MasterSend (uint8_t Data,ChannelID_t ChannelID);

I2C_ErrorCheck_t I2C_MasterRecieve (uint8_t* Data,ChannelID_t ChannelID);

/*
I2C_ErrorCheck_t I2C_SlaveSend (void);

I2C_ErrorCheck_t I2C_SlaveRecieve (void);
*/

#endif
