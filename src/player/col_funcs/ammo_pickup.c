/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ammo_pickup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 14:06:05 by euan          #+#    #+#                 */
/*   Updated: 2020/04/15 12:33:07 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_bool.h"
#include "player.h"
#include "types.h"
#include "audio.h"
#include "rinfo.h"
#include "game.h"

void	ammo_pickup(t_game *game,
							t_sector *sec, t_object *obj, t_player *player)
{
	const int	ammo_add = 10;
	t_list		*lst;

	player->ammo += ammo_add;
	play_sound(game->audio_man, "ammo_pickup");
	lst = ft_lstfind_content(sec->objects, (void*)obj, sizeof(t_object));
	if (lst == NULL)
		return ;
	ft_lstunlink(&sec->objects, lst);
	ft_lstdelone(&lst, ft_lstdelmem);
	sec->object_count--;
}
