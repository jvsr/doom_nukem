/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   imagenew.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:15:07 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/03 10:29:12 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_memory.h"
#include "gui.h"
#include "game.h"
#include "libft/ft_string.h"

t_image		*imagenew(t_guiinfo *guiinfo, const SDL_Surface *texture)
{
	t_image *image;

	image = (t_image*)ft_memalloc(sizeof(t_image));
	image->texture = SDL_CreateRGBSurface(0, (int)texture->w, (int)texture->h, 32, 0, 0, 0, 0);
	sdl_surface_merge(image->texture, (SDL_Surface*)texture, (t_pixel){0, 0});
	ft_memcpy(&image->transform.position, &guiinfo->position, sizeof(t_coord));
	ft_memcpy(&image->size, &guiinfo->size, sizeof(t_coord));
	image->transform.name = ft_strdup(guiinfo->name);
	image->transform.children = NULL;
	image->transform.guitype = IMAGE;
	image->transform.guielem = (void*)image;
	return (image);
}
