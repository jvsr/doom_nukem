/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   click_on_door.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 15:05:27 by euan          #+#    #+#                 */
/*   Updated: 2020/04/14 20:17:26 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "player.h"
#include "audio.h"
#include "rinfo.h"

void		click_on_door(t_player *plyr, t_game *game)
{
	t_wall	*ray;

	ray = raycast_wall(game->map->sectors + plyr->cur_sector, plyr, TRUE, TRUE);
	if (ray == NULL || ray->is_door == FALSE || plyr->keys == 0)
		return ;
	plyr->keys--;
	play_sound(game->audio_man, "door_unlock");
	ray->is_door = FALSE;
	ray->is_portal = TRUE;
	ray->texture.left[0] = TEXTURE_BRICK_WALL;
}
