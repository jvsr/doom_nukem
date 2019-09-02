/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textnew.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:06:16 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/02 12:28:57 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_memory.h"
#include "libft/ft_string.h"

t_text			*textnew(t_guiinfo *guiinfo, char *text,
				t_font *font)
{
	t_text *textui;

	textui = (t_text*)ft_memalloc(sizeof(t_text));
	textui->text = ft_strdup(text);
	ft_memcpy(&textui->font, font, sizeof(t_font));
	ft_memcpy(&textui->transform.position, &guiinfo->position, sizeof(t_coord));
	textui->transform.name = ft_strdup(guiinfo->name);
	textui->transform.children = NULL;
	textui->transform.guitype = TEXT;
	textui->transform.guielem = (void*)textui;
	return (textui);
}
