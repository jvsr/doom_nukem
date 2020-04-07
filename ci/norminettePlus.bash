# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    norminettePlus.bash                                :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/01 16:19:41 by pholster      #+#    #+#                  #
#    Updated: 2019/10/01 16:19:41 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

function norm {
	local NORM=`python ~/norminette+/run.py $1 | grep --color=never -E "(Error: [^N])" -B 1`

	if [[ $NORM != "" ]]; then
		echo "$NORM"
		exit 1
	fi
}

norm "`find . -name "Makefile"`"
norm "`find src -name "*.c"`"
exit 0
