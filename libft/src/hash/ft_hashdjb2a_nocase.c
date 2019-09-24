/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashdjb2a_nocase.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:05:09 by pholster       #+#    #+#                */
/*   Updated: 2019/08/22 12:03:55 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include "ft_char.h"

size_t	ft_hashdjb2a_nocase(const void *key, size_t size)
{
	const char	*str;
	size_t		hash;
	size_t		i;

	i = 0;
	hash = 5381;
	str = key;
	while (i < size)
	{
		hash = ft_tolower(str[i]) ^ (hash * 33);
		i++;
	}
	return (hash);
}
