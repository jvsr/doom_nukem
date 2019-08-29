/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buttoncolournew.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 16:58:48 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/29 11:33:52 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_memory.h"
#include "libft/ft_string.h"

t_button	*buttoncolournew(const t_guiinfo *guiinfo, const char *text, 
			const t_font *font, const unsigned int colour)
{
	t_button *button;

	button = (t_button*)ft_memalloc(sizeof(t_button));
	button->texture = SDL_CreateRGBSurface(0, guiinfo->size.x, guiinfo->size.y, 
	32, 0xFF & (colour >> 24), 0xFF & (colour >> 16), 0xFF & (colour >> 8), 
	0xFF & colour);
	ft_strcpy(button->text, text);
	ft_memcpy(&button->font, font, sizeof(t_font));
	ft_memcpy(&button->transform.position, &guiinfo->position, sizeof(t_coord));
	ft_memcpy(&button->size, &guiinfo->size, sizeof(t_coord));
	ft_strcpy(&button->transform.name, &guiinfo->name);
	button->transform.children = NULL;
	button->transform.guitype = BUTTON;
	button->transform.guielem = (void*)button;
	return (button);
}
