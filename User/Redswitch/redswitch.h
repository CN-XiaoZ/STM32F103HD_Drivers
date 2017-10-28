#ifndef __RED_H
#define __RED_H

#include "stm32f10x.h"
#include "./Motor/motor.h"
#include "./delay/delay.h"
#define Black 1
#define White 0
//L2 C6 L1 C8 R1 C9 R2 C7 MID A15   RF B13  RB B15  LF B14  LB B12
#define R1_GPIO_PORT GPIOC
#define R1_GPIO_CLK RCC_APB2Periph_GPIOC
#define R1_GPIO_PIN GPIO_Pin_9

#define R2_GPIO_PORT GPIOC
#define R2_GPIO_CLK RCC_APB2Periph_GPIOC
#define R2_GPIO_PIN GPIO_Pin_7

#define MID_GPIO_PORT GPIOA
#define MID_GPIO_CLK RCC_APB2Periph_GPIOA
#define MID_GPIO_PIN GPIO_Pin_15

#define L1_GPIO_PORT GPIOC
#define L1_GPIO_CLK RCC_APB2Periph_GPIOC
#define L1_GPIO_PIN GPIO_Pin_8

#define L2_GPIO_PORT GPIOC
#define L2_GPIO_CLK RCC_APB2Periph_GPIOC
#define L2_GPIO_PIN GPIO_Pin_6

#define RF_GPIO_PORT GPIOB
#define RF_GPIO_CLK RCC_APB2Periph_GPIOB
#define RF_GPIO_PIN GPIO_Pin_13

#define RB_GPIO_PORT GPIOB
#define RB_GPIO_CLK RCC_APB2Periph_GPIOB
#define RB_GPIO_PIN GPIO_Pin_15

#define LF_GPIO_PORT GPIOB
#define LF_GPIO_CLK RCC_APB2Periph_GPIOB
#define LF_GPIO_PIN GPIO_Pin_14

#define LB_GPIO_PORT GPIOB
#define LB_GPIO_CLK RCC_APB2Periph_GPIOB
#define LB_GPIO_PIN GPIO_Pin_12

//开关
#define SWITCH_GPIO_PORT GPIOB
#define SWITCH_GPIO_CLK RCC_APB2Periph_GPIOB
#define SWITCH_GPIO_PIN GPIO_Pin_5

#define R1 GPIO_ReadInputDataBit(R1_GPIO_PORT, R1_GPIO_PIN)
#define R2 GPIO_ReadInputDataBit(R2_GPIO_PORT, R2_GPIO_PIN)
#define MID GPIO_ReadInputDataBit(MID_GPIO_PORT, MID_GPIO_PIN)
#define L1 GPIO_ReadInputDataBit(L1_GPIO_PORT, L1_GPIO_PIN)
#define L2 GPIO_ReadInputDataBit(L2_GPIO_PORT, L2_GPIO_PIN)
#define LB GPIO_ReadInputDataBit(RF_GPIO_PORT, RF_GPIO_PIN)
#define RB GPIO_ReadInputDataBit(RB_GPIO_PORT, RB_GPIO_PIN)
#define LF GPIO_ReadInputDataBit(LF_GPIO_PORT, LF_GPIO_PIN)
#define RF GPIO_ReadInputDataBit(LB_GPIO_PORT, LB_GPIO_PIN)
#define SWITCH GPIO_ReadInputDataBit(SWITCH_GPIO_PORT, SWITCH_GPIO_PIN)
void Redswitch_Config(void);
void Switch_Config(void);

#endif
