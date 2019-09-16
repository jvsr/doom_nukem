/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 16:23:52 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:59:38 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_memory.h"

#include "gui.h"
#include "color.h"

static void	draw_color(t_transform *elem, t_image *image)
{
	size_t			index;
	int				*color_stream;
	const Uint32	color_value = color_to_rgba(image->color);
	const size_t	pixels = elem->surface->w * elem->surface->h;

	index = 0;
	color_stream = (int*)elem->surface->pixels;
	while (index < pixels)
	{
		color_stream[index] = color_value;
		index++;
	}
}

void		draw_image(t_transform *elem)
{
	t_image	*image;

	image = elem->gui_elem.image;
	if (image->draw_method == COLOR)
		draw_color(elem, image);
}
