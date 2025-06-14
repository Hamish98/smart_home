#ifndef STORAGE_FACTORY_H
#define STORAGE_FACTORY_H

#include <soci/soci.h>
#include <string>

class storageFactory {
public:
    static void createTables(soci::session& sql) {
        // 设备表
        sql << "CREATE TABLE IF NOT EXISTS devices ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "name VARCHAR(100) NOT NULL,"
               "unique_id VARCHAR(100) UNIQUE NOT NULL,"
               "manufacturer VARCHAR(100),"
               "model VARCHAR(100),"
               "protocol VARCHAR(50),"
               "area_id INTEGER,"
               "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,"
               "updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,"
               ");";

        // 设备连接信息表
        sql << "CREATE TABLE IF NOT EXISTS device_connections ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "device_id INTEGER NOT NULL,"
               "connection_type VARCHAR(50),"
               "connection_info TEXT,"
               "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,"
               "FOREIGN KEY (device_id) REFERENCES devices(id) ON DELETE CASCADE"
               ");";

        // 实体表
        sql << "CREATE TABLE IF NOT EXISTS entities ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "device_id INTEGER NOT NULL,"
               "entity_id VARCHAR(100) UNIQUE NOT NULL,"
               "name VARCHAR(100),"
               "platform VARCHAR(50),"
               "state VARCHAR(50),"
               "attributes TEXT,"
               "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,"
               "updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,"
               ");";
    }
};

#endif // STORAGE_FACTORY_H