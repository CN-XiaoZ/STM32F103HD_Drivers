#ifndef _IIC_H
#define _IIC_H
#include "stm32f10x.h"
//本文件针对I2C2总线,有时间改I2C1
#define SCL_H         GPIOB->BSRR = GPIO_Pin_10
#define SCL_L         GPIOB->BRR  = GPIO_Pin_10
   
#define SDA_H         GPIOB->BSRR = GPIO_Pin_11
#define SDA_L         GPIOB->BRR  = GPIO_Pin_11

#define SCL_read      GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)
#define SDA_read      GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)

void I2C_Config(void);
void I2C_Stop(void);
u8 I2C_Start(void);
void I2C_Stop(void);
void I2C_SendACK(u8 i);
u8 I2C_WaitAck(void);
void I2C_SendByte(u8 dat);
u8 I2C_RecvByte(int ack);
void I2C_NAck(void);
void I2C_Ack(void);
u8 Single_WriteI2C_byte(u8 Slave_Address,u8 REG_Address,u8 data);
u8 Single_ReadI2C(u8 Slave_Address,u8 REG_Address,u8 *REG_data,u8 length);

#endif
