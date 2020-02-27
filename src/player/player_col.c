/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_col.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 17:24:34 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/21 22:11:05 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h" //
#include "libft/ft_bool.h"
#include "libft/ft_mem.h"
#include "game.h"
#include "error.h"
#include "setting.h"
#include "player.h"
#include "rinfo.h"
#include "cmath.h"
#include "keymap.h"
#include <stdio.h>
#include <limits.h>

static t_bool		coll(t_coord c0, t_coord c1, t_coord c2, t_coord c3)
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
	if (coll(c0, c1, wall->corner_0, wall->corner_1))
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

void	check_wall_col(t_tricoord coord, t_player *player,
						t_wall *wall, t_uint8 *col)
{
	if (wall_col(coord.x, player->pos, wall) == TRUE)
		*col |= 1;
	if (wall_col(coord.y, player->pos, wall) == TRUE)
		*col |= 2;
	if (wall_col(coord.xy, player->pos, wall) == TRUE)
		*col |= 4;
}

static t_uint32		check_col(t_game *game, t_player *player, t_uint8 *col,
									t_map *map, float xspeed, float yspeed)
{
	t_tricoord	coord;
	t_wall		*walls;
	t_list		*objects;
	int			i;
	int			max;
	t_uint32	next_sector;
	t_list		*portals;
	t_list		*new_wall;
	static t_uint32	prev_sector = UINT32_MAX;

	coord.x = (t_coord){player->pos.x + xspeed, player->pos.y};
	coord.y = (t_coord){player->pos.x, player->pos.y + yspeed};
	coord.xy = (t_coord){player->pos.x + xspeed, player->pos.y + yspeed};
	i = 0;
	max = map->sectors[player->cur_sector].wall_count;
	next_sector = UINT32_MAX;
	t_uint32 temp = player->cur_sector;
	portals = NULL;
	if (prev_sector == UINT32_MAX)
		prev_sector = player->cur_sector;
	walls = map->sectors[player->cur_sector].walls;
	while (i < max)
	{
		if (walls[i].is_portal == FALSE || walls[i].is_window == TRUE)
			check_wall_col(coord, player, &walls[i], col);
		else if (walls[i].is_portal == TRUE
		&& get_sector_id(map, walls[i].window) != prev_sector)
		{
			if (wall_col(coord.xy, player->pos, &walls[i]) == TRUE
			|| wall_col(coord.x, player->pos, &walls[i]) == TRUE
			|| wall_col(coord.y, player->pos, &walls[i]) == TRUE)
			{
				new_wall = ft_lstnew(&walls[i], sizeof(t_wall*));
				if (new_wall == NULL)
					error_msg_errno("Failed to alloc New Wall");
				ft_lstadd(&portals, new_wall);
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
	objects = map->sectors[player->cur_sector].objects;
	while (objects != NULL)
	{
		int tmp = 0;
		t_object *obj = objects->content;
		objects = objects->next;
		if (obj->size.y < player->heightoffset - player->player_height)
			continue ;
		if (get_distance(&coord.x, &obj->pos) <= obj->col_radius && get_distance(&coord.x, &obj->pos) < get_distance(&player->pos, &obj->pos))
			tmp |= 1;
		if (get_distance(&coord.y, &obj->pos) <= obj->col_radius && get_distance(&coord.y, &obj->pos) < get_distance(&player->pos, &obj->pos))
			tmp |= 2;
		if (get_distance(&coord.xy, &obj->pos) <= obj->col_radius && get_distance(&coord.xy, &obj->pos) < get_distance(&player->pos, &obj->pos))
			tmp |= 4;
		if (tmp == 0)
			continue ;
		if (obj->can_col == TRUE)
			*col |= tmp;
		if (obj->on_collide)
			obj->on_collide(game, (void*)&map->sectors[player->cur_sector], obj, player);
		if (*col == 7)
		{
			player->cur_sector = temp;
			prev_sector = UINT32_MAX;
			return (UINT32_MAX);
		}
	}
	while (portals != NULL)
	{
		if (
		((*col & 1) == 0 && wall_col(coord.x, player->pos, (t_wall*)portals->content))
		|| ((*col & 2) == 0 && wall_col(coord.y, player->pos, (t_wall*)portals->content))
		|| (*col == 0 && wall_col(coord.xy, player->pos, (t_wall*)portals->content))
		)
		{
			prev_sector = player->cur_sector;
			next_sector = get_sector_id(map, (*((t_wall*)portals->content)).window);
			player->cur_sector = next_sector;
			check_col(game, player, col, map, xspeed, yspeed);
			player->cur_sector = temp;
		}
		portals = portals->next;
	}
	if (*col == 7)
	{
		player->cur_sector = temp;
		return (UINT32_MAX);
	}
	prev_sector = UINT32_MAX;
	return (next_sector);
}

static void			player_move_col(t_uint8 col, t_player *player, t_coord pos_xy, t_coord pos_x, t_coord pos_y, float xspeed, float yspeed)
{
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
}

t_bool				player_col(t_game *game, float xspeed, float yspeed)
{
	t_coord		pos_x;
	t_coord		pos_y;
	t_coord		pos_xy;
	t_uint8		col;
	t_uint32	next_sector;

	t_player *player = game->player;
	t_map *map = game->map;
	t_hashmap *keymap = game->keymap;


	pos_x = (t_coord){player->pos.x + xspeed, player->pos.y};
	pos_y = (t_coord){player->pos.x, player->pos.y + yspeed};
	pos_xy = (t_coord){player->pos.x + xspeed, player->pos.y + yspeed};
	col = 0;
	next_sector = check_col(game, player, &col, map, xspeed, yspeed);
	if (col == 7)
		return (FALSE);
	if (next_sector != UINT32_MAX)
	{
		if (map->sectors[player->cur_sector].f_exit != NULL)
			map->sectors[player->cur_sector].f_exit(game, &map->sectors[player->cur_sector]);
		// ft_printf("%f, %f\n", player->height + player->heightoffset + PLAYER_CLIMB, map->sectors[next_sector].floor);
		if (player->height + player->heightoffset + PLAYER_CLIMB - player->player_height < map->sectors[next_sector].floor
		|| player->height + player->heightoffset + (map->sectors[next_sector].floor - map->sectors[player->cur_sector].floor) > map->sectors[next_sector].ceil
		)
		{
			// ft_printf("col: %d\n", col);
			return (FALSE);
		}
		// ft_printf("height: %f, other: %f\n", player->height + player->heightoffset + (map->sectors[next_sector].floor - map->sectors[player->cur_sector].floor), map->sectors[next_sector].ceil);
		if (player->height + player->heightoffset > map->sectors[next_sector].floor + player->player_height)
			player->heightoffset += player->height - (map->sectors[next_sector].floor + player->player_height);
		else
			player->heightoffset = 0.0001;
		if (is_helddown(keymap, game->setting->controls.crouch) == FALSE)
			player->player_height = PLAYER_HEIGHT;
		player->cur_sector = next_sector;
		player->height = map->sectors[next_sector].floor + player->player_height;
		if (map->sectors[player->cur_sector].f_enter != NULL)
			map->sectors[player->cur_sector].f_enter(game, &map->sectors[player->cur_sector]);
	}
	player_move_col(col, player, pos_xy, pos_x, pos_y, xspeed, yspeed);
	return (TRUE);
}

