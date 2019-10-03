/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_layer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 11:43:29 by pholster       #+#    #+#                */
/*   Updated: 2019/09/16 11:43:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"

#include "gui.h"

void			set_elem_layer(t_transform *elem, short layer)
{
	short				old_layer;
	t_transform			**p_children;
	const t_parent_type	last_type = elem->parent_type;

	if (elem->parent_type == PARENT_UNDFINED || elem->layer == layer)
	{
		elem->layer = layer;
		return ;
	}
	if (elem->parent_type == ELEM)
		p_children = &elem->parent.elem->gui_elem.panel->children;
	else
		p_children = &elem->parent.ui->children;
	old_layer = elem->layer;
	elem->layer = layer;
	remove_elem_parent(elem);
	if (layer > old_layer && elem->next != NULL)
		add_to_children(&elem->next, elem);
	else
		add_to_children(p_children, elem);
	elem->parent_type = last_type;
	set_elem_moved(elem);
}
