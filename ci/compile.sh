#!/bin/bash

export BRANCH=$(git rev-parse --abbrev-ref HEAD)
export COMMIT_TAG=$(git describe --abbrev=0 --tags)
export CD_ENVIROMENT=$CD_ENVIROMENT

echo "BRANCH: ${BRANCH}"
echo "COMMIT_TAG: ${COMMIT_TAG}"
echo "CI_COMMIT_SHORT_SHA: ${CI_COMMIT_SHORT_SHA}"
echo "APP_VERSION: ${APP_VERSION}"


if [ -z ${APP_VERSION+x} ]; then 
    if [ -n ${COMMIT_TAG+x} ] && [ "$BRANCH" = "master" ]; then
        export APP_VERSION=$COMMIT_TAG
    elif [ "$BRANCH" = "stage" ] && [ -n ${COMMIT_TAG+x} ]; then
        export APP_VERSION="v${COMMIT_TAG}_RC"
    else 
        export APP_VERSION="v${CI_COMMIT_SHORT_SHA}_SNAPSHOT"
    fi
fi

echo "Generating app configuration..."
echo "CI_COMMIT_REF_NAME: ${CI_COMMIT_REF_NAME}"
cd App

rm conf.hpp
eval "echo \"$(cat conf.hpp.template)\"" > conf.hpp

cd .. 

echo "Instaling Arduino Libs"
arduino-cli lib install "MySensors"
arduino-cli lib install "Bounce2"

echo "Compile Arduino App"
arduino-cli compile --fqbn arduino:avr:mega App