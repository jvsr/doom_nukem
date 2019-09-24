/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_set_surface_alpha.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 15:30:37 by euan           #+#    #+#                */
/*   Updated: 2019/09/24 15:30:37 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>
#include "types.h"
#include "libft/ft_mem.h"

void		set_alpha(t_uint32 *pixel, t_uint32 zero_mask, t_uint32 value)
{
	*pixel &= zero_mask;
	*pixel |= value;
}

void		sdl_set_surface_alpha(SDL_Surface *surface, t_uint8 alpha)
{
	const t_uint32	zero_mask = ~(surface->format->Amask);
	const size_t	px_size = surface->w * surface->h;
	t_uint32		*pixels;
	t_uint32		value;
	size_t			i;

	ft_memset(&value, alpha, sizeof(value));
	value &= surface->format->Amask;
	i = 0;
	pixels = (t_uint32*)surface->pixels;
	while (i < px_size)
	{
		set_alpha(&pixels[i], zero_mask, value);
		i++;
	}
}
