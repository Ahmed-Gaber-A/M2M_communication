/*
* C file of the I2C module configurations
*/

#include "I2C_PBCfg.h"
#include "I2C.h"

const I2C_CFG_t I2C_CFG_arr[I2C_CHANELLS_NUMBER]=
                                                {
                                                 {I2C0,PORTB,MASTER,3,2,0x9} /* 1 channel */

                                                };




