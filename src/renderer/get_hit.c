/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_hit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 18:15:20 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/14 17:33:32 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rinfo.h"
#include "player.h"
#include "cmath.h"

t_hit	get_hit(t_coord *cosin,
						t_player *player, t_sector *sector, t_sector *prev)
{
	t_uint64	i;
	t_wall		*walls;
	t_hit		hit;
	t_coord		val;
	float		dist;

	i = 0;
	walls = sector->walls;
	hit.dist = MAX_HIT;
	while (i < sector->wall_count)
	{
		if (!(prev != NULL && walls[i].is_portal && walls[i].window == prev) &&
			get_collision(&player->pos, cosin,
			(t_coord[2]){walls[i].corner_0, walls[i].corner_1}, &val))
		{
			dist = get_distance(&player->pos, &val);
			if (dist < hit.dist)
				hit = (t_hit){dist, dist, val, &walls[i], sector, 0};
		}
		i++;
	}
	return (hit);
}
