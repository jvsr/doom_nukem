/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_ispositiveint.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 19:21:03 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	pf_ispositiveint(const t_info *info)
{
	return (pf_issignint(info) && info->is_negative == FALSE);
}
