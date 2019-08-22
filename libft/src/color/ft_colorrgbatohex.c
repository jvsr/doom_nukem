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

t_color		ft_colorrgbatohex(t_color r, t_color g, t_color b, t_color a)
{
	t_color	color;

	color = r;
	color |= ((long long)g << 8);
	color |= ((long long)b << 16);
	color |= ((long long)a << 24);
	return (color);
}
