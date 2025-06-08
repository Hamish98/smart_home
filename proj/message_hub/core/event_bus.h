#ifndef EVENT_BUS_H
#define EVENT_BUS_H

#include "event.h"
#include <functional>
#include <string>

class EventBus {
public:
    virtual ~EventBus() {}
    virtual void publish(const Event& event) = 0;
    virtual void subscribe(const std::string& event_type, std::function<void(const Event&)> callback) = 0;
};

#endif // EVENT_BUS_H