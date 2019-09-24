/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorhextorgba.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 14:59:08 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:05:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"

void	ft_colorhextorgba(t_color *color, t_uint32 hex)
{
	color->a = (t_uint8)(hex >> 24);
	color->r = (t_uint8)(hex >> 16);
	color->g = (t_uint8)(hex >> 8);
	color->b = (t_uint8)(hex);
}
