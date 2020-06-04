# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    installMixer.bash                                  :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/01 16:19:49 by pholster      #+#    #+#                  #
#    Updated: 2019/10/01 16:19:49 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

if [[ $0 =~ $PWD ]]; then
	SELF_LOCATION=$0
else
	SELF_LOCATION="$PWD/$0"
fi
SELF_LOCATION=`echo "$SELF_LOCATION" | rev | cut -d"/" -f 2- | rev`

function updateXcode {
	# touch /tmp/.com.apple.dt.CommandLineTools.installondemand.in-progress

	PROD=`softwareupdate -l | grep "\*.*Command Line" | head -n 1 |
		awk -F"*" '{print $2}' | sed -e 's/^ *//' | tr -d '\n'`
	softwareupdate -i "$PROD" --verbose

	rm -f /tmp/.com.apple.dt.CommandLineTools.installondemand.in-progress
}

if [ -z $GITHUB_ACTION ]; then
	updateXcode
fi

brew install pkg-config
brew install libmodplug libvorbis mpg123 flac opus
brew reinstall --build-from-source "$SELF_LOCATION/sdl2_mixer.rb"
brew link sdl2_mixer flac opus mpg123 pkg-config libmodplug libvorbis
