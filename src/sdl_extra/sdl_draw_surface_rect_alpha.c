/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_draw_surface_rect_alpha.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 12:24:03 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/10 14:58:45 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include "color.h"

static int		calculate_color(int *dst, SDL_Color src)
{
	float		op;
	SDL_Color	cdst;
	const int	maxalpha = 255;

	rgba_to_color(&cdst, *dst);
	op = (float)src.a / maxalpha;
	cdst.a = maxalpha;
	cdst.r = cdst.r * (1 - op) + src.r * op;
	cdst.g = cdst.g * (1 - op) + src.g * op;
	cdst.b = cdst.b * (1 - op) + src.b * op;
	return (color_to_rgba(cdst));
}

static size_t	calculate_length(SDL_Surface *dst, SDL_Rect rect, SDL_Point cur)
{
	int			len;
	const int	*start_dst = (int*)(dst->userdata);
	const int	ref_dst = *start_dst;

	len = 0;
	while (rect.x + cur.x + len < dst->w && cur.x + len < rect.w
	&& start_dst[len] == ref_dst)
		len++;
	return ((size_t)len);
}

static void		copy_color(int *dst, t_uint32 color, size_t length)
{
	size_t i;

	i = 0;
	while (i < length)
	{
		dst[i] = color;
		i++;
	}
}

static size_t	merge_pixel(SDL_Surface *dst, SDL_Color color,
							SDL_Rect rect, SDL_Point cur)
{
	size_t		length;
	t_uint32	color_value;

	dst->userdata = dst->pixels + ((rect.y + cur.y) * dst->pitch)
					+ (rect.x + cur.x) * 4;
	color_value = calculate_color(dst->userdata, color);
	length = calculate_length(dst, rect, cur);
	copy_color((int*)dst->userdata, color_value, length);
	return (length);
}

void			sdl_draw_surface_rect_alpha(SDL_Surface *dst, SDL_Color color,
											SDL_Rect rect)
{
	SDL_Point	cur;

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
					cur.x += merge_pixel(dst, color, rect, cur) - 1;
				cur.x++;
			}
		}
		cur.y++;
	}
}
