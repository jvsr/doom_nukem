/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunum_cbase.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:49:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unsignednumber.h"

t_bool	ft_putunum_cbase(uintmax_t value, int base, t_bool up)
{
	return (ft_putunum_cbase_fd(value, base, up, 1));
}
