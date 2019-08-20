/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrdindex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:38:37 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_chrdindex(const char *str, const char *dlm)
{
	size_t		i;
	long long	bytes[2];

	i = 0;
	if (str == NULL || dlm == NULL)
		return (-1);
	ft_chrsetbytes(bytes, (char *)dlm);
	while (str[i] != '\0')
	{
		if (ft_chrinbytes(bytes, str[i]))
			return (i);
		i++;
	}
	return (-1);
}
