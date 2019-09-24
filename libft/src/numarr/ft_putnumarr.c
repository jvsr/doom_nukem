/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnumarr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:18:27 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:22:45 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_numarr.h"
#include "ft_char.h"
#include "ft_str.h"
#include "ft_num.h"

t_bool	ft_putnumarr(const intmax_t *arr, size_t len)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (ft_putstr(NULL));
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
