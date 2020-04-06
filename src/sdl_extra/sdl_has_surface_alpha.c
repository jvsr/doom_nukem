/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_has_surface_alpha.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 16:44:18 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:04:32 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>

#include "libft/ft_bool.h"

#include "types.h"

static t_bool	check_32(SDL_Surface *surface, const t_uint64 alpha_mask,
						const size_t pixels, size_t *index)
{
	size_t			index_step;
	long long		*color_stream;
	const t_uint64	alpha_mask_8 = alpha_mask | (alpha_mask << 32);
	const size_t	pixels_8 = pixels / 2;
	const size_t	step = 4;

	index_step = 0;
	color_stream = (long long *)surface->pixels;
	while ((index_step + step) < pixels_8)
	{
		if ((color_stream[index_step] & alpha_mask_8) != alpha_mask_8)
			return (TRUE);
		if ((color_stream[index_step + 1] & alpha_mask_8) != alpha_mask_8)
			return (TRUE);
		if ((color_stream[index_step + 2] & alpha_mask_8) != alpha_mask_8)
			return (TRUE);
		if ((color_stream[index_step + 3] & alpha_mask_8) != alpha_mask_8)
			return (TRUE);
		index_step += step;
	}
	*index = index_step * 2;
	return (FALSE);
}

t_bool			sdl_has_surface_alpha(SDL_Surface *surface)
{
	size_t			index;
	t_uint32		*color_stream;
	const t_uint32	alpha_mask = surface->format->Amask;
	const size_t	pixels = surface->w * surface->h;

	if (check_32(surface, alpha_mask, pixels, &index))
		return (TRUE);
	index = 0;
	color_stream = (t_uint32 *)surface->pixels;
	while (index < pixels)
	{
		if ((color_stream[index] & alpha_mask) != alpha_mask)
			return (TRUE);
		index++;
	}
	return (FALSE);
}
