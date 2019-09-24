/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unumlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:49:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unum.h"

size_t		ft_unumlen(uintmax_t value)
{
	return (ft_unumlen_base(value, 10));
}
