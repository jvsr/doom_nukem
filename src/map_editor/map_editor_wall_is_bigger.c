/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_wall_is_bigger.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/26 11:17:02 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/26 11:17:02 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cmath.h"
#include "map_editor.h"

t_bool	map_editor_wall_is_bigger(t_editor_wall *wall, t_editor_wall *other)
{
	t_coord	other_vec;
	t_coord	wall_vec;

	get_vector_from_points(&other->corner_0, &other->corner_1, &other_vec);
	get_vector_from_points(&wall->corner_0, &wall->corner_1, &wall_vec);
	if (get_vector_magnitude(&wall_vec) > get_vector_magnitude(&other_vec))
		return (TRUE);
	return (FALSE);
}
