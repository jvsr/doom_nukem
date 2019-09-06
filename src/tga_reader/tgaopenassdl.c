/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tgaopenassdl.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 15:37:13 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/06 16:40:25 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "libft/ft_memory.h"

#include "tga.h"

SDL_Surface		*tgaopenassdl(char *loc)
{
	t_img		img;
	SDL_Surface *sdl;

	if (opentga(&img, loc))
		return (NULL);
	sdl = SDL_CreateRGBSurfaceWithFormat(0, img.width, img.height, 32, SDL_PIXELFORMAT_RGBA32);
	ft_memcpy(sdl->pixels, img.pixels, img.height * img.width * sizeof(int));
	free(img.pixels);
	return (sdl);
}
