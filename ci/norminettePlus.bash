# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    norminettePlus.bash                                :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/01 16:19:41 by pholster       #+#    #+#                 #
#    Updated: 2019/10/01 16:19:41 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

function norm {
	python ~/norminette+/run.py $1 | grep --color=never -E "(Error|Warning: [^N])" -B 1
}

norm "`find . -name "Makefile"`"
norm "`find src -name "*.c"`"
