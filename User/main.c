#include "stm32f10x.h"
#include "./usart/usart.h"
#include "./delay/delay.h"
#include "./Colorsensor/colorsensor.h"
#include "./IIC/IIC.h"
#include "./Motor/motor.h"
#include "./MPU/MPU6050.h"
#include "./Servo/servo.h"
#include "./Redswitch/redswitch.h"
#include "./Ultrasound/ultrasound.h"

int main(void)
{	
	delay_init();
  USART_Config();
	I2C_Config();
	Motor_Config();
	Redswitch_Config();
	Servo_Config();
	Ultrasound_Config();
	
  while(1)
	{	
		
	}	
}