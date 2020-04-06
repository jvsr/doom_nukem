/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_create_surface_default.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 13:54:06 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:04:59 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>

#include "error.h"

SDL_Surface	*sdl_create_surface_default(SDL_Point size)
{
	SDL_Surface *new;

	new = SDL_CreateRGBSurface(0,
		size.x,
		size.y,
		32,
		0x00FF0000,
		0x0000FF00,
		0x000000FF,
		0xFF000000);
	if (new == NULL)
		error_msg_sdl(ENOMEM, "Failed to alloc new surface");
	return (new);
}
