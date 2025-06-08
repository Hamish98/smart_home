#/bin/sh

set -e

INSTALL_DIR="/root/proj/3th_lib/bin"

# 安装依赖
apt-get update
apt-get install -y libsqlite3-dev libpq-dev unixodbc-dev libboost-all-dev pkg-config zlib1g-dev

# 清理旧构建
rm -rf build
mkdir build
cd build

# 配置编译参数
cmake -DSOCI_SHARED=ON \
        -DSOCI_STATIC=OFF \
        -DSOCI_TESTS=OFF \
        -DSOCI_SQLITE3=ON \
        -DSOCI_POSTGRESQL=ON \
        -DSOCI_ODBC=OFF \
        -DSOCI_MYSQL=OFF \
        -DCMAKE_INSTALL_PREFIX="$INSTALL_DIR" \
        ..

# 编译并安装
make -j$(nproc)
make install
echo "soci 已安装到 $INSTALL_DIR"