/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_clear_surface.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 13:54:06 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/17 14:13:16 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>

#include "libft/ft_memory.h"

#include "error.h"

void	sdl_create_surface_default(SDL_Surface *surface)
{
	ft_bzero(surface->pixels, surface->pitch * surface->h);
}
