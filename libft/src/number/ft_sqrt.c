/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:17:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"

intmax_t	ft_sqrt(intmax_t nb)
{
	intmax_t	n;

	n = 0;
	while (n < nb)
	{
		n++;
		if (n * n == nb)
			return (n);
		if (n * n > nb)
			return (0);
		if (n * n == 46340)
			return (0);
	}
	return (0);
}
