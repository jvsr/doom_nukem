/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:43:05 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:14:25 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"

intmax_t		ft_abs(intmax_t num)
{
	if (num < 0)
		return (-num);
	return (num);
}
