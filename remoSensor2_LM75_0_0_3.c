/*
 * remoSensor_2_LM75_0_0_3.c
 *
 *  Created on: 16-Jul-2022
 *      Author: Harish
 */
#include <stdint.h>
#include <stdbool.h>
#include "remoDIO.h"
#include "remoI2C.h"
#include "remoSensor2_LM75_0_0_3.h"


//Read Temperature Data (16-bit register)
uint16_t LM75BTemperature_Register(){
    uint16_t reg_data = i2cReceive(LM75B_ADDR,2,Temp); //Read register data
    //Mask bits D0 to D6 to get temperature reading
    reg_data = reg_data&0xff80; //masking by bitwise AND operation with 1111111110000000
    return reg_data;
}

//code has been completed just to return back the temp as of now
/*
//configure LM75B using the neccessary parameters
void LM75BConfigWrite(uint8_t ConfigParams){
    //send ConfigParams (by default 0?) to Config register 0x1
    i2cSend(LM73B_ADDR,?,POWERUP);
}
//read LM75B Config Register
uint8_t LM75BConfigRead(){
    uint8_t ConfigParams =i2cReceive(LM73B_ADDR,2,Config);  //read ConfigParams
    return ConfigParams;
}



//Read T_HYST (16-bit) register
uint16_t LM75B_T_HYSTRead(){
    uint16_t reg_data = i2cReceive(LM73B_ADDR,?,THyst); //Read register data
    //Mask bits D0 to D6 to get T_HYST Trip Temperature Data.
    reg_data = reg_data&0xff80; //masking by bitwise AND operation with 1111111110000000
    return reg_data;
}
//Read T_OS (16-bit) register
uint16_t LM75B_T_OSRead(){
    uint16_t reg_data = i2cReceive(LM73B_ADDR,?,TOS); //Read register data
    //Mask bits D0 to D6 to get T_OS Trip Temperature Data.
    reg_data = reg_data&0xff80; //masking by bitwise AND operation with 1111111110000000
    return reg_data;
}
//Write T_HYST (16-bit) register
void LM75B_T_HYST_Write(uint16_t T_HYST_params){
    //push params to register 0x2
    i2cSend(LM73B_ADDR,?,T_HYST_params);
}
//Write T_OS (16-bit) register
void LM75B_T_OS_Write(uint16_t T_OS_params){
    //push params to register 0x3
    i2cSend(LM73B_ADDR,?,T_OS_params);
}

*/
/***************************************************/



