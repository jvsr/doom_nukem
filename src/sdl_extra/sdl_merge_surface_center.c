/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_merge_surface_center.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 16:55:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/17 17:25:33 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>

#include "sdl_extra.h"

/*
** * Surface merge will take two surfaces and a starting pixel.
** * The starting pixel represents the top left corner of the src surface.
** * It will then copy the src surface directly into the dst surface.
** * It does not take an Alpha stat into account,
** * this function considers the Alpha to be 255
*/

void	sdl_merge_surface_center(SDL_Surface *dst, SDL_Surface *src)
{
	const SDL_Point	start = {(dst->w - src->w) / 2, (dst->h - src->h) / 2};

	sdl_merge_surface(dst, src, start);
}
