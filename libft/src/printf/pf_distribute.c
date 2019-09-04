/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_distribute.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 13:25:57 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		pf_distribute(t_info *info, const char *start)
{
	size_t	ret;

	if (*start == '{')
		ret = pf_formatcolor(info, &start[1]);
	else if (*start == '[')
		ret = pf_commands(info, &start[1]);
	else
	{
		pf_infosetdefault(info);
		ret = pf_getinfo(info, start);
		pf_formatdistribute(info);
	}
	return (ret);
}
