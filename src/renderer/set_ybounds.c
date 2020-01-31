/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_ybounds.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 16:53:30 by ehollidg       #+#    #+#                */
/*   Updated: 2020/01/24 16:53:30 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"
#include "renderer.h"
#include "player.h"
#include "game.h"
#include "rinfo.h"

t_point		set_ybounds(t_objrend *obj,
									t_game *game, t_ybinfo info, t_zbuf *buf)
{
	t_player	*plyr;
	t_sector	*sec;
	t_point		ret;
	int			i;

	plyr = game->player;
	sec = &game->map->sectors[plyr->cur_sector];
	if (obj->sec == sec)
		ret = (t_point){ft_constrain(info.ybounds->x, 0, info.h),
						ft_constrain(info.ybounds->y, 0, info.h)};
	else
	{
		i = 0;
		while (buf->bounds[i].sec != NULL && buf->bounds[i].sec != obj->sec)
			i++;
		if (buf->bounds[i].sec == NULL)
			i--;
		ret = (t_point){
			ft_constrain(info.ybounds->x, buf->bounds[i].bounds.x,
				buf->bounds[i].bounds.y),
			ft_constrain(info.ybounds->y, buf->bounds[i].bounds.x,
				buf->bounds[i].bounds.y)};
	}
	return (ret);
}
