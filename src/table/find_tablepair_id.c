/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_tablepair_id.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:19:41 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/06 17:36:23 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft/ft_str.h"

#include "table.h"

char const	*find_tablepair_id(t_tablepair const *table, size_t table_size,
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
	return (NULL);
}
