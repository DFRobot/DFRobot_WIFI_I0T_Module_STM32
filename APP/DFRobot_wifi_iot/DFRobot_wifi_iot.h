#ifndef _DFROBOT_WIFI_IOT_H
#define _DFROBOT_WIFI_IOT_H
#include "usart.h"
#include "system.h"
#include "SysTick.h"

/**
 * @brief 配置MQTT连接
 * @param url  物联网连接
 * @param port  物联网端口号
 * @param iotid 物联网账号
 * @param iotpwd 物联网账号密码
 * @param topic  订阅频道
 */
void mqtt(const char* url, const char *port, const char *iotid, const char *iotpwd , const char *topic);
/**
 * @brief 监听发送到物联网平台数据
 */
void loop(void);
/**
 * @brief 发送数据到MQTT服务器 
 * @param data 发送数据
 */
void publish(const char *topic,const char *masag);
/**
 * @brief 使用HTTP post协议发送数据到IFTTT
 * @param data 发送数据
 */
void IFTTTSendMasage(const char *data1, const char *data2, const char *data3);
/**
 * @brief 使用HTTP get协议发送数据到ThingSpeak
 * @param key  连接服务器密钥
 * @param data 发送数据
 */
void thingSpeakSendMasage(const char *data1, const char *data2);
/**
 * @brief 处理接收到数据
 */
void splitString(void);
/**
 * @brief wifi连接函数
 * @param ssid wifi名称
 * @param pwd  wifi密码
 */
void connectWifi(const char *ssid , const char *pwd);
/**
 * @brief 配置IFTTT
 * @param event 事件
 * @param key   密钥
 */
void configIFTTT(const char *event , const char *key);
/**
 * @brief 配置thingSpeak
 * @param key   密钥
 */
void configThingSpeak(const char *key);

#endif
