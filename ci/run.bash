# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    run.bash                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/01 16:19:41 by pholster      #+#    #+#                  #
#    Updated: 2019/10/01 16:19:41 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

function linuxRun {
	:
}

function osxRun {
	:
}

OS_NAME=`uname -s`
if [[ $OS_NAME == "Linux" ]]; then
	linuxRun
elif [[ $OS_NAME == "Darwin" ]]; then
	osxRun
else
	echo "Error: OS: '$OS_NAME' is not supported"
	exit 1
fi
