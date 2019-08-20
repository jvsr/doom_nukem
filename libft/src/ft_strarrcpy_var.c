/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrcpy_var.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:18:39 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarrcpy_var(char **dst, size_t count, ...)
{
	size_t		i;
	va_list		args;

	i = 0;
	va_start(args, count);
	while (i < count)
	{
		dst[i] = ft_strdup(va_arg(args, char *));
		if (dst[i] == NULL)
		{
			va_end(args);
			return (NULL);
		}
		i++;
	}
	va_end(args);
	return (dst);
}
