/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize_vector.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 14:41:14 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 11:33:17 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"
#include "cmath.h"

t_coord		*normalize_vector(t_coord *vec)
{
	float mag;

	mag = get_vector_magnitude(vec);
	vec->x /= mag;
	vec->y /= mag;
	return (vec);
}
