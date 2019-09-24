/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_to_img.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 21:36:50 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/17 16:35:24 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "libft/ft_mem.h"

#include "tga.h"
#include "error.h"

void		str_to_img(t_img *img, t_tga *tga, unsigned char *str)
{
	size_t			i;
	size_t			j;
	size_t			max;
	const size_t	tga_header_size = 19;
	const size_t	pitch = img->px_depth / 8;

	i = tga_header_size + tga->id_len;
	if (tga->clr_map_type == 2)
		i += tga->cm_len * (tga->cm_size / 4);
	img->pixels = (unsigned int*)ft_memalloc(sizeof(unsigned int) *
				(img->height * img->width));
	if (img->pixels == NULL)
		error_msg(strerror(errno), errno, "Failed to allocate tga pixels");
	max = (img->height * img->width * pitch) + i;
	j = 0;
	while (i < max)
	{
		img->pixels[j] = pixel_from_pos(str, i, img);
		i += pitch;
		j++;
	}
}
