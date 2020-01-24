/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_remove_last_wall.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:37:31 by pholster       #+#    #+#                */
/*   Updated: 2020/01/23 17:37:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"

#include "gui.h"
#include "map_editor.h"

void	map_editor_remove_last_wall(t_transform *map_editor_elem)
{
	t_list	*lst;
	t_list	*prv;

	prv = NULL;
	lst = map_editor_elem->gui_elem.map_editor->wall;
	while (lst != NULL && lst->next != NULL)
	{
		prv = lst;
		lst = lst->next;
	}
	if (prv != NULL)
		prv->next = NULL;
	else
		map_editor_elem->gui_elem.map_editor->wall = NULL;
	ft_lstdel(&lst, &ft_lstdelmem);
	set_elem_redraw(map_editor_elem);
}
