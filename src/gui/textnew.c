/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textnew.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:06:16 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/28 17:25:26 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_memory.h"

t_text			*textnew(t_guiinfo *guiinfo, char *text, t_font *font)
{
	t_text *textui;

	textui = (t_text*)ft_memalloc(sizeof(t_text));
	ft_strcpy(textui->text, text);
	ft_memcpy(&textui->font, font, sizeof(t_font));
	ft_memcpy(&textui->transform.position, &guiinfo->position, sizeof(t_coord));
	ft_memcpy(&textui->transform.parent, &guiinfo->parent, sizeof(t_transform));
	ft_strcpy(&textui->transform.name, &guiinfo->name);
	textui->transform.children = NULL;
	return (text);
}
