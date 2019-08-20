/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_isstr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 13:00:18 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool		pf_isstr(t_info *info)
{
	return (info->var_type == STR || info->var_type == T_WCHAR_STR);
}
