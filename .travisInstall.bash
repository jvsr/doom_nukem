#!/bin/bash

function linuxInstall {
	sudo add-apt-repository -y ppa:snaipewastaken/ppa
	sudo apt-get update
	sudo apt-get install -y libsdl2-dev
	sudo apt-get install -y criterion-dev

	sudo apt-get install -y xvfb
	export DISPLAY=':99.0'
	Xvfb :99 -screen 0 1920x1080x24 > /dev/null 2>&1 &
}

function osxInstall {
	export HOMEBREW_NO_AUTO_UPDATE=1
	brew install SDL2
	brew install snaipe/soft/criterion
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
