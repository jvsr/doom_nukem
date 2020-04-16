# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    pack_textures.bash                                 :+:    :+:             #
#                                                      +:+                     #
#    By: jvisser <jvisser@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/05 14:32:06 by jvisser       #+#    #+#                  #
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

resources+=$(find resources/data/map/campaign -type f)
resources+=$'\n'
for ext in "${extensions[@]}"; do
resources+=$(find resources -type f -name "*.$ext")
resources+=$'\n'
done

IFS=$'\n' resources=( $resources )

dd if=/dev/zero bs=1 count=128 >> doom-nukem

for file in "${resources[@]}"; do
if [[ -z "$file" ]]; then
	continue
fi

cat "$file" >> doom-nukem

if [[ $(uname -s) == "Darwin" ]]; then
	size=$(stat -f%z "$file")
else
	size=$(du -bs "$file" | column -t | cut -d' ' -f1)
fi

echo "$size"
echo -n "$size" >> doom-nukem
pad=$((24-${#size}))
echo $pad
dd if=/dev/zero bs=1 count=$pad >> doom-nukem

echo "$file"
echo -n "$file" >> doom-nukem
pad=$((128-${#file}))
dd if=/dev/zero bs=1 count=$pad >> doom-nukem

done
