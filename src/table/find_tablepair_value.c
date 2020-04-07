/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_tablepair_value.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:19:29 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 11:50:59 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "table.h"

void const	*find_tablepair_value(t_tablepair const *table, size_t table_size,
								char const *id)
{
	size_t	i;

	i = 0;
	while (i < table_size)
	{
		if (ft_strequ_nocase(id, table[i].id))
			return (table[i].value);
		i++;
	}
	return (NULL);
}
