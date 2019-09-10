/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newtext.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:06:16 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:56:09 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_memory.h"
#include "libft/ft_string.h"

#include "gui.h"
#include "error.h"

t_text			*newtext(t_guiinfo *guiinfo, char *text,
				t_font *font)
{
	t_text *textui;

	textui = (t_text*)ft_memalloc(sizeof(t_text));
	if (textui == NULL)
		error_msg(strerror(errno), errno);
	textui->text = ft_strdup(text);
	textui->transform.name = ft_strdup(guiinfo->name);
	if (textui->text == NULL || textui->transform.name == NULL)
		error_msg(strerror(errno), errno);
	ft_memcpy(&textui->font, font, sizeof(t_font));
	ft_memcpy(&textui->transform.position, &guiinfo->position, sizeof(t_coord));
	textui->transform.children = NULL;
	textui->transform.guitype = TEXT;
	textui->transform.guielem = (void*)textui;
	textui->transform.onclick = NULL;
	textui->transform.visible = TRUE;
	textui->transform.layer = 0;
	return (textui);
}
