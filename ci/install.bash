#!/bin/bash

if [[ $0 =~ $PWD ]]; then
	SELF_LOCATION=$0
else
	SELF_LOCATION="$PWD/$0"
fi
SELF_LOCATION=`echo "$SELF_LOCATION" | rev | cut -d"/" -f 2- | rev`

function linuxInstall {
	sudo add-apt-repository -y ppa:snaipewastaken/ppa
	sudo apt-get update
	sudo apt-get install -y libsdl2-dev
	sudo apt-get install -y libsdl2-ttf-dev
	sudo apt-get install -y criterion-dev

	sudo apt-get install -y libmodplug-dev libvorbis-dev libmpg123-dev
	sudo apt-get install -y libflac-dev libopus-dev libsdl2-mixer-dev
	sudo apt-get install -y libpulse-dev
}

function osxInstall {
	export HOMEBREW_NO_AUTO_UPDATE=1
	brew install SDL2
	brew install SDL2_ttf
	brew install snaipe/soft/criterion

	bash $SELF_LOCATION/osx/installMixer.bash
	brew install Caskroom/cask/soundflower switchaudio-osx
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
