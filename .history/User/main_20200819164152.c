
#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "DFRobot_wifi_iot.h"

int main()
{
	u8 i=0;  
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	USART3_Init(9600);
	printf("start");
	mqtt();
	//Usart_SendStriong(USART3,"|2|1|ChinaNet-2Rj5,279k2jjh|\r");
	//delay_ms(100);
	
	while(1){
		//printf("%s",Data_RX_BUF);
		//delay_ms(100);
	
		i++;
		if(i%20==0)
		{
			led1=!led1;
		}
		delay_ms(10);
	}
}
