/*
 *	BH1745NUC.h
 *
 *  Created on: 20-Jul-2022
 *      Author: Aditya Anirudh
 */

#define BH174NUC_ID 0x38 //0011 1000 for Low
#define BH174NUC_ID 0x39// 0011 1001 for High

#define BH174_SYSTEM_CONTROL  0x40
#define BH174_MODE_CONTROL1   0x41
#define BH174_MODE_CONTROL2   0x42
#define BH174_MODE_CONTROL3   0x43
#define BH174_RED_DATA_LSB    0x50
#define BH174_RED_DATA_MSB    0x51
#define BH174_GREEN_DATA_LSB  0x52
#define BH174_GREEN_DATA_MSB  0x53
#define BH174_BLUE_DATA_LSB   0x54
#define BH174_BLUE_DATA_MSB   0x55
#define BH174_CLEAR_DATA_LSB  0x56
#define BH174_CLEAR_DATA_MSB  0x57
#define BH174_DINT_DATA_LSB   0x58
#define BH174_DINT_DATA_MSB   0x59
#define BH174_INTERRUPT       0x60
#define BH174_PERSISTENCE     0x61
#define BH174_TH_LSB          0x62
#define BH174_TH_MSB          0x63
#define BH174_TL_LSB          0x64
#define BH174_TL_MSB          0x65
#define BH174_MANUFACTURER_ID 0x92

void BH174_SoftwareReset(void); //All registers are reset and BH1745NUC becomes power down by Software reset command

void BH174_Read_Part_ID(void); // Read Part ID 

void BH174_MeasurementTimeControl(uint8_t mode); //Control RGBC Measurement time

bool BH174_DataValdity(void); //Checks whether Data is updated after the last write to Mode Control Registers

void BH174_RGBC_Enable(void); //Enable RGBC Measurement

int BH174_DC_Gain(uint8_t gain_setting); //GAIN setting for RGBC measurement

bool BH174_Get_Interrupt_Status(void); //Read status of interrupt signal, enable interrupt pin, latch input, source select, persistence

void BH174_Interrupt_Enable(uint 8_t mode); //Enabling interrupt pin

void BH174_Interrupt_Latch(uint 8_t mode); //Latch interrupt pin

void BH174_Interrupt_Source_Select(uint 8_t mode); // Selecting Interrupt Source(R,G,or B)

void BH174_Persistence_Mode_Select(uint 8_t mode); // Interrupt persistence function

void BH174_Get_Red_Data_LSB(void);// Sensing Red

void BH174_Get_Red_Data_MSB(void);// Sensing Red

void BH174_Get_Green_Data_LSB(void);// Sensing Green

void BH174_Get_Green_Data_MSB(void);// Sensing Green

void BH174_Get_Blue_Data_LSB(void);// Sensing Blue

void BH174_Get_Blue_Data_LSB(void);// Sensing Blue

void BH174_Clear_Data(void);//Clearing all registers

//uint8_t BH174_Get_Manufacturer_ID(void); // Get Manufacturer ID





