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

void	*ft_memchr(void *str, int c, size_t len)
{
	unsigned char	*temp_str;
	size_t			i;

	i = 0;
	temp_str = (unsigned char *)str;
	while (i < len)
	{
		if (temp_str[i] == (unsigned char)c)
			return (&temp_str[i]);
		i++;
	}
	return (NULL);
}