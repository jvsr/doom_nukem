/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_vector_from_points.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 16:26:48 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:33:50 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "coord.h"

t_coord		*get_vector_from_points(t_coord *pos0, t_coord *pos1, t_coord *vec)
{
	vec->x = pos1->x - pos0->x;
	vec->y = pos1->y - pos0->y;
	return (vec);
}
