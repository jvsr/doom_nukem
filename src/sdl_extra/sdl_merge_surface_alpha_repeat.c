/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_merge_surface_alpha_repeat.c                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 19:02:29 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:04:28 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>

#include "libft/ft_mem.h"

#include "color.h"

/*
** * Surface merge will take two surfaces and a starting pixel.
** * The starting pixel represents the top left corner of the src surface.
** * It will then copy the src surface directly into the dst surface.
** * It does not take an Alpha stat into account,
** * this function considers the Alpha to be 255
*/

static size_t	calculate_length(SDL_Surface *dst, SDL_Surface *src,
								SDL_Point cur)
{
	int			len;
	const int	*start_dst = (int*)(dst->userdata);
	const int	*start_src = (int*)(src->userdata);
	const int	ref_dst = *start_dst;
	const int	ref_src = *start_src;

	len = 0;
	while (cur.x + len < dst->w && (cur.x % src->w) + len < src->w
	&& start_dst[len] == ref_dst && start_src[len] == ref_src)
		len++;
	return ((size_t)len);
}

static t_uint32	mix_color_wrapper(t_uint32 *dst_data, t_uint32 *src_data)
{
	return (mix_color(*dst_data, *src_data));
}

static int		merge_pixel(SDL_Surface *dst, SDL_Surface *src,
							SDL_Point cur)
{
	size_t		length;
	t_uint32	color;

	src->userdata = src->pixels + (cur.y % src->h) * src->pitch
								+ (cur.x % src->w) * 4;
	dst->userdata = dst->pixels + cur.y * dst->pitch + cur.x * 4;
	color = mix_color_wrapper(dst->userdata, src->userdata);
	length = calculate_length(dst, src, cur);
	ft_memset4((int*)dst->userdata, color, length);
	return (length);
}

void			sdl_merge_surface_alpha_repeat(SDL_Surface *dst,
												SDL_Surface *src)
{
	SDL_Point	cur;

	cur.y = 0;
	while (cur.y < dst->h)
	{
		if (cur.y > dst->h - 1)
			break ;
		else if (cur.y >= 0)
		{
			cur.x = 0;
			while (cur.x < dst->w)
			{
				if (cur.x > dst->w - 1)
					break ;
				else if (cur.x >= 0)
					cur.x += merge_pixel(dst, src, cur) - 1;
				cur.x++;
			}
		}
		cur.y++;
	}
}
