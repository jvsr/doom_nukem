/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashsdbm.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:05:09 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:07:55 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

size_t	ft_hashsdbm(const void *key)
{
	const char	*str;
	size_t		hash;
	size_t		i;

	i = 0;
	hash = 0;
	str = key;
	while (str[i] != '\0')
	{
		hash = str[i] + (hash << 6) + (hash << 16) - hash;
		i++;
	}
	return (hash);
}
