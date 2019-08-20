/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrarr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:12:56 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_putstrarr(const char **arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (TRUE);
	while (arr[i] != 0)
	{
		if (ft_putendl(arr[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
