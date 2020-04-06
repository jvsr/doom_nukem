/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_image_color.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 17:05:26 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:12:50 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>

#include "libft/ft_mem.h"

#include "gui.h"

void	set_elem_image_color(t_transform *elem, SDL_Color color)
{
	t_image	*image;

	if (elem->gui_type == IMAGE)
		image = elem->gui_elem.image;
	else
		image = elem->gui_elem.button->image;
	image->draw_method = COLOR;
	elem->has_alpha = (color.a != 255);
	ft_memcpy(&image->color, &color, sizeof(SDL_Color));
	set_elem_redraw(elem);
}
