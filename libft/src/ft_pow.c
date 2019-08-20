/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 17:13:48 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

intmax_t	ft_pow(intmax_t num, intmax_t pow)
{
	intmax_t	ret;

	ret = num;
	if (pow == 0)
		return (1);
	if (pow == 1 && num < 0)
		return (num);
	if (pow < 0)
		return (0);
	if (num < 0)
		num = -num;
	if (ret < 0)
		ret = -ret;
	while (pow > 1)
	{
		pow--;
		ret *= num;
	}
	return (ret);
}
