/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_del_object.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 15:04:41 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/12 15:04:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_list.h"

#include "game.h"
#include "map_editor.h"

static t_bool	on_point(t_editor_object *object, t_editor_object *other)
{
	return (ft_memequ(&object->pos, &other->pos, sizeof(t_coord)));
}

void			map_editor_del_object(t_editor_map *editor_map,
					t_editor_object *object)
{
	t_list	*lst;
	t_list	*next;

	lst = editor_map->objects;
	while (lst != NULL)
	{
		next = lst->next;
		if (on_point(object, lst->content) == TRUE)
		{
			ft_lstunlink(&editor_map->objects, lst);
			ft_lstdelone(&lst, &ft_lstdelmem);
		}
		lst = next;
	}
}
