/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_has_surface_alpha.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 16:44:18 by pholster       #+#    #+#                */
/*   Updated: 2019/09/19 16:44:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>

#include "libft/ft_bool.h"

#include "types.h"

static t_bool	check_32(SDL_Surface *surface, const t_uint64 alhpa_mask,
						const size_t pixels, size_t *index)
{
	size_t			index_step;
	long long		*color_stream;
	const t_uint64	alhpa_mask_8 = alhpa_mask | (alhpa_mask << 32);
	const size_t	pixels_8 = pixels / 2;
	const size_t	step = 4;

	index_step = 0;
	color_stream = (long long *)surface->pixels;
	while ((index_step + step) < pixels_8)
	{
		if ((color_stream[index_step] & alhpa_mask_8) != alhpa_mask_8)
			return (TRUE);
		if ((color_stream[index_step + 1] & alhpa_mask_8) != alhpa_mask_8)
			return (TRUE);
		if ((color_stream[index_step + 2] & alhpa_mask_8) != alhpa_mask_8)
			return (TRUE);
		if ((color_stream[index_step + 3] & alhpa_mask_8) != alhpa_mask_8)
			return (TRUE);
		index_step += step;
	}
	*index = index_step * 2;
	return (FALSE);
}

t_bool			sdl_has_surface_alpha(SDL_Surface *surface)
{
	size_t			index;
	int				*color_stream;
	const t_uint32	alhpa_mask = surface->format->Amask;
	const size_t	pixels = surface->w * surface->h;

	if (check_32(surface, alhpa_mask, pixels, &index))
		return (TRUE);
	color_stream = (int *)surface->pixels;
	while (index < pixels)
	{
		if ((color_stream[index] & alhpa_mask) != alhpa_mask)
			return (TRUE);
		index++;
	}
	return (FALSE);
}
