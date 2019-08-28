/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_surface_merge.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 16:55:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/08/28 19:18:13 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "libft/ft_memory.h"

#include "coord.h"
#include "color.h"

void		sdl_surface_merge(SDL_Surface *dst, SDL_Surface *src,
									t_pixel start)
{
	t_pixel	cur;

	cur.y = 0;
	while (cur.y < src->h)
	{
		if (start.y + cur.y > dst->h - 1)
			break ;
		else if (start.y + cur.y >= 0)
		{
			cur.x = 0;
			while (cur.x < src->w)
			{
				if (start.x + cur.x > dst->w - 1)
					break ;
				else if (start.x + cur.x >= 0)
				{
					ft_memcpy(dst->pixels + ((start.y + cur.y) * dst->w
						+ start.x + cur.x) * 4, src->pixels + ((cur.y * src->w)
						+ cur.x) * 4, sizeof(int));
				}
				cur.x++;
			}
		}
		cur.y++;
	}
}
