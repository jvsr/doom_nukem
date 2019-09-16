/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_draw_surface_texture_scaled.c                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 17:36:32 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/16 18:18:40 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_memory.h"

#include "gui.h"
#include "coord.h"

void	sdl_merge_surface_scaled(SDL_Surface *dst, SDL_Surface *src)
{
	SDL_Point		cur;
	int				*dst_stream = (int*)dst->pixels;
	const int		*src_stream = (int*)src->pixels;
	const t_coord	ratio = {(float)src->w / (float)dst->h,
							(float)src->h / (float)dst->w};

	cur.y = 0;
	while (cur.y < dst->h)
	{
		cur.x = 0;
		while (cur.x < dst->w)
		{
			dst_stream[cur.y * dst->w + cur.x] = \
			src_stream[(int)((cur.y * ratio.y) * src->w + (cur.x * ratio.x))];
			cur.x++;
		}
		cur.y++;
	}
}