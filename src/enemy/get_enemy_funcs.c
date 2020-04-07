/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_enemy_funcs.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 12:51:25 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:37:23 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"
#include "enemy.h"
#include "rinfo.h"

static t_tablepair const	g_notable[] = {
	{"reset", reset_func}
};

static t_tablepair const	g_ontable[] = {
	{"shooty", shooty_func}
};

char const	*get_no_name(t_nofunc *nofunc)
{
	size_t const	table_size = sizeof(g_notable) / sizeof(t_tablepair);

	if (nofunc == NULL)
		return (NULL);
	return (find_tablepair_id(g_notable, table_size, nofunc));
}

t_nofunc	*get_no_from_name(const char *name)
{
	size_t const	table_size = sizeof(g_notable) / sizeof(t_tablepair);

	if (name == NULL)
		return (NULL);
	return (find_tablepair_value(g_notable, table_size, name));
}

char const	*get_on_name(t_onfunc *onfunc)
{
	size_t const	table_size = sizeof(g_ontable) / sizeof(t_tablepair);

	if (onfunc == NULL)
		return (NULL);
	return (find_tablepair_id(g_ontable, table_size, onfunc));
}

t_onfunc	*get_on_from_name(const char *name)
{
	size_t const	table_size = sizeof(g_ontable) / sizeof(t_tablepair);

	if (name == NULL)
		return (NULL);
	return (find_tablepair_value(g_ontable, table_size, name));
}
