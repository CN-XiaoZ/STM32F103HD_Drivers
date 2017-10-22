#ifndef __UTL_H
#define __UTL_H

#include "stm32f10x.h"

#define TRIG_GPIO_PORT GPIOC
#define TRIG_GPIO_CLK RCC_APB2Periph_GPIOC
#define TRIG_GPIO_PIN GPIO_Pin_0

#define ECHO_GPIO_PORT GPIOC
#define ECHO_GPIO_CLK RCC_APB2Periph_GPIOC
#define ECHO_GPIO_PIN GPIO_Pin_2

#define TRIG_H TRIG_GPIO_PORT->BSRR = TRIG_GPIO_PIN //拉高
#define TRIG_L TRIG_GPIO_PORT->BRR = TRIG_GPIO_PIN  //拉低

void Ultrasound_Config(void);
float Ultrasound_Measure(void);

#endif
