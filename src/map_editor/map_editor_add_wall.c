/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_add_wall.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:37:31 by pholster       #+#    #+#                */
/*   Updated: 2020/01/23 17:37:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"

#include "gui.h"
#include "rinfo.h"
#include "error.h"
#include "map_editor.h"

/*
** Todo Detect if line is inside other line and prevent placing
*/

static t_bool		line_invalid(t_wall *wall, t_wall *compare_wall)
{
	t_coord tmp_corner;
	t_bool	equal;

	if (ft_memequ(wall, compare_wall, sizeof(t_wall)))
		return (TRUE);
	tmp_corner = wall->corner_0;
	wall->corner_0 = wall->corner_1;
	wall->corner_1 = tmp_corner;
	equal = ft_memequ(wall, compare_wall, sizeof(t_wall));
	wall->corner_1 = wall->corner_0;
	wall->corner_0 = tmp_corner;
	return (equal);
}

static void		add_to_back(t_list **head, t_list *new)
{
	t_wall	*new_wall;
	t_wall	*wall;
	t_list	*lst;

	lst = *head;
	new_wall = (t_wall*)new->content;
	while (lst != NULL)
	{
		wall = (t_wall*)lst->content;
		if (line_invalid(new_wall, wall))
		{
			ft_lstdel(&new, ft_lstdelmem);
			return ;
		}
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	if (lst == NULL)
		*head = new;
	else
		lst->next = new;
	return ;
}

void	map_editor_add_wall(t_transform *map_editor_elem, t_wall *wall)
{
	t_list	*new;

	new = ft_lstnew((void*)wall, sizeof(t_wall));
	if (new == NULL)
		error_msg_errno("Failed to alloc map editor wall");
	add_to_back(&map_editor_elem->gui_elem.map_editor->wall, new);
	set_elem_redraw(map_editor_elem);
}
