/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numarrsortac.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 23:47:03 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:18:13 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_numarr.h"

t_bool		ft_numarrsortac(intmax_t current, intmax_t num)
{
	return (current < num && (current - num) != 0);
}
