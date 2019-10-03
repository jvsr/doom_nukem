/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorrgbatohex.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 14:59:08 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:06:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"

t_uint32		ft_colorrgbatohex(t_color rgba)
{
	t_uint32	hex;

	hex = (t_uint32)(rgba.a << 24);
	hex |= (t_uint32)(rgba.r << 16);
	hex |= (t_uint32)(rgba.g << 8);
	hex |= (t_uint32)rgba.b;
	return (hex);
}
