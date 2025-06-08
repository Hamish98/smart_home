#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <map>

struct Event {
    std::string type;
    std::map<std::string, std::string> data;
};

#endif // EVENT_H