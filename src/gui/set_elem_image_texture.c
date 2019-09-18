/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_image_texture.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 17:05:26 by pholster       #+#    #+#                */
/*   Updated: 2019/09/18 17:05:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_video.h>

#include "libft/ft_bool.h"

#include "gui.h"

static t_bool	has_alpha(SDL_Surface *texture)
{
	size_t			index;
	char			*color_stream;
	const size_t	pixels = texture->pitch * texture->h;

	index = 0;
	color_stream = (char *)texture->pixels;
	while (index < pixels)
	{
		if (color_stream[index] != 0)
			return (TRUE);
		index += 4;
	}
	return (FALSE);
}

void			set_elem_image_texture(t_transform *elem, SDL_Surface *texture)
{
	t_image	*image;

	if (elem->gui_type == IMAGE)
		image = elem->gui_elem.image;
	else
		image = elem->gui_elem.button->image;
	image->texture = texture;
	elem->has_alpha = has_alpha(texture);
	set_elem_redraw(elem);
}
