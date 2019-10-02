/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_new_elem.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:54:20 by pholster       #+#    #+#                */
/*   Updated: 2019/09/26 17:54:20 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "exec.h"
#include "parse.h"

const t_onclickpair	g_onclicks[] = {
	{"button_menu_missions", NULL},
	{"button_menu_options", NULL},
	{"button_menu_quit", NULL},
};

static t_onclick	*get_onclick(char *onclick)
{
	const size_t	size = sizeof(g_onclicks) / sizeof(t_onclickpair);
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (ft_strequ_nocase(onclick, g_onclicks[i].name))
			return (g_onclicks[i].f);
		i++;
	}
	return (NULL);
}

static void			set_gui_info(t_transform *elem, t_parse_info *elem_info)
{
	if (elem->gui_type == TEXT)
		exec_set_gui_text(elem, elem_info);
	else if (elem->gui_type == IMAGE)
		exec_set_gui_image(elem, elem_info);
	else if (elem->gui_type == BUTTON)
		exec_set_gui_button(elem, elem_info);
}

t_transform			*exec_new_elem(t_gui *ui, t_parse_info *elem_info)
{
	t_transform	*elem;

	elem = new_elem(ui, elem_info->name, elem_info->type);
	set_elem_pos(elem, elem_info->pos);
	set_elem_dim(elem, elem_info->dim);
	set_elem_onclick(elem, get_onclick(elem_info->onclick));
	set_elem_layer(elem, elem_info->layer);
	set_elem_clickable(elem, elem_info->clickable);
	set_elem_show(elem, elem_info->show);
	set_gui_info(elem, elem_info);
	return (elem);
}
