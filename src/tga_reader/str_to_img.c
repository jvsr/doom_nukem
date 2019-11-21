/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_to_img.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 21:36:50 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/12 18:24:54 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/ft_mem.h"

#include "tga.h"
#include "error.h"

static void	bottomright(t_img *img, t_tga *tga, unsigned char *str)
{
	size_t			i;
	size_t			j;
	size_t			min;
	const size_t	pitch = img->px_depth / 8;

	min = TGA_HEADER_SIZE + tga->id_len;
	if (tga->clr_map_type == 2)
		min += tga->cm_len * (tga->cm_size / 4);
	i = (img->height * img->width * pitch) + min;
	j = 0;
	while (min < i)
	{
		i -= pitch;
		img->pixels[j] = pixel_from_pos(str, i, img);
		j++;
	}
}

static void	bottomleft(t_img *img, t_tga *tga, unsigned char *str)
{
	size_t			i;
	size_t			j;
	size_t			min;
	const size_t	pitch = img->px_depth / 8;

	min = TGA_HEADER_SIZE + tga->id_len;
	if (tga->clr_map_type == 2)
		min += tga->cm_len * (tga->cm_size / 4);
	i = ((img->height - 1) * img->width * pitch) + min;
	j = 0;
	while (j != (size_t)(img->width * img->height))
	{
		img->pixels[j] = pixel_from_pos(str, i, img);
		i += pitch;
		j++;
		if (j != 0 && j % img->width == 0)
			i -= (img->width * pitch) * 2;
	}
}

static void	topleft(t_img *img, t_tga *tga, unsigned char *str)
{
	size_t			i;
	size_t			j;
	size_t			max;
	const size_t	pitch = img->px_depth / 8;

	i = TGA_HEADER_SIZE + tga->id_len;
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

static void	topright(t_img *img, t_tga *tga, unsigned char *str)
{
	size_t			i;
	size_t			j;
	size_t			max;
	size_t			min;
	const size_t	pitch = img->px_depth / 8;

	min = TGA_HEADER_SIZE + tga->id_len;
	if (tga->clr_map_type == 2)
		min += tga->cm_len * (tga->cm_size / 4);
	max = (img->height * img->width * pitch) + min;
	j = img->width * img->height - 1;
	i = min + (img->width * pitch);
	while (i < max)
	{
		i -= pitch;
		img->pixels[j] = pixel_from_pos(str, i, img);
		if (i - min == 0 || (i - min) % (img->width * pitch) == 0)
			i += (img->width * pitch) * 2;
		j--;
	}
}

void		str_to_img(t_img *img, t_tga *tga, unsigned char *str)
{
	img->pixels = (unsigned int*)ft_memalloc(sizeof(unsigned int) *
		(img->height * img->width));
	if (img->pixels == NULL)
		error_msg_errno("Failed to allocate tga pixels");
	if ((img->origin & 0x30) == 0x00)
		bottomleft(img, tga, str);
	else if ((img->origin & 0x30) == 0x10)
		bottomright(img, tga, str);
	else if ((img->origin & 0x30) == 0x20)
		topleft(img, tga, str);
	else
		topright(img, tga, str);
}
