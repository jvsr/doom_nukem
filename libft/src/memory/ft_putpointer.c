/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpointer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 00:11:56 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:14:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include "ft_number.h"

t_bool	ft_putpointer(void *pointer)
{
	if (ft_putstr("0x") == FALSE)
		return (FALSE);
	return (ft_putnum_cbase((size_t)pointer, 16, FALSE));
}
