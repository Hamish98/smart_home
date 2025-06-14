#ifndef _MODEL_ENTITY_H_
#define _MODEL_ENTITY_H_

#include <string>

struct Entity
{
    std::string id;           // Entity ID (primary key)
    std::string device_id;    // Device ID (foreign key)
    std::string entity_id;    // Unique entity identifier
    std::string name;         // Entity name
    std::string platform;     // Platform (e.g., sensor, switch)
    std::string state;        // Current state
    std::string attributes;   // Attributes (JSON or string)
    std::string created_at;   // Creation timestamp
    std::string updated_at;   // Update timestamp
};

#endif // _MODEL_ENTITY_H_