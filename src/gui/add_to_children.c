/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_to_children.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 15:52:19 by pholster       #+#    #+#                */
/*   Updated: 2019/09/16 15:52:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

/*
** * Gui internal function
*/

void		add_to_children(t_transform **children, t_transform *child)
{
	t_transform	*cur;

	child->next = NULL;
	cur = *children;
	while (cur != NULL && cur->next != NULL && child->layer > cur->layer)
		cur = cur->next;
	if (cur == NULL)
		*children = child;
	else if (cur->next == NULL)
		cur->next = child;
	else
	{
		child->next = cur->next;
		cur->next = child;
	}
}
