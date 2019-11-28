/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dot_vectors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 16:15:19 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/22 16:15:19 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"

float		dot_vectors(t_coord *vec0, t_coord *vec1)
{
	return ((vec0->x * vec1->x) + (vec0->y * vec1->y));
}
