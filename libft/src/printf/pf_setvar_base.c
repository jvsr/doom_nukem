/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_setvar_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 11:12:01 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:29:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_character.h"

void	pf_setvar_base(t_info *info)
{
	if (ft_chrin("diuf", info->type))
		info->var_base = 10;
	else if (ft_chrin("xXaA", info->type) || info->type == 'p')
		info->var_base = 16;
	else if (info->type == 'o')
		info->var_base = 8;
	else if (info->type == 'b')
		info->var_base = 2;
	else
		info->var_base = -1;
}
