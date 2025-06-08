message_hub/
├── core/                              # 框架核心，抽象接口与工厂
│   ├── event.h                        # 事件结构体
│   ├── event_types.h                  # 事件类型常量
│   ├── event_bus.h                    # 消息总线抽象基类
│   ├── event_bus_factory.h            # 工厂方法声明
│   └── event_bus_factory.cpp          # 工厂方法实现
├── backends/                          # 各通信后端实现与接口
│   ├── local/
│   │   ├── local_event_bus.h
│   │   └── local_event_bus.cpp
│   ├── mqtt/
│   │   ├── mqtt_event_bus.h
│   │   └── mqtt_event_bus.cpp
│   ├── dds/
│   │   ├── dds_event_bus.h
│   │   └── dds_event_bus.cpp
│   ├── grpc/
│   │   ├── grpc_event_bus.h
│   │   └── grpc_event_bus.cpp
│   └── ipc/
│       ├── ipc_event_bus.h
│       └── ipc_event_bus.cpp
├── CMakeLists.txt
└── README.md