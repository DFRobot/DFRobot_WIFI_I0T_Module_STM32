/*!
 * @file 
 * @brief 本例程使用串口和IOT模块通信，向不同的IOT平台发送数据
 * @copyright    Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence      The MIT License (MIT)
 * @author       [tang](jie.tang@dfrobot.com)
 * @version      V1.0
 * @eGDAte       2020-08-21
 * @get          from https://www.dfrobot.com
 * @url          https://github.com/DFRobot/DFRobot_WiFi_IOT_Module(STM32)
 */
#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "DFRobot_wifi_iot.h"

//wifi 
#define WIFISSID     "hitest"  //WiFi名称
#define WIFIPWS      "12345678" //wifi密码

//MQTT
//#define MQTT
#ifdef MQTT
#define SERVER        "iot.dfrobot.com.cn"  //服务器地址
#define PORT          "1883"                //端口号
#define DEVICENAME    "rHpr0RcWR"           //用户名称
#define DEVICESECRET  "9NtrAg5ZRz"          //用户登录密码
#define TOPIC         "OSpwrHHMg"           //订阅频道
#endif

//IFTTT
#define IFTTT
#ifdef IFTTT
#define IFTTTKEY      "dtpfTlU3Wqa8y0HRh77xXE"
#define IFTTTEVENT    "BBB"
#endif

//ThingSpeak
//#define THINGSPEAK
#ifdef THINGSPEAK
#define THINGSPEAKKEY "U01NPZTC2G9WTDNY"
#endif

int main()
{
	u8 i=0;  
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
	LED_Init();
	//USB打印串口 ，串口对应引脚:RX对应PA10、TX对应引脚PA9
	USART1_Init(9600);
	//IOT通信串口 ，串口对应引脚：RX对应PB11、TX对应引脚PB10
	USART3_Init(9600);
	//连接wifi
	connectWifi(WIFISSID,WIFIPWS);
	
	//访问EASYIOT
	#ifdef MQTT
	mqtt(SERVER,PORT,DEVICENAME,DEVICESECRET,TOPIC);
	#endif
	
	#ifdef IFTTT
	configIFTTT(IFTTTEVENT,IFTTTKEY);
	#endif
	
	#ifdef THINGSPEAK
	configThingSpeak(THINGSPEAKKEY);
	#endif
	while(1){
		
		#ifdef MQTT
		//使用MQTT时发送数
		publish(TOPIC,"HI TANG");
		#endif
		#ifdef IFTTT
		//访问IFTTT 向IFTTT注册事件发送信息
		IFTTTSendMasage("100","78","78");
		#endif
		#ifdef THINGSPEAK
		//访问thingSpeak  向thingSpeak发送信息
		thingSpeakSendMasage("5000", "100");
		#endif
		i+=10;
		if(i%20==0)
		{
			i=0;
			led1=!led1;
		}
		
		delay_ms(100);
		loop();
	}
}

