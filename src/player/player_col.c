/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_col.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 17:24:34 by ehollidg       #+#    #+#                */
/*   Updated: 2020/01/09 17:24:34 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "libft/ft_mem.h"
#include "player.h"
#include "rinfo.h"
#include "cmath.h"
#include <stdio.h>

static t_bool		col(t_coord c0, t_coord c1, t_coord c2, t_coord c3)
{
	t_coord b;
	t_coord d;
	t_coord c;
	t_coord dots;

	b = (t_coord){c1.x - c0.x, c1.y - c0.y};
	d = (t_coord){c3.x - c2.x, c3.y - c2.y};
	dots.x = b.x * d.y - b.y * d.x;
	if (dots.x == 0)
		return (FALSE);
	c = (t_coord){c2.x - c0.x, c2.y - c0.y};
	dots.y = (c.x * d.y - c.y * d.x) / dots.x;
	if (dots.y < 0 || dots.y > 1)
		return (FALSE);
	dots.y = (c.x * b.y - c.y * b.x) / dots.x;
	if (dots.y < 0 || dots.y > 1)
		return (FALSE);
	return (TRUE);
}

static t_bool		wall_col(t_coord c0, t_coord c1, t_wall *wall)
{
	if (col(c0, c1, wall->corner_0, wall->corner_1))
		return (TRUE);
	return (FALSE);
}

static t_uint32		get_sector_id(t_map *map, t_sector *sec)
{
	t_uint32 i;

	i = 0;
	while (i < map->sector_count)
	{
		if (&map->sectors[i] == sec)
			return (i);
		i++;
	}
	return (4294967294);
}

t_bool				player_col(t_player *player,
									t_map *map, float xspeed, float yspeed)
{
	t_coord		pos;
	t_wall		*walls;
	int			i;
	int			max;
	t_uint32	cur_sector;

	pos = (t_coord){player->pos.x + xspeed, player->pos.y + yspeed};
	walls = map->sectors[player->cur_sector].walls;
	i = 0;
	max = map->sectors[player->cur_sector].wall_count;
	cur_sector = player->cur_sector;
	while (i < max)
	{
		/*if (!walls[i].is_portal &&
			wall_col(pos, player->pos, &walls[i]) == TRUE)
			return (FALSE);*/
		if (walls[i].is_portal && wall_col(pos, player->pos, &walls[i]))
			cur_sector = get_sector_id(map, walls[i].window);
		i++;
	}
	if (cur_sector != 4294967294)
	{
		player->cur_sector = cur_sector;
		player->height = map->sectors[cur_sector].floor + 6;
	}
	ft_memcpy(&(player->pos), &pos, sizeof(pos));
	return (TRUE);
}
