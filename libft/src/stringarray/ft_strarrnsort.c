/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrnsort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 15:07:28 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:40:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stringarray.h"

void	ft_strarrnsort(char **arr, t_bool (*f)(const char *, const char *),
			size_t n)
{
	size_t	i;
	size_t	j;
	char	*current;

	i = 1;
	while (i < n && arr[i] != NULL)
	{
		j = i;
		current = arr[i];
		while (j > 0 && f((const char *)current, (const char *)arr[j - 1]))
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = current;
		i++;
	}
}
