/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_tablepair_int_value.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:19:39 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/06 14:53:02 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft/ft_str.h"

#include "table.h"

int	find_tablepair_int_value(t_tablepair_int *table, size_t table_size,
								const char *id)
{
	size_t	i;

	i = 0;
	while (i < table_size)
	{
		if (ft_strequ_nocase(id, table[i].id))
			return (table[i].value);
		i++;
	}
	return(-1);
}
