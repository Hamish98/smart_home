add_library(message_hub SHARED
    core/event_bus_factory.cpp
    backends/mqtt/mqtt_event_bus.cpp
    # 其它需要的 cpp 文件
)

target_include_directories(message_hub PUBLIC
    ${PROJECT_SOURCE_DIR}/core
    ${PROJECT_SOURCE_DIR}/backends/mqtt
    /root/proj/3th_lib/bin/include
)

target_link_directories(message_hub PUBLIC
    /root/proj/3th_lib/bin/lib
    /root/proj/3th_lib/bin/lib64
)

target_link_libraries(message_hub
    paho-mqttpp3
    paho-mqtt3as
    pthread
)

# 测试程序依赖动态库
add_executable(test_mqtt_event_bus
    test/test_mqtt_event_bus.cpp
)
target_link_libraries(test_mqtt_event_bus message_hub)
target_include_directories(test_mqtt_event_bus PRIVATE ${PROJECT_SOURCE_DIR})