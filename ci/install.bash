# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    install.bash                                       :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/01 16:19:45 by pholster      #+#    #+#                  #
#    Updated: 2019/10/01 16:19:45 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

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
}

function osxInstall {
	export HOMEBREW_NO_AUTO_UPDATE=1
	brew install SDL2
	brew install SDL2_ttf
	brew install snaipe/soft/criterion

	bash $SELF_LOCATION/osx/installMixer.bash
}

function generalInstall {
	if [ -n $GITHUB_ACTION ]; then
		git clone https://github.com/thijsdejong/codam-norminette-plus ~/norminette+
	fi
}

OS_NAME=`uname -s`
if [[ $OS_NAME == "Linux" ]]; then
	linuxInstall
	generalInstall
elif [[ $OS_NAME == "Darwin" ]]; then
	osxInstall
	generalInstall
else
	echo "Error: OS: '$OS_NAME' is not supported"
	exit 1
fi
