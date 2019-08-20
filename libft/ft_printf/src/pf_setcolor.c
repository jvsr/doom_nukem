/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_setcolor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 15:32:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_setcolor(t_info *info, int color)
{
	if (color < 0 || color > 255)
	{
		pf_addtobuff(info, "\e[39m\e[K", 8);
		return ;
	}
	pf_addtobuff(info, "\e[38;5;", 7);
	pf_addnum(info, color);
	pf_addtobuff(info, "m", 1);
}
