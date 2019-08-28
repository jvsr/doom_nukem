/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buttontexturenew.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 16:19:04 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/28 17:25:06 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_memory.h"
#include "libft/ft_string.h"

t_button	*buttontexturenew(t_guiinfo *guiinfo, char *text, t_font *font, 
			SDL_Surface *texture)
{
	t_button *button;

	button = (t_button*)ft_memalloc(sizeof(t_button));
	button->texture = texture;
	ft_strcpy(button->text, text);
	ft_memcpy(&button->font, font, sizeof(t_font));
	ft_memcpy(&button->transform.position, &guiinfo->position, sizeof(t_coord));
	ft_memcpy(&button->size, &guiinfo->size, sizeof(t_coord));
	ft_memcpy(&button->transform.parent, &guiinfo->parent, sizeof(t_transform));
	ft_strcpy(&button->transform.name, &guiinfo->name);
	button->transform.children = NULL;
	return (button);
}
