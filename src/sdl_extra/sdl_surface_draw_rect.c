/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_surface_draw_rect.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 12:24:03 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/04 13:05:56 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "color.h"

void	sdl_surface_draw_rect(SDL_Surface *dst, t_color color, SDL_Rect rect)
{
	int			*start;
	Uint32		color_value;
	SDL_Point	cur;

	color_value = color_to_rgba(color);
	start = dst->pixels + (rect.y * dst->pitch) + (rect.x * 4);
	cur.y = 0;
	while (cur.y < rect.h)
	{
		if (rect.y + cur.y > dst->h - 1)
			break ;
		else if (rect.y + cur.y >= 0)
		{
			cur.x = 0;
			while (cur.x < rect.w)
			{
				if (rect.x + cur.x > dst->w - 1)
					break ;
				else if (rect.x + cur.x >= 0)
					start[cur.y * dst->w + cur.x] = color_value;
				cur.x++;
			}
		}
		cur.y++;
	}
}
