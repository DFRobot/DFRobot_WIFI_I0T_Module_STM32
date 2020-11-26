#include "DFRobot_wifi_iot.h"


//MQTT≈‰÷√
void mqtt(const char *ssid , const char *pwd, const char* url, const char *port, const char *iotid, const char *iotpwd , const char *topic)
{
	char *data = " ";
	strcat(data,"|2|1|");
	strcat(data,ssid);
	strcat(data,",");
	strcat(data,pwd);
	strcat(data,"|\r");
	Usart_SendStriong(USART3, data);
	while(strcmp("|2|1|",Data_RX_BUF) != 0){
		printf(".");
	}
	printf("Wifi Connect SUCCESS");
	char *data = " ";
	strcat(data,"|4|1|1|");
	strcat(data,url);
	strcat(data,"|");
	strcat(data,port);
	strcat(data,"|");
	strcat(data,iotid);
	strcat(data,"|");
	strcat(data,iotpwd);
	strcat(data,"|\r");
	Usart_SendStriong(USART3, data);
	while(strcmp("|4|1|1|1|",Data_RX_BUF) != 0){
		printf(".");
	}
	printf("MQTT Connect SUCCESS");
	char *data = " ";
	strcat(data,"|4|1|2|");
	strcat(data,topic);
	strcat(data,"|\r");
	Usart_SendStriong(USART3, data);
	while(strcmp("|4|1|2|1|",Data_RX_BUF) != 0){
		printf(".");
	}
	printf("Subscribe Topic SUCCESS");
}

void publish(){
	
}



