/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_moved.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 18:07:36 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:12:42 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	set_elem_moved(t_transform *elem)
{
	t_transform	*cur;

	cur = elem;
	elem->moved = TRUE;
	if (elem->parent_type == PARENT_UNDEFINED)
		return ;
	while (cur->parent_type == ELEM)
	{
		cur->parent.elem->moved = TRUE;
		cur = cur->parent.elem;
	}
}
