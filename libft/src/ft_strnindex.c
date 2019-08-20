/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnindex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:07:07 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_strnindex(const char **arr, const char *str, size_t n)
{
	size_t	i;

	i = 0;
	if (arr == NULL || str == NULL)
		return (-1);
	while (i < n)
	{
		if (ft_strequ(str, arr[i]))
			return (i);
		i++;
	}
	return (-1);
}
