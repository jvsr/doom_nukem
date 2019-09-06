/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tgaopenassdl.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 15:37:13 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 16:16:22 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tga.h"
#include "libft/ft_memory.h"

SDL_Surface		*tgaopenassdl(char *loc)
{
	t_img img;
	SDL_Surface *sdl;

	if (!opentga(&img, loc))
		return (NULL);
	sdl = SDL_CreateRGBSurfaceWithFormat(0, img.width, img.height, 32, SDL_PIXELFORMAT_RGBA32);
	printf("Pixels Pointer -> %p, %p\n", sdl->pixels, img.pixels);
	ft_memcpy(sdl->pixels, img.pixels, img.height * img.width * sizeof(int));
	printf("%i, %i\n", ((int*)sdl->pixels)[45], img.pixels[45]);
	free(img.pixels);
	return (sdl);
}
