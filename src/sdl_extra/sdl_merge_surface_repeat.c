/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_merge_surface_repeat.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:52:32 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/14 16:52:32 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>

void	sdl_merge_surface_repeat(SDL_Surface *dst, SDL_Surface *src)
{
	SDL_Point		cur;
	int				*dst_stream;
	const int		*src_stream = (int*)src->pixels;

	cur.y = 0;
	dst_stream = (int*)dst->pixels;
	while (cur.y < dst->h)
	{
		cur.x = 0;
		while (cur.x < dst->w)
		{
			dst_stream[cur.y * dst->w + cur.x] = \
			src_stream[(int)(cur.y) % src->h * src->w +
						(int)(cur.x) % src->w];
			cur.x++;
		}
		cur.y++;
	}
}
