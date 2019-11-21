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
#include "table.h"

static t_tablepair_int const	g_draw_methods[] = {
	{"DRAW_METHOD_UNDEFINED", DRAW_METHOD_UNDEFINED},
	{"SCALED", SCALED},
	{"REPEAT", REPEAT},
	{"FIXED", FIXED},
	{"CENTERED", CENTERED},
	{"COLOR", COLOR},
};

char const		*get_draw_method_name(t_draw_method draw_method)
{
	size_t const	size = sizeof(g_draw_methods) / sizeof(t_tablepair_int);

	return (find_tablepair_int_id(g_draw_methods, size, draw_method));
}

t_draw_method	get_draw_method_value(const char *name)
{
	size_t const	size = sizeof(g_draw_methods) / sizeof(t_tablepair_int);

	if (name == NULL)
		return (DRAW_METHOD_UNDEFINED);
	return (find_tablepair_int_value(g_draw_methods, size, name));
}
