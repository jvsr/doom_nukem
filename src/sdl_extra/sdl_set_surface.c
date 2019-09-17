/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_set_surface.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 12:28:01 by pholster       #+#    #+#                */
/*   Updated: 2019/09/17 12:28:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_rect.h>

#include "color.h"

void	sdl_set_surface(SDL_Surface *surface, SDL_Color color)
{
	size_t			index;
	int				*color_stream;
	const Uint32	color_value = color_to_rgba(color);
	const size_t	pixels = surface->w * surface->h;

	index = 0;
	color_stream = (int *)surface->pixels;
	while (index < pixels)
	{
		color_stream[index] = color_value;
		index++;
	}
}
