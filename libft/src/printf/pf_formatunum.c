/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatunum.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 17:46:23 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:28:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_unsignednumber.h"

void		pf_formatunum(t_info *info)
{
	uintmax_t	num;

	num = pf_overflowunsigned(info);
	info->iszero = (num == 0);
	info->var_len = ft_unumlen_base(num, info->var_base);
	pf_formatpad(info);
	if (info->precision >= 0 && info->iszero)
	{
		if (info->precision > 0 ||
			(info->type == 'o' && PF_FLAG_HASH))
			pf_addnstr(info, "0", 1);
		else if (info->width > 0)
			pf_addnstr(info, " ", 1);
		return ;
	}
	pf_addunum(info, num, info->var_len, info->var_base);
}
