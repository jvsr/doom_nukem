/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_collision.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 15:17:21 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:34:12 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "cmath.h"
#include "coord.h"

t_coord		*get_collision(t_coord *start,
									t_coord *a, t_coord *wall, t_coord *pos)
{
	float	d;
	float	dx;
	float	dy;
	t_coord	vec;

	dx = wall[0].x - wall[1].x;
	dy = wall[0].y - wall[1].y;
	d = (dx * -a->y) - (dy * -a->x);
	if (d == 0)
		return (NULL);
	vec.x = (((wall[0].x - start->x) * -a->y) -
		((wall[0].y - start->y) * -a->x)) / d;
	vec.y = -((dx * (wall[0].y - start->y)) -
		(dy * (wall[0].x - start->x))) / d;
	if (vec.x > 0 && vec.x < 1 && vec.y > 0)
	{
		pos->x = wall[0].x + (vec.x * -dx);
		pos->y = wall[0].y + (vec.x * -dy);
		return (pos);
	}
	return (NULL);
}
