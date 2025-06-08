#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "mqtt/async_client.h"

const std::string SERVER_ADDRESS = "mqtt://10.7.0.4:1883";
const std::string CLIENT_ID = "paho_cpp_client";
const std::string TOPIC = "test/topic";

const int QOS = 1;
const auto TIMEOUT = std::chrono::seconds(10);

class callback : public virtual mqtt::callback {
public:
    void connected(const std::string& cause) override {
        std::cout << "Connected: " << cause << std::endl;
    }

    void connection_lost(const std::string& cause) override {
        std::cout << "Connection lost: " << cause << std::endl;
    }

    void message_arrived(mqtt::const_message_ptr msg) override {
        std::cout << "Message arrived:\n"
                  << "  topic: " << msg->get_topic() << "\n"
                  << "  payload: " << msg->to_string() << "\n";
    }
};

int main() {
    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);
    callback cb;
    client.set_callback(cb);

    mqtt::connect_options connOpts;
    connOpts.set_clean_session(true);

    try {
        std::cout << "Connecting to the MQTT server..." << std::endl;
        client.connect(connOpts)->wait();
        std::cout << "Connected." << std::endl;

        std::cout << "Subscribing to topic: " << TOPIC << std::endl;
        client.subscribe(TOPIC, QOS)->wait();

        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::string payload = "Hello from Paho C++!";
        auto msg = mqtt::make_message(TOPIC, payload);
        msg->set_qos(QOS);

        std::cout << "Publishing message..." << std::endl;
        client.publish(msg)->wait();

        // 等待消息到达
        std::this_thread::sleep_for(std::chrono::seconds(5));

        std::cout << "Disconnecting..." << std::endl;
        client.disconnect()->wait();
        std::cout << "Disconnected." << std::endl;
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return 1;
    }

    return 0;
}
