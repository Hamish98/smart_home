#ifndef _MODEL_DEVICE_CONN_H_
#define _MODEL_DEVICE_CONN_H_

#include <string>

struct DevConn
{
    std::string id;               // Connection ID
    std::string device_id;        // Device ID (foreign key)
    std::string conn_type;  // Connection type (e.g., WiFi, Zigbee)
    std::string conn_info;  // Connection parameters (JSON or string)
    std::string created_at;       // Creation timestamp
};

#endif // _MODEL_DEVICE_CONN_H_