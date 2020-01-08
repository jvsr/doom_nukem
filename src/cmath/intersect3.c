/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect3.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:22:25 by ehollidg       #+#    #+#                */
/*   Updated: 2020/01/08 15:22:25 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"

static float	vec_cross_product(float x0, float y0, float x1, float y1)
{
	return ((x0 * y1) - (x1 * y0));
}

t_coord			intersect3(t_coord c0, t_coord c1, t_coord c2, t_coord c3)
{
	float x;
	float y;

	x = vec_cross_product(
			vec_cross_product(c0.x, c0.y, c1.x, c1.y), c0.x - c1.x,
			vec_cross_product(c2.x, c2.y, c3.x, c3.y), c2.x - c3.x) /
		vec_cross_product(c0.x - c1.x, c0.y - c1.y, c2.x - c3.x, c2.y - c3.y);
	y = vec_cross_product(
			vec_cross_product(c0.x, c0.y, c1.x, c1.y), c0.y - c1.y,
			vec_cross_product(c2.x, c2.y, c3.x, c3.y), c2.y - c3.y) /
		vec_cross_product(c0.x - c1.x, c0.y - c1.y, c2.x - c3.x, c2.y - c3.y);
	return ((t_coord){x, y});
}
