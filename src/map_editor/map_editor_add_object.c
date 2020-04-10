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
#include "libft/ft_mem.h"

#include "error.h"
#include "map_editor.h"

static t_bool	check_collision_valid(t_editor_object *object,
					t_editor_object *other)
{
	if (ft_memequ(&object->pos, &other->pos, sizeof(t_coord)))
		return (FALSE);
	return (TRUE);
}

static t_bool	add_to_back(t_editor_map *editor_map, t_list *new)
{
	t_editor_object	*new_object;
	t_list			*lst;
	t_bool			valid;

	valid = TRUE;
	lst = editor_map->objects;
	new_object = (t_editor_object*)new->content;
	while (lst != NULL)
	{
		valid = check_collision_valid(new_object, lst->content);
		if (valid == FALSE || lst->next == NULL)
			break ;
		lst = lst->next;
	}
	if (valid == FALSE)
	{
		ft_lstdel(&new, ft_lstdelmem);
		return (FALSE);
	}
	if (lst == NULL)
		editor_map->objects = new;
	else
		lst->next = new;
	return (TRUE);
}

t_bool			map_editor_add_object(t_editor_map *editor_map,
					t_editor_object *object)
{
	t_list	*new;

	new = ft_lstnew((void*)object, sizeof(t_editor_object));
	if (new == NULL)
		error_msg_errno("Failed to alloc map editor object");
	return (add_to_back(editor_map, new));
}
