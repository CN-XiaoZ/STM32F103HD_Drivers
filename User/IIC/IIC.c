#include "./IIC/IIC.h"
#include "./delay/delay.h"

#define I2C_SDA_READ()  ((I2C2->IDR & GPIO_Pin_11) != 0)	/* ��SDA����״̬ */

void I2C_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	SCL_H;
	SDA_H;
}

u8 I2C_Start(void)
{
	SDA_H;
	delay_us(5);
	SCL_H;
	delay_us(5);
	if (!SDA_read)
		return 0;
	SDA_L;
	delay_us(5);
	if (SDA_read)
		return 0;
	SCL_L;
	delay_us(5);
	return 1;
}
void I2C_Stop(void)
{
	SDA_L;
	SCL_L;
	delay_us(5);
	SCL_H;
	delay_us(5);
	SDA_H;
}
void I2C_SendACK(u8 i)
{
	if (1 == i)
		SDA_H;
	else
		SDA_L;
	SCL_H;
	delay_us(5);
	SCL_L;
	delay_us(5);
}
u8 I2C_WaitAck(void)
{
	uint16_t i = 0;
	SDA_H;
	SCL_H;
	while (SDA_read)
	{
		i++;
		if (i == 500)
			break;
	}
	if (SDA_read)
	{
		SCL_L;
		return RESET;
	}
	delay_us(5);
	SCL_L;
	delay_us(5);
	return SET;
}

void I2C_SendByte(u8 dat)
{
	u8 i;
	SCL_L;
	for (i = 0; i < 8; i++)
	{
		if (dat & 0x80)
			SDA_H;
		else
			SDA_L;
		SCL_H;
		delay_us(5);
		SCL_L;
		delay_us(5);
		dat <<= 1;
	}
}
void I2C_Ack(void)
{
	SDA_L;	/* CPU����SDA = 0 */
	delay_us(5);
	SCL_H;	/* CPU����1��ʱ�� */
	delay_us(5);
	SCL_L;
	delay_us(5);
	SDA_H;	/* CPU�ͷ�SDA���� */
}
void I2C_NAck(void)
{
	SDA_H;	/* CPU����SDA = 1 */
	delay_us(5);
	SCL_H;	/* CPU����1��ʱ�� */
	delay_us(5);
	SCL_L;
	delay_us(5);
}
u8 I2C_RecvByte(int ack)
{
	u8 i;
	u8 value;

	value = 0;
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		SCL_H;
		delay_us(5);
		if (SDA_read)
		{
			value++;
		}
		SCL_L;
		delay_us(5);
	}
	if(ack==0)
		I2C_NAck();
	else
		I2C_Ack();
	return value;
}
u8 Single_WriteI2C_byte(u8 Slave_Address, u8 REG_Address, u8 data)
{
	if (I2C_Start() == 0)
	{
		I2C_Stop();
		return RESET;
	}

	I2C_SendByte(Slave_Address);
	if (!I2C_WaitAck())
	{
		I2C_Stop();
		return RESET;
	}

	I2C_SendByte(REG_Address);
	if (!I2C_WaitAck())
	{
		I2C_Stop();
		return RESET;
	}

	I2C_SendByte(data);
	if (!I2C_WaitAck())
	{
		I2C_Stop();
		return RESET;
	}

	I2C_Stop();

	return SET;
}
u8 Single_ReadI2C(u8 Slave_Address, u8 REG_Address, u8 *REG_data, u8 length)
{
	if (I2C_Start() == 0)
	{
		I2C_Stop();
		return RESET;
	}

	I2C_SendByte(Slave_Address);
	if (!I2C_WaitAck())
	{
		I2C_Stop();
		return RESET;
	}

	I2C_SendByte(REG_Address);
	if (!I2C_WaitAck())
	{
		I2C_Stop();
		return RESET;
	}

	if (I2C_Start() == 0)
	{
		I2C_Stop();
		return RESET;
	}

	I2C_SendByte(Slave_Address + 1);
	if (!I2C_WaitAck())
	{
		I2C_Stop();
		return RESET;
	}

	while (length - 1)
	{
		*REG_data++ = I2C_RecvByte(1);
		I2C_SendACK(0);
		length--;
	}
	*REG_data = I2C_RecvByte(0);
	I2C_SendACK(1);
	I2C_Stop();
	return SET;
}
