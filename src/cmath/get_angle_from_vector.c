/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_angle_from_vector.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:37:51 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/22 13:37:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <cmath.h>
#include "coord.h"

float	get_angle_from_vector(t_coord *vec)
{
	return (atan(vec->y / vec->x) * PI_D);
}
