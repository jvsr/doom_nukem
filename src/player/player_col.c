/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_col.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 17:24:34 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/15 18:49:40 by euan          ########   odam.nl         */
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
#include <limits.h>

static void		move_pos_col(t_uint8 col, t_coord *new_pos, t_tricoord pos)
{
	if (col == 0)
		ft_memcpy(new_pos, &pos.xy, sizeof(pos.xy));
	else
	{
		if ((col & 3) == 0)
			ft_memcpy(new_pos, &pos.x, sizeof(pos.x));
		else if ((col & 1) == 0)
			ft_memcpy(new_pos, &pos.x, sizeof(pos.x));
		else if ((col & 2) == 0)
			ft_memcpy(new_pos, &pos.y, sizeof(pos.y));
	}
}

static t_bool	switch_sector(t_game *game, t_map *map, t_player *player,
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

t_bool			player_col(t_game *game, float xspeed, float yspeed)
{
	t_tricoord	pos;
	t_uint8		col;
	t_coord		new_pos;
	t_uint32	next_sector;
	t_player	*player;

	player = game->player;
	pos.x = (t_coord){player->pos.x + xspeed, player->pos.y};
	pos.y = (t_coord){player->pos.x, player->pos.y + yspeed};
	pos.xy = (t_coord){player->pos.x + xspeed, player->pos.y + yspeed};
	col = 0;
	check_walls(game, &col, &game->map->sectors[player->cur_sector], pos);
	check_objects(game, &col, pos);
	if (col == 7)
		return (FALSE);
	move_pos_col(col, &new_pos, pos);
	next_sector = player_get_sector(player, game->map, &new_pos);
	if (next_sector != player->cur_sector &&
		switch_sector(game, game->map, player, next_sector) == FALSE)
		return (FALSE);
	ft_memcpy(&player->pos, &new_pos, sizeof(t_coord));
	return (TRUE);
}
