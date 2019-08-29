/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashmapnew.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:05:11 by pholster       #+#    #+#                */
/*   Updated: 2019/08/23 16:11:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include "ft_memory.h"

t_hashmap		*ft_hashmapnew(size_t size, size_t (*f)(const void *, size_t))
{
	t_hashmap	*new;

	new = (t_hashmap *)ft_memalloc(sizeof(t_hashmap));
	if (new == NULL)
		return (NULL);
	new->arr = (t_hashlist **)ft_memalloc(sizeof(t_hashlist *) * size);
	if (new->arr == NULL)
	{
		free(new);
		return (NULL);
	}
	new->f = f;
	new->size = size;
	return (new);
}
