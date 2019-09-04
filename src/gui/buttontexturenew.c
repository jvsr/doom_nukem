/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buttontexturenew.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 16:19:04 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 13:39:02 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_memory.h"
#include "libft/ft_string.h"

t_button	*buttontexturenew(t_guiinfo *guiinfo, char *text,
			t_font *font, const SDL_Surface *texture)
{
	t_button *button;

	button = (t_button*)ft_memalloc(sizeof(t_button));
	button->texture = (SDL_Surface*)texture;
	button->text = ft_strdup(text);
	ft_memcpy(&button->font, font, sizeof(t_font));
	ft_memcpy(&button->transform.position, &guiinfo->position, sizeof(t_coord));
	ft_memcpy(&button->size, &guiinfo->size, sizeof(t_coord));
	button->transform.name = ft_strdup(guiinfo->name);
	button->transform.children = NULL;
	button->transform.guitype = BUTTON;
	button->transform.guielem = (void*)button;
	button->transform.onclick = NULL;
	button->transform.visible = TRUE;
	return (button);
}
