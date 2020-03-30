/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_shoot.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 15:45:07 by euan           #+#    #+#                */
/*   Updated: 2020/03/30 18:31:38 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "rinfo.h"
#include "audio.h"
#include "game.h"

void		player_shoot(t_game *game, t_player *plyr)
{
	t_object	*obj;
	t_enemy		*en;

	obj = raycast_object(game, game->map, plyr);
	if (obj == NULL || obj->is_enemy == FALSE || plyr->ammo <= 0)
		return ;
	en = obj->data;
	en->health -= PLAYER_SHOT_DAMAGE;
	if (en->health <= 0)
		en->state = ENEMY_DEAD;
	plyr->ammo--;
}
