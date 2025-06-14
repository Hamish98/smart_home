#ifndef _MODEL_DEVICE_H_
#define _MODEL_DEVICE_H_

#include <string>

struct Dev
{
    std::string id;            // Device ID
    std::string name;          // Device name
    std::string unique_id;     // Unique identifier for the device
    std::string manufacturer;  // Manufacturer of the device
    std::string model;         // Model of the device
    std::string protocol;      // Protocol type (e.g., Zigbee, WiFi, Bluetooth)
    std::string area_id;       // Area ID (foreign key to areas table)
    std::string created_at;    // Creation timestamp
    std::string updated_at;    // Update timestamp
};

#endif // _MODEL_DEVICE_H_