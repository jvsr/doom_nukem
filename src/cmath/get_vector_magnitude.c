/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_vector_magnitude.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 16:18:03 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/22 16:18:03 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "coord.h"

float		get_vector_magnitude(t_coord *vec)
{
	return (sqrt(pow(vec->x, 2) + pow(vec->y, 2)));
}
