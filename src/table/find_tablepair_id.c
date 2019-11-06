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

const char	*find_tablepair_id(t_tablepair *table, size_t table_size, void *value)
{
	size_t	i;
	const char	*result;

	i = 0;
	while (i < table_size)
	{
		if (table[i].value != NULL && value == table[i].value)
		{
			result = ft_strdup(table[i].id);
			if (result == NULL)
				error_msg_errno("Failed to alloc tablepair_int value name");
			return (result);
		}
		i++;
	}
}
