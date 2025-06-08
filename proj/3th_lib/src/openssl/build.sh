#!/bin/bash
# filepath: /root/proj/3th_lib/src/openssl/build.sh

set -e

INSTALL_DIR="/root/proj/3th_lib/bin"

# 进入源码目录
cd "$(dirname "$0")"

apt-get update

apt-get install -y perl

# 配置
./Configure --prefix="$INSTALL_DIR" linux-x86_64

# 编译
make -j$(nproc)

# 安装
make install_sw

echo "OpenSSL 3.0.16 已安装到 $INSTALL_DIR"