/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tgaopenassdl.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 15:37:13 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/17 14:11:20 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>

#include "libft/ft_memory.h"

#include "tga.h"
#include "error.h"
#include "sdl_extra.h"

SDL_Surface		*tgaopenassdl(char *loc)
{
	t_img		img;
	SDL_Surface	*sdl;

	if (!opentga(&img, loc))
		return (NULL);
	sdl = sdl_create_surface_default((SDL_Point){img.width, img.height});
	ft_memcpy(sdl->pixels, img.pixels, img.height * img.width * sizeof(int));
	free(img.pixels);
	return (sdl);
}
