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

#define TABLE_SIZE 6

static t_tablepair_int	*create_gui_type_table(void)
{
	t_tablepair_int	*gui_types;
	
	gui_types = (t_tablepair_int*)ft_memalloc
				(sizeof(t_tablepair_int) * TABLE_SIZE);
	if (gui_types == NULL)
		error_msg_errno("Failed to allocate gui type table");
	gui_types[0] = (t_tablepair_int){"GUI_UNDEFINED", GUI_UNDEFINED};
	gui_types[1] = (t_tablepair_int){"TEXT", TEXT};
	gui_types[2] = (t_tablepair_int){"TEXT_BLOCK", TEXT};
	gui_types[3] = (t_tablepair_int){"IMAGE", IMAGE};
	gui_types[4] = (t_tablepair_int){"BUTTON", BUTTON};
	gui_types[5] = (t_tablepair_int){"PANEL", PANEL};
	return (gui_types);
}

const char				*get_gui_type_name(t_gui_type gui_type)
{
	const char		*result;
	t_tablepair_int	*gui_types;

	gui_types = create_gui_type_table();
	result = find_tablepair_int_id(gui_types, TABLE_SIZE, gui_type);
	free(gui_types);
	return (result);
}

t_gui_type				get_gui_type_value(const char *name)
{
	t_gui_type		result;
	t_tablepair_int	*gui_types;

	if (name == NULL)
		return (GUI_UNDEFINED);
	gui_types = create_gui_type_table();
	result = find_tablepair_int_value(gui_types, TABLE_SIZE, name);
	free(gui_types);
	return (result);
}
