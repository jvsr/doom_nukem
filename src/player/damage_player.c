/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   damage_player.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 11:39:23 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:55:26 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"

void	damage_player(t_game *game, t_player *player, t_uint32 damage)
{
	(void)game;
	if (player->health <= damage)
	{
		player->health = 0;
		player->is_dead = TRUE;
	}
	else
		player->health -= damage;
}
