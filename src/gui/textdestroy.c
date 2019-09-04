/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textdestroy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:44:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 11:23:30 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		textdestroy(t_gui *ui, t_text *text, const t_bool destroychildren)
{
	if (text->transform.onclick != NULL)
		clickdestroy(ui, text->transform.name);
	ft_strdel(&text->text);
	if (destroychildren == TRUE)
		childrendestroy(ui, text->transform.children, TRUE);
	else if (text->transform.parent != NULL)
		ft_lstadd(&text->transform.parent->children,
			text->transform.children);
	ft_strdel(&text->transform.name);
	free(text);
	text = NULL;
}
