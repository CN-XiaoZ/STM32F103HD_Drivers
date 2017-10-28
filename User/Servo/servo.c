#include "./Servo/servo.h"
#include "./delay/delay.h"

void Servo_Config()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;
    RCC_APB2PeriphClockCmd(DJ1_GPIO_CLK | DJ2_GPIO_CLK | DJ3_GPIO_CLK | DJ4_GPIO_CLK | DJ5_GPIO_CLK | DJ6_GPIO_CLK | DJ7_GPIO_CLK | DJ8_GPIO_CLK, ENABLE);

    GPIO_InitStructure.GPIO_Pin = DJ1_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(DJ1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DJ2_GPIO_PIN;
    GPIO_Init(DJ2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DJ3_GPIO_PIN;
    GPIO_Init(DJ3_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DJ4_GPIO_PIN;
    GPIO_Init(DJ4_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DJ5_GPIO_PIN;
    GPIO_Init(DJ5_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DJ6_GPIO_PIN;
    GPIO_Init(DJ6_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DJ7_GPIO_PIN;
    GPIO_Init(DJ7_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DJ8_GPIO_PIN;
    GPIO_Init(DJ8_GPIO_PORT, &GPIO_InitStructure);

    RCC_APB1PeriphClockCmd(TIM_Group_1_CLK | TIM_Group_2_CLK, ENABLE);
    
    TIM_TimeBaseStructure.TIM_Period = 9999;
    TIM_TimeBaseStructure.TIM_Prescaler = 143;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM_Group_1, &TIM_TimeBaseStructure);
    TIM_TimeBaseInit(TIM_Group_2, &TIM_TimeBaseStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;

    TIM_OCInitStructure.TIM_Pulse = 750;
    TIM_OC1Init(TIM_Group_1, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM_Group_1, TIM_OCPreload_Enable);

    TIM_OCInitStructure.TIM_Pulse = 750;
    TIM_OC2Init(TIM_Group_1, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM_Group_1, TIM_OCPreload_Enable);

    TIM_OCInitStructure.TIM_Pulse = 750;
    TIM_OC3Init(TIM_Group_1, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM_Group_1, TIM_OCPreload_Enable);

    TIM_OCInitStructure.TIM_Pulse = 750;
    TIM_OC4Init(TIM_Group_1, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM_Group_1, TIM_OCPreload_Enable);

    TIM_OCInitStructure.TIM_Pulse = 750;
    TIM_OC1Init(TIM_Group_2, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM_Group_2, TIM_OCPreload_Enable);

    TIM_OCInitStructure.TIM_Pulse = 750;
    TIM_OC2Init(TIM_Group_2, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM_Group_2, TIM_OCPreload_Enable);

    TIM_OCInitStructure.TIM_Pulse = 750;
    TIM_OC3Init(TIM_Group_2, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM_Group_2, TIM_OCPreload_Enable);

    TIM_OCInitStructure.TIM_Pulse = 750;
    TIM_OC4Init(TIM_Group_2, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM_Group_2, TIM_OCPreload_Enable);

    TIM_ARRPreloadConfig(TIM_Group_1, ENABLE);
    TIM_Cmd(TIM_Group_1, ENABLE);
    TIM_ARRPreloadConfig(TIM_Group_2, ENABLE);
    TIM_Cmd(TIM_Group_2, ENABLE);
}
//平滑过渡角度函数
/*
void Servo_Angle(int angle1, int angle2, int angle3, int angle4, int angle5, int angle6, int angle7, int angle8)
{
    float i1, i2, i3, i4, i5, i6, i7, i8;
    int i;
    int k1, k2, k3, k4, k5, k6, k7, k8;
    angle1 = angle1 * 5.55;
    angle1 = angle1 + 250;
    angle2 = angle2 * 5.55;
    angle2 = angle2 + 250;
    angle3 = angle3 * 5.55;
    angle3 = angle3 + 250;
    angle4 = angle4 * 5.55;
    angle4 = angle4 + 250;
    angle5 = angle5 * 5.55;
    angle5 = angle5 + 250;
    angle6 = angle6 * 5.55;
    angle6 = angle6 + 250;
    angle7 = angle7 * 5.55;
    angle7 = angle7 + 250;
    angle8 = angle8 * 5.55;
    angle8 = angle8 + 250;
    k1 = angle1;
    k2 = angle2;
    k3 = angle3;
    k4 = angle4;
    k5 = angle5;
    k6 = angle6;
    k7 = angle7;
    k8 = angle8;
    i1 = TIM_Group_1->CCR1;
    i2 = TIM_Group_1->CCR2;
    i3 = TIM_Group_1->CCR3;
    i4 = TIM_Group_1->CCR4;
    i5 = TIM_Group_2->CCR1;
    i6 = TIM_Group_2->CCR2;
    i7 = TIM_Group_2->CCR3;
    i8 = TIM_Group_2->CCR4;
    i1 = angle1 - i1;
    i1 = i1 / 30;
    i2 = angle2 - i2;
    i2 = i2 / 30;
    i3 = angle3 - i3;
    i3 = i3 / 30;
    i4 = angle4 - i4;
    i4 = i4 / 30;
    i5 = angle5 - i5;
    i5 = i5 / 30;
    i6 = angle6 - i6;
    i6 = i6 / 30;
    i7 = angle7 - i7;
    i7 = i7 / 30;
    i8 = angle8 - i8;
    i8 = i8 / 30;
    for (i = 0; i < 30; i++)
    {
        angle1 = i1 + TIM_Group_1->CCR1;
        angle2 = i2 + TIM_Group_1->CCR2;
        angle3 = i3 + TIM_Group_1->CCR3;
        angle4 = i4 + TIM_Group_1->CCR4;
        angle5 = i5 + TIM_Group_2->CCR1;
        angle6 = i6 + TIM_Group_2->CCR2;
        angle7 = i7 + TIM_Group_2->CCR3;
        angle8 = i8 + TIM_Group_2->CCR4;
        TIM_Group_2->CCR4 = angle8;
        TIM_Group_2->CCR3 = angle7;
        TIM_Group_2->CCR2 = angle6;
        TIM_Group_2->CCR1 = angle5;
        TIM_Group_1->CCR4 = angle4;
        TIM_Group_1->CCR3 = angle3;
        TIM_Group_1->CCR2 = angle2;
        TIM_Group_1->CCR1 = angle1;
        delay_ms(40);
    }
    TIM_Group_2->CCR4 = k8;
    TIM_Group_2->CCR3 = k7;
    TIM_Group_2->CCR2 = k6;
    TIM_Group_2->CCR1 = k5;
    TIM_Group_1->CCR4 = k4;
    TIM_Group_1->CCR3 = k3;
    TIM_Group_1->CCR2 = k2;
    TIM_Group_1->CCR1 = k1;
}
*/
/*无平滑处理*/
void Servo_Angle(int angle1, int angle2, int angle3, int angle4, int angle5, int angle6, int angle7, int angle8)
 {
     angle1 = angle1 * 5.55;
     angle1 = angle1 + 250;
     angle2 = angle2 * 5.55;
     angle2 = angle2 + 250;
     angle3 = angle3 * 5.55;
     angle3 = angle3 + 250;
     angle4 = angle4 * 5.55;
     angle4 = angle4 + 250;
     angle5 = angle5 * 5.55;
     angle5 = angle5 + 250;
     angle6 = angle6 * 5.55;
     angle6 = angle6 + 250;
     angle7 = angle7 * 5.55;
     angle7 = angle7 + 250;
     angle8 = angle8 * 5.55;
     angle8 = angle8 + 250;  
     TIM_Group_2->CCR4 = angle8;
     TIM_Group_2->CCR3 = angle7;
     TIM_Group_2->CCR2 = angle6;
     TIM_Group_2->CCR1 = angle5;
     TIM_Group_1->CCR4 = angle4;
     TIM_Group_1->CCR3 = angle3;
     TIM_Group_1->CCR2 = angle2;
     TIM_Group_1->CCR1 = angle1;
}
