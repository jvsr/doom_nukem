/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_colormap.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 18:50:13 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/21 20:17:26 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "wad.h"
#include "error.h"
#include "serializer.h"

#define COLORMAP_SIZE 256

// static void				print_colormap(t_wad_colormap *colormap)
// {
// 	size_t i;

// 	i = 0;
// 	while (i < colormap->color_amount)
// 	{
// 		printf("I:%zu, B:%d\n",
// 			i,
// 			colormap->color[i]);
// 		i++;
// 	}
// }

static void				alloc_colormap(t_wad_general *wad_general, size_t colormap_amount)
{
	size_t	i;

	wad_general->colormap_amount = colormap_amount;
	wad_general->colormap = (t_wad_colormap**)ft_memalloc(sizeof(t_wad_colormap*) * colormap_amount);
	if (wad_general->colormap == NULL)
		error_msg_errno("Failed to allocate colormap");
	i = 0;
	while (i < colormap_amount)
	{
		wad_general->colormap[i] = (t_wad_colormap*)ft_memalloc(sizeof(t_wad_colormap));
		if (wad_general->colormap[i] == NULL)
			error_msg_errno("Failed to allocate colormap single");
		i++;
	}
}

static void				alloc_color(t_wad_colormap *colormap, size_t color_amount)
{
	colormap->color_amount = color_amount;
	colormap->color = (uint8_t*)ft_memalloc(sizeof(uint8_t) * colormap->color_amount);
	if (colormap->color == NULL)
			error_msg_errno("Failed to allocate colormap colors");
}

static void				fill_wad_colormap(t_binary_read *wad_bin, t_wad_colormap *colormap)
{
	size_t			i;

	alloc_color(colormap, COLORMAP_SIZE);
	i = 0;
	while (i < colormap->color_amount)
	{
		colormap->color[i] = read_char(wad_bin);
		i++;
	}
}

void	parse_wad_colormap(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory)
{
	size_t	i;

	if (directory->size_lump % COLORMAP_SIZE == 0)
		alloc_colormap(wad_general, directory->size_lump / COLORMAP_SIZE);
	else
		error_msg("Failed to parse WAD map", 25, "Invalid COLORMAP lump");
	i = 0;
	while (i < wad_general->colormap_amount)
	{
		wad_bin->content_pos = directory->loc_lump + i * COLORMAP_SIZE;
		fill_wad_colormap(wad_bin, wad_general->colormap[i]);
		// print_colormap(wad_general->colormap[i]);
		i++;
	}
}