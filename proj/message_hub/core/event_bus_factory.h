#ifndef EVENT_BUS_FACTORY_H
#define EVENT_BUS_FACTORY_H

#include "event_bus.h"
#include <memory>
#include <string>

enum class BusBackend {
    MQTT
};

std::shared_ptr<EventBus> create_event_bus(BusBackend backend, const std::string& config = "");

#endif // EVENT_BUS_FACTORY_H