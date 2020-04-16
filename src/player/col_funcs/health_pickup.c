/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   health_pickup.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 16:03:32 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/15 12:32:56 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_bool.h"
#include "player.h"
#include "types.h"
#include "rinfo.h"
#include "audio.h"
#include "game.h"

void	health_pickup(t_game *game,
							t_sector *sec, t_object *obj, t_player *player)
{
	const int	health_add = 10;
	t_list		*lst;

	if (player->health == PLAYER_MAX_HEALTH)
		return ;
	if (player->health + health_add > PLAYER_MAX_HEALTH)
		player->health = PLAYER_MAX_HEALTH;
	else
		player->health += health_add;
	play_sound(game->audio_man, "health_pickup");
	lst = ft_lstfind_content(sec->objects, (void*)obj, sizeof(t_object));
	if (lst == NULL)
		return ;
	ft_lstunlink(&sec->objects, lst);
	ft_lstdelone(&lst, ft_lstdelmem);
	sec->object_count--;
}
