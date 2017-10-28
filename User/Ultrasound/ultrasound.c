#include "Ultrasound.h"
#include "delay.h"
#include "usart.h"

void Ultrasound_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(TRIG_GPIO_CLK | ECHO_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = TRIG_GPIO_PIN;
    GPIO_Init(TRIG_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin = ECHO_GPIO_PIN;
    GPIO_Init(ECHO_GPIO_PORT, &GPIO_InitStructure);
}

float Ultrasound_Measure(void)
{
    int count = 0;
    float Lenth;
    TRIG_H;
    delay_us(10);
    TRIG_L; //初始化 发送触发波
    while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2) == 0){}
    while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2) == 1 && count < 2000) //需要测量距离3m 6m/340
    {
        delay_us(10);
        count++;
    }
    Lenth = count*1.7;//mm
    if (count >= 1999)
        Lenth = -1;
    return Lenth;
}
