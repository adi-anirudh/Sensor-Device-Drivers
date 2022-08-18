/*
 * remoSensor1_BM1383_0_0_1.c
 *
 *  Created on: 13-Jul-2022
 *      
 */
#include <remoSensor1_BM1383_0_0_3.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_i2c.h"
#include "inc/hw_ints.h"

#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/i2c.h"
#include "driverlib/pin_map.h"
#include "driverlib/interrupt.h"

#include "remoUtils.h"
#include "remoI2C.h"
#include "remoDIO.h"


//PWR_DOWN=1 and RSTB=1(Activates the measurement block) has to be set for all these functions
void BM1383GLV_Set(void)
{
    i2cSend(BM1383_ADDR,2,BM1383_POWER_ON);
    i2cSend(BM1383_ADDR,2,BM1383_RSTB_ACT);
}

//resets BM1383GLV by writing 80h to register 11h(software reset
void BM1383GLVReset(void)
{
    i2cSend(BM1383_ADDR,2,BM1383_SW_RESET);
}
//set the mode of measurements of BM1383GLV write in register 14h

void BM1383GLVSetMode(void)
{
    i2cSend(BM1383_ADDR,1,BM1383_MODE_SET);//Default mode set
}
//gets the manufacture ID and Part ID from register 10h
uint8_t BM1383GLVGet_ID(void)
{
  return(LOWBYTE(i2cReceive(BM1383_ADDR,1,BM1383_ID)));
}

//set the interrupt control of BM1383GLV write in register 19h
void BM1383GLV_SetInterrupt(void)//filing this up later
{
    //enable interrupt
    i2cSend(BM1383_ADDR,1,BM1383_INTCTRL);//chose a mode (latch or unlatch)

    //set threshold upper and lower values by accessing 15h to 18h registers
    uint8_t uint8_CTRLSTATUS;
    uint8_CTRLSTATUS= (LOWBYTE(i2cReceive(BM1383_ADDR,1,BM1383_INTCTRL)));
    int temp = uint8_CTRLSTATUS & 0xC0;  //bit masking with 11000000 to get D7 and D6 which contains the H and L status
    if(temp!=0){
        //interrupt
    }
}

//gets measurements for pressure from register 1Ch and 1Dh(MSB,LSB)
float BM1383GLV_GetPressure(void)
{
    //Conversion to pressure value is like below.
    //Pressure value[hPa] = { uint16_pressure[15:8], uint16_pressure[7:0], pressuredecimal[5:0] } / 2048
    float PressureValueHpa;
    uint16_t uint16_Pressure;
    uint8_t uint8_Pressuredecimal;
    uint16_Pressure=(LOWWORD(i2cReceive(BM1383_ADDR,2,BM1383_PRESSURE_MSB)));
    float tempint= uint16_Pressure & 0xFFE0;
    uint8_Pressuredecimal=(LOWBYTE(i2cReceive(BM1383_ADDR,2,BM1383_PRESSURE_LSB_6)));
    float tempdec= (((uint16_Pressure & 0x1F)+ (uint8_Pressuredecimal & 0xFC))/2048);
    PressureValueHpa= tempint+tempdec;
    return(PressureValueHpa);
}






