/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_tablepair_ii_value.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 17:16:45 by euan          #+#    #+#                 */
/*   Updated: 2020/04/13 17:18:33 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "table.h"

void const	*find_tablepair_ii_value(t_tablepair_ii const *table,
				size_t table_size, int const id)
{
	size_t	i;

	i = 0;
	while (i < table_size)
	{
		if (id == table[i].id)
			return (table[i].value);
		i++;
	}
	return (NULL);
}
