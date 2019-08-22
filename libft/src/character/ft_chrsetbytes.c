/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrsetbytes.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 01:29:23 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:03:45 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_character.h"
#include "ft_memory.h"

void	ft_chrsetbytes(long long *bytes, char *str)
{
	size_t	i;

	i = 0;
	ft_memset(&bytes[0], 0, sizeof(bytes[0]));
	ft_memset(&bytes[1], 0, sizeof(bytes[1]));
	while (str[i] != '\0')
	{
		if (str[i] >= 64)
			bytes[1] |= (1LL << (str[i] - 64));
		else
			bytes[0] |= (1LL << str[i]);
		i++;
	}
}
