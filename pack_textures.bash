# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    pack_textures.bash                                 :+:    :+:             #
#                                                      +:+                     #
#    By: jvisser <jvisser@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/05 14:32:06 by jvisser        #+#    #+#                 #
#    Updated: 2020/03/06 15:51:23 by jvisser       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

declare -a extensions=(
    "tga"
    "ui.yml"
    "ttf"
    "wav"
    "mp3"
)
resources=

for ext in ${extensions[@]}; do
resources+=$(find resources -name "*.$ext")
resources+=" "
done

dd if=/dev/zero bs=1 count=128 >> doom-nukem

for file in $resources; do
cat $file >> doom-nukem

size=$(du -bs $file | column -t | cut -d' ' -f1)
echo $size
echo -n $size >> doom-nukem
pad=$((24-${#size}))
echo $pad
dd if=/dev/zero bs=1 count=$pad >> doom-nukem

echo $file
echo -n $file >> doom-nukem
pad=$((128-${#file}))
dd if=/dev/zero bs=1 count=$pad >> doom-nukem

done
