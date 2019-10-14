/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_gui_type.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 10:38:50 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 13:38:52 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"

static const t_matchpair	g_gui_types[] = {
	{"GUI_UNDEFINED", GUI_UNDEFINED},
	{"TEXT", TEXT},
	{"TEXT_BLOCK", TEXT},
	{"IMAGE", IMAGE},
	{"BUTTON", BUTTON},
	{"PANEL", PANEL},
};

const char		*get_gui_type_name(t_gui_type gui_type)
{
	const size_t	size = sizeof(g_gui_types) / sizeof(t_matchpair);
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (gui_type == g_gui_types[i].value)
			return (g_gui_types[i].name);
		i++;
	}
	return (NULL);
}

t_gui_type		get_gui_type_value(const char *name)
{
	const size_t	size = sizeof(g_gui_types) / sizeof(t_matchpair);
	size_t			i;

	if (name == NULL)
		return (GUI_UNDEFINED);
	i = 0;
	while (i < size)
	{
		if (ft_strequ_nocase(name, g_gui_types[i].name))
			return (g_gui_types[i].value);
		i++;
	}
	return (GUI_UNDEFINED);
}
