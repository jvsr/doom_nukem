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

#include "gui.h"
#include "sdl_extra.h"

void		draw_image(t_transform *elem)
{
	t_image	*image;

	image = elem->gui_elem.image;
	if (image->draw_method == COLOR)
		sdl_fill_surface_color(elem->surface, image->color);
	else if (image->draw_method == FIXED)
		sdl_merge_surface(elem->surface, image->texture, (SDL_Point){0, 0});
	else
		sdl_merge_surface_scaled(elem->surface, image->texture);
}
