/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_slope.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/17 12:16:51 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 10:52:54 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cmath.h"
#include "rinfo.h"

static int		get_slope_1(t_hitem *item, t_wall *sw, float ang, t_rinfo *rin)
{
	t_coord	v0;
	t_coord	v1;
	t_coord v2;
	float	tmp;

	get_vector_from_points(&sw->corner_1, &item->hit.pos, &v0);
	get_vector_from_points(&sw->corner_1, &sw->corner_0, &v1);
	normalize_vector(&v0);
	normalize_vector(&v1);
	tmp = dot_vectors(&v0, &v1);
	v2 = (t_coord){sw->corner_1.x + (v1.x * tmp),
				sw->corner_1.y + (v1.y * tmp)};
	tmp = get_distance(&v2, &item->hit.pos);
	item->tang = tan(PI_R * ang);
	return ((((item->tang * tmp) + item->hit.sect->floor) /
		item->st.x) * rin->dst->h);
}

static int		get_slope_0(t_hitem *item, t_wall *sw, float ang, t_rinfo *rin)
{
	t_coord	v0;
	t_coord	v1;
	t_coord v2;
	float	tmp;

	get_vector_from_points(&sw->corner_0, &item->hit.pos, &v0);
	get_vector_from_points(&sw->corner_0, &sw->corner_1, &v1);
	normalize_vector(&v0);
	normalize_vector(&v1);
	tmp = dot_vectors(&v0, &v1);
	v2 = (t_coord){sw->corner_0.x + (v1.x * tmp),
				sw->corner_0.y + (v1.y * tmp)};
	tmp = get_distance(&v2, &item->hit.pos);
	item->tang = tan(PI_R * ang);
	return ((((item->tang * tmp) + item->hit.sect->floor) /
		item->st.x) * rin->dst->h);
}

int				get_slope(t_hitem *item, t_wall *sw, float ang, t_rinfo *rin)
{
	float a;
	float b;

	a = get_distance(&item->hit.pos, &sw->corner_0);
	b = get_distance(&item->hit.pos, &sw->corner_1);
	if (a < b)
		return (get_slope_0(item, sw, ang, rin));
	return (get_slope_1(item, sw, ang, rin));
}
