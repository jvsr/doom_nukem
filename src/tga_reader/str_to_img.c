/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strtoimg.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 21:36:50 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/17 16:08:34 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_memory.h"

#include "tga.h"

void		str_to_img(t_img img, t_tga *tga, unsigned char *str)
{
	size_t i;
	size_t j;
	size_t size;
	size_t max;
	const size_t tga_header_size = 19;

	i = tga_header_size + tga->id_len;
	if (tga->clr_map_type == 2)
		i += tga->cm_len * (tga->cm_size / 4);
	size = img.px_depth / 8;
	img.pixels = (unsigned int*)ft_memalloc(sizeof(unsigned int) *
				(img.height * img.width));
	max = (img.height * img.width * size) + i;
	j = 0;
	while (i < max)
	{
		img.pixels[j] = pixel_from_pos(str, i, img);
		i += size;
		j++;
	}
}
