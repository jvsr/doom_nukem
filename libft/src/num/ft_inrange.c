/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_inrange.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:42:00 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:14:55 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_num.h"

t_bool	ft_inrange(intmax_t value, intmax_t min, intmax_t max)
{
	if (value < min || value > max)
		return (FALSE);
	return (TRUE);
}
