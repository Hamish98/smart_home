#ifndef MQTT_DRIVER_H
#define MQTT_DRIVER_H

#include <string>

class mqttDriver
{
private:
    std::string host;  // MQTT服务器地址
    int port;          // MQTT服务器端口
    std::string clientId; // 客户端ID

    // 连接到MQTT服务器
    bool connect(const std::string& host, int port, const std::string& clientId);

    // 断开连接
    void disconnect();

    // 发布消息
    bool publish(const std::string& topic, const std::string& message);

    // 订阅主题
    bool subscribe(const std::string& topic);  

    // 取消订阅主题
    bool unsubscribe(const std::string& topic);

public:
    mqttDriver(/* args */);
    ~mqttDriver();

    
};

#endif // MQTT_DRIVER_H