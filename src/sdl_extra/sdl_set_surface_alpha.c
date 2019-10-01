/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_set_surface_alpha.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 15:30:37 by euan           #+#    #+#                */
/*   Updated: 2019/09/25 16:40:29 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>

#include "libft/ft_mem.h"

#include "types.h"

static void	set_alpha(t_uint32 *pixel, t_uint32 zero_mask, t_uint32 value)
{
	*pixel &= zero_mask;
	*pixel |= value;
}

static void	set_alpha32(long long *pixel, t_uint64 zero_mask, t_uint64 value)
{
	*pixel &= zero_mask;
	*pixel |= value;
}

static void	roll32(SDL_Surface *surface, t_uint64 zero_mask,
	t_uint64 value_mask, size_t *index)
{
	const t_uint64	d_zero = zero_mask | (zero_mask << 32);
	const t_uint64	d_val = value_mask | (value_mask << 32);
	const size_t	d_size = (surface->w * surface->h) / 2;
	long long		*d_pixels;
	size_t			step;

	d_pixels = (long long *)surface->pixels;
	step = 0;
	while (step + 4 < d_size)
	{
		set_alpha32(&d_pixels[step], d_zero, d_val);
		set_alpha32(&d_pixels[step + 1], d_zero, d_val);
		set_alpha32(&d_pixels[step + 2], d_zero, d_val);
		set_alpha32(&d_pixels[step + 3], d_zero, d_val);
		step += 4;
	}
	*index = step * 2;
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
	roll32(surface, zero_mask, value, &i);
	pixels = (t_uint32*)surface->pixels;
	while (i < px_size)
	{
		set_alpha(&pixels[i], zero_mask, value);
		i++;
	}
}
