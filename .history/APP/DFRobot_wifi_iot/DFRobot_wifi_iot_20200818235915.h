#ifndef _DFROBOT_WIFI_IOT_H
#define _DFROBOT_WIFI_IOT_H
#include <usart.h>
#include <string.h>

u8 wifiConet(char *SSD, char *PWD);

u8 begin(void);
void mqtt(const char *ssid , const char *pwd, const char* url, const char *port, const char *iotid, const char* iotpwd);

typedef void (*callback)(const char *topic, const char *message);
void setCallBack(callback call);
void updata(void);
	

#endif
