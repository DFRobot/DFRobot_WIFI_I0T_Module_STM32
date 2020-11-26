#include "DFRobot_wifi_iot.h"


//MQTT配置
void mqtt(const char *ssid , const char *pwd, const char* url, const char *port, const char *iotid, const char* iotpwd)
{
	char *data = " ";
	strcat(data,"|2|1|");
	strcat(data,_ssid);
	strcat(data,",");
	strcat(data,_pwd);
	strcat(data,"|\r");
	Usart_SendStriong(USART3, data);
	while(strcmp("|2|1|",Data_RX_BUF) != 0){
		printf(".");
	}
	printf("Wifi Connect SUCCESS");
	char *data = " ";
	strcat(data,"|4|1|1|");
	strcat(data,_url);
	strcat(data,"|");
	strcat(data,_port);
	strcat(data,"|");
	strcat(data,_iotid);
	strcat(data,"|");
	strcat(data,_iotpwd);
	strcat(data,"|\r");
	Usart_SendStriong(USART3, data);
	while(strcmp("|4|1|1|1|",Data_RX_BUF) != 0){
		printf(".");
	}
	printf("MQTT Connect SUCCESS");

	
}
//设置回调函数
void setCallBack(callback call)
{
	_call = call;
}


