#include "./Redswitch/redswitch.h"
#include "stm32f10x.h"

void Redswitch_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(R1_GPIO_CLK | R2_GPIO_CLK | L1_GPIO_CLK | L2_GPIO_CLK | MID_GPIO_CLK | RF_GPIO_CLK | RB_GPIO_CLK | LF_GPIO_CLK | LB_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;

    GPIO_InitStructure.GPIO_Pin = RF_GPIO_PIN;
    GPIO_Init(RF_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = RF_GPIO_PIN;
    GPIO_Init(RB_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = RF_GPIO_PIN;
    GPIO_Init(LF_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = RF_GPIO_PIN;
    GPIO_Init(LB_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = L1_GPIO_PIN;
    GPIO_Init(L1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = L2_GPIO_PIN;
    GPIO_Init(L2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = R1_GPIO_PIN;
    GPIO_Init(R1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = R2_GPIO_PIN;
    GPIO_Init(R2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = MID_GPIO_PIN;
    GPIO_Init(MID_GPIO_PORT, &GPIO_InitStructure);
}

void Switch_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(SWITCH_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin = SWITCH_GPIO_PIN;
    GPIO_Init(SWITCH_GPIO_PORT, &GPIO_InitStructure);
}
