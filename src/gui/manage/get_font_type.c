/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_font_type.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 10:38:50 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:13:03 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui_internal.h"
#include "table.h"

static t_tablepair_int const	g_font_types[] = {
	{"FONT_UNDEFINED", FONT_UNDEFINED},
	{"ROBOTO", ROBOTO},
	{"MONOF", MONOF},
	{"KARARC", KARARC},
	{"FOULFIEND", FOULFIEND},
	{"NECKROMANCER", NECKROMANCER},
};

char const		*get_font_type_name(t_font_type font_type)
{
	size_t const	size = sizeof(g_font_types) / sizeof(t_tablepair_int);

	return (find_tablepair_int_id(g_font_types, size, font_type));
}

t_font_type		get_font_type_value(const char *name)
{
	const size_t	size = sizeof(g_font_types) / sizeof(t_tablepair_int);

	if (name == NULL)
		return (FONT_UNDEFINED);
	return (find_tablepair_int_value(g_font_types, size, name));
}
