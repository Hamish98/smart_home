cmake_minimum_required(VERSION 3.10)

project(SmartHome)

# === 编译标准 ===
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === 开启编译器警告（建议开发时打开）===
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter")

# === 第三方库根目录 ===
set(THIRD_PARTY_LIB_PREFIX /root/proj/3th_lib/bin)

# === 头文件路径 ===
include_directories(
    ${THIRD_PARTY_LIB_PREFIX}/include
)

# === 库文件路径 ===
link_directories(
    ${THIRD_PARTY_LIB_PREFIX}/lib
    ${THIRD_PARTY_LIB_PREFIX}/lib64
)

message(STATUS "Include directories: ${THIRD_PARTY_LIB_PREFIX}/include")
message(STATUS "Library directories: ${THIRD_PARTY_LIB_PREFIX}/lib")
message(STATUS "Library directories: ${THIRD_PARTY_LIB_PREFIX}/lib64")

# === 构建 & 安装时 RPATH 设置（确保运行时找到 .so 文件）===
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "${THIRD_PARTY_LIB_PREFIX}/lib;${THIRD_PARTY_LIB_PREFIX}/lib64")
set(CMAKE_BUILD_RPATH "${THIRD_PARTY_LIB_PREFIX}/lib;${THIRD_PARTY_LIB_PREFIX}/lib64")
set(CMAKE_SKIP_BUILD_RPATH FALSE)

add_subdirectory(message_hub)
add_subdirectory(device_manager)
