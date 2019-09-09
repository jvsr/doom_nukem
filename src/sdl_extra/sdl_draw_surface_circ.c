/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_draw_surface_circ.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 12:58:54 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 13:48:13 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <_types/_uint32_t.h>

#include "shape.h"
#include "color.h"

void	sdl_surface_draw_circ(SDL_Surface *dst, SDL_Color color, t_circle c)
{
	uint32_t		color_value;
	SDL_Point		cur;
	const SDL_Point	start = {c.mid.x - c.d / 2, c.mid.y - c.d / 2};

	cur.y = 0;
	color_value = color_to_rgba(color);
	while (cur.y < (int)c.d)
	{
		if (start.y + cur.y >= 0)
		{
			cur.x = 0;
			while (cur.x < (int)c.d)
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