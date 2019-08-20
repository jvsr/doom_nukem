/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wrddcount.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:26:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wrddcount(const char *str, const char *dlm)
{
	long long	bytes[2];
	size_t		count;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	count = 0;
	if (str == NULL || dlm == NULL)
		return (0);
	ft_chrsetbytes(bytes, (char *)dlm);
	while (str[i] != '\0')
	{
		if (ft_chrinbytes(bytes, str[i]))
			j = 0;
		else if (j == 0)
		{
			count++;
			j = 1;
		}
		i++;
	}
	return (count);
}
