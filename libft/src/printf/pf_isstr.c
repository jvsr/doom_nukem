/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_isstr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 13:00:18 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool		pf_isstr(const t_info *info)
{
	return (info->var_type == STR || info->var_type == T_WCHAR_STR);
}
