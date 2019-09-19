/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_fill_surface_color.c                           :+:    :+:            */
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
#include "types.h"

static void	fill_32(SDL_Surface *surface, const t_uint64 color_value,
						const size_t pixels, size_t *index)
{
	size_t			index_step;
	long long		*color_stream;
	const t_uint64	color_value_8 = color_value | (color_value << 32);
	const size_t	pixels_8 = pixels / 2;
	const size_t	step = 4;

	index_step = 0;
	color_stream = (long long *)surface->pixels;
	while ((index_step + step) < pixels_8)
	{
		color_stream[index_step] = color_value_8;
		color_stream[index_step + 1] = color_value_8;
		color_stream[index_step + 2] = color_value_8;
		color_stream[index_step + 3] = color_value_8;
		index_step += step;
	}
	*index = index_step * 2;
}

void		sdl_fill_surface_color(SDL_Surface *surface, SDL_Color color)
{
	size_t			index;
	int				*color_stream;
	const t_uint32	color_value = color_to_rgba(color);
	const size_t	pixels = surface->w * surface->h;

	fill_32(surface, color_value, pixels, &index);
	color_stream = (int *)surface->pixels;
	while (index < pixels)
	{
		color_stream[index] = color_value;
		index++;
	}
}
