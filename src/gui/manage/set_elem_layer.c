/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_layer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 11:43:29 by pholster       #+#    #+#                */
/*   Updated: 2019/11/12 18:20:46 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"

#include "gui_internal.h"

void			set_elem_layer(t_transform *elem, short layer)
{
	t_transform			**p_children;
	const t_parent_type	parent_type = elem->parent_type;

	if (elem->parent_type == PARENT_UNDEFINED || elem->layer == layer)
	{
		elem->layer = layer;
		return ;
	}
	if (elem->parent_type == ELEM)
		p_children = &elem->parent.elem->gui_elem.panel->children;
	else
		p_children = &elem->parent.ui->children;
	elem->layer = layer;
	remove_elem_parent(elem);
	add_to_children(p_children, elem);
	elem->parent_type = parent_type;
	set_elem_moved(elem);
}
