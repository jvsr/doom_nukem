/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textdestroy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:44:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/29 11:33:11 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		textdestroy(t_text *text, const t_bool destroychildren)
{
	ft_strdel(&text->text);
	if (destroychildren == TRUE)
		childrendestroy(&text->transform.children, TRUE);
	else if (&text->transform.parent != NULL)
		ft_lstadd(&text->transform.parent->children,
			text->transform.children);
	free(text);
	text = NULL;
}
