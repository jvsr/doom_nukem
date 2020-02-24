/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_cline.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 16:02:24 by euan           #+#    #+#                */
/*   Updated: 2020/02/22 16:04:39 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"
#include "coord.h"
#include "rinfo.h"

void	draw_cline(SDL_Surface *dst, t_point **bounds, size_t index, int colour)
{
	int		*pixels;
	int		i;
	t_point	c_ybounds;

	pixels = dst->pixels;
	if (index >= (size_t)dst->w)
		return ;
	*bounds[0] = (t_point){ft_constrain(bounds[0]->x, 0, dst->h),
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
