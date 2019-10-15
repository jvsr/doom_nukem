/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_isunsignint.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 15:52:53 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	pf_isunsignint(const t_info *info)
{
	if (info->var_type == U_INT || info->var_type == U_SHORT)
		return (TRUE);
	if (info->var_type == MAX_U_INT || info->var_type == SIZE_T)
		return (TRUE);
	if (info->var_type == U_LONG || info->var_type == U_LONG_LONG)
		return (TRUE);
	if (info->var_type == U_CHAR_I || info->var_type == VOID)
		return (TRUE);
	return (FALSE);
}
