/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addunum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 02:16:09 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_addunum(t_info *info, uintmax_t value, size_t len, int base)
{
	char	c;

	if (len == 0)
		return ;
	if (len > 1)
		pf_addunum(info, value / base, len - 1, base);
	c = value % base;
	if (c <= 9)
		c += '0';
	else if (c > 9 && info->type != 'X')
		c += 'a' - 10;
	else
		c += 'A' - 10;
	pf_addtobuff(info, &c, 1);
}
