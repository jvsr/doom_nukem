# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    run.bash                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/01 16:19:41 by pholster       #+#    #+#                 #
#    Updated: 2019/10/01 16:19:41 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

function linuxRun {
	xvfb-run --server-args="-screen 0 1920x1080x24" make test GCOV=TRUE
}

function osxRun {
	make test GCOV=TRUE
}

OS_NAME=`uname -s`
if [ -z $GITHUB_ACTION ]; then
	echo "Error: Not running travis"
	exit 1
elif [[ $OS_NAME == "Linux" ]]; then
	linuxRun
elif [[ $OS_NAME == "Darwin" ]]; then
	osxRun
else
	echo "Error: OS is not supported"
	exit 1
fi
