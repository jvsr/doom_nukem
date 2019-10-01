#!/bin/bash

function linuxRun {
	xvfb-run --server-args="-screen 0 1920x1080x24" make test GCOV=TRUE
}

function osxRun {
	SwitchAudioSource -s "Soundflower (2ch)" -t input
	SwitchAudioSource -s "Soundflower (2ch)" -t output

	make test GCOV=TRUE
}

OS_NAME=`uname -s`
if [ -z $GITHUB_ACTION ]; then
	echo "Error: Not running travis"
	exit 1
elif [[ $OS_NAME == "linux" ]]; then
	linuxRun
elif [[ $OS_NAME == "Darwin" ]]; then
	osxRun
else
	echo "Error: OS is not supported"
	exit 1
fi
