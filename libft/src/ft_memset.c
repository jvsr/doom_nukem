/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:08:38 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

static size_t	prepare(char **str, long long *temp_c, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		*temp_c |= (((long long)(unsigned char)c) << (i * 8));
		i++;
	}
	while (i < len && (((size_t)*str) & 7) != 0)
	{
		**str = (unsigned char)c;
		*str += 1;
		len--;
	}
	return (len);
}

void			*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	long long		temp_c;
	char			*temp_str;

	i = 0;
	temp_c = 0;
	temp_str = str;
	len = prepare(&temp_str, &temp_c, c, len);
	while (len - (i * 8) >= 8)
	{
		((long long *)temp_str)[i] = temp_c;
		i++;
	}
	i *= 8;
	while (i < len)
	{
		temp_str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
