# pragma once
#include "event_bus_factory.h"
#include "event_types.h"
#include <memory>
#include <functional>
#include <string>

class MessageHub {
public:
    MessageHub(BusBackend backend, const std::string& config)
        : bus_(create_event_bus(backend, config)) {}

    virtual ~MessageHub() {}

    // 发布事件
    void publish(const Event& evt) {
        if (bus_) bus_->publish(evt);
    }

    // 订阅事件
    void subscribe(const std::string& event_type, std::function<void(const Event&)> callback) {
        if (bus_) bus_->subscribe(event_type, callback);
    }

protected:
    std::shared_ptr<EventBus> bus_;
};