/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashmapdelone.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 16:59:50 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 17:16:33 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include "ft_string.h"

void	ft_lstdelone(t_hashmap *map, char *key, void (*del)(void *))
{
	t_hashlist	*current;
	t_hashlist	*prv;
	size_t		index;

	prv = NULL;
	index = map->f(key) % map->size;
	current = map->arr[index];
	while (current != NULL && ft_strequ(current->key, key) == FALSE)
	{
		prv = current;
		current = current->next;
	}
	if (current == NULL)
		return ;
	if (del != NULL && current->value != NULL)
		del(current->value);
	if (prv != NULL)
		prv->next = current->next;
	free(current->key);
	free(current);
}
