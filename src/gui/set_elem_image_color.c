/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_image_color.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 17:05:26 by pholster       #+#    #+#                */
/*   Updated: 2019/09/18 17:05:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>

#include "gui.h"

void	set_elem_image_color(t_transform *elem, SDL_Color color)
{
	t_image	*image;

	if (elem->gui_type == IMAGE)
		image = elem->gui_elem.image;
	else
		image = elem->gui_elem.button->image;
	image->color = color;
	image->draw_method = COLOR;
	elem->has_alpha = (color.a != 255);
	set_elem_redraw(elem);
}
