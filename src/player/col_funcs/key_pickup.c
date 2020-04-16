/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_pickup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 15:20:57 by euan          #+#    #+#                 */
/*   Updated: 2020/04/15 12:33:03 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_bool.h"
#include "player.h"
#include "types.h"
#include "audio.h"
#include "rinfo.h"
#include "game.h"

void	key_pickup(t_game *game,
							t_sector *sec, t_object *obj, t_player *player)
{
	t_list		*lst;

	player->keys++;
	play_sound(game->audio_man, "key_pickup");
	lst = ft_lstfind_content(sec->objects, (void*)obj, sizeof(t_object));
	if (lst == NULL)
		return ;
	ft_lstunlink(&sec->objects, lst);
	ft_lstdelone(&lst, ft_lstdelmem);
	sec->object_count--;
}
