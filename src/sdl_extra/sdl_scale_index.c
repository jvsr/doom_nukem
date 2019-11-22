/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_scale_index.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 20:06:03 by pholster       #+#    #+#                */
/*   Updated: 2019/11/20 20:06:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>

#include "coord.h"

void	sdl_scale_index(SDL_Point *result, SDL_Point *cur,
							t_coord const *ratio, SDL_Surface *target_surface)
{
	int		y;
	int		x;

	y = (int)round(cur->y * ratio->y);
	if (y >= target_surface->h)
		y = target_surface->h - 1;
	x = (int)round(cur->x * ratio->x);
	if (x >= target_surface->w)
		x = target_surface->w - 1;
	result->y = y;
	result->x = x;
}
