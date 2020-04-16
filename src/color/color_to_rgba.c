/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_to_rgba.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 13:47:21 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 11:36:39 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>

#include "types.h"

t_uint32	color_to_rgba(SDL_Color c)
{
	t_uint32	rgba;

	rgba = (c.a << 24);
	rgba = (c.r << 16) | rgba;
	rgba = (c.g << 8) | rgba;
	rgba = c.b | rgba;
	return (rgba);
}
