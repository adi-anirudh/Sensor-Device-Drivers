/*
 *	BH1745NUC.c
 *
 *  Created on: 22-Jul-2022
 *      Author: Aditya Anirudh
 */
#include "asf.h"
#include "stdio_serial.h"
#include "conf_board.h"
#include "conf_clock.h"
#include ""
#include "D:\Renalyx\xdk-asf-3.52.0\common\services\twi\twi_master.h"//Depends on which directory the relevant files are stored
#include "cl_types.h" 
#include "cl_consolecontroller.h"

#include "BH1745NUC.h"
#include "D:\Renalyx\Renalyx_DM1\src\Platform\Drivers\DD_IIC\DD_IIC.h"//Depends on the directory
#define SLAVE_ADDR1 0x38
#define SLAVE_ADDR2 0x39
#define SLAVE_ADDR1 0x38
#define SLAVE_ADDR2 0x39


static void dd_write_data_on_iicbus1(uint8_t data,uint8_t length, uint8_t data_addr[3])
{
	twi_packet_t iic_packet = {
		//.chip         = SLAVE_ADDR1,
		.addr		  = data_addr,
		.addr_length  = 1;
		.chip         =  BH174NUC_ID,
		.buffer       = (void *)data, // transfer data source buffer
		//.length       = 4   // transfer data size (bytes)
		.length       = length   // transfer data size (bytes)
	};
	twi_master_write1(TWI0, &iic_packet);
}

static void dd_read_data_from_iicbus1(uint8_t data_addr[3], uint8_t length)
{
	twi_packet_t iic_packet = {
		.addr		  = data_addr,
		.addr_length  = 1,
		.chip         = BH174NUC_ID,
		.buffer       = NULL, // transfer data source buffer
		.length       = length  // transfer data size (bytes)
	};

	//iic_packet.buffer =  (void *)data;
	
	twi_master_read(TWI0, &iic_packet)	;
	;
}


void BH174_SoftwareReset(void)
{
	
	DD_INIT_IIC();
	dd_write_data_on_iicbus1(0x8B, 1, 0x40);
	
}

void BH174_Read_Part_ID(void)
{
	DD_INIT_IIC();
	dd_read_data_from_iicbus1(0x40, 1);
}

void BH174_MeasurementTimeControl(uint8_t mode)
{
	DD_INIT_IIC();
	dd_write_data_on_iicbus1(mode, 1, 0x41);
}

bool BH174_DataValdity()
{
	DD_INIT_IIC();
	dd_read_data_from_iicbus1(0x42, 1);//7th bit is the validity bit
	
}

void BH174_RGBC_Enable()
{
	DD_INIT_IIC();
	dd_write_data_on_iicbus1(0x90,1, 0x42);
}

void BH174_DC_Gain(uint8_t gain_setting)
{
	DD_INIT_IIC();
	dd_write_data_on_iicbus1(gain_setting,1, 0x42);// user will give the required byte to write to the register
}

bool BH174_Get_Interrupt_Status()
{
	DD_INIT_IIC();
	dd_read_data_from_iicbus1(0x60, 1);//7th bit gives interrupt status
}

void BH174_Interrupt_Enable(uint8_t mode)
{
	DD_INIT_IIC();
	dd_write_data_on_iicbus1(mode, 1, 0x60);
}

void BH174_Interrupt_Latch(uint8_t mode)
{
	DD_INIT_IIC();
	dd_write_data_on_iicbus1(mode, 1, 0x60);
}

void BH174_Interrupt_Source_Select(uint8_t mode)
{
	DD_INIT_IIC();
	dd_write_data_on_iicbus1(mode, 1, 0x60);
}
void BH174_Persistence_Mode_Select(uint8_t mode)
{
	DD_INIT_IIC();
	dd_write_data_on_iicbus1(mode, 1, 0x61);
}

void BH174_Get_Red_Data_LSB()
{
	DD_INIT_IIC();
	dd_read_data_from_iicbus1(0x50, 1);
}

void BH174_Get_Red_Data_MSB()
{
	DD_INIT_IIC();
	dd_read_data_from_iicbus1(0x51, 1);
}

void BH174_Get_Green_Data_LSB()
{
	DD_INIT_IIC();
	dd_read_data_from_iicbus1(0x52, 1);
}

void BH174_Get_Green_Data_LSB()
{
	DD_INIT_IIC();
	dd_read_data_from_iicbus1(0x53, 1);
}

void BH174_Get_Blue_Data_LSB()
{
	DD_INIT_IIC();
	dd_read_data_from_iicbus1(0x54, 1);
}

void BH174_Get_Blue_Data_MSB()
{
	DD_INIT_IIC();
	dd_read_data_from_iicbus1(0x55, 1);
}

void BH174_Clear_Data()
{
	DD_INIT_IIC();
	dd_write_data_on_iicbus1(0xFF, 1, 0x56);
	dd_write_data_on_iicbus1(0xFF, 1, 0x57);
	
}





