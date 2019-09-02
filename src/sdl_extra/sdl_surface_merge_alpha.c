/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_surface_merge_alpha.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 19:02:29 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/02 15:33:29 by jvisser       ########   odam.nl         */
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

static int	merge_pixels(int *dst, int *src)
{
	float		op;
	t_color		cdst;
	t_color		csrc;
	const int	maxalpha = 255;

	rgba_to_color(&cdst, *dst);
	rgba_to_color(&csrc, *src);
	op = (float)csrc.a / maxalpha;
	cdst.a = maxalpha;
	cdst.r = cdst.r * (1 - op) + csrc.r * op;
	cdst.g = cdst.g * (1 - op) + csrc.g * op;
	cdst.b = cdst.b * (1 - op) + csrc.b * op;
	return (color_to_rgba(cdst));
}

static size_t	calculate_length(int *start_dst, int *start_src, t_pixel start, t_pixel cur, int dstw, int srcw)
{
	int		ref_dst;
	int		ref_src;
	size_t	length;
	
	length = 1;
	ref_dst = *start_dst;
	ref_src = *start_src;
	while (start_dst[length] == ref_dst && start_src[length] == ref_src)
	{
		if (start.x + cur.x + length > dstw - 1 || cur.x + length > srcw - 1)
			return (length);
		length++;
	}
	return (length);
}

void		sdl_surface_merge_alpha(SDL_Surface *dst, SDL_Surface *src,
									t_pixel start)
{
	int		*start_dst;
	int		*start_src;
	int		result;
	size_t	length;
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
				length = 0;
				if (start.x + cur.x > dst->w - 1)
					break ;
				else if (start.x + cur.x >= 0)
				{
					start_src = (int*)src->pixels + (cur.y * src->w) + cur.x;
					start_dst = (int*)dst->pixels + (start.y + cur.y) * dst->w + start.x + cur.x;
					result = merge_pixels(start_dst, start_src);
					length = calculate_length(start_dst, start_src, start, cur, dst->w, src->w);
					for (int i = 0; i < length; i++)
						ft_memcpy(&start_dst[i], &result, 4);
				}
				cur.x += length;
			}
		}
		cur.y++;
	}
}

/*
		if (start.x + cur.x + length > dstw - 1)
			length -= (start.x + cur.x + length) - dstw;
		if (cur.x + length > srcw - 1)
			length -= (cur.x + length) - srcw;
*/
