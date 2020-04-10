/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_angle_from_vectors.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:19:58 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/07 15:59:11 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cmath.h"
#include "coord.h"

float	get_angle_from_vectors(t_coord *vec0, t_coord *vec1)
{
	float top;
	float bottom;

	top = dot_vectors(vec0, vec1);
	bottom = get_vector_magnitude(vec0) * get_vector_magnitude(vec1);
	return (wrap_angle(acos(top / bottom) * PI_D));
}
