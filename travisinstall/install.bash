#!/bin/bash

LOCATION=`echo "$PWD/$0" | rev | cut -d"/" -f 2- | rev`

xcode-select --install
sleep 1
osascript <<EOD
  tell application "System Events"
    tell process "Install Command Line Developer Tools"
      keystroke return
      click button "Agree" of window "License Agreement"
    end tell
  end tell
EOD

brew install pkg-config
brew install --build-from-source "$LOCATION/sdl2_mixer"
brew link sdl2_mixer