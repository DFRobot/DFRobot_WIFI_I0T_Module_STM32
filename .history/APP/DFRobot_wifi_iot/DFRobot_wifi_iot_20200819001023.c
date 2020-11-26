#include "DFRobot_wifi_iot.h"


const char *_ssid;
const char *_pwd;
const char *_url;
const char *_port;
const char *_iotid;
const char *_iotpwd;
callback _call;

typedef enum{
		IOT_PING,
		IOT_CONNECTWIFI,
		IOT_CONNECTMQTT,
		IOT_OK
	}ewifiIot;
	ewifiIot state = IOT_PING;
//MQTT配置
void mqtt(const char *ssid , const char *pwd, const char* url, const char *port, const char *iotid, const char* iotpwd)
{
	_ssid   = ssid;
	_pwd    = pwd;
  _iotid  = iotid;
	_iotpwd = iotpwd;
	_url    = url;
	_port   = port;
}
//设置回调函数
void setCallBack(callback call)
{
	_call = call;
}

//数据处理

void updata(void)
{
	char *data;
	if(state == IOT_PING){
		Usart_SendStriong(USART3, "|1|1|\r");
		if(strcmp("|1|1|",Data_RX_BUF) != 0){
			state = IOT_CONNECTWIFI;
		}else{
			state = IOT_PING;
		}
	}else if(state == IOT_CONNECTWIFI)
	{
		strcat(data,"|2|1|");
		strcat(data,_ssid);
		strcat(data,",");
		strcat(data,_pwd);
		strcat(data,"|\r");
		Usart_SendStriong(USART3, data);
		while(1){
			if(strcmp("|2|1|",Data_RX_BUF) == 0){
				state = IOT_CONNECTWIFI;
				break;
			}else if(strcmp("|2|3|",Data_RX_BUF) == 0){
				state = IOT_CONNECTMQTT;
				break;
			}else if(strcmp("|2|4|",Data_RX_BUF) == 0){
				printf("Check whether SSID and PWD are input correctly");
			}else if(strcmp("|2|2|",Data_RX_BUF) == 0){
				printf(".");
			}
		}
	}else if(state == IOT_CONNECTMQTT){
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
		while(1){
			if(strcmp("|4|1|1|1|",Data_RX_BUF) == 0){
				state = IOT_OK;
				break;
			}else if(strcmp("|4|1|1|2|",Data_RX_BUF) == 0){
			}
		}
	}
	
	
}



u8 begin(void)
{
	Usart_SendStriong(USART3, "|1|1|\r");
	if(strcmp("|1|1|",Data_RX_BUF) != 0){
		return 1;
	}else{
		return 0;
	}
}







