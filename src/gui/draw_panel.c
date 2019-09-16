/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_panel.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 13:48:38 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:58:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"

/*
** * Gui internal function
*/

static void	draw_children(t_transform *child)
{
	while (child != NULL)
	{
		draw_elem(child);
		child = child->next;
	}
}

void		draw_panel(t_transform *elem)
{
	draw_children(elem->gui_elem.panel->children);
}
