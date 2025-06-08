#ifndef MQTT_EVENT_BUS_H
#define MQTT_EVENT_BUS_H

#include "../../core/event_bus.h"
#include <mqtt/async_client.h>
#include <memory>
#include <map>
#include <vector>
#include <mutex>

class MqttEventBus : public EventBus, public virtual mqtt::callback {
public:
    explicit MqttEventBus(const std::string& uri); // 修改为字符串
    ~MqttEventBus();

    void publish(const Event& event) override;
    void subscribe(const std::string& event_type, std::function<void(const Event&)> callback) override;

    void connection_lost(const std::string& cause) override;
    void message_arrived(mqtt::const_message_ptr msg) override;
    void delivery_complete(mqtt::delivery_token_ptr) override {}

private:
    std::unique_ptr<mqtt::async_client> client_;
    mqtt::connect_options conn_opts_;
    std::map<std::string, std::vector<std::function<void(const Event&)>>> subscribers_;
    std::mutex mtx_;
    bool connected_ = false;

    void ensure_connected();
};

#endif // MQTT_EVENT_BUS_H