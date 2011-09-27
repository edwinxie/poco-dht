#!/bin/sh

BUILD_DIR="_build"

[ -d ${BUILD_DIR} ] || exit 1

cd ${BUILD_DIR}/src/node/ && ./node ../../../etc/node.ini

