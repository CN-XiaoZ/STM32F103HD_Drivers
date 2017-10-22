#ifndef __MOTOR_H
#define __MOTOR_H


#include "stm32f10x.h"

#define LA1_GPIO_PORT    GPIOA
#define LA1_GPIO_CLK     RCC_APB2Periph_GPIOA 
#define LA1_GPIO_PIN     GPIO_Pin_0

#define LA2_GPIO_PORT    GPIOA
#define LA2_GPIO_CLK     RCC_APB2Periph_GPIOA
#define LA2_GPIO_PIN     GPIO_Pin_4

#define LB1_GPIO_PORT    GPIOA
#define LB1_GPIO_CLK     RCC_APB2Periph_GPIOA
#define LB1_GPIO_PIN     GPIO_Pin_1

#define LB2_GPIO_PORT    GPIOA
#define LB2_GPIO_CLK     RCC_APB2Periph_GPIOA
#define LB2_GPIO_PIN     GPIO_Pin_5

#define RA1_GPIO_PORT   GPIOA
#define RA1_GPIO_CLK    RCC_APB2Periph_GPIOA
#define RA1_GPIO_PIN    GPIO_Pin_2

#define RA2_GPIO_PORT   GPIOC
#define RA2_GPIO_CLK    RCC_APB2Periph_GPIOC
#define RA2_GPIO_PIN    GPIO_Pin_4

#define RB1_GPIO_PORT   GPIOA
#define RB1_GPIO_CLK    RCC_APB2Periph_GPIOA
#define RB1_GPIO_PIN    GPIO_Pin_3

#define RB2_GPIO_PORT   GPIOC
#define RB2_GPIO_CLK    RCC_APB2Periph_GPIOC
#define RB2_GPIO_PIN    GPIO_Pin_5


void Motor_Config(void);
void Set_Speed(uint32_t LA,uint32_t LB,uint32_t RA,uint32_t RB);
void Motor_Control(int32_t LA,int32_t LB,int32_t RA,int32_t RB);
void Motor_FWD(void);
void Motor_BEH(void);
void Motor_STOP(void);

#endif
