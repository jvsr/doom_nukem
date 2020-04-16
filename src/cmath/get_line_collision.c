/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_line_collision.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:42:41 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/06 16:42:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"
#include "cmath.h"

t_coord			*get_line_collision(t_bicoord *line1, t_bicoord *line2,
					t_coord *result)
{
	float	d;
	t_coord	vec;

	d = ((line2->pos1.x - line2->pos2.x) * (line1->pos1.y - line1->pos2.y)) -
		((line2->pos1.y - line2->pos2.y) * (line1->pos1.x - line1->pos2.x));
	if (d == 0)
		return (NULL);
	vec = (t_coord){
		(((line2->pos1.x - line1->pos1.x) * (line1->pos1.y - line1->pos2.y)) -
		((line2->pos1.y - line1->pos1.y) * (line1->pos1.x - line1->pos2.x))),
		-(((line2->pos1.x - line2->pos2.x) * (line2->pos1.y - line1->pos1.y)) -
		((line2->pos1.y - line2->pos2.y) * (line2->pos1.x - line1->pos1.x)))
	};
	vec = (t_coord){vec.x / d, vec.y / d};
	if (vec.x >= 0 && vec.x <= 1 && vec.y >= 0 && vec.y <= 1)
	{
		result->x = line2->pos1.x + (vec.x * (line2->pos2.x - line2->pos1.x));
		result->y = line2->pos1.y + (vec.x * (line2->pos2.y - line2->pos1.y));
		return (result);
	}
	return (NULL);
}
