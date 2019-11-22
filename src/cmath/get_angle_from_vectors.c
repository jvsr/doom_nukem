/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_angle_from_vectors.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:19:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/22 13:19:58 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "coord.h"

float	get_angle_from_vectors(t_coord *vec0, t_coord *vec1)
{
	float top;
	float bottom;

	top = (vec0->x * vec1->x) + (vec0->y * vec1->y);
	bottom = sqrt(pow(vec0->x, 2) + pow(vec0->y, 2)) *
			sqrt(pow(vec1->x, 2) + pow(vec1->y, 2));
	return (top / bottom);
}
