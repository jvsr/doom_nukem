# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    get_headers.bash                                   :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/29 14:12:35 by pholster       #+#    #+#                 #
#    Updated: 2019/09/29 14:12:35 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

TARGET_FILES=$2

#Includes and Src path (dont trail with /)
INCLUDES_PATH=$1
ALL_INCLUDES=""
for FILE in $TARGET_FILES; do
	INCLUDES=`cat $FILE | grep "#include \""`
	INCLUDES=`echo "$INCLUDES" | cut -d" " -f2 | sed 's/\"//g'`
	INCLUDES=`echo "$INCLUDES" | sed "s,^,$INCLUDES_PATH/,g"`

	if [[ $ALL_INCLUDES == "" ]]; then
		ALL_INCLUDES=$INCLUDES
	else
		ALL_INCLUDES=$ALL_INCLUDES"\n"$INCLUDES
	fi
done

ALL_INCLUDES=`echo -e "$ALL_INCLUDES" | sort -u`
echo -e "$ALL_INCLUDES"
