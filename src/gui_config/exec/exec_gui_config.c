/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_gui_config.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:23:44 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:44:59 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "exec.h"
#include "parse.h"
#include "gui.h"
#include "error.h"

static void		exec_children(t_gui *ui, t_parse_info *child,
								t_transform *parent, char const *exec_path)
{
	t_transform		*elem;
	t_parse_info	*next;

	while (child != NULL)
	{
		next = child->next;
		elem = new_exec_elem(ui, child, exec_path);
		if (elem->gui_type == PANEL)
			exec_children(ui, child->child, elem, exec_path);
		add_elem_child(parent, elem);
		del_parse_info(&child);
		child = next;
	}
}

t_transform		*exec_gui_config(t_gui *ui, t_parse_info *parse_info,
									char const *exec_path)
{
	t_transform		*panel;

	panel = new_exec_elem(ui, parse_info, exec_path);
	exec_children(ui, parse_info->child, panel, exec_path);
	del_parse_info(&parse_info);
	return (panel);
}
