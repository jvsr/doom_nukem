/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_add_object.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:37:31 by pholster      #+#    #+#                 */
/*   Updated: 2020/01/23 17:37:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"

#include "error.h"
#include "map_editor.h"

void			map_editor_add_object(t_editor_map *editor_map,
					t_editor_object *object)
{
	t_list	*new;

	new = ft_lstnew((void*)object, sizeof(t_editor_object));
	if (new == NULL)
		error_msg_errno("Failed to alloc map editor object");
	ft_lstaddbck(&editor_map->objects, new);
}
