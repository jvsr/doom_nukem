/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_overflow.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 14:12:31 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

intmax_t	ft_overflow(intmax_t num, intmax_t min, intmax_t max)
{
	if (num < min)
		return (ft_overflow(max + (num - min), min, max));
	if (num >= max)
		return (ft_overflow((num + min) - max, min, max));
	return (num);
}
