#ifndef ENTITY_CTRL_H
#define ENTITY_CTRL_H

#include <soci/soci.h>
#include <string>
#include <vector>
#include "../model/entity.h"

class entityCtrl
{
private:
    soci::session& sql;
public:
    entityCtrl(soci::session& sqlSession) : sql(sqlSession) {}

    // 新增实体
    bool createEntity(const Entity& entity) {
        try {
            sql << "INSERT INTO entities (device_id, entity_id, name, platform, state, attributes) "
                   "VALUES (:device_id, :entity_id, :name, :platform, :state, :attributes)",
                soci::use(entity.device_id),
                soci::use(entity.entity_id),
                soci::use(entity.name),
                soci::use(entity.platform),
                soci::use(entity.state),
                soci::use(entity.attributes);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 更新实体
    bool updateEntity(const Entity& entity) {
        try {
            sql << "UPDATE entities SET name = :name, platform = :platform, state = :state, attributes = :attributes, updated_at = CURRENT_TIMESTAMP "
                   "WHERE id = :id",
                soci::use(entity.name),
                soci::use(entity.platform),
                soci::use(entity.state),
                soci::use(entity.attributes),
                soci::use(entity.id);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 删除实体
    bool deleteEntity(int entityId) {
        try {
            sql << "DELETE FROM entities WHERE id = :id", soci::use(entityId);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 查询单个实体
    bool getEntity(int entityId, Entity& entity) {
        try {
            soci::indicator ind;
            sql << "SELECT id, device_id, entity_id, name, platform, state, attributes, created_at, updated_at "
                   "FROM entities WHERE id = :id",
                soci::into(entity.id, ind),
                soci::into(entity.device_id, ind),
                soci::into(entity.entity_id, ind),
                soci::into(entity.name, ind),
                soci::into(entity.platform, ind),
                soci::into(entity.state, ind),
                soci::into(entity.attributes, ind),
                soci::into(entity.created_at, ind),
                soci::into(entity.updated_at, ind),
                soci::use(entityId);
            return ind == soci::i_ok;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 查询某设备的所有实体
    std::vector<Entity> getEntitiesByDevice(int deviceId) {
        std::vector<Entity> entities;
        soci::rowset<soci::row> rs = (sql.prepare << "SELECT id, device_id, entity_id, name, platform, state, attributes, created_at, updated_at FROM entities WHERE device_id = :device_id", soci::use(deviceId));
        for (const auto& row : rs) {
            Entity entity;
            entity.id = row.get<int>(0);
            entity.device_id = row.get<int>(1);
            entity.entity_id = row.get<std::string>(2, "");
            entity.name = row.get<std::string>(3, "");
            entity.platform = row.get<std::string>(4, "");
            entity.state = row.get<std::string>(5, "");
            entity.attributes = row.get<std::string>(6, "");
            entity.created_at = row.get<std::string>(7, "");
            entity.updated_at = row.get<std::string>(8, "");
            entities.push_back(entity);
        }
        return entities;
    }
};

#endif // ENTITY_CTRL_H