/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_to_rgba.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 13:47:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/08/29 13:48:00 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	color_to_rgba(int *color, t_color c)
{
	*color = 0;
	*color = (c.a << 24) | *color;
	*color = (c.r << 16) | *color;
	*color = (c.g << 8) | *color;
	*color = (c.b) | *color;
}
