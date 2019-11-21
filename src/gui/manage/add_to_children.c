/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_to_children.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 15:52:19 by pholster       #+#    #+#                */
/*   Updated: 2019/09/24 15:17:40 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"

/*
** * Gui internal function
*/

void				add_to_children(t_transform **children, t_transform *child)
{
	t_transform	*cur;
	t_transform	*prv;

	prv = NULL;
	cur = *children;
	child->next = NULL;
	while (cur != NULL && child->layer > cur->layer)
	{
		prv = cur;
		cur = cur->next;
	}
	if (cur == NULL && prv != NULL)
	{
		prv->next = child;
		return ;
	}
	if (prv == NULL)
		*children = child;
	else
		prv->next = child;
	child->next = cur;
}
