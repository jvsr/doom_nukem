/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_angle_between_pointsv.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:13:11 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:34:28 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cmath.h"
#include "coord.h"

float	get_angle_between_pointsv(t_coord *pos0, t_coord *pos1)
{
	t_coord point;

	get_vector_from_points(pos0, pos1, &point);
	return (get_angle_from_vector(&point));
}
