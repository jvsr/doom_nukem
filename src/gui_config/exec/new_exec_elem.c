/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_exec_elem.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:54:20 by pholster       #+#    #+#                */
/*   Updated: 2019/09/26 17:54:20 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/ft_str.h"

#include "exec.h"
#include "error.h"
#include "parse.h"

static void			validate(t_parse_info *elem_info, t_onclick *onclick)
{
	char	*msg;

	msg = "";
	if (elem_info->onclick && onclick == NULL)
		msg = ft_strformat("Invalid elem onclick in %s", elem_info->name);
	if (ft_strequ(msg, "") == FALSE)
		error_msg("Executer validation error", 21, msg);
}

static void			set_gui_info(t_transform *elem, t_parse_info *elem_info)
{
	if (elem->gui_type == TEXT)
		set_exec_gui_text(elem, elem_info);
	else if (elem->gui_type == IMAGE)
		set_exec_gui_image(elem, elem_info);
	else if (elem->gui_type == BUTTON)
		set_exec_gui_button(elem, elem_info);
}

t_transform			*new_exec_elem(t_gui *ui, t_parse_info *elem_info)
{
	t_onclick	*onclick;
	t_transform	*elem;

	onclick = get_onclick_f(elem_info->onclick);
	validate(elem_info, onclick);
	elem = new_elem(ui, elem_info->name, elem_info->type);
	set_elem_pos(elem, elem_info->pos);
	set_elem_dim(elem, elem_info->dim);
	set_elem_onclick(elem, onclick);
	set_elem_layer(elem, elem_info->layer);
	set_elem_clickable(elem, elem_info->clickable);
	set_elem_show(elem, elem_info->show);
	set_gui_info(elem, elem_info);
	return (elem);
}
