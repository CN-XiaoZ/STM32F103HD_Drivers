#include "./Motor/motor.h"
#include "stm32f10x.h"
#include "./delay/delay.h"

void Motor_Config(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
    RCC_APB2PeriphClockCmd(LA1_GPIO_CLK | LA2_GPIO_CLK | LB1_GPIO_CLK | LB2_GPIO_CLK, ENABLE);
    RCC_APB2PeriphClockCmd(RA1_GPIO_CLK | RA2_GPIO_CLK | RB1_GPIO_CLK | RB2_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = LA1_GPIO_PIN;
    GPIO_Init(LA1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = LA2_GPIO_PIN;
    GPIO_Init(LA2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = LB1_GPIO_PIN;
    GPIO_Init(LB1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = LB2_GPIO_PIN;
    GPIO_Init(LB2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = RA1_GPIO_PIN;
    GPIO_Init(RA1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = RA2_GPIO_PIN;
    GPIO_Init(RA2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = RB1_GPIO_PIN;
    GPIO_Init(RB1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = RB2_GPIO_PIN;
    GPIO_Init(RB2_GPIO_PORT, &GPIO_InitStructure);

    TIM_TimeBaseStructure.TIM_Period = 25499;
    TIM_TimeBaseStructure.TIM_Prescaler = 143;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;

    TIM_OC1Init(TIM5, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable);

    TIM_OC2Init(TIM5, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Enable);

    TIM_OC3Init(TIM5, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM5, TIM_OCPreload_Enable);

    TIM_OC4Init(TIM5, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM5, TIM_OCPreload_Enable);

    TIM_ARRPreloadConfig(TIM5, ENABLE);
    TIM_Cmd(TIM5, ENABLE);
}

void Set_Speed(uint32_t LA, uint32_t LB, uint32_t RA, uint32_t RB)
{
    TIM5->CCR1 = LA;
    TIM5->CCR2 = LB;
    TIM5->CCR3 = RA;
    TIM5->CCR4 = RB;
}

void Motor_Control(int32_t LA, int32_t LB, int32_t RA, int32_t RB)
{
    if (LA < 0)
    {
        GPIO_SetBits(LA2_GPIO_PORT, LA2_GPIO_PIN);
        LA = LA + 25499;
    }
    else
        GPIO_ResetBits(LA2_GPIO_PORT, LA2_GPIO_PIN);

    if (LB < 0)
    {
        GPIO_SetBits(LB2_GPIO_PORT, LB2_GPIO_PIN);
        LB = LB + 25499;
    }
    else
        GPIO_ResetBits(LB2_GPIO_PORT, LB2_GPIO_PIN);

    if (RA < 0)
    {
        GPIO_SetBits(RA2_GPIO_PORT, RA2_GPIO_PIN);
        RA = RA + 25499;
    }
    else
        GPIO_ResetBits(RA2_GPIO_PORT, RA2_GPIO_PIN);

    if (RB < 0)
    {
        GPIO_SetBits(RB2_GPIO_PORT, RB2_GPIO_PIN);
        RB = RB + 25499;
    }
    else
        GPIO_ResetBits(RB2_GPIO_PORT, RB2_GPIO_PIN);

    Set_Speed(LA, LB, RA, RB);
}

void Motor_FWD(void)
{
    Motor_Control(21801, 22056, 25499, 25499);
}
void Motor_BEH(void)
{
    Motor_Control(-16750, -16750, -19900, -19900);
}
void Motor_STOP(void)
{
    Motor_Control(0, 0, 0, 0);
}
