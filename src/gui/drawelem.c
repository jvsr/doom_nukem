/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawelem.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 17:28:28 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 14:23:24 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "gui.h"
#include "game.h"

void		drawelem(t_gui *ui, t_transform *elem)
{
	t_list *lst;

	if (elem->guitype == BUTTON)
		drawbutton(ui, (t_button*)elem->guielem);
	else if (elem->guitype == IMAGE)
		drawimage(ui, (t_image*)elem->guielem);
	else if (elem->guitype == PANEL)
		drawpanel(ui, (t_panel*)elem->guielem);
	else if (elem->guitype == TEXT)
		drawtext(ui, (t_text*)elem->guielem);
	lst = elem->children;
	while (lst != NULL && elem->guitype != PANEL)
	{
		if (((t_transform*)lst->content)->visible == TRUE)
			drawelem(ui, (t_transform*)lst->content);
		lst = lst->next;
	}
}
