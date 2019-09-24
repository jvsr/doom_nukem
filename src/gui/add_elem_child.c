/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_elem_child.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 11:02:33 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:54:30 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void		add_elem_child(t_transform *parent, t_transform *child)
{
	child->parent_type = ELEM;
	child->parent.elem = parent;
	add_to_children(&parent->gui_elem.panel->children, child);
	set_elem_redraw(child);
}
