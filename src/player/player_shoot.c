/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_shoot.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 15:45:07 by euan          #+#    #+#                 */
/*   Updated: 2020/04/15 17:09:13 by euan          ########   odam.nl         */
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

	if (plyr->ammo <= 0)
		return ;
	obj = raycast_object(game, game->map, plyr);
	plyr->ammo--;
	play_sound(game->audio_man, "shotgun");
	if (obj == NULL || obj->is_enemy == FALSE)
		return ;
	en = obj->data;
	en->health -= PLAYER_SHOT_DAMAGE;
	if (en->health <= 0)
	{
		en->state = ENEMY_DEAD;
		obj->can_col = FALSE;
	}
}
