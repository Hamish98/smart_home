#include "event_bus_factory.h"
#include "../backends/mqtt/mqtt_event_bus.h"

std::shared_ptr<EventBus> create_event_bus(BusBackend backend, const std::string& config) {
    switch (backend) {
        case BusBackend::MQTT:
            if (!config.empty()) {
                return std::make_shared<MqttEventBus>(config);
            }
            // 默认配置
            return std::make_shared<MqttEventBus>("tcp://localhost:1883");
        default:
            return nullptr;
    }
}