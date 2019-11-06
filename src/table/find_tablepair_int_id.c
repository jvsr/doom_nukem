/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_tablepair_int_id.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:19:35 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/06 14:52:57 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft/ft_str.h"

#include "error.h"
#include "table.h"

const char	*find_tablepair_int_id(t_tablepair_int *table, size_t table_size,
										int value)
{
	size_t	i;
	char	*result;

	i = 0;
	while (i < table_size)
	{
		if (value == table[i].value)
		{
			result = ft_strdup(table[i].id);
			if (result == NULL)
				error_msg_errno("Failed to alloc tablepair_int value name");
			return (result);
		}
		i++;
	}
	return (NULL);
}
