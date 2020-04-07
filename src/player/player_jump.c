/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_jump.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 21:42:49 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 13:07:37 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "game.h"
#include "rinfo.h"
#include "setting.h"
#include "cmath.h"
#include "player.h"

static t_bool	move_jump_bool(t_game *game,
						t_player *player, float old_height, float new_height)
{
	return ((game->map->sectors[player->cur_sector].has_ceiling &&
	player->height + player->heightoffset + new_height - old_height
	>= game->map->sectors[player->cur_sector].ceil));
}

t_bool			move_jump(t_game *game, t_player *player, t_bool *jump)
{
	static uint64_t	momentum = UINT64_MAX;
	static float	old_height;
	float			new_height;
	uint64_t		cur;

	*jump = TRUE;
	if (momentum == UINT64_MAX)
	{
		old_height = 0;
		momentum = get_gametime(&game->starttime);
	}
	cur = get_gametime(&game->starttime) - momentum;
	new_height = PLAYER_INIT_JUMP_HEIGHT - (PLAYER_INIT_JUMP_HEIGHT
	* pow(1.0 - ((double)cur / PLAYER_JUMP_TIME), 2));
	if (cur > PLAYER_JUMP_TIME
	|| move_jump_bool(game, player, old_height, new_height))
	{
		*jump = FALSE;
		momentum = UINT64_MAX;
		return (FALSE);
	}
	player->heightoffset += new_height - old_height;
	old_height = new_height;
	return (TRUE);
}

t_bool			move_down(t_game *game, t_player *player, t_bool *jump)
{
	static uint64_t	momentum = UINT64_MAX;
	static float	old_drop;
	float			new_drop;
	uint64_t		cur;

	if (momentum == UINT64_MAX)
	{
		old_drop = 0;
		momentum = get_gametime(&game->starttime);
	}
	cur = get_gametime(&game->starttime) - momentum;
	new_drop = PLAYER_INIT_JUMP_HEIGHT * pow((double)cur / PLAYER_JUMP_TIME, 2);
	player->heightoffset -= new_drop - old_drop;
	old_drop = new_drop;
	if (player->heightoffset <= 0)
	{
		*jump = FALSE;
		player->heightoffset = 0;
		momentum = UINT64_MAX;
	}
	return (TRUE);
}

t_bool			fly_up(t_game *game, t_player *player, t_bool *jump)
{
	static float	height_to_go = 400;
	float			diff;

	diff = lerp(0, height_to_go, (float)game->lastframe / PLAYER_FLY_SPEED);
	if (player->height + player->heightoffset + diff
	< game->map->sectors[player->cur_sector].ceil)
		player->heightoffset += diff;
	*jump = TRUE;
	return (TRUE);
}

t_bool			fly_down(t_game *game, t_player *player, t_bool *jump)
{
	static float	height_to_go = 400;
	float			diff;

	diff = lerp(0, height_to_go, (float)game->lastframe / PLAYER_FLY_SPEED);
	if (player->heightoffset - diff < 0)
		player->heightoffset = 0;
	else if (player->height + player->heightoffset - diff
	> game->map->sectors[player->cur_sector].floor)
		player->heightoffset -= diff;
	*jump = FALSE;
	return (TRUE);
}
