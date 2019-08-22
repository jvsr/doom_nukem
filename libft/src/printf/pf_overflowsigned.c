/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_overflowsigned.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 18:15:52 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	pf_overflowsigned(t_info *info)
{
	if (info->var_type == LONG)
		return (va_arg(info->args, long));
	if (info->var_type == LONG_LONG)
		return (va_arg(info->args, long long));
	if (info->var_type == INT_MAX)
		return (va_arg(info->args, intmax_t));
	if (info->var_type == CHAR_I)
		return ((char)va_arg(info->args, int));
	if (info->var_type == SHORT)
		return ((short)va_arg(info->args, int));
	return (va_arg(info->args, int));
}
