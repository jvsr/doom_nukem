/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_draw_method.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/08 11:53:17 by pholster       #+#    #+#                */
/*   Updated: 2019/10/08 11:53:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui_internal.h"

static const t_matchpair	g_draw_methods[] = {
	{"DRAW_METHOD_UNDEFINED", DRAW_METHOD_UNDEFINED},
	{"SCALED", SCALED},
	{"REPEAT", REPEAT},
	{"FIXED", FIXED},
	{"CENTERED", CENTERED},
	{"COLOR", COLOR},
};

const char		*get_draw_method_name(t_draw_method draw_method)
{
	const size_t	size = sizeof(g_draw_methods) / sizeof(t_matchpair);
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (draw_method == g_draw_methods[i].value)
			return (g_draw_methods[i].name);
		i++;
	}
	return (NULL);
}

t_draw_method	get_draw_method_value(const char *name)
{
	const size_t	size = sizeof(g_draw_methods) / sizeof(t_matchpair);
	size_t			i;

	if (name == NULL)
		return (DRAW_METHOD_UNDEFINED);
	i = 0;
	while (i < size)
	{
		if (ft_strequ_nocase(name, g_draw_methods[i].name))
			return (g_draw_methods[i].value);
		i++;
	}
	return (DRAW_METHOD_UNDEFINED);
}
