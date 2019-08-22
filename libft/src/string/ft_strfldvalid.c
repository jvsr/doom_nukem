/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strfldvalid.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 18:29:21 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:34:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_character.h"
#include "ft_stringarray.h"

t_bool	ft_strfldvalid(char **arr, size_t x, size_t y, char *dlm)
{
	long long	bytes[2];
	size_t		i;
	size_t		j;

	i = 0;
	if (ft_strarrnlen(arr, y + 1) != y)
		return (FALSE);
	ft_chrsetbytes(bytes, dlm);
	while (i < y)
	{
		j = 0;
		if (ft_strnlen(arr[i], x + 1) != x)
			return (FALSE);
		while (j < x)
		{
			if (ft_chrinbytes(bytes, arr[i][j]) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
