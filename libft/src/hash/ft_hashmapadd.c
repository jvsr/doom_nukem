/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashmapadd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:05:11 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 17:16:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include "ft_memory.h"

static t_hashlist	*newlst(const void *key, size_t keysize, void *value)
{
	void		*key_dup;
	t_hashlist	*new;

	key_dup = ft_memdup(key, keysize);
	if (key_dup == NULL)
		return (NULL);
	new = (t_hashlist *)ft_memalloc(sizeof(t_hashlist));
	if (new == NULL)
	{
		ft_memdel(&key_dup);
		return (NULL);
	}
	new->key = key_dup;
	new->value = value;
	new->keysize = keysize;
	return (new);
}

t_bool				ft_hashmapadd(const t_hashmap *map, const void *key,
						size_t keysize, void *value)
{
	t_hashlist	*current;
	size_t		index;

	index = map->f(key) % map->size;
	current = map->arr[index];
	if (current == NULL)
	{
		map->arr[index] = newlst(key, keysize, value);
		return (map->arr[index] != NULL);
	}
	while (current->next != NULL && hs_keyequ(current, key, keysize) == FALSE)
		current = current->next;
	if (hs_keyequ(current, key, keysize) == TRUE)
	{
		current->value = value;
		return (TRUE);
	}
	current->next = newlst(key, keysize, value);
	return (current->next != NULL);
}
