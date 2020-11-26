#include "DFRobot_wifi_iot.h"


/**
 * @brief 配置MQTT连接
 * @param ssid wifi名称
 * @param pwd  wifi密码
 * @param url  物联网连接
 * @param port  物联网端口号
 * @param iotid 物联网账号
 * @param iotpwd 物联网账号密码
 * @param topic  订阅频道
 */
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
/**
 * @brief 发送数据到MQTT服务器 
 * @param data 发送数据
 */
void publish(const char *data)
{
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

/**
 * @brief 监听发送到物联网平台数据
 */
void loop(void)
{
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
/**
 * @brief 使用HTTP post协议发送数据到IFTTT
 */
void IFTTT(const char *ssid , const char *pwd, const char *url, const char *data)
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
	strcat(data,"|3|2|");
	strcat(data,url);
	strcat(data,",");
	strcat(data,data);
	strcat(data,"|\r");
	Usart_SendStriong(USART3, data);
}

/**
 * @brief 使用HTTP get协议发送数据到ThingSpeak
 */
void thingSpeak(const char *ssid , const char *pwd, const char *url)
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
	strcat(data,"|3|2|");
	strcat(data,url);
	Usart_SendStriong(USART3, data);
}