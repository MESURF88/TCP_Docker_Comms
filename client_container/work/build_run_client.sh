#!/bin/bash
IPADDR=$1
PORT=$2
MESSAGE_NUM=$3

if [ -d build ]
then
	rm -rf build
fi
mkdir build
cd build
cmake ..
make
cd ..
exec ./target/bin/client $IPADDR $PORT $MESSAGE_NUM;
