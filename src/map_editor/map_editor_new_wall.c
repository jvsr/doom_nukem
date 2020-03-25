/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_new_wall.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:37:31 by pholster       #+#    #+#                */
/*   Updated: 2020/01/23 17:37:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "error.h"
#include "rinfo.h"
#include "map_editor.h"

t_editor_wall		*map_editor_new_wall(t_editor_map *editor_map, t_coord corner_0,
				t_coord corner_1)
{
	t_editor_wall	*new;

	new = (t_editor_wall*)ft_memalloc(sizeof(t_editor_wall));
	if (new == NULL)
		error_msg_errno("Failed to alloc new map editor wall");
	new->corner_0 = corner_0;
	new->corner_1 = corner_1;
	map_editor_add_wall(editor_map, new);
	return (new);
}
