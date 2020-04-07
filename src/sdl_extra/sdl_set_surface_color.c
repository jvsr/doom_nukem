/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_set_surface_color.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 15:30:37 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 12:04:09 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>

#include "libft/ft_mem.h"

#include "color.h"
#include "types.h"

static void		set_color(t_uint32 *pixel, t_uint32 zero_mask, t_uint32 value)
{
	*pixel &= zero_mask;
	*pixel |= value;
}

static void		set_color32(t_uint64 *pixel, t_uint64 zero_mask,
							t_uint64 value)
{
	*pixel &= zero_mask;
	*pixel |= value;
}

static t_uint32	prepare_value(SDL_Color color, SDL_PixelFormat *format)
{
	t_uint32	value;
	t_uint32	temp;

	value = 0;
	ft_memset(&temp, color.r, sizeof(temp));
	value |= temp & format->Rmask;
	ft_memset(&temp, color.g, sizeof(temp));
	value |= temp & format->Gmask;
	ft_memset(&temp, color.b, sizeof(temp));
	value |= temp & format->Bmask;
	return (value);
}

static void		roll32(SDL_Surface *surface, t_uint64 zero_mask,
	t_uint64 value_mask, size_t *index)
{
	const t_uint64	d_zero = zero_mask | (zero_mask << 32);
	const t_uint64	d_val = value_mask | (value_mask << 32);
	const size_t	d_size = (surface->w * surface->h) / 2;
	t_uint64		*d_pixels;
	size_t			step;

	d_pixels = (t_uint64 *)surface->pixels;
	step = 0;
	while ((step + 4) < d_size)
	{
		set_color32(&d_pixels[step], d_zero, d_val);
		set_color32(&d_pixels[step + 1], d_zero, d_val);
		set_color32(&d_pixels[step + 2], d_zero, d_val);
		set_color32(&d_pixels[step + 3], d_zero, d_val);
		step += 4;
	}
	*index = step * 2;
}

void			sdl_set_surface_color(SDL_Surface *surface, SDL_Color color)
{
	const t_uint32	zero_mask = surface->format->Amask;
	const size_t	px_size = surface->w * surface->h;
	t_uint32		*pixels;
	t_uint32		value;
	size_t			i;

	i = 0;
	value = prepare_value(color, surface->format);
	roll32(surface, zero_mask, value, &i);
	pixels = (t_uint32*)surface->pixels;
	while (i < px_size)
	{
		set_color(&pixels[i], zero_mask, value);
		i++;
	}
}
