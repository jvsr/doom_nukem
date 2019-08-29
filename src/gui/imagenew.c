/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   imagenew.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:15:07 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/29 11:41:46 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_memory.h"
#include "gui.h"

t_image		*imagenew(const t_guiinfo *guiinfo, const SDL_Surface *texture)
{
	t_image *image;

	image = (t_image*)ft_memalloc(sizeof(t_image));
	image->texture = texture;
	ft_memcpy(&image->transform.position, &guiinfo->position, sizeof(t_coord));
	ft_memcpy(&image->size, &guiinfo->size, sizeof(t_coord));
	ft_strcpy(&image->transform.name, &guiinfo->name);
	image->transform.children = NULL;
	image->transform.guitype = IMAGE;
	image->transform.guielem = (void*)image;
	return (image);
}
