-- 设备表
CREATE TABLE devices (
    id            INTEGER PRIMARY KEY AUTOINCREMENT,
    name          VARCHAR(100) NOT NULL,
    unique_id     VARCHAR(100) UNIQUE NOT NULL,
    manufacturer  VARCHAR(100),
    model         VARCHAR(100),
    protocol      VARCHAR(50), -- 设备接入协议，如 Zigbee/WiFi/Bluetooth
    area_id       INTEGER,
    created_at    TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at    TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
);

-- 设备连接信息表
CREATE TABLE device_connections (
    id                INTEGER PRIMARY KEY AUTOINCREMENT,
    device_id         INTEGER NOT NULL,
    connection_type   VARCHAR(50),         -- 如 WiFi, Zigbee, Bluetooth
    connection_info   TEXT,                -- 连接参数(JSON)
    created_at        TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (device_id) REFERENCES devices(id) ON DELETE CASCADE
);

-- 实体表
CREATE TABLE entities (
    id            INTEGER PRIMARY KEY AUTOINCREMENT,
    device_id     INTEGER NOT NULL,
    entity_id     VARCHAR(100) UNIQUE NOT NULL,
    name          VARCHAR(100),
    platform      VARCHAR(50),             -- 如 sensor, switch
    state         VARCHAR(50),
    attributes    TEXT,                    -- JSON 格式
    created_at    TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at    TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
);
