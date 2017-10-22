#include "./MPU/MPU6050.h"
#include "./usart/usart.h"
#include "./IIC/IIC.h"

void MPU6050_WriteReg(u8 reg_add, u8 reg_dat)
{
	I2C_Start();
	I2C_SendByte(MPU6050_SLAVE_ADDRESS);
	I2C_WaitAck();
	I2C_SendByte(reg_add);
	I2C_WaitAck();
	I2C_SendByte(reg_dat);
	I2C_WaitAck();
	I2C_Stop();
}

void MPU6050_ReadData(u8 reg_add, unsigned char *Read, u8 num)
{
	unsigned char i;

	I2C_Start();
	I2C_SendByte(MPU6050_SLAVE_ADDRESS);
	I2C_WaitAck();
	I2C_SendByte(reg_add);
	I2C_WaitAck();

	I2C_Start();
	I2C_SendByte(MPU6050_SLAVE_ADDRESS + 1);
	I2C_WaitAck();

	for (i = 0; i < (num - 1); i++)
	{
		*Read = I2C_RecvByte(1);
		Read++;
	}
	*Read = I2C_RecvByte(0);
	I2C_Stop();
}

void MPU6050_STOP(void)
{
	MPU6050_WriteReg(MPU6050_RA_PWR_MGMT_1, 0x01);
}

void MPU6050_Init(void)
{
	int i = 0, j = 0;
	for (i = 0; i < 1000; i++)
	{
		for (j = 0; j < 1000; j++)
		{
			;
		}
	}
	MPU6050_WriteReg(MPU6050_RA_PWR_MGMT_1, 0x00);
	MPU6050_WriteReg(MPU6050_RA_SMPLRT_DIV, 0x07);
	MPU6050_WriteReg(MPU6050_RA_CONFIG, 0x06);
	MPU6050_WriteReg(MPU6050_RA_ACCEL_CONFIG, 0x00);
	MPU6050_WriteReg(MPU6050_RA_GYRO_CONFIG, 0x18);
}

uint8_t MPU6050ReadID(void)
{
	unsigned char Re = 0;
	MPU6050_ReadData(MPU6050_RA_WHO_AM_I, &Re, 1);
	if (Re != 0x75)
	{
		printf("MPU6050 dectected error!\r\n");
		return 1;
	}
	else
	{
		printf("MPU6050 ID = %d\r\n", Re);
		return 1;
	}
}

void MPU6050ReadAcc(short *accData)
{
	u8 buf[6];
	MPU6050_ReadData(MPU6050_ACC_OUT, buf, 6);
	accData[0] = (buf[0] << 8) | buf[1];
	accData[1] = (buf[2] << 8) | buf[3];
	accData[2] = (buf[4] << 8) | buf[5];
}

void MPU6050ReadGyro(short *gyroData)
{
	u8 buf[6];
	MPU6050_ReadData(MPU6050_GYRO_OUT, buf, 6);
	gyroData[0] = (buf[0] << 8) | buf[1];
	gyroData[1] = (buf[2] << 8) | buf[3];
	gyroData[2] = (buf[4] << 8) | buf[5];
}

void MPU6050ReadTemp(short *tempData)
{
	u8 buf[2];
	MPU6050_ReadData(MPU6050_RA_TEMP_OUT_H, buf, 2);
	*tempData = (buf[0] << 8) | buf[1];
}

void MPU6050_ReturnTemp(float *Temperature)
{
	short temp3;
	u8 buf[2];

	MPU6050_ReadData(MPU6050_RA_TEMP_OUT_H, buf, 2);
	temp3 = (buf[0] << 8) | buf[1];
	*Temperature = ((double)temp3 / 340.0) + 36.53;
}
