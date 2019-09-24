/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_merge_surface.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 16:55:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/18 14:50:14 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>

#include "libft/ft_memory.h"

/*
** * Surface merge will take two surfaces and a starting pixel.
** * The starting pixel represents the top left corner of the src surface.
** * It will then copy the src surface directly into the dst surface.
** * It does not take an Alpha stat into account,
** * this function considers the Alpha to be 255
*/

static void	calc_offset_dst(SDL_Point *offset, SDL_Point start)
{
	if (start.y <= 0)
		offset->y = 0;
	else
		offset->y = start.y;
	if (start.x <= 0)
		offset->x = 0;
	else
		offset->x = start.x;
}

static void	calc_offset_src(SDL_Point *offset, SDL_Point start)
{
	if (start.y > 0)
		offset->y = 0;
	else
		offset->y = start.y * -1;
	if (start.x > 0)
		offset->x = 0;
	else
		offset->x = start.x * -1;
}

void		sdl_merge_surface(SDL_Surface *dst, SDL_Surface *src,
								SDL_Point start)
{
	int			len;
	SDL_Point	cur;
	SDL_Point	offset_dst;
	SDL_Point	offset_src;

	calc_offset_dst(&offset_dst, start);
	calc_offset_src(&offset_src, start);
	len = src->w - offset_src.x;
	if (len > dst->w - offset_dst.x)
		len = dst->w - offset_dst.x;
	cur.y = 0;
	while (cur.y < src->h)
	{
		if (offset_dst.y + cur.y > dst->h - 1)
			break ;
		else if (offset_dst.y + cur.y >= 0)
		{
			ft_memcpy(
				dst->pixels + ((cur.y + offset_dst.y) * dst->w + offset_dst.x) * 4,
				src->pixels + ((cur.y + offset_src.y) * src->w + offset_src.x) * 4,
				len * 4
			);
		}
		cur.y++;
	}
}
