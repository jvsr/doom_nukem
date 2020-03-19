/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_slope.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 11:44:27 by euan           #+#    #+#                */
/*   Updated: 2020/03/19 14:08:32 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "rinfo.h"
#include "cmath.h"

static float	slope(t_sector *sec,
								t_player *pyr, t_coord *cn_0, t_coord *cn_1)
{
	t_coord v0;
	t_coord v1;
	t_coord v2;
	float	tmp;

	get_vector_from_points(cn_0, &pyr->pos, &v0);
	get_vector_from_points(cn_0, cn_1, &v1);
	tmp = dot_vectors(&v0, &v1) / dot_vectors(&v1, &v1);
	v2 = (t_coord){cn_0->x + (v1.x * tmp), cn_1->y + (v1.y * tmp)};
	tmp = get_distance(&v2, &pyr->pos);
	return (sec->floor + pyr->player_height - (tmp * tan(PI_R * sec->angle)));
}

float			player_slope(t_player *pyr, t_sector *sec)
{
	t_wall	*sw;
	float	a;
	float	b;

	sw = sec->swall;
	a = get_distance(&pyr->pos, &sw->corner_0);
	b = get_distance(&pyr->pos, &sw->corner_1);
	if (a < b)
		return (slope(sec, pyr, &sw->corner_0, &sw->corner_1));
	return (slope(sec, pyr, &sw->corner_1, &sw->corner_0));
}
