/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashdjb2a.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:05:09 by pholster       #+#    #+#                */
/*   Updated: 2019/08/22 12:03:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

size_t	ft_hashdjb2a(char *str)
{
	size_t	hash;
	size_t	i;

	i = 0;
	hash = 5381;
	while (str[i] != '\0')
	{
		hash = str[i] ^ (hash * 33);
		i++;
	}
	return (hash);
}
