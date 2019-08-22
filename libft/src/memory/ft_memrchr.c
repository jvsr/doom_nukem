/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 20:17:24 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:12:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memrchr(void *str, int c, size_t len)
{
	unsigned char	*temp_str;

	temp_str = (unsigned char *)str;
	while (len > 0)
	{
		len--;
		if (temp_str[len] == (unsigned char)c)
			return (&temp_str[len]);
	}
	return (NULL);
}
