/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 16:37:51 by ehollidg       #+#    #+#                */
/*   Updated: 2020/03/30 12:42:18 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "cmath.h"
#include "game.h"
#include "loop.h"
#include "enemy.h"
#include "player.h"

void		loop_game(t_game *game)
{
	player_move(game);
	enemy_move(game);
	loop_game_gui(game);
	if (game->player->is_dead)
		player_died(game);
	if (game->map->has_won)
		player_won(game);
}
