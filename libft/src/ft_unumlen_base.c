/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unumlen_base.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

size_t		ft_unumlen_base(uintmax_t value, int base)
{
	size_t	len;

	len = 0;
	if (base < 2 || base > 36)
		return (0);
	while (base != -1)
	{
		len++;
		value = value / base;
		if (value == 0)
			return (len);
	}
	return (len);
}
