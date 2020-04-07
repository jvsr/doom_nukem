/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_elem_child.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 11:02:33 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:12:18 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"

static t_transform	*get_elem_root_children(t_transform *elem)
{
	while (elem->parent_type != PARENT_UNDEFINED)
	{
		if (elem->parent_type == GUI)
			return (elem->parent.ui->children);
		elem = elem->parent.elem;
	}
	return (elem->gui_elem.panel->children);
}

void				add_elem_child(t_transform *parent, t_transform *child)
{
	child->parent_type = ELEM;
	child->parent.elem = parent;
	check_elem_duplicate(get_elem_root_children(child), child);
	add_to_children(&parent->gui_elem.panel->children, child);
	set_elem_redraw(child);
}
