/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spike_damage.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 11:35:36 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:55:51 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "rinfo.h"
#include "game.h"

void	spike_damage(t_game *game,
							t_sector *sec, t_object *obj, t_player *player)
{
	const t_uint32	damage = 10;
	t_uint64		cur_time;
	t_uint64		*last_time;

	(void)sec;
	last_time = (t_uint64*)obj->data;
	if (*last_time == 0)
	{
		*last_time = get_gametime(&game->starttime);
		damage_player(game, player, damage);
	}
	cur_time = get_gametime(&game->starttime);
	if (cur_time - *last_time > DAMAGE_REPEAT_SPEED)
	{
		*last_time = cur_time;
		damage_player(game, player, damage);
	}
}
