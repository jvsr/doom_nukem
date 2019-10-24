/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_gui_config.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:23:44 by pholster       #+#    #+#                */
/*   Updated: 2019/10/24 15:34:11 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "exec.h"
#include "parse.h"
#include "gui.h"
#include "error.h"

static void		exec_children(t_gui *ui, t_parse_info *child,
								t_transform *parent)
{
	t_transform		*elem;
	t_parse_info	*next;

	while (child != NULL)
	{
		next = child->next;
		elem = new_exec_elem(ui, child);
		if (elem->gui_type == PANEL)
			exec_children(ui, child->child, elem);
		add_elem_child(parent, elem);
		del_parse_info(&child);
		child = next;
	}
}

t_transform		*exec_gui_config(t_gui *ui, t_parse_info *parse_info)
{
	t_transform		*panel;

	panel = new_exec_elem(ui, parse_info);
	exec_children(ui, parse_info->child, panel);
	del_parse_info(&parse_info);
	return (panel);
}
