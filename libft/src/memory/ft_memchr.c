/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 20:17:24 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:12:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	const unsigned char	*temp_str;
	unsigned char		temp_c;
	size_t				i;

	i = 0;
	temp_c = c;
	temp_str = str;
	while (i < len)
	{
		if (temp_str[i] == temp_c)
			return ((void *)&temp_str[i]);
		i++;
	}
	return (NULL);
}
