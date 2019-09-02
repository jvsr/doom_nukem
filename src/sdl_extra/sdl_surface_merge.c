/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_surface_merge.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 16:55:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/08/29 16:05:22 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "libft/ft_memory.h"

#include "coord.h"
#include "color.h"

/*
** * Surface merge will take two surfaces and a starting pixel.
** * The starting pixel represents the top left corner of the src surface.
** * It will then copy the src surface directly into the dst surface.
** * It does not take an Alpha stat into account,
** * this function considers the Alpha to be 255
*/

void		sdl_surface_merge(SDL_Surface *dst, SDL_Surface *src,
								t_pixel start)
{
	int		len;
	t_pixel	cur;

	cur.y = 0;
	while (cur.y < src->h)
	{
		if (start.y + cur.y > dst->h - 1)
			break ;
		else if (start.y + cur.y >= 0)
		{
			len = src->w;
			if (start.x + len > dst->w)
				len -= start.x + len - dst->w;
			ft_memcpy(
				dst->pixels + ((start.y + cur.y) * dst->w + start.x) * 4,
				src->pixels + cur.y * src->w * 4,
				len * 4);
		}
		cur.y++;
	}
}
