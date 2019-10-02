
/*
#define PORTA_BASE_ADDRESS 0x40004000
#define PORTB_BASE_ADDRESS 0x40005000
#define PORTC_BASE_ADDRESS 0x40006000
#define PORTD_BASE_ADDRESS 0x40007000
#define PORTE_BASE_ADDRESS 0x40024000
#define PORTF_BASE_ADDRESS 0x40025000

#define I2C0_BASE_ADDRESS  0x40020000
#define I2C1_BASE_ADDRESS  0x40021000
#define I2C2_BASE_ADDRESS  0x40022000
#define I2C3_BASE_ADDRESS  0x40023000
*/
/*I2C master registers */
#define I2CSA_Offset   0x000 // I2C Master Slave Address
#define I2CMCS_Offset  0x004 // I2C Master Control/Status
#define I2CMDR_Offset  0x008 // I2C Master Data
#define I2CMTPR_Offset 0x00C // I2C Master Timer Period
/*Interrupts*/
#define I2CMIMR_Offset 0x010
#define I2CMRIS_Offset 0x014
#define I2CMMIS_Offset 0x018
#define I2CMICR_Offset 0x01C
/**/
#define I2CMCR_Offset      0x020      // I2C Master Configuration
#define I2CMCLKOCNT_Offset 0x024 // I2C Master Clock Low Timeout Count
#define I2CMBMON_Offset    0x02C // I2C Master Bus Monitor
#define I2CMCR2_Offset    0x038  // I2C Master Configuration 2

/*I2C slave registers */
