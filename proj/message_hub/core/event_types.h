#ifndef EVENT_TYPES_H
#define EVENT_TYPES_H

#include <string>

namespace EventTypes {
    // 设备与实体
    const std::string STATE_CHANGED = "state_changed";
    const std::string ENTITY_REGISTRY_UPDATED = "entity_registry_updated";
    const std::string DEVICE_REGISTRY_UPDATED = "device_registry_updated";

    // 自动化与脚本
    const std::string AUTOMATION_TRIGGERED = "automation_triggered";
    const std::string SCRIPT_STARTED = "script_started";
    const std::string SCRIPT_STOPPED = "script_stopped";

    // 服务调用
    const std::string CALL_SERVICE = "call_service";

    // 时间与调度
    const std::string TIME_CHANGED = "time_changed";
    const std::string TIMER_STARTED = "timer_started";
    const std::string TIMER_FINISHED = "timer_finished";

    // 系统
    const std::string SYSTEM_START = "system_start";
    const std::string SYSTEM_STOP = "system_stop";
    const std::string SYSTEM_RESTART = "system_restart";
    const std::string NOTIFICATIONS_UPDATED = "persistent_notifications_updated";

    // 前端与用户
    const std::string LOVELACE_UPDATED = "lovelace_updated";
    const std::string MOBILE_APP_NOTIFICATION_ACTION = "mobile_app_notification_action";

    // 自定义事件
    // 用户可自定义其它事件类型
}

#endif // EVENT_TYPES_H