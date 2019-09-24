/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_var.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 17:00:01 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:35:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_strarr.h"
#include "ft_mem.h"

char			*ft_strjoin_var(size_t count, ...)
{
	size_t	i;
	char	*str;
	char	**arr;
	va_list	args;

	i = 0;
	arr = (char **)ft_strarrnew(count);
	if (arr == NULL)
		return (NULL);
	va_start(args, count);
	while (i < count)
	{
		arr[i] = va_arg(args, char *);
		i++;
	}
	va_end(args);
	str = ft_strjoin_arr((const char **)arr);
	ft_memdel((void **)&arr);
	return (str);
}
