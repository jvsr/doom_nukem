/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_surface_merge_alpha.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 19:02:29 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/02 17:47:53 by jvisser       ########   odam.nl         */
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

static int		calculate_color(int *dst, int *src)
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

static size_t	calculate_length(SDL_Surface *dst, SDL_Surface *src,
								t_pixel start, t_pixel cur)
{
	int			len;
	const int	*start_dst = (int*)(dst->userdata);
	const int	*start_src = (int*)(src->userdata);
	const int	ref_dst = *start_dst;
	const int	ref_src = *start_src;

	len = 1;
	while (start_dst[len] == ref_dst && start_src[len] == ref_src)
	{
		if (start.x + cur.x + len > dst->w - 1 || cur.x + len > src->w - 1)
			return (len);
		len++;
	}
	return ((size_t)len);
}

static void		copy_color(int *dst, int color, size_t length)
{
	size_t i;

	i = 0;
	while (i < length)
	{
		dst[i] = color;
		i++;
	}
}

static int		merge_pixel(SDL_Surface *dst, SDL_Surface *src,
							t_pixel start, t_pixel cur)
{
	int		color;
	size_t	length;

	src->userdata = src->pixels + (cur.y * src->pitch) + (cur.x * 4);
	dst->userdata = dst->pixels + ((start.y + cur.y) * dst->pitch)
					+ (start.x + cur.x) * 4;
	color = calculate_color(dst->userdata, src->userdata);
	length = calculate_length(dst, src, start, cur);
	copy_color((int*)dst->userdata, color, length);
	return (length);
}

void			sdl_surface_merge_alpha(SDL_Surface *dst, SDL_Surface *src,
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
					cur.x += merge_pixel(dst, src, start, cur);
			}
		}
		cur.y++;
	}
}
