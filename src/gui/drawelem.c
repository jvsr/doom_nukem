/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawelem.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 17:28:28 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/02 12:01:08 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"

void		drawelem(t_gui *ui, t_transform *elem)
{
	t_list *lst;

	//if (elem->guitype == BUTTON)
		//drawbutton
	//else if (elem->guitype == IMAGE)
		//drawimage;
	//else if (elem->guitype == PANEL)
		//drawpanel;
	if (elem->guitype == TEXT)
		drawtext(ui, (t_text*)elem->guielem);
	lst = elem->children;
	while (lst != NULL)
	{
		drawelem(ui, (t_transform*)lst->content);
		lst = lst->next;
	}
}
