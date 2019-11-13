/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_font_type.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 10:38:50 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 13:38:52 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui_internal.h"

static const t_matchpair	g_font_types[] = {
	{"FONT_UNDEFINED", FONT_UNDEFINED},
	{"ROBOTO", ROBOTO},
	{"MONOF", MONOF},
	{"KARARC", KARARC},
	{"FOULFIEND", FOULFIEND},
	{"NECKROMANCER", NECKROMANCER},
};

const char		*get_font_type_name(t_font_type font_type)
{
	const size_t	size = sizeof(g_font_types) / sizeof(t_matchpair);
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (font_type == g_font_types[i].value)
			return (g_font_types[i].name);
		i++;
	}
	return (NULL);
}

t_font_type		get_font_type_value(const char *name)
{
	const size_t	size = sizeof(g_font_types) / sizeof(t_matchpair);
	size_t			i;

	if (name == NULL)
		return (FONT_UNDEFINED);
	i = 0;
	while (i < size)
	{
		if (ft_strequ_nocase(name, g_font_types[i].name))
			return (g_font_types[i].value);
		i++;
	}
	return (FONT_UNDEFINED);
}
