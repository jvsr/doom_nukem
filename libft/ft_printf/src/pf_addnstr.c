/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 17:30:53 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_addnstr(t_info *info, char *str, size_t n)
{
	if (n == 0)
		return ;
	pf_addtobuff(info, str, n);
}
