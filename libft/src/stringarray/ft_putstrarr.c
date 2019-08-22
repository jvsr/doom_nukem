/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrarr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:12:56 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:39:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stringarray.h"
#include "ft_string.h"

t_bool	ft_putstrarr(char **arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (ft_putstr(NULL));
	while (arr[i] != NULL)
	{
		if (ft_putendl(arr[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
