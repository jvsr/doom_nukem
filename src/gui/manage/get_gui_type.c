/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_gui_type.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 10:38:50 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/06 17:32:54 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "table.h"
#include "error.h"
#include "gui_internal.h"

static t_tablepair_int const	g_types[] = {
	{"GUI_UNDEFINED", GUI_UNDEFINED},
	{"TEXT", TEXT},
	{"TEXT_BLOCK", TEXT},
	{"IMAGE", IMAGE},
	{"BUTTON", BUTTON},
	{"PANEL", PANEL},
	{"GVIEW", GVIEW},
};

char const		*get_gui_type_name(t_gui_type gui_type)
{
	size_t const	size = sizeof(g_types) / sizeof(t_tablepair_int);

	return (find_tablepair_int_id(g_types, size, gui_type));
}

t_gui_type		get_gui_type_value(const char *name)
{
	size_t const	size = sizeof(g_types) / sizeof(t_tablepair_int);

	if (name == NULL)
		return (GUI_UNDEFINED);
	return (find_tablepair_int_value(g_types, size, name));
}
