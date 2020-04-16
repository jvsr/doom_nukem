/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_angle_from_vector.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:37:51 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:34:25 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <cmath.h>
#include "coord.h"

float	get_angle_from_vector(t_coord *vec)
{
	return (wrap_angle(atan(vec->y / vec->x) * PI_D));
}
