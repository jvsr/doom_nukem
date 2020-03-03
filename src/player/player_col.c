/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_col.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 17:24:34 by ehollidg       #+#    #+#                */
/*   Updated: 2020/03/02 16:58:20 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
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

static t_uint32		check_col(t_game *game, t_player *player, t_uint8 *col, t_map *map, t_tricoord coord);

void			check_portals(t_game *game, t_uint8 *col, t_list **portals, t_tricoord coord, t_uint32 *prev_sector, t_uint32 *next_sector)
{
	t_uint32	temp;
	t_list		*next_portal;
	t_player	*player;
	t_wall		*wall;
	
	player = game->player;
	while ((*portals) != NULL)
	{
		next_portal = (*portals)->next;
		wall = (*portals)->content;
		if (((*col & 1) == 0 && wall_col(coord.x, player->pos, wall))
		|| ((*col & 2) == 0 && wall_col(coord.y, player->pos, wall))
		|| (*col == 0 && wall_col(coord.xy, player->pos, wall)))
		{
			*prev_sector = player->cur_sector;
			*next_sector = get_sector_id(game->map, (*wall).window);
			temp = player->cur_sector;
			player->cur_sector = *next_sector;
			check_col(game, player, col, game->map, coord);
			player->cur_sector = temp;
		}
		ft_lstdelone(portals, NULL);
		(*portals) = next_portal;
	}
}

t_list				*check_walls(t_game *game, t_uint8 *col,
										t_tricoord coord, t_uint32 prev_sector)
{
	int			i;
	int			max;
	t_wall		*walls;
	t_list		*new_wall;
	t_list		*portals;

	portals = NULL;
	walls = game->map->sectors[game->player->cur_sector].walls;
	i = 0;
	max = game->map->sectors[game->player->cur_sector].wall_count;
	while (i < max)
	{
		if (walls[i].is_portal == FALSE || walls[i].is_window == TRUE)
			check_wall_col(coord, game->player, &walls[i], col);
		else if (walls[i].is_portal == TRUE
		&& get_sector_id(game->map, walls[i].window) != prev_sector)
		{
			if (wall_col(coord.xy, game->player->pos, &walls[i]) == TRUE
			|| wall_col(coord.x, game->player->pos, &walls[i]) == TRUE
			|| wall_col(coord.y, game->player->pos, &walls[i]) == TRUE)
			{
				new_wall = ft_lstnew(&walls[i], sizeof(t_wall*));
				if (new_wall == NULL)
					error_msg_errno("Failed to alloc New Wall");
				ft_lstadd(&portals, new_wall);
			}
		}
		if (*col == 7)
			return (portals);
		i++;
	}
	return (portals);
}

static t_uint32		check_col(t_game *game, t_player *player, t_uint8 *col,
									t_map *map, t_tricoord coord)
{
	t_list		*objects;
	t_uint32	next_sector;
	t_list		*portals;
	const t_uint32	temp = player->cur_sector;
	static t_uint32	prev_sector = UINT32_MAX;

	next_sector = UINT32_MAX;
	portals = NULL;
	if (prev_sector == UINT32_MAX)
		prev_sector = player->cur_sector;
	portals = check_walls(game, col, coord, prev_sector);
	if (*col == 7)
	{
		player->cur_sector = temp;
		prev_sector = UINT32_MAX;
		ft_lstdel(&portals, NULL);
		return (UINT32_MAX);
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
			ft_lstdel(&portals, NULL);
			return (UINT32_MAX);
		}
	}
	check_portals(game, col, &portals, coord, &prev_sector, &next_sector);
	if (*col == 7)
	{
		player->cur_sector = temp;
		return (UINT32_MAX);
	}
	prev_sector = UINT32_MAX;
	return (next_sector);
}

static void			player_move_col(t_uint8 col, t_player *player,
																t_tricoord pos)
{
	if (col == 0)
		ft_memcpy(&(player->pos), &pos.xy, sizeof(pos.xy));
	else
	{
		if ((col & 3) == 0)
			ft_memcpy(&(player->pos), &pos.x, sizeof(pos.x));
		else if ((col & 1) == 0)
			ft_memcpy(&(player->pos), &pos.x, sizeof(pos.x));
		else if ((col & 2) == 0)
			ft_memcpy(&(player->pos), &pos.y, sizeof(pos.y));
	}
}

t_bool				switch_sector(t_game *game, t_map *map, t_player *player,
														t_uint32 next_sector)
{
	float		h_o;
	float		p_h;
	t_sector	*n_sector;
	t_sector	*cur_sector;

	h_o = player->height + player->heightoffset;
	p_h = player->player_height;
	cur_sector = &map->sectors[player->cur_sector];
	n_sector = &map->sectors[next_sector];
	if (cur_sector->f_exit)
		cur_sector->f_exit(game, cur_sector);
	if (h_o + PLAYER_CLIMB - p_h < n_sector->floor
	|| h_o + (n_sector->floor - cur_sector->floor) > n_sector->ceil)
		return (FALSE);
	if (h_o > n_sector->floor + p_h)
		player->heightoffset += player->height - (n_sector->floor + p_h);
	else
		player->heightoffset = 0.0001;
	if (is_helddown(game->keymap, game->setting->controls.crouch) == FALSE)
		player->player_height = PLAYER_HEIGHT;
	player->cur_sector = next_sector;
	player->height = n_sector->floor + p_h;
	if (n_sector->f_enter)
		n_sector->f_enter(game, n_sector);
	return (TRUE);
}

t_bool				player_col(t_game *game, float xspeed, float yspeed)
{
	t_tricoord	pos;
	t_uint8		col;
	t_uint32	next_sector;
	t_player	*player = game->player;
	t_map		*map = game->map;

	pos.x = (t_coord){player->pos.x + xspeed, player->pos.y};
	pos.y = (t_coord){player->pos.x, player->pos.y + yspeed};
	pos.xy = (t_coord){player->pos.x + xspeed, player->pos.y + yspeed};
	col = 0;
	next_sector = check_col(game, player, &col, map, pos);
	if (col == 7)
		return (FALSE);
	if (next_sector != UINT32_MAX
	&& switch_sector(game, map, player, next_sector) == FALSE)
		return (FALSE);
	player_move_col(col, player, pos);
	return (TRUE);
}
