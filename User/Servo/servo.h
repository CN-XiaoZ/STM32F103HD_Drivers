#ifndef __SERVO_H
#define __SERVO_H

#include "stm32f10x.h"

#define TIM_Group_1 TIM4
#define TIM_Group_2 TIM3

#define TIM_Group_1_CLK RCC_APB1Periph_TIM4
#define TIM_Group_2_CLK RCC_APB1Periph_TIM3
//TIM4_CH1
#define DJ1_GPIO_CLK RCC_APB2Periph_GPIOB
#define DJ1_GPIO_PORT GPIOB
#define DJ1_GPIO_PIN GPIO_Pin_6
//TIM4_CH2
#define DJ2_GPIO_CLK RCC_APB2Periph_GPIOB
#define DJ2_GPIO_PORT GPIOB
#define DJ2_GPIO_PIN GPIO_Pin_7
//TIM4_CH3
#define DJ3_GPIO_CLK RCC_APB2Periph_GPIOB
#define DJ3_GPIO_PORT GPIOB
#define DJ3_GPIO_PIN GPIO_Pin_8
//TIM4_CH4
#define DJ4_GPIO_CLK RCC_APB2Periph_GPIOB
#define DJ4_GPIO_PORT GPIOB
#define DJ4_GPIO_PIN GPIO_Pin_9
//TIM3_CH1
#define DJ5_GPIO_CLK RCC_APB2Periph_GPIOA
#define DJ5_GPIO_PORT GPIOA
#define DJ5_GPIO_PIN GPIO_Pin_6
//TIM3_CH2
#define DJ6_GPIO_CLK RCC_APB2Periph_GPIOA
#define DJ6_GPIO_PORT GPIOA
#define DJ6_GPIO_PIN GPIO_Pin_7
//TIM3_CH3
#define DJ7_GPIO_CLK RCC_APB2Periph_GPIOB
#define DJ7_GPIO_PORT GPIOB
#define DJ7_GPIO_PIN GPIO_Pin_0
//TIM3_CH4
#define DJ8_GPIO_CLK RCC_APB2Periph_GPIOB
#define DJ8_GPIO_PORT GPIOB
#define DJ8_GPIO_PIN GPIO_Pin_1

void Servo_Config(void);
void Servo_Angle(int angle1, int angle2, int angle3, int angle4, int angle5, int angle6, int angle7, int angle8);

#endif
