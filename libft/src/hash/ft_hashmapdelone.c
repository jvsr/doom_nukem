/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashmapdelone.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 16:59:50 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 17:27:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include <stdlib.h>

void	ft_hashmapdelone(const t_hashmap *map, const void *key, size_t keysize,
			void (*del)(void *))
{
	t_hashlist	*current;
	t_hashlist	*prv;
	size_t		index;

	prv = NULL;
	index = map->f(key) % map->size;
	current = map->arr[index];
	while (current != NULL && hs_keyequ(current, key, keysize) == FALSE)
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
