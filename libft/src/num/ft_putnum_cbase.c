/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnum_cbase.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:41:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_num.h"

t_bool	ft_putnum_cbase(intmax_t value, int base, t_bool up)
{
	return (ft_putnum_cbase_fd(value, base, up, 1));
}
