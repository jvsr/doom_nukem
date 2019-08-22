/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:15:59 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"
#include "ft_unsignednumber.h"

size_t		ft_numlen_base(intmax_t value, int base)
{
	uintmax_t	num;

	num = (value < 0 && base == 10) ? -value : value;
	return (ft_unumlen_base(num, base) + (value < 0 && base == 10));
}
