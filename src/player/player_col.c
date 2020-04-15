/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_col.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 17:24:34 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/15 17:40:13 by euan          ########   odam.nl         */
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

void		check_portals(t_game *game, t_uint8 *col, t_list **portals,
								t_col col_inf)
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
		if (((*col & 1) == 0 && wall_col(col_inf.coord.x, player->pos, wall))
		|| ((*col & 2) == 0 && wall_col(col_inf.coord.y, player->pos, wall))
		|| (*col == 0 && wall_col(col_inf.coord.xy, player->pos, wall)))
		{
			*col_inf.prev_sector = player->cur_sector;
			*col_inf.next_sector = get_sector_id(game->map, (*wall).window);
			temp = player->cur_sector;
			player->cur_sector = *col_inf.next_sector;
			check_col(game, player, col, col_inf.coord);
			player->cur_sector = temp;
		}
		ft_lstdelone(portals, NULL);
		(*portals) = next_portal;
	}
}

t_uint32	check_col(t_game *game, t_player *player, t_uint8 *col,
															t_tricoord coord)
{
	t_uint32		next_sector;
	t_list			*portals;
	const t_uint32	temp = player->cur_sector;
	static t_uint32	p_sec = UINT32_MAX;

	next_sector = UINT32_MAX;
	if (p_sec == UINT32_MAX)
		p_sec = player->cur_sector;
	portals = check_walls(game, col, coord, p_sec);
	check_objects(game, col, coord);
	if (*col == 7)
	{
		player->cur_sector = temp;
		p_sec = UINT32_MAX;
		ft_lstdel(&portals, NULL);
		return (UINT32_MAX);
	}
	// check_portals(game, col, &portals, (t_col){coord, &p_sec, &next_sector});
	if (*col == 7)
	{
		player->cur_sector = temp;
		return (UINT32_MAX);
	}
	p_sec = UINT32_MAX;
	return (next_sector);
}

static void	player_move_col(t_uint8 col, t_player *player,
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

t_bool		switch_sector(t_game *game, t_map *map, t_player *player,
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

t_bool		player_col(t_game *game, float xspeed, float yspeed)
{
	t_tricoord	pos;
	t_uint8		col;
	t_uint32	next_sector;
	t_map		*map;
	t_player	*player;

	player = game->player;
	map = game->map;
	pos.x = (t_coord){player->pos.x + xspeed, player->pos.y};
	pos.y = (t_coord){player->pos.x, player->pos.y + yspeed};
	pos.xy = (t_coord){player->pos.x + xspeed, player->pos.y + yspeed};
	col = 0;
	next_sector = check_col(game, player, &col, pos);
	if (col == 7)
		return (FALSE);
	if (next_sector != UINT32_MAX
	&& switch_sector(game, map, player, next_sector) == FALSE)
		return (FALSE);
	player_move_col(col, player, pos);
	player->cur_sector = player_get_sector(player, map);
	return (TRUE);
}
