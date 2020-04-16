/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnindex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:07:07 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:43:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

ssize_t		ft_strnindex(const char **arr, const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (ft_strequ(str, arr[i]))
			return (i);
		i++;
	}
	return (-1);
}
