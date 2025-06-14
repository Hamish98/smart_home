#ifndef DEVICE_CONN_CTRL_H
#define DEVICE_CONN_CTRL_H

#include <soci/soci.h>
#include <string>
#include <vector>
#include "../model/device_connection.h"

class deviceConnCtrl
{
private:
    soci::session& sql;
public:
    deviceConnCtrl(soci::session& sqlSession) : sql(sqlSession) {}

    // 新增设备连接信息
    bool createDeviceConnection(const DeviceConnection& conn) {
        try {
            sql << "INSERT INTO device_connections (device_id, connection_type, connection_info) "
                   "VALUES (:device_id, :connection_type, :connection_info)",
                soci::use(conn.device_id),
                soci::use(conn.connection_type),
                soci::use(conn.connection_info);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 更新设备连接信息
    bool updateDeviceConnection(const DeviceConnection& conn) {
        try {
            sql << "UPDATE device_connections SET connection_type = :connection_type, "
                   "connection_info = :connection_info "
                   "WHERE id = :id",
                soci::use(conn.connection_type),
                soci::use(conn.connection_info),
                soci::use(conn.id);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 删除设备连接信息
    bool deleteDeviceConnection(int connId) {
        try {
            sql << "DELETE FROM device_connections WHERE id = :id", soci::use(connId);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 查询单个设备连接信息
    bool getDeviceConnection(int connId, DeviceConnection& conn) {
        try {
            soci::indicator ind;
            sql << "SELECT id, device_id, connection_type, connection_info, created_at "
                   "FROM device_connections WHERE id = :id",
                soci::into(conn.id, ind),
                soci::into(conn.device_id, ind),
                soci::into(conn.connection_type, ind),
                soci::into(conn.connection_info, ind),
                soci::into(conn.created_at, ind),
                soci::use(connId);
            return ind == soci::i_ok;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 查询某设备的所有连接信息
    std::vector<DeviceConnection> getConnectionsByDevice(int deviceId) {
        std::vector<DeviceConnection> connections;
        soci::rowset<soci::row> rs = (sql.prepare << "SELECT id, device_id, connection_type, connection_info, created_at FROM device_connections WHERE device_id = :device_id", soci::use(deviceId));
        for (const auto& row : rs) {
            DeviceConnection conn;
            conn.id = row.get<int>(0);
            conn.device_id = row.get<int>(1);
            conn.connection_type = row.get<std::string>(2, "");
            conn.connection_info = row.get<std::string>(3, "");
            conn.created_at = row.get<std::string>(4, "");
            connections.push_back(conn);
        }
        return connections;
    }
};

#endif // DEVICE_CONN_CTRL_H