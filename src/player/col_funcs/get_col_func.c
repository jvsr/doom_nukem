/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_col_func.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 22:18:13 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 12:55:56 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "table.h"
#include "rinfo.h"

static t_tablepair const	g_plyrcol[] = {
	{"health_pickup", health_pickup},
	{"key_pickup", key_pickup},
	{"spike_damage", spike_damage},
	{"ammo_pickup", ammo_pickup}
};

char const	*get_col_name(t_plyrcol *plyrcol)
{
	size_t const	table_size = sizeof(g_plyrcol) / sizeof(t_tablepair);

	if (plyrcol == NULL)
		return (NULL);
	return (find_tablepair_id(g_plyrcol, table_size, plyrcol));
}

t_plyrcol	*get_col_from_name(const char *name)
{
	size_t const	table_size = sizeof(g_plyrcol) / sizeof(t_tablepair);

	if (name == NULL)
		return (NULL);
	return (find_tablepair_value(g_plyrcol, table_size, name));
}
