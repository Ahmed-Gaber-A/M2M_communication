/*
* C file of the I2C module
*/

#include "I2C.h"
#include "I2C_RegisterMap.h" //memory_map.h
#include "GPIO.h"
/*******************************
 * function definitions
 *******************************/

/*************************************************************
 * Function Name :  I2C_init
 * Description   :  Initialize I2C modules that chosen by user
 * Inputs        :  configuration structure (global)
 * Outputs       :  NULL
 * Return:       :  Error checker {I2C_OK or I2C_NOK}
 *************************************************************/
I2C_ErrorCheck_t I2C_init(void)
{   uint8_t LoopIndex;
    I2C_ErrorCheck_t ErrorChecker;
   for (LoopIndex=0; LoopIndex<I2C_CHANELLS_NUMBER && ErrorChecker != I2C_NOK ; LoopIndex++)
   {
    if (I2C_CFG_arr[LoopIndex] > I2C_MAX_CHANNELnum)
    {
        ErrorChecker = I2C_NOK;
    }
    else
    {
        Alternate_GPIO_Select(I2C_CFG_arr[LoopIndex].PortId , I2C_CFG_arr[LoopIndex].SCLPinNum);
        Alternate_GPIO_Select(I2C_CFG_arr[LoopIndex].PortId , I2C_CFG_arr[LoopIndex].SDAPinNum);

    }
   }
 return ErrorChecker ;
}

/*******************************
 * Function Name : I2C_SetSlaveAddress
 * Description :
 * Inputs:
 * Outputs:
 * Return:
 *******************************/
I2C_ErrorCheck_t I2C_SetSlaveAddress (uint8_t SlaveAddress, uint8_t ReadWrite, ChannelID_t ChannelID);
{
    I2C_ErrorCheck_t ErrorChecker;

    *(I2C_CFG_arr[0].ChannelID + I2CSA_Offset) = slaveAddress;

 return ErrorChecker ;
}

/*******************************
 * Function Name : I2C_MasterSend
 * Description :
 * Inputs:
 * Outputs:
 * Return:
 *******************************/
I2C_ErrorCheck_t I2C_MasterSend (uint8_t Data,ChannelID_t ChannelID);
{
    I2C_ErrorCheck_t ErrorChecker;
if (reg =1 )

else
    ErrorChecker = I2C_NOK;
 return ErrorChecker ;
}

/*******************************
 * Function Name : I2C_MasterRecieve
 * Description :
 * Inputs:
 * Outputs:
 * Return:
 *******************************/
I2C_ErrorCheck_t I2C_MasterRecieve (uint8_t* Data,ChannelID_t ChannelID);
{
    I2C_ErrorCheck_t ErrorChecker;


 return ErrorChecker ;
}
