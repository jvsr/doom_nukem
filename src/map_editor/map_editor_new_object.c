/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_new_object.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:37:31 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/13 18:18:26 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "error.h"
#include "map_editor.h"

t_editor_object	*map_editor_new_object(t_editor_map *editor_map, t_obj type,
					t_coord pos)
{
	t_editor_object	*new;

	new = (t_editor_object*)ft_memalloc(sizeof(t_editor_object));
	if (new == NULL)
		error_msg_errno("Failed to alloc new map editor object");
	new->pos = pos;
	new->type = type;
	if (map_editor_add_object(editor_map, new) == FALSE)
		return (NULL);
	return (new);
}
