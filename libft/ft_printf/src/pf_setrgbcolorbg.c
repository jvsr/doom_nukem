/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_setrgbcolorbg.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 15:32:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_setrgbcolorbg(t_info *info, t_color r, t_color g, t_color b)
{
	pf_addtobuff(info, "\e[48;2;", 7);
	pf_addnum(info, r);
	pf_addtobuff(info, ";", 1);
	pf_addnum(info, g);
	pf_addtobuff(info, ";", 1);
	pf_addnum(info, b);
	pf_addtobuff(info, "m", 1);
}
