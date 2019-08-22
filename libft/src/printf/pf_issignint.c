/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_issignint.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 15:52:55 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool		pf_issignint(t_info *info)
{
	if (info->var_type == INT || info->var_type == INT_MAX)
		return (TRUE);
	if (info->var_type == LONG || info->var_type == LONG_LONG)
		return (TRUE);
	if (info->var_type == CHAR_I || info->var_type == SHORT)
		return (TRUE);
	return (FALSE);
}
