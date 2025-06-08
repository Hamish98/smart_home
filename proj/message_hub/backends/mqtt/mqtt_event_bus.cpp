#include "mqtt_event_bus.h"
#include "../../core/event_types.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <thread>
#include <chrono>

MqttEventBus::MqttEventBus(const std::string& uri) {
    // 只用 uri 初始化 client，用户名密码等可根据需要扩展
    client_ = std::make_unique<mqtt::async_client>(uri, "");
    client_->set_callback(*this);
    ensure_connected();
}

MqttEventBus::~MqttEventBus() {
    try {
        if (connected_) client_->disconnect()->wait();
    } catch (...) {}
}

void MqttEventBus::ensure_connected() {
    while (!connected_) {
        try {
            client_->connect(conn_opts_)->wait();
            connected_ = true;
        } catch (const mqtt::exception& e) {
            std::cerr << "MQTT连接失败，重试中: " << e.what() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

void MqttEventBus::publish(const Event& event) {
    ensure_connected();
    nlohmann::json j;
    j["type"] = event.type;
    j["data"] = event.data;
    auto msg = mqtt::make_message(event.type, j.dump());
    client_->publish(msg);
}

void MqttEventBus::subscribe(const std::string& event_type, std::function<void(const Event&)> callback) {
    ensure_connected();
    {
        std::lock_guard<std::mutex> lock(mtx_);
        subscribers_[event_type].push_back(callback);
    }
    client_->subscribe(event_type, 1)->wait();
}

void MqttEventBus::connection_lost(const std::string& cause) {
    connected_ = false;
    std::cerr << "MQTT连接丢失: " << cause << std::endl;
    ensure_connected();
}

void MqttEventBus::message_arrived(mqtt::const_message_ptr msg) {
    Event evt;
    try {
        auto j = nlohmann::json::parse(msg->to_string());
        evt.type = j.value("type", msg->get_topic());
        evt.data = j.value("data", std::map<std::string, std::string>());
    } catch (...) {
        evt.type = msg->get_topic();
        evt.data["raw"] = msg->to_string();
    }
    std::lock_guard<std::mutex> lock(mtx_);
    auto it = subscribers_.find(evt.type);
    if (it != subscribers_.end()) {
        for (auto& cb : it->second) {
            cb(evt);
        }
    }
}