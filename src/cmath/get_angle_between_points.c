/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_angle_between_points.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 15:57:50 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:34:32 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cmath.h"
#include "coord.h"

float		get_angle_between_points(t_coord *a, t_coord *b)
{
	return (wrap_angle(atan2(b->y - a->y, b->x - a->x) * PI_D));
}
