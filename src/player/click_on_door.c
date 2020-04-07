/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   click_on_door.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 15:05:27 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 12:55:08 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "rinfo.h"

void		click_on_door(t_player *plyr, t_map *map)
{
	t_wall	*ray;

	ray = raycast_wall(map->sectors + plyr->cur_sector, plyr, TRUE, TRUE);
	if (ray == NULL || ray->is_door == FALSE || plyr->keys == 0)
		return ;
	plyr->keys--;
	ray->is_door = FALSE;
	ray->is_portal = TRUE;
}
