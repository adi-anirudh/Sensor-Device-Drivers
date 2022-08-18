/*
 * remoSensor2_LM75_0_0_3.h
 *
 *  Created on: 16-Jul-2022
 *      Author: Harish
 */

#ifndef REMOSENSOR2_LM75_0_0_3_H_
#define REMOSENSOR2_LM75_0_0_3_H_

#include <stdint.h>
#include <stdbool.h>

//Common Addresses for Sensor
#define LM75B_ADDR  0x48

//Register Select for Pointer Register BIT.2, BIT.1 and BIT.0 setting every register to default mode
#define Temp        0x00
#define Config      0x0100//(address of register 01+00 default mode)
#define THyst       0x02
#define TOS         0x03

/*Configuration Settings*/
//Shutdown BIT.0
#define POWERUP     0x00
#define SHUTDOWN    0x01

//Comparator/Interrupt Mode Set BIT.1
#define CMPMode     0x00
#define INTMode     0x02

//O.S. Polarity Set BIT.2
#define ACT_LOW     0x00
#define ACT_HIGH    0x04

//Fault Queue Set BIT.4, BIT.3
#define FAULT_1     0x00
#define FAULT_2     0x08
#define FAULT_4     0x10
#define FAULT_6     0X18


/* Software model of LM75B */
typedef struct{
    //uint16_t ui8ManufacturerID;       Sensor does not have a seperate register
    //uint16_t ui8DeviceID;             which stores the Manufacturer and Device ID
    uint8_t ui8_ID;
    // Raw Temperature data read from Sensor Register- Local variable
    uint16_t ui16_Temperature;
    // Real Temperature- Read using API
    float Temperature;
}lm75b_t;


/***************************************************/
/* Driver API for LM75B Temperature Sensor         */
/***************************************************/

//to select the register to read/write to
void LM75BSelectRegister(uint8_t);

//read LM75B Config Register
uint8_t LM75BConfigRead(void);

//configure LM75B using the necessary parameters
void LM75BConfig(uint8_t *CongifParams);

//Read Temperature Data (16-bit register)
uint16_t LM75BTemperature_Register();

//Read T_HYST (16-bit) register
uint16_t LM75B_T_HYSTRead();

//Read T_OS (16-bit) register
uint16_t LM75B_T_OSRead();

//Write T_HYST (16-bit) register
void LM75B_T_HYST_Write(uint16_t T_HYST_params);

//Write T_OS (16-bit) register
void LM75B_T_OS_Write(uint16_t T_HYST_params);

//resets LM75B
void LM75BReset(void);

/***************************************************/


#endif /* REMOSENSOR2_LM75_0_0_3_H_ */
