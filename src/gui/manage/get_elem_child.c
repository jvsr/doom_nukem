/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_elem_child.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/06 11:27:49 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:13:08 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"

static t_transform	*get_child(t_transform *child, const char *name)
{
	t_transform	*found;

	found = NULL;
	while (child != NULL)
	{
		if (ft_strequ_nocase(child->name, name) == TRUE)
			return (child);
		if (child->gui_type == PANEL)
			found = get_child(child->gui_elem.panel->children, name);
		if (found != NULL)
			return (found);
		child = child->next;
	}
	return (NULL);
}

t_transform			*get_elem_child(t_transform *elem, const char *name)
{
	if (elem->gui_type != PANEL)
		return (NULL);
	return (get_child(elem->gui_elem.panel->children, name));
}
