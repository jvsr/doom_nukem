/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_collision.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 15:17:21 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/14 15:17:21 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "coord.h"

t_coord		*get_collision(t_coord *start,
									t_coord *a, t_coord *wall, t_coord *pos)
{
	float	x;
	float	y;
	float	d;
	t_coord	vec;

	x = start->x + a->x;
	y = start->y + a->y;
	d = ((wall[0].x - wall[1].x) * (start->y - y)) -
		((wall[0].y - wall[1].y) * (start->x - x));
	if (d == 0)
		return (NULL);
	vec.x = (((wall[0].x - start->x) * (start->y - y)) -
		((wall[0].y - start->y) * (start->x - x))) / d;
	vec.y = -(((wall[0].x - wall[1].x) * (wall[0].y - start->y)) -
		((wall[0].y - wall[1].y) * (wall[0].x - start->x))) / d;
	if (vec.x > 0 && vec.x < 1 && vec.y > 0)
	{
		pos->x = wall[0].x + (vec.x * (wall[1].x - wall[0].x));
		pos->y = wall[0].y + (vec.x * (wall[1].y - wall[0].y));
		return (pos);
	}
	return (NULL);
}
