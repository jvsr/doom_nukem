/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:36:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	castmagic(long long *str)
{
	long long	himagic;
	long long	lomagic;
	char		*longword;
	size_t		i;
	size_t		len;

	len = 0;
	himagic = 0x80808080L | (0x80808080L << 32);
	lomagic = 0x01010101L | (0x01010101L << 32);
	while (TRUE)
	{
		if (((str[len] - lomagic) & (~str[len] & himagic)) != 0)
		{
			i = 0;
			longword = (char *)&str[len];
			while (i < 8)
			{
				if (longword[i] == '\0')
					return ((len * 8) + i);
				i++;
			}
		}
		len++;
	}
	return (0);
}

size_t			ft_strlen(char *str)
{
	size_t		len;

	len = 0;
	if (str == NULL)
		return (0);
	while ((((size_t)&str[len]) & 7) != 0)
	{
		if (str[len] == '\0')
			return (len);
		len++;
	}
	return (len + castmagic((long long *)&str[len]));
}
