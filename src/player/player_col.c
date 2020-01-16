/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_col.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 17:24:34 by ehollidg       #+#    #+#                */
/*   Updated: 2020/01/15 21:21:04 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "libft/ft_mem.h"
#include "player.h"
#include "rinfo.h"
#include "cmath.h"
#include <stdio.h>
#include <limits.h>

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

static t_uint32		check_col(t_player *player, t_uint8 *col,
									t_map *map, float xspeed, float yspeed)
{
	t_coord		pos_x;
	t_coord		pos_y;
	t_coord		pos_xy;
	t_wall		*walls;
	int			i;
	int			max;
	t_uint32	next_sector;
	static t_uint32	prev_sector = UINT32_MAX;

	pos_x = (t_coord){player->pos.x + xspeed, player->pos.y};
	pos_y = (t_coord){player->pos.x, player->pos.y + yspeed};
	pos_xy = (t_coord){player->pos.x + xspeed, player->pos.y + yspeed};
	walls = map->sectors[player->cur_sector].walls;
	i = 0;
	max = map->sectors[player->cur_sector].wall_count;
	next_sector = player->cur_sector;
	t_uint32 temp = player->cur_sector;
	if (prev_sector == UINT32_MAX)
		prev_sector = player->cur_sector;
	while (i < max)
	{
		if (walls[i].is_portal == FALSE)
		{
			if (wall_col(pos_x, player->pos, &walls[i]) == TRUE)
				*col |= 1;
			if (wall_col(pos_y, player->pos, &walls[i]) == TRUE)
				*col |= 2;
			if (wall_col(pos_xy, player->pos, &walls[i]) == TRUE)
				*col |= 4;
		}
		else if (walls[i].is_portal == TRUE
		&& get_sector_id(map, walls[i].window) != prev_sector)
		{
			if (wall_col(pos_xy, player->pos, &walls[i])
			|| wall_col(pos_x, player->pos, &walls[i]) == TRUE
			|| wall_col(pos_y, player->pos, &walls[i]) == TRUE)
			{
				prev_sector = player->cur_sector;
				next_sector = get_sector_id(map, walls[i].window);
				player->cur_sector = next_sector;
				check_col(player, col, map, xspeed, yspeed);
			}
		}
		if (*col == 7)
		{
			player->cur_sector = temp;
			prev_sector = UINT32_MAX;
			return (UINT32_MAX);
		}
		i++;
	}
	prev_sector = UINT32_MAX;
	return (next_sector);
}

t_bool				player_col(t_player *player,
									t_map *map, float xspeed, float yspeed)
{
	t_coord		pos_x;
	t_coord		pos_y;
	t_coord		pos_xy;
	t_uint8		col;
	t_uint32	next_sector;

	pos_x = (t_coord){player->pos.x + xspeed, player->pos.y};
	pos_y = (t_coord){player->pos.x, player->pos.y + yspeed};
	pos_xy = (t_coord){player->pos.x + xspeed, player->pos.y + yspeed};
	col = 0;
	next_sector = check_col(player, &col, map, xspeed, yspeed);
	if (col == 7)
		return (FALSE);
	if (next_sector != UINT32_MAX)
	{
		player->cur_sector = next_sector;
		player->height = map->sectors[next_sector].floor + PLAYER_HEIGHT;
	}
	if (col == 0)
		ft_memcpy(&(player->pos), &pos_xy, sizeof(pos_xy));
	else
	{
		if ((col & 3) == 0)
		{
			if (xspeed > yspeed)
				ft_memcpy(&(player->pos), &pos_x, sizeof(pos_x));
			else
				ft_memcpy(&(player->pos), &pos_y, sizeof(pos_y));
		}
		else if ((col & 1) == 0)
			ft_memcpy(&(player->pos), &pos_x, sizeof(pos_x));
		else if ((col & 2) == 0)
			ft_memcpy(&(player->pos), &pos_y, sizeof(pos_y));
	}
	return (TRUE);
}

