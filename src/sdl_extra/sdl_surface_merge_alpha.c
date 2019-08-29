/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_surface_merge_alpha.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 19:02:29 by jvisser        #+#    #+#                */
/*   Updated: 2019/08/29 13:48:33 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "coord.h"
#include "color.h"

/*
** * Surface merge will take two surfaces and a starting pixel.
** * The starting pixel represents the top left corner of the src surface.
** * It will then copy the src surface directly into the dst surface.
** * It does not take an Alpha stat into account,
** * this function considers the Alpha to be 255
*/

static void	merge_pixels(int *dst, int *src)
{
	float		op;
	t_color		cdst;
	t_color		csrc;
	const int	alpha = 255;

	rgba_to_color(&cdst, *dst);
	rgba_to_color(&csrc, *src);
	op = (float)csrc.a / alpha;
	cdst.a = alpha;
	cdst.r = cdst.r * (1 - op) + csrc.r * op;
	cdst.g = cdst.g * (1 - op) + csrc.g * op;
	cdst.b = cdst.b * (1 - op) + csrc.b * op;
	color_to_rgba(dst, cdst);
}

void		sdl_surface_merge_alpha(SDL_Surface *dst, SDL_Surface *src,
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
					merge_pixels((int*)dst->pixels
								+ (start.y + cur.y) * dst->w + start.x + cur.x,
								(int*)src->pixels + (cur.y * src->w) + cur.x);
				cur.x++;
			}
		}
		cur.y++;
	}
}
