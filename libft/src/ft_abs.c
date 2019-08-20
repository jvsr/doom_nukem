/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:43:05 by pholster       #+#    #+#                */
/*   Updated: 2019/08/16 15:50:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

intmax_t		ft_abs(intmax_t num)
{
	if (num < 0)
		return (-num);
	return (num);
}
