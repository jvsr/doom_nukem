/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_vector_from_angle.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 16:05:32 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:33:54 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cmath.h"
#include "coord.h"

t_coord		*get_vector_from_angle(float angle, t_coord *vec)
{
	vec->x = cos(angle * PI_R);
	vec->y = sin(angle * PI_R);
	return (vec);
}
