/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrdindex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:38:37 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:40:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_character.h"

ssize_t		ft_chrdindex(const char *str, const char *dlm)
{
	size_t		i;
	long long	bytes[2];

	i = 0;
	ft_chrsetbytes(bytes, dlm);
	while (str[i] != '\0')
	{
		if (ft_chrinbytes(bytes, str[i]))
			return (i);
		i++;
	}
	return (-1);
}
