/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_to_rgba.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 13:47:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 15:13:57 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>

Uint32	color_to_rgba(SDL_Color c)
{
	Uint32	result;

	result = 0;
	result = (c.a << 24) | result;
	result = (c.r << 16) | result;
	result = (c.g << 8) | result;
	result = (c.b) | result;
	return (result);
}
