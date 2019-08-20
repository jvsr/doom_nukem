/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatnum.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 17:46:23 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		pf_formatnum(t_info *info)
{
	intmax_t	num;

	num = pf_overflowsigned(info);
	info->iszero = (num == 0);
	info->isnegative = (num < 0);
	info->var_len = ft_numlen(num) - info->isnegative;
	pf_formatpad(info);
	if (info->precision == 0 && num == 0)
	{
		if (info->width != -1)
			pf_addnstr(info, " ", 1);
		return ;
	}
	pf_addnum(info, num);
}
