/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:08:38 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:13:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

static long long	prepare(unsigned char c)
{
	long long	temp_c;

	temp_c = 0;
	temp_c |= ((long long)c << 0);
	temp_c |= ((long long)c << 8);
	temp_c |= ((long long)c << 16);
	temp_c |= ((long long)c << 24);
	temp_c |= ((long long)c << 32);
	temp_c |= ((long long)c << 40);
	temp_c |= ((long long)c << 48);
	temp_c |= ((long long)c << 56);
	return (temp_c);
}

void				*ft_memset(void *str, int c, size_t len)
{
	size_t				i;
	unsigned char		temp_c;
	long long			temp_c_8;
	unsigned char		*temp_str;
	unsigned long long	*temp_str_8;

	i = 0;
	temp_c = c;
	temp_c_8 = prepare(temp_c);
	temp_str_8 = str;
	while (len - (i * 8) >= 8)
	{
		temp_str_8[i] = temp_c_8;
		i++;
	}
	i *= 8;
	if (i >= len)
		return (str);
	temp_str = str;
	while (i < len)
	{
		temp_str[i] = temp_c;
		i++;
	}
	return (str);
}
