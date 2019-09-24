/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunum_base.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 15:28:35 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:49:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unum.h"

t_bool	ft_putunum_base(uintmax_t value, int base)
{
	return (ft_putunum_cbase_fd(value, base, TRUE, 1));
}
