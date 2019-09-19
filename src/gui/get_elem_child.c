/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_elem_child.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/06 11:27:49 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 14:24:12 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_string.h"

#include "gui.h"

t_transform		*get_elem_child(t_transform *elem, const char *name)
{
	t_transform	*found;
	t_transform	*cur;

	cur = elem;
	found = NULL;
	while (cur != NULL)
	{
		if (ft_strequ(cur->name, name))
			return (cur);
		if (cur->gui_type == PANEL)
			found = get_elem_child(cur->gui_elem.panel->children, name);
		if (found != NULL)
			return (found);
		cur = cur->next;
	}
	return (NULL);
}
