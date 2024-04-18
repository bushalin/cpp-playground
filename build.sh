#!/bin/bash

## Project global variables
NPROC=$(nproc)
ARCH=`uname -m`
APP_NAME="OpenCVExample"

## Set up directories
PROJECT_DIR=$(pwd)
BUILD_DIR=${PROJECT_DIR}/build

rm -rf ${BUILD_DIR}/*
mkdir -p ${BUILD_DIR} && cd ${BUILD_DIR}

cmake \
    -S $PROJECT_DIR \
    -DBUILD_TARGET=$ARCH \
    -DAPP_NAME=$APP_NAME \

make -j $NPROC
