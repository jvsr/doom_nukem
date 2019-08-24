/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashmapdel.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 17:14:55 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 17:20:49 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include <stdlib.h>

void	ft_hashmapdel(t_hashmap *map, void (*del)(void *))
{
	size_t		i;
	t_hashlist	*next;
	t_hashlist	*current;

	if (map == NULL)
		return ;
	i = map->size;
	while (i > 0)
	{
		i--;
		current = map->arr[i];
		while (current != NULL)
		{
			next = current->next;
			if (del != NULL && current->value != NULL)
				del(current->value);
			if (current->key != NULL)
				free(current->key);
			free(current);
			current = next;
		}
	}
	free(map->arr);
	free(map);
}
