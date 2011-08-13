#!/bin/sh

BUILD_DIR="_build"

[ -d ${BUILD_DIR} ] || mkdir ${BUILD_DIR}

cd ${BUILD_DIR} && cmake ../ && make


