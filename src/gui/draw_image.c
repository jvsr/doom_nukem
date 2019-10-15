/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 16:23:52 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/17 17:21:20 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "sdl_extra.h"

void		draw_image(SDL_Surface *dst, t_image *image)
{
	if (image->draw_method == SCALED)
		sdl_merge_surface_scaled(dst, image->texture);
	else if (image->draw_method == FIXED)
		sdl_merge_surface(dst, image->texture, (SDL_Point){0, 0});
	else if (image->draw_method == CENTERED)
		sdl_merge_surface_center(dst, image->texture);
	else if (image->draw_method == COLOR)
		sdl_fill_surface_color(dst, image->color);
}