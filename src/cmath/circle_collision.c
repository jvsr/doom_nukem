/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   circle_collision.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:42:41 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/06 16:42:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"
#include "cmath.h"

t_bool	circle_collision(t_bicoord *line, t_coord *circle_mid, float radius)
{
	t_coord circle_vec;
	t_coord	line_vec;
	t_coord	coord_on_line;
	float	dot_product;

	get_vector_from_points(&line->pos1, &line->pos2, &line_vec);
	get_vector_from_points(&line->pos1, circle_mid, &circle_vec);
	dot_product = dot_vectors(&circle_vec, &line_vec) /
					dot_vectors(&line_vec, &line_vec);
	dot_product = clamp_float(dot_product, 0, 1);
	coord_on_line = (t_coord){line->pos1.x + (line_vec.x * dot_product),
						line->pos1.y + (line_vec.y * dot_product)};
	return ((get_distance(&coord_on_line, circle_mid) - radius) <= 0);
}
