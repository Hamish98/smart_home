#!/bin/bash
# filepath: /root/proj/3th_lib/src/json/build.sh

set -e

INSTALL_DIR="/root/proj/3th_lib/bin"

# 进入源码目录
cd "$(dirname "$0")"

# 清理旧构建
rm -rf build
mkdir build
cd build

# 配置编译参数，指定 OpenSSL 路径
cmake .. \
    -DCMAKE_INSTALL_PREFIX="$INSTALL_DIR"

# 编译并安装
make -j$(nproc)
make install

echo "nlohmann/json 已安装到 $INSTALL_DIR"