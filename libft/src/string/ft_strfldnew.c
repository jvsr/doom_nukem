/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strfldnew.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 18:29:21 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:34:43 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_stringarray.h"
#include "ft_memory.h"

char		**ft_strfldnew(size_t x, size_t y, char c)
{
	char	**arr;
	size_t	i;

	i = 0;
	arr = ft_strarrnew(y);
	if (arr == NULL)
		return (NULL);
	while (i < y)
	{
		arr[i] = ft_strnew(x);
		if (arr[i] == NULL)
		{
			ft_strarrdel(&arr);
			return (NULL);
		}
		ft_memset(arr[i], c, x);
		i++;
	}
	return (arr);
}
