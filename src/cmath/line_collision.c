/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line_collision.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:42:41 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/06 16:42:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"
#include "cmath.h"

t_bool	line_collision(t_bicoord *line1, t_bicoord *line2)
{
	t_coord	result;

	return (get_line_collision(line1, line2, &result) != NULL);
}
