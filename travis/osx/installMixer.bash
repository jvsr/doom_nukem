#!/bin/bash

if [[ $0 =~ $PWD ]]; then
	SELF_LOCATION=$0
else
	SELF_LOCATION="$PWD/$0"
fi
SELF_LOCATION=`echo "$SELF_LOCATION" | rev | cut -d"/" -f 2- | rev`

function UpdateXcode {
	if [ -z $TRAVIS ] || [[ $TRAVIS != true ]]; then
	# touch /tmp/.com.apple.dt.CommandLineTools.installondemand.in-progress
	PROD=`softwareupdate -l | grep "\*.*Command Line" | head -n 1 |
		awk -F"*" '{print $2}' | sed -e 's/^ *//' | tr -d '\n'`
	softwareupdate -i "$PROD" --verbose
	# rm /tmp/.com.apple.dt.CommandLineTools.installondemand.in-progress
	fi
}

UpdateXcode
brew install pkg-config
brew install --build-from-source "$SELF_LOCATION/sdl2_mixer"
brew link sdl2_mixer flac opus mpg123 pkg-config libmodplug libvorbis
