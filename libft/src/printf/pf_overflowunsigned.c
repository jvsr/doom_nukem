/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_overflowunsigned.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 18:15:52 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	pf_overflowunsigned(t_info *info)
{
	if (info->var_type == U_LONG || info->var_type == VOID)
		return (va_arg(info->args, unsigned long));
	if (info->var_type == U_LONG_LONG)
		return (va_arg(info->args, unsigned long long));
	if (info->var_type == MAX_U_INT)
		return (va_arg(info->args, uintmax_t));
	if (info->var_type == U_CHAR_I)
		return ((unsigned char)va_arg(info->args, int));
	if (info->var_type == U_SHORT)
		return ((unsigned short)va_arg(info->args, int));
	if (info->var_type == SIZE_T)
		return (va_arg(info->args, size_t));
	return (va_arg(info->args, unsigned));
}
