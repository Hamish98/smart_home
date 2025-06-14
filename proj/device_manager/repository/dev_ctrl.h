#ifndef DEVICE_CTRL_H
#define DEVICE_CTRL_H

#include <soci/soci.h>
#include <string>
#include <vector>
#include "../model/dev_model.h"

class devCtrl
{
private:
    soci::session& sql;
public:
    devCtrl(soci::session& sqlSession) : sql(sqlSession) {}

    // 新增设备
    bool createDevice(const Device& device) {
        try {
            sql << "INSERT INTO devices (name, unique_id, manufacturer, model, protocol, area_id) "
                   "VALUES (:name, :unique_id, :manufacturer, :model, :protocol, :area_id)",
                soci::use(device.name),
                soci::use(device.unique_id),
                soci::use(device.manufacturer),
                soci::use(device.model),
                soci::use(device.protocol),
                soci::use(device.area_id);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 更新设备
    bool updateDevice(const Device& device) {
        try {
            sql << "UPDATE devices SET name = :name, unique_id = :unique_id, manufacturer = :manufacturer, "
                   "model = :model, protocol = :protocol, area_id = :area_id, updated_at = CURRENT_TIMESTAMP "
                   "WHERE id = :id",
                soci::use(device.name),
                soci::use(device.unique_id),
                soci::use(device.manufacturer),
                soci::use(device.model),
                soci::use(device.protocol),
                soci::use(device.area_id),
                soci::use(device.id);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 删除设备
    bool deleteDevice(int deviceId) {
        try {
            sql << "DELETE FROM devices WHERE id = :id", soci::use(deviceId);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 查询单个设备
    bool getDevice(int deviceId, Device& device) {
        try {
            soci::indicator ind;
            sql << "SELECT id, name, unique_id, manufacturer, model, protocol, area_id, created_at, updated_at "
                   "FROM devices WHERE id = :id",
                soci::into(device.id, ind),
                soci::into(device.name, ind),
                soci::into(device.unique_id, ind),
                soci::into(device.manufacturer, ind),
                soci::into(device.model, ind),
                soci::into(device.protocol, ind),
                soci::into(device.area_id, ind),
                soci::into(device.created_at, ind),
                soci::into(device.updated_at, ind),
                soci::use(deviceId);
            return ind == soci::i_ok;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 查询所有设备
    std::vector<Device> getAllDevices() {
        std::vector<Device> devices;
        soci::rowset<soci::row> rs = (sql.prepare << "SELECT id, name, unique_id, manufacturer, model, protocol, area_id, created_at, updated_at FROM devices");
        for (const auto& row : rs) {
            Device device;
            device.id = row.get<int>(0);
            device.name = row.get<std::string>(1);
            device.unique_id = row.get<std::string>(2);
            device.manufacturer = row.get<std::string>(3, "");
            device.model = row.get<std::string>(4, "");
            device.protocol = row.get<std::string>(5, "");
            device.area_id = row.get<int>(6);
            device.created_at = row.get<std::string>(7, "");
            device.updated_at = row.get<std::string>(8, "");
            devices.push_back(device);
        }
        return devices;
    }
};

#endif // DEVICE_CTRL_H