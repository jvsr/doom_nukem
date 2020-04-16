/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_slope.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 11:44:27 by euan          #+#    #+#                 */
/*   Updated: 2020/04/09 13:45:09 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "rinfo.h"
#include "cmath.h"

static float	slope(t_sector *sec,
								t_player *pyr, t_coord *cn[2], t_coord *pos)
{
	t_coord v0;
	t_coord v1;
	t_coord v2;
	float	tmp;

	get_vector_from_points(cn[0], pos, &v0);
	get_vector_from_points(cn[0], cn[1], &v1);
	normalize_vector(&v0);
	normalize_vector(&v1);
	tmp = dot_vectors(&v0, &v1);
	v2 = (t_coord){cn[0]->x + (v1.x * tmp), cn[1]->y + (v1.y * tmp)};
	tmp = get_distance(&v2, pos);
	return (sec->floor + pyr->player_height - (tmp * tan(PI_R * sec->angle)));
}

float			player_slope(t_player *pyr, t_sector *sec, t_coord *pos)
{
	t_wall	*sw;
	float	a;
	float	b;

	if (sec->has_slope == FALSE)
		return (0);
	sw = sec->swall;
	a = get_distance(pos, &sw->corner_0);
	b = get_distance(pos, &sw->corner_1);
	if (a < b)
	{
		return (slope(sec, pyr, (t_coord*[2]){&sw->corner_0, &sw->corner_1},
		pos));
	}
	return (slope(sec, pyr, (t_coord*[2]){&sw->corner_1, &sw->corner_0}, pos));
}
