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
	printf("Wifi Connect SUCCESS\n");
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
	printf("MQTT Connect SUCCESS\n");
	char *data = " ";
	strcat(data,"|4|1|2|");
	strcat(data,topic);
	strcat(data,"|\r");
	Usart_SendStriong(USART3, data);
	while(strcmp("|4|1|2|1|",Data_RX_BUF) != 0){
		printf(".");
	}
	printf("Subscribe Topic SUCCESS\n");
}

void publish(const char *data){
	char *data = " ";
	strcat(data,"|4|1|3|");
	strcat(data,data);
	strcat(data,"|\r");
	Usart_SendStriong(USART3, data);
	while(strcmp("|4|1|3|1|",Data_RX_BUF) != 0){
		printf("Failed to send\n");
	}
	printf("Successfully sent\n");
}

void loop(void){
	char *data[];
	u8 count = 0;
	data[count] = strtok(Data_RX_BUF, '|');
	while(data[count])
  {
    data[++count] = strtok(NULL, '|');
  }

	if(data[0] == "4"){
		if(data[2] == "5"){
			printf("topic:")
			printf(data[3]);
			printf("masage:");
			printf(data[4]);
		}
	}
}


