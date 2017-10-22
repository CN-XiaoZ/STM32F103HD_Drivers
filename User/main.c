#include "stm32f10x.h"
#include "usart.h"
#include "delay.h"


/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  USART_Config();
	delay_init();
	

  while(1)
	{	
		
	}	
}
/*********************************************END OF FILE**********************/
