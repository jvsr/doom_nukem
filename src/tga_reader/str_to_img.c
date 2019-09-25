/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_to_img.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 21:36:50 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/25 15:51:13 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "libft/ft_mem.h"
#include "tga.h"
#include "error.h"

static void	bottomleft(t_img *img, t_tga *tga, unsigned char *str)
{
	size_t			i;
	size_t			j;
	size_t			min;
	const size_t	tga_header_size = 19;
	const size_t	pitch = img->px_depth / 8;

	min = tga_header_size + tga->id_len;
	if (tga->clr_map_type == 2)
		min += tga->cm_len * (tga->cm_size / 4);
	i = (img->height * img->width * pitch) + min - pitch;
	j = 0;
	while (min < i)
	{
		img->pixels[j] = pixel_from_pos(str, i, img);
		i -= pitch;
		j++;
	}
}

static void	topleft(t_img *img, t_tga *tga, unsigned char *str)
{
	size_t			i;
	size_t			j;
	size_t			max;
	const size_t	tga_header_size = 19;
	const size_t	pitch = img->px_depth / 8;

	i = tga_header_size + tga->id_len;
	if (tga->clr_map_type == 2)
		i += tga->cm_len * (tga->cm_size / 4);
	max = (img->height * img->width * pitch) + i;
	j = 0;
	while (i < max)
	{
		img->pixels[j] = pixel_from_pos(str, i, img);
		i += pitch;
		j++;
	}
}

void		str_to_img(t_img *img, t_tga *tga, unsigned char *str)
{
	img->pixels = (unsigned int*)ft_memalloc(sizeof(unsigned int) *
		(img->height * img->width));
	if (img->pixels == NULL)
		error_msg(strerror(errno), errno, "Failed to allocate tga pixels");
	if ((img->origin & 0x20) == 0)
		bottomleft(img, tga, str);
	else
		topleft(img, tga, str);
}
