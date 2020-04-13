/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_tablepair_ii_id.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 17:13:41 by euan          #+#    #+#                 */
/*   Updated: 2020/04/13 17:23:56 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft/ft_str.h"

#include "table.h"

int			find_tablepair_ii_id(t_tablepair_ii const *table, size_t table_size,
				void const *value)
{
	size_t		i;

	i = 0;
	while (i < table_size)
	{
		if (value == table[i].value)
			return (table[i].id);
		i++;
	}
	return (-1);
}
