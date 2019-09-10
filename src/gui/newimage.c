/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newimage.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:15:07 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:56:26 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_memory.h"
#include "libft/ft_string.h"

#include "gui.h"
#include "sdl_extra.h"
#include "error.h"

t_image		*newimage(t_guiinfo *guiinfo, const SDL_Surface *texture)
{
	t_image *image;

	image = (t_image*)ft_memalloc(sizeof(t_image));
	if (image == NULL)
		error_msg(strerror(errno), errno);
	image->texture = SDL_CreateRGBSurface(0, (int)texture->w,
		(int)texture->h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	image->transform.name = ft_strdup(guiinfo->name);
	if (image->texture == NULL || image->transform.name == NULL)
		error_msg(strerror(errno), errno);
	sdl_merge_surface(image->texture, (SDL_Surface*)texture, (SDL_Point){0, 0});
	ft_memcpy(&image->transform.position, &guiinfo->position, sizeof(t_coord));
	ft_memcpy(&image->size, &guiinfo->size, sizeof(t_coord));
	image->transform.children = NULL;
	image->transform.guitype = IMAGE;
	image->transform.guielem = (void*)image;
	image->transform.onclick = NULL;
	image->transform.visible = TRUE;
	image->transform.layer = 0;
	return (image);
}
