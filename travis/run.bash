#!/bin/bash

function linuxRun {
	xvfb-run --server-args="-screen 0 1920x1080x24" make test GCOV=TRUE
}

function osxRun {
	make test GCOV=TRUE
}

if [ -z $TRAVIS ] || [[ $TRAVIS != true ]]; then
	echo "Error: Not running travis"
elif [[ $TRAVIS_OS_NAME == "linux" ]]; then
	linuxRun
elif [[ $TRAVIS_OS_NAME == "osx" ]]; then
	osxRun
else
	echo "Error: OS is not supported"
fi
