/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrinbytes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 01:47:24 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:02:59 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_character.h"

t_bool		ft_chrinbytes(const long long *bytes, char c)
{
	if (c >= 64 && bytes[1] & (1LL << (c - 64)))
		return (TRUE);
	if (c < 64 && c >= 0 && bytes[0] & (1LL << c))
		return (TRUE);
	return (FALSE);
}
