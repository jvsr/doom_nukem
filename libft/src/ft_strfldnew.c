/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strfldnew.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 18:29:21 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strfldnew(size_t x, size_t y, char c)
{
	char	**arr;
	size_t	i;

	i = 0;
	if (x <= 0 || y <= 0)
		return (NULL);
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
