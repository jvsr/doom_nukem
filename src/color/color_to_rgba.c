/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_to_rgba.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 13:47:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/10 14:57:47 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>

#include "types.h"

t_uint32	color_to_rgba(SDL_Color c)
{
	t_uint32	result;

	result = 0;
	result = (c.a << 24) | result;
	result = (c.r << 16) | result;
	result = (c.g << 8) | result;
	result = (c.b) | result;
	return (result);
}
