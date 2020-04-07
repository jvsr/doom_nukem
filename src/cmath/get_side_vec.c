/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_side_vec.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 14:39:55 by euan          #+#    #+#                 */
/*   Updated: 2020/04/07 14:53:10 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"
#include "cmath.h"

int			get_side_vec(t_coord *v0, t_coord *v1, int is_clockwise)
{
	float dot;

	dot = dot_vectors(v0, v1);
	if ((is_clockwise && dot >= 0) || (!is_clockwise && dot <= 0))
		return (1);
	return (-1);
}
