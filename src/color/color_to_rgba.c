/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_to_rgba.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 13:47:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/02 12:00:32 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	color_to_rgba(t_color c)
{
	int	result;
	
	result = 0;
	result = (c.a << 24) | result;
	result = (c.r << 16) | result;
	result = (c.g << 8) | result;
	result = (c.b) | result;
	return (result);
}
