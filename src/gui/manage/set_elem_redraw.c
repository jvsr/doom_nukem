/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_redraw.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 18:07:36 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:12:37 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	set_elem_redraw(t_transform *elem)
{
	t_transform	*cur;

	cur = elem;
	elem->redraw = TRUE;
	if (elem->parent_type == PARENT_UNDEFINED)
		return ;
	while (cur->parent_type == ELEM)
	{
		cur->parent.elem->redraw = TRUE;
		cur = cur->parent.elem;
	}
	if (cur->parent_type == GUI)
		cur->parent.ui->redraw = TRUE;
}
