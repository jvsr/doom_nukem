#!/bin/bash

function linuxInstall {
}

function osxInstall {
}

if [ -z $TRAVIS ] || [[ $TRAVIS != true ]]; then
    echo "Error: Not running travis"
elif [[ $TRAVIS_OS_NAME == "linux" ]]; then
    linuxInstall
elif [[ $TRAVIS_OS_NAME == "osx" ]]; then
    osxInstall
else
    echo "Error: OS is not supported"
fi
