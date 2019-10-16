/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_elem_child.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 11:50:04 by pholster       #+#    #+#                */
/*   Updated: 2019/09/16 11:50:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"

void	del_elem_child(t_transform *elem, const char *name)
{
	del_child(&elem->gui_elem.panel->children, name);
	set_elem_redraw(elem);
}
