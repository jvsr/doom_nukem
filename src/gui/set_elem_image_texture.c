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

#include "gui.h"
#include "sdl_extra.h"

void	set_elem_image_texture(t_transform *elem, SDL_Surface *texture)
{
	t_image	*image;

	if (elem->gui_type == IMAGE)
		image = elem->gui_elem.image;
	else
		image = elem->gui_elem.button->image;
	image->texture = texture;
	if (image->draw_method == COLOR)
		image->draw_method = SCALED;
	elem->has_alpha = sdl_has_surface_alpha(texture);
	set_elem_redraw(elem);
}
