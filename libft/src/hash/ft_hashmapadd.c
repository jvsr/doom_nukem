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
#include "ft_string.h"

static t_hashlist	*newlst(char *key, void *value)
{
	char		*key_dup;
	t_hashlist	*new;

	key_dup = ft_strdup(key);
	if (key_dup == NULL)
		return (NULL);
	new = (t_hashlist *)ft_memalloc(sizeof(t_hashlist));
	if (new == NULL)
	{
		ft_strdel(&key_dup);
		return (NULL);
	}
	new->key = key_dup;
	new->value = value;
	return (new);
}

t_bool				ft_hashmapadd(t_hashmap *map, char *key, void *value)
{
	t_hashlist	*current;
	size_t		index;

	index = map->f(key) % map->size;
	current = map->arr[index];
	if (current == NULL)
	{
		map->arr[index] = newlst(key, value);
		return (map->arr[index] != NULL);
	}
	while (current->next != NULL && ft_strequ(current->key, key) == FALSE)
		current = current->next;
	if (ft_strequ(current->key, key) == TRUE)
	{
		current->value = value;
		return (TRUE);
	}
	current->next = newlst(key, value);
	return (current->next != NULL);
}
