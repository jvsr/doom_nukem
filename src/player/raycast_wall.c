/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_wall.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 14:44:20 by euan           #+#    #+#                */
/*   Updated: 2020/03/30 15:08:29 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "player.h"
#include "rinfo.h"
#include "cmath.h"

static t_wall	*ray(t_sector *secs, t_sector *prv, t_player *plyr, t_bool ip)
{
	t_uint64	i;
	t_coord		vec;
	t_wall		*wall;

	i = 0;
	while (i < secs->wall_count)
	{
		wall = secs->walls + i;
		if (get_collision(&plyr->pos, (t_coord*)(&plyr->mag), (t_coord[2]){
			wall->corner_0, wall->corner_1}, &vec) != NULL &&
			get_distance(&plyr->pos, &vec) <= PLAYER_GRAB_DIST)
		{
			if (!wall->is_portal)
				return (wall);
			else if (ip == FALSE)
				return (wall);
			else if (wall->window != prv)
				return (ray(wall->window, secs, plyr, ip));
		}
		i++;
	}
	return (NULL);
}

t_wall		*raycast_wall(t_sector *sec, t_player *plyr, t_bool ignore_portal)
{
	return (ray(sec, NULL, plyr, ignore_portal));
}
