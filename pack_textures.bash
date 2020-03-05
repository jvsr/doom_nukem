# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    pack_textures.bash                                 :+:    :+:             #
#                                                      +:+                     #
#    By: jvisser <jvisser@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/05 14:32:06 by jvisser        #+#    #+#                 #
#    Updated: 2020/03/05 15:14:32 by jvisser       ########   odam.nl          #
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
echo $ext
resources+=$(find resources -name "*.$ext")
resources+=" "
done

for file in $resources; do
size=$(stat -f%z $file)
cat $file >> doom-nukem
echo $size >> doom-nukem
pad=$((24-${#size}))
echo $size
echo $pad
dd if=/dev/zero bs=1 count=$pad >> doom-nukem
echo $file
done
# echo $resources

# dd if=/dev/zero bs=1 count=5 >> test.test