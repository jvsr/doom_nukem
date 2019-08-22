/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_gettype.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:50:26 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:28:48 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_character.h"

int		pf_gettype(t_info *info, char *str)
{
	info->type = *str;
	if (ft_chrin(PF_A_TYPE_L, info->type))
	{
		info->type = ft_tolower(info->type);
		info->length = 'l';
	}
	return (-1);
}
