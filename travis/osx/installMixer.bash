#!/bin/bash

function UpdateXcode {
	touch /tmp/.com.apple.dt.CommandLineTools.installondemand.in-progress

	PROD=`softwareupdate -l | grep "\*.*Command Line" | head -n 1 |
		awk -F"*" '{print $2}' | sed -e 's/^ *//' | tr -d '\n'`
	softwareupdate -i "$PROD" --verbose

	rm /tmp/.com.apple.dt.CommandLineTools.installondemand.in-progress
}

UpdateXcode
brew install pkg-config
brew install --build-from-source "sdl2_mixer.rb"
brew link sdl2_mixer flac opus mpg123 pkg-config libmodplug libvorbis
