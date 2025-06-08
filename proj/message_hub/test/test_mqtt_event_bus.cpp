#include "../core/message_hub.h"
#include <iostream>
#include <thread>
#include <chrono>

class MyApp : public MessageHub {
public:
    MyApp(const std::string& mqtt_url)
        : MessageHub(BusBackend::MQTT, mqtt_url) {}

    void start() {
        subscribe(EventTypes::STATE_CHANGED, [this](const Event& evt) {
            on_state_changed(evt);
        });

        Event evt;
        evt.type = EventTypes::STATE_CHANGED;
        evt.data["entity_id"] = "light.living_room";
        evt.data["state"] = "on";
        publish(evt);
    }

    void on_state_changed(const Event& evt) {
        std::cout << "[MyApp] 收到状态变化事件: ";
        for (const auto& kv : evt.data) {
            std::cout << kv.first << "=" << kv.second << " ";
        }
        std::cout << std::endl;
    }
};



int main() {
    // 创建应用实例，连接到 MQTT 服务器
    MyApp app("tcp://192.168.2.57:1883");

    // 启动应用，订阅事件并发布一个状态变化事件
    app.start();

    // 模拟等待一段时间以接收事件
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}