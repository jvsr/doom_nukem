/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatdistribute.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_formatdistribute(t_info *info)
{
	if (pf_issignint(info))
		pf_formatnum(info);
	else if (pf_isunsignint(info))
		pf_formatunum(info);
	else if (info->var_type == CHAR || info->var_type == T_WCHAR)
		pf_formatchar(info);
	else if (pf_isstr(info))
		pf_formatstr(info);
	else if (info->var_type == DOUBLE || info->var_type == LONG_DOUBLE)
		pf_formatdouble(info);
	pf_formatbackpad(info);
}
