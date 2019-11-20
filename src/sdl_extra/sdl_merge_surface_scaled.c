/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_merge_surface_scaled.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 17:36:32 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/24 15:24:45 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "sdl_extra.h"
#include "gui.h"
#include "coord.h"

void		sdl_merge_surface_scaled(SDL_Surface *dst, SDL_Surface *src)
{
	SDL_Point		cur;
	SDL_Point		src_index;
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
			sdl_scale_index(&src_index, &cur, &ratio, src);
			dst_stream[cur.y * dst->w + cur.x] = \
				src_stream[src_index.y * src->w + src_index.x];
			cur.x++;
		}
		cur.y++;
	}
}
