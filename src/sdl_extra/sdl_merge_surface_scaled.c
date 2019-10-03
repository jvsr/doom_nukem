/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_merge_surface_scaled.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 17:36:32 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/17 14:33:44 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "gui.h"
#include "coord.h"

void	sdl_merge_surface_scaled(SDL_Surface *dst, SDL_Surface *src)
{
	SDL_Point		cur;
	int				*dst_stream;
	const int		*src_stream = (int*)src->pixels;
	const t_coord	ratio = {(float)src->w / dst->w, (float)src->h / dst->h};

	cur.y = 0;
	dst_stream = (int*)dst->pixels;
	while (cur.y < dst->h)
	{
		cur.x = 0;
		while (cur.x < dst->w)
		{
			dst_stream[cur.y * dst->w + cur.x] = \
			src_stream[(int)(cur.y * ratio.y) * src->w +
			(int)(cur.x * ratio.x)];
			cur.x++;
		}
		cur.y++;
	}
}
