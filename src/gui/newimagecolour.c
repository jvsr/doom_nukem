/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newimagecolour.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 17:26:08 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 10:49:09 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "sdl_extra.h"
#include "libft/ft_string.h"
#include "libft/ft_memory.h"

t_image		*newimagecolour(t_guiinfo *guiinfo, SDL_Color colour)
{
	t_image *image;

	image = (t_image*)ft_memalloc(sizeof(t_image));
	image->texture = SDL_CreateRGBSurface(0, 1, 1, 32,
			0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	sdl_draw_surface_rect(image->texture, colour, (SDL_Rect){0, 0, 1, 1});
	ft_memcpy(&image->transform.position, &guiinfo->position, sizeof(t_coord));
	ft_memcpy(&image->size, &guiinfo->size, sizeof(t_coord));
	image->transform.name = ft_strdup(guiinfo->name);
	image->transform.children = NULL;
	image->transform.guitype = IMAGE;
	image->transform.guielem = (void*)image;
	image->transform.onclick = NULL;
	image->transform.visible = TRUE;
	image->transform.layer = 0;
	return (image);
}
