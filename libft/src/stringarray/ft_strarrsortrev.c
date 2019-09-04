/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrsortrev.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 15:07:28 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:40:52 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stringarray.h"

void	ft_strarrsortrev(char **arr, t_bool (*f)(const char *, const char *))
{
	size_t	i;
	size_t	j;
	char	*current;

	i = 1;
	while (arr[i] != NULL)
	{
		j = i;
		current = arr[i];
		while (j > 0 &&
			f((const char *)current, (const char *)arr[j - 1]) == FALSE)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = current;
		i++;
	}
}
