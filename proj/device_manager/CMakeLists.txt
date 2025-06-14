# 包含头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(/root/proj/3th_lib/bin/include)

link_directories(
    /root/proj/3th_lib/bin/lib
    /root/proj/3th_lib/bin/lib64
)

# 只编译测试程序
add_executable(test_db
    tests/test_db.cpp
)

# 关键：链接 SOCI 的 core 和 sqlite3 子库
target_link_libraries(test_db
    soci_core
    soci_sqlite3
    sqlite3
    pthread
)