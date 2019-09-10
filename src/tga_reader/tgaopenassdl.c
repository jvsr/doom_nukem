/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tgaopenassdl.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 15:37:13 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 15:09:02 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tga.h"
#include "error.h"
#include "libft/ft_memory.h"

SDL_Surface		*tgaopenassdl(char *loc)
{
	t_img		img;
	SDL_Surface	*sdl;

	if (!opentga(&img, loc))
		return (NULL);
	sdl = SDL_CreateRGBSurface(0, img.width, img.height, 32,
		0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	if (sdl == NULL)
		error_msg("Error Allocating TGA Surface", 1);
	ft_memcpy(sdl->pixels, img.pixels, img.height * img.width * sizeof(int));
	free(img.pixels);
	return (sdl);
}
