/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy_on_los.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 13:49:28 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 11:37:27 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "rinfo.h"
#include "audio.h"
#include "player.h"

void	shooty_func(t_game *game, t_object *obj, t_player *plr)
{
	t_enemy	*enemy;

	enemy = obj->data;
	enemy->last_seen += game->lastframe;
	if (enemy->last_seen > 2000)
	{
		damage_player(game, plr, 2);
		play_sound(game->audio_man, "singleshot");
		enemy->last_seen = 0;
	}
}
