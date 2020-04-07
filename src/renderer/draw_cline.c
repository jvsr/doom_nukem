/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_cline.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 16:02:24 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:09:52 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"
#include "coord.h"
#include "rinfo.h"

void	draw_cline(SDL_Surface *dst, SDL_Point **bounds, size_t index,
																	int colour)
{
	int			*pixels;
	int			i;
	SDL_Point	c_ybounds;

	pixels = dst->pixels;
	if (index >= (size_t)dst->w)
		return ;
	*bounds[0] = (SDL_Point){ft_constrain(bounds[0]->x, 0, dst->h),
					ft_constrain(bounds[0]->y, 0, dst->h)};
	c_ybounds.x = ft_constrain(bounds[1]->x, bounds[0]->x, bounds[0]->y);
	c_ybounds.y = ft_constrain(bounds[1]->y, c_ybounds.x, bounds[0]->y);
	i = c_ybounds.x;
	while (i < c_ybounds.y)
	{
		pixels[index + (dst->w * (dst->h - i - 1))] = colour;
		i++;
	}
}
