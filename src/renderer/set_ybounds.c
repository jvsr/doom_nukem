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

#include "libft/ft_list.h"
#include "libft/ft_num.h"
#include "renderer.h"
#include "player.h"
#include "game.h"
#include "rinfo.h"

t_point		set_ybounds(t_objrend *obj, t_game *game, t_ybinfo info)
{
	t_player	*plyr;
	t_point		bnds;
	t_sector	*sec;
	t_point		ret;

	plyr = game->player;
	sec = &game->map->sectors[plyr->cur_sector];
	if (obj->sec == sec)
		ret = (t_point){ft_constrain(info.ybounds->x, 0, info.h),
						ft_constrain(info.ybounds->y, 0, info.h)};
	else
	{
		if (info.prev)
			bnds = info.prev->hits[info.index].bounds;
		else
			bnds = (t_point){0, info.h};
		ret = (t_point){
			ft_constrain(info.ybounds->x, bnds.x,
				bnds.y),
			ft_constrain(info.ybounds->y, bnds.x,
				bnds.y)};
	}
	return (ret);
}
