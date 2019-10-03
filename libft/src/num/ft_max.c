/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_max.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:40:13 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:15:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_num.h"

intmax_t	ft_max(intmax_t num1, intmax_t num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}
