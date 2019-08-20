/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp_nocase.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp_nocase(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	temp_a;
	unsigned char	temp_b;

	i = 0;
	while (i < n)
	{
		temp_a = ft_tolower(str1[i]);
		temp_b = ft_tolower(str2[i]);
		if (temp_a != temp_b)
			return (temp_a - temp_b);
		if (temp_a == '\0')
			return (0);
		i++;
	}
	return (0);
}
