/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_distance.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 15:20:47 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/25 15:20:47 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "coord.h"

float		get_distance(t_coord *pos0, t_coord *pos1)
{
	return (sqrt(pow(pos1->x - pos0->x, 2) + pow(pos1->y - pos0->y, 2)));
}
