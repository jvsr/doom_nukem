/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_elem_parent.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 11:50:04 by pholster       #+#    #+#                */
/*   Updated: 2019/09/16 11:50:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	remove_elem_parent(t_transform *elem)
{
	t_transform	**children;
	t_transform	*cur;
	t_transform	*prv;

	prv = NULL;
	if (elem->parent_type == ELEM)
		children = &elem->parent.elem->gui_elem.panel->children;
	else
		children = &elem->parent.ui->children;
	cur = *children;
	while (cur != NULL && cur != elem)
	{
		prv = cur;
		cur = cur->next;
	}
	if (cur == NULL)
		return ;
	if (cur == *children)
		*children = cur->next;
	else
		prv->next = cur->next;
	elem->parent_type = PARENT_UNDEFINED;
}
