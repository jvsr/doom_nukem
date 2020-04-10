/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_side_vec.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 21:17:24 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/10 13:02:41 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"
#include "cmath.h"

static float	dot_side(t_coord *v0, t_coord *v1)
{
	return (-v0->x * v1->y + v0->y * v1->x);
}

int				get_side_vec(t_coord *v0, t_coord *v1, int is_clockwise)
{
	float dot;

	dot = dot_side(v0, v1);
	if ((is_clockwise && dot >= 0) || (!is_clockwise && dot <= 0))
		return (1);
	return (-1);
}
