/*
 * remoSensor1_BM1383_0_0_2.h
 *
 *  Created on: 11-Jul-2022
 *      Author: Harish
 */

#ifndef REMOSENSOR1_BM1383_0_0_3_H_
#define REMOSENSOR1_BM1383_0_0_3_H_
#include <stdint.h>
// I2C Address of the sensor
#define BM1383_ADDR   0x5D //1011101

/* Common address definition for BM1383 Sensor */
#define BM1383_ID 0x10
#define BM1383_RESETCTRL 0x11
#define BM1383_POWERDWN 0x12
#define BM1383_RESET 0x13
#define BM1383_MODECTRL_ 0x14
#define BM1383_INT_H_MSB 0x15
#define BM1383_INT_H_LSB 0x16
#define BM1383_INT_L_MSB 0x17
#define BM1383_INT_L_LSB 0x18
#define BM1383_INTCTRL 0x19
#define BM1383_PRESSURE_MSB 0x1C
#define BM1383_PRESSURE_LSB 0x1D
#define BM1383_PRESSURE_LSB_6 0x1E

//Give power to the device
#define BM1383_POWER_ON    0x1201

//Set the measurement control block to active state
#define BM1383_BLOCK_ACTIVE 0x1301
//Set average of measurement data BIT.7,BIT.6 and BIT.5
#define BM1383_MODE_SET 0x00

//All the modes have been defined what mode should be used??

//Measurement control block
#define BM1383_RSTB_RESET 0x1300
#define BM1383_RSTB_ACT 0x1301

//Software reset for BM1383
#define BM1383_SW_RESET 0x1180

typedef struct BM1383{
    uint8_t ui8_ID;
    // Manufacture ID[7:4] + Device ID[3:0]
    uint16_t ui_16Pressure;
    //Raw Pressure data from sensor
    float Pressure;
    //Pressure data
}BM1383_t;


/***************************************************/
/* Driver API for BM1383 Pressure Sensor         */
/***************************************************/

//sets PWR_DOWN=1 and RSTB=1
void BM1383GLV_Set(void);
//gets the manufacture and part ID from register 10h
uint8_t BM1383GLV_GetID(void);
//resets BM1383GLV by writing 80h to register 11h
void BM1383GLV_Reset(void);
//set the mode of measurements of BM1383GLV write in register 14h
void BM1383GLV_SetMode(void);
//set the interrupt control of BM1383GLV write in register 19h
void BM1383GLV_SetInterrupt(void);
//gets measurements for pressure from register 1Ch
float BM1383GLV_GetPressure(void);

#endif /* REMOSENSOR1_BM1383_0_0_3_H_ */
