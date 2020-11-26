#ifndef _DFROBOT_WIFI_IOT_H
#define _DFROBOT_WIFI_IOT_H
#include <usart.h>
#include <string.h>

void mqtt(const char *ssid , const char *pwd, const char* url, const char *port, const char *iotid, const char *iotpwd , const char *topic);
void loop(void);
void publish(const char *data);
void IFTTT(const char *ssid , const char *pwd, const char *url, const char *data)；

#endif
