/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_tablepair_int_id.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:19:35 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 11:50:33 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft/ft_str.h"

#include "table.h"

char const	*find_tablepair_int_id(t_tablepair_int const *table,
									size_t table_size, int value)
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
