/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnumarr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:18:27 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_putnumarr(const intmax_t *arr, size_t len)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (TRUE);
	while (i < len)
	{
		if (ft_putnum(arr[i]) == FALSE)
			return (FALSE);
		if (ft_putchar('\n') == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
