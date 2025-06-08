#/bin/bash
set -e

echo "构建mosquitto容器"
cd ./mosquitto/
chmod +x ./build.sh
./build.sh
cd ..

echo "构建ubuntu容器"
cd ./ubuntu/
chmod +x ./build.sh
./build.sh
cd ..

