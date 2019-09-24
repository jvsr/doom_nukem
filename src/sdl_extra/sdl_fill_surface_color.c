/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_fill_surface_color.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 12:28:01 by pholster       #+#    #+#                */
/*   Updated: 2019/09/24 15:25:14 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>

#include "libft/ft_mem.h"

#include "color.h"
#include "types.h"

void		sdl_fill_surface_color(SDL_Surface *surface, SDL_Color color)
{
	const t_uint32	color_value = color_to_rgba(color);
	const size_t	pixels = surface->w * surface->h;

	ft_memset4(surface->pixels, color_value, pixels);
}
