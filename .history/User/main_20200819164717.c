
#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "DFRobot_wifi_iot.h"

int main()
{
	u8 i=0;  
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //?§Ø?????????? ??2??
	LED_Init();
	USART1_Init(9600);
	USART3_Init(9600);
	printf("start");
	mqtt("ChinaNet-2Rj5","279k2jjh","iot.dfrobot.com.cn","1883","rHpr0RcWR","9NtrAg5ZRz","F2zNkDuZR");
	
	while(1){
		publish("HI TANG");
		i++;
		if(i%20==0)
		{
			led1=!led1;
		}
		delay_ms(10);
	}
	loop();
}
