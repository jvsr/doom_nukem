/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   open_tga_sdl.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 15:37:13 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:38:31 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>

#include "libft/ft_mem.h"

#include "tga.h"
#include "error.h"
#include "sdl_extra.h"

SDL_Surface		*open_tga_sdl(char *file_name, char const *exec_path)
{
	t_img		img;
	SDL_Surface	*surface;

	create_image(file_name, exec_path, &img);
	surface = sdl_create_surface_default((SDL_Point){img.width, img.height});
	ft_memcpy(surface->pixels, img.pixels, (img.width * img.height) * 4);
	free(img.pixels);
	return (surface);
}
