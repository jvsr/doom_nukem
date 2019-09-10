/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroytext.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:44:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 10:57:14 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		destroytext(t_gui *ui, t_text **text, const t_bool delchildren)
{
	t_text *txt;

	txt = *text;
	if (txt->transform.onclick != NULL)
		destroyclick(ui, txt->transform.name);
	ft_strdel(&txt->text);
	if (delchildren == TRUE)
		destroychildren(ui, txt->transform.children, TRUE);
	else if (txt->transform.parent != NULL)
		ft_lstadd(&txt->transform.parent->children,
			txt->transform.children);
	ft_strdel(&txt->transform.name);
	free(txt);
	text = NULL;
}
