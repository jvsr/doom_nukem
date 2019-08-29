/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textnew.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:06:16 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/29 11:42:06 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_memory.h"

t_text			*textnew(const t_guiinfo *guiinfo, const char *text,
				const t_font *font)
{
	t_text *textui;

	textui = (t_text*)ft_memalloc(sizeof(t_text));
	ft_strcpy(textui->text, text);
	ft_memcpy(&textui->font, font, sizeof(t_font));
	ft_memcpy(&textui->transform.position, &guiinfo->position, sizeof(t_coord));
	ft_strcpy(&textui->transform.name, &guiinfo->name);
	textui->transform.children = NULL;
	textui->transform.guitype = TEXT;
	textui->transform.guielem = (void*)textui;
	return (text);
}
