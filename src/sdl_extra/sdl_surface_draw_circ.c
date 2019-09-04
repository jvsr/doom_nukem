/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_surface_draw_circ.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 12:58:54 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/04 16:40:23 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <SDL2/SDL.h>

#include "color.h"
#include "shape.h"

void	sdl_surface_draw_circ(SDL_Surface *dst, t_color color, t_circle c)
{
	int				color_value;
	SDL_Point		cur;
	const SDL_Point	start = {c.mid.x - c.d / 2, c.mid.y - c.d / 2};

	cur.y = 0;
	color_value = color_to_rgba(color);
	while (cur.y < c.d)
	{
		if (start.y + cur.y >= 0)
		{
			cur.x = 0;
			while (cur.x < c.d)
			{
				if (start.x + cur.x > dst->w - 1
				|| start.y + cur.y > dst->h - 1)
					break ;
				else if (start.x + cur.x >= 0 && sqrt(pow(c.mid.x - start.x -
				cur.x, 2) + pow(c.mid.y - start.y - cur.y, 2)) < c.d / 2)
					((int*)dst->pixels)[(start.y + cur.y) * dst->w + start.x +
					cur.x] = color_value;
				cur.x++;
			}
		}
		cur.y++;
	}
}
