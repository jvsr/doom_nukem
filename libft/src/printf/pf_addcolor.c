/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addcolor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 15:32:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_addcolor(t_info *info, int color)
{
	if (color < 0 || color > 255)
	{
		pf_addtobuff(info, "\033[39m\033[K", 8);
		return ;
	}
	pf_addtobuff(info, "\033[38;5;", 7);
	pf_addnum(info, color);
	pf_addtobuff(info, "m", 1);
}
